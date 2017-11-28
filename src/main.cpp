#include <iostream>

#include "infraestrutura/utilitarios/excecao.h"
#include "infraestrutura/janela.h"
#include "infraestrutura/perspectiva.h"
#include "negocio/humanoide.h"


using namespace std;
using namespace infraestrutura;
using namespace negocio;

void desenhe()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glPushMatrix();
    glRotatef(30, 0.f, 1.f, 0.f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(1, 1, 0, 0);
    glRotatef(1, 0, 1, 0);
    glRotatef(1, 0, 0, 1);

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 0, 0);
    glutSolidSphere(4, 40, 40);

    glPopMatrix();
    glutSwapBuffers();

    cerr << "Desenhe!" << endl;
}

void ao_click_do_mouse(int, int, int, int)
{
    cerr << "Clicou!" << endl;
}

void ao_mover_mouse(int, int)
{
    cerr << "Moveu!" << endl;
}

void ao_clicar_tecla(unsigned char, int, int)
{
    cerr << "Tecla!" << endl;
}

void ao_clicar_tecla_especial(int, int, int)
{
    cerr << "Tecla especial!" << endl;
}

int main()
{
    try
    {
        Janela* janela = new Janela(500, 500, "Título");
        Perspectiva* perspectiva = new Perspectiva(50);

        Humanoide* humanoide = new Humanoide();

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
