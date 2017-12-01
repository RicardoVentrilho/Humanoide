#ifndef HUMANOIDE_H
#define HUMANOIDE_H

#include "infraestrutura/objetoComFuncoesOpenGL.h"
#include "enumeradores/enummembro.h"
#include "junta.h"
#include "osso.h"
#include "GL/gl.h"

using namespace enumeradores;
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
    void desenhe(int rotacao_x, int rotacao_y);
    void selecione_junta(EnumMembro membro);
    void cria_esqueleto(int x, int y, int z);

    Junta* get_cabeca();
    Junta* get_braco_direto();

private:
    Junta* _cabeca;
    Junta* _pescoco;
    Junta* _braco_esquerdo;
    Junta* _braco_direito;
    Junta* _antebraco_esquerdo;
    Junta* _antebraco_direito;
    Junta* _tronco;
    Junta* _ilio_esquerdo;
    Junta* _ilio_direito;
    Junta* _coxa_direita;
    Junta* _coxa_esquerda;
    Junta* _canela_esquerda;
    Junta* _canela_direita;
    Junta* _pe_esquerdo;
    Junta* _pe_direito;
    Junta* _selecionado;
};

}

#endif // HUMANOIDE_H
