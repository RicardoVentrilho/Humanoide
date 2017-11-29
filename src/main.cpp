#include <iostream>

#include "infraestrutura/utilitarios/excecao.h"
#include "infraestrutura/janela.h"
#include "infraestrutura/perspectiva.h"
#include "negocio/humanoide.h"


using namespace std;
using namespace infraestrutura;
using namespace negocio;

Humanoide* humanoide = new Humanoide(0, 30, 0);

void desenhe()
{
    humanoide->desenhe();
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
        Janela* janela = new Janela(500, 500, "Computação Gráfica");
        Perspectiva* perspectiva = new Perspectiva(50);

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
