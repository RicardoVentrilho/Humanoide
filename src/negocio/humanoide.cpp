#include "humanoide.h"

negocio::Humanoide::Humanoide(int x, int y, int z)
{
    cria_esqueleto(x, y, z);
}

void negocio::Humanoide::set_desenhe(void (*funcao)())
{
    get_desenhe = funcao;
}

void negocio::Humanoide::set_evento_clicar_mouse(void (*funcao)(int, int, int, int))
{
    get_evento_mouse_click = funcao;
}

void negocio::Humanoide::set_evento_mover_mouse(void (*funcao)(int, int))
{
    get_evento_mover_mouse = funcao;
}

void negocio::Humanoide::set_evento_clicar_tecla(void (*funcao)(unsigned char, int, int))
{
    get_evento_clicar_tecla = funcao;
}

void negocio::Humanoide::set_evento_clicar_tecla_especial(void (*funcao)(int, int, int))
{
    get_evento_clicar_tecla_especial = funcao;
}

void negocio::Humanoide::desenhe()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    _cabeca->desenhe();

    glutSwapBuffers();
}

void negocio::Humanoide::cria_esqueleto(int x, int y, int z)
{
    _cabeca = new Junta(x, 10 + y, z);

    _pescoco = new Junta(x, y, z);

    _cabeca->adicione_junta(_pescoco);

    _braco_esquerdo = new Junta(-10 + x, -5 + y, z);
    _braco_direito = new Junta(10 + x, -5 + y, z);

    _braco_esquerdo->adicione_junta(new Junta(-20 + x, y, z));
    _braco_direito->adicione_junta(new Junta(20 + x, y, z));

    _pescoco->adicione_junta(_braco_esquerdo);
    _pescoco->adicione_junta(_braco_direito);

    _tronco = new Junta(x, -25 + y, z);

    _pescoco->adicione_junta(_tronco);

    _ilio_esquerdo = new Junta(-5 + x, -25 + y, z);
    _ilio_direito = new Junta(5 + x, -25 + y, z);

    _tronco->adicione_junta(_ilio_esquerdo);
    _tronco->adicione_junta(_ilio_direito);

    _coxa_esquerda = new Junta(-5 + x, -40 + y, z);
    _coxa_direita = new Junta(5 + x, -40 + y, z);

    _ilio_esquerdo->adicione_junta(_coxa_esquerda);
    _ilio_direito->adicione_junta(_coxa_direita);

    _canela_esquerda = new Junta(-5 + x, -55 + y, z);
    _canela_direita = new Junta(5 + x, -55 + y, z);

    _ilio_esquerdo->adicione_junta(_canela_esquerda);
    _ilio_direito->adicione_junta(_canela_direita);

    _pe_esquerdo = new Junta(-10 + x, -60 + y, z);
    _pe_direito = new Junta(10 + x, -60 + y, z);

    _canela_esquerda->adicione_junta(_pe_esquerdo);
    _canela_direita->adicione_junta(_pe_direito);
}

Menu *negocio::Humanoide::get_menu()
{

}

void negocio::Humanoide::set_menu(Menu *menu)
{

}
