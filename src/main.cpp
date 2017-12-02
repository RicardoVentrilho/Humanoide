#include <iostream>

#include "compartilhado.h"
#include "enumeradores/enummembro.h"
#include "infraestrutura/utilitarios/excecao.h"
#include "infraestrutura/janela.h"
#include "infraestrutura/perspectiva.h"
#include "negocio/humanoide.h"

using namespace std;
using namespace enumeradores;
using namespace infraestrutura;
using namespace negocio;

Humanoide* humanoide = new Humanoide(0, 30, 0);

void desenhe()
{
    humanoide->desenhe(ROTACAO_CAMERA_X, ROTACAO_CAMERA_Y);
}

void ao_click_do_mouse(int, int, int, int)
{
}

void ao_mover_mouse(int, int)
{
}

void ao_clicar_tecla(unsigned char tecla, int, int)
{
    switch (tecla)
    {
        case '-':
            humanoide->rotacione_membro(EIXO_SELECIONADO, -5);
            break;
        case '+':
            humanoide->rotacione_membro(EIXO_SELECIONADO, 5);
            break;
        case 'x':
            EIXO_SELECIONADO = EIXO_X;
            break;
        case 'y':
            EIXO_SELECIONADO = EIXO_Y;
            break;
        case 'z':
            EIXO_SELECIONADO = EIXO_Z;
            break;
        default:
            break;
    }

    desenhe();
}

void ao_clicar_tecla_especial(int tecla, int, int)
{
    switch(tecla) {
        case GLUT_KEY_LEFT:
            ROTACAO_CAMERA_Y -= 2;
            break;
        case GLUT_KEY_RIGHT:
            ROTACAO_CAMERA_Y += 2;
            break;
        case GLUT_KEY_UP:
            ROTACAO_CAMERA_X -= 2;
            break;
        case GLUT_KEY_DOWN:
            ROTACAO_CAMERA_X += 2;
            break;
    }

    glutPostRedisplay();
}

void funcao_do_menu(int operacao)
{
    OPERACAO_EXECUTADA_DO_MENU = operacao;
    humanoide->selecione_junta((EnumMembro)operacao);
    glutPostRedisplay();
}

int main()
{
    try
    {
        Janela* janela = new Janela(500, 500, "Computação Gráfica");
        Perspectiva* perspectiva = new Perspectiva(50);
        Menu* menu = new Menu(funcao_do_menu);

        janela->adicione_itens_no_menu(menu);

        humanoide->set_desenhe(desenhe);
        humanoide->set_evento_clicar_mouse(ao_click_do_mouse);
        humanoide->set_evento_mover_mouse(ao_mover_mouse);
        humanoide->set_evento_clicar_tecla(ao_clicar_tecla);
        humanoide->set_evento_clicar_tecla_especial(ao_clicar_tecla_especial);

        janela->set_perspectiva(perspectiva);
        janela->aplique_perspectiva();
        janela->aplique_configuracao_padrao();

        janela->set_objeto(humanoide);

        janela->loop();
    }
    catch(Excecao* erro)
    {
        cout << erro->get_mensagem() << endl;
    }

    return 0;
}
