#ifndef HUMANOIDE_H
#define HUMANOIDE_H

#include "infraestrutura/objetoComFuncoesOpenGL.h"
#include "junta.h"
#include "osso.h"

using namespace infraestrutura;

namespace negocio
{

class Humanoide : public ObjetoComFuncoesOpenGL
{
public:
    Humanoide(int x, int y, int z);
    void set_desenhe(void (*funcao)());
    void set_evento_clicar_mouse(void (*funcao)(int, int, int, int));
    void set_evento_mover_mouse(void (*funcao)(int, int));
    void set_evento_clicar_tecla(void (*funcao)(unsigned char, int, int));
    void set_evento_clicar_tecla_especial(void (*funcao)(int, int, int));
    void desenhe();
    void cria_esqueleto(int x, int y, int z);
    Menu* get_menu();
    void set_menu(Menu* menu);

private:
    Junta* _cabeca;
    Junta* _pescoco;
    Junta* _braco_esquerdo;
    Junta* _braco_direito;
    Junta* anti_braco_esquerdo;
    Junta* _anti_braco_direito;
    Junta* _tronco;
    Junta* _ilio_esquerdo;
    Junta* _ilio_direito;
    Junta* _coxa_direita;
    Junta* _coxa_esquerda;
    Junta* _canela_esquerda;
    Junta* _canela_direita;
    Junta* _pe_esquerdo;
    Junta* _pe_direito;
};

}

#endif // HUMANOIDE_H
