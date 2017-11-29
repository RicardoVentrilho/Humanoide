#include "humanoide.h"

negocio::Humanoide::Humanoide(int x, int y, int z)
{
    cria_esqueleto(x, y, z);
}

negocio::Junta *negocio::Humanoide::get_raiz()
{
    return _raiz;
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

    _raiz->desenhe();

    glutSwapBuffers();
}

void negocio::Humanoide::cria_esqueleto(int x, int y, int z)
{
    auto cabeca = new Junta(x, 10 + y, z);

    auto pescoco = new Junta(x, y, z);

    cabeca->adicione_junta(pescoco);

    auto braco_esquerdo = new Junta(-10 + x, -5 + y, z);
    auto braco_direito = new Junta(10 + x, -5 + y, z);

    braco_esquerdo->adicione_junta(new Junta(-20 + x, y, z));
    braco_direito->adicione_junta(new Junta(20 + x, y, z));

    pescoco->adicione_junta(braco_esquerdo);
    pescoco->adicione_junta(braco_direito);

    auto tronco = new Junta(x, -25 + y, z);

    pescoco->adicione_junta(tronco);

    auto ilio_esquerdo = new Junta(-5 + x, -25 + y, z);
    auto ilio_direito = new Junta(5 + x, -25 + y, z);

    tronco->adicione_junta(ilio_esquerdo);
    tronco->adicione_junta(ilio_direito);

    auto femur_esquerdo = new Junta(-5 + x, -40 + y, z);
    auto femur_direito = new Junta(5 + x, -40 + y, z);

    ilio_esquerdo->adicione_junta(femur_esquerdo);
    ilio_direito->adicione_junta(femur_direito);

    auto tibia_esquerdo = new Junta(-5 + x, -55 + y, z);
    auto tibia_direito = new Junta(5 + x, -55 + y, z);

    ilio_esquerdo->adicione_junta(tibia_esquerdo);
    ilio_direito->adicione_junta(tibia_direito);

    auto pe_esquerdo = new Junta(-10 + x, -60 + y, z);
    auto pe_direito = new Junta(10 + x, -60 + y, z);

    tibia_esquerdo->adicione_junta(pe_esquerdo);
    tibia_direito->adicione_junta(pe_direito);

    _raiz = cabeca;
}
