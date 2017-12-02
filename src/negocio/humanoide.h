#ifndef HUMANOIDE_H
#define HUMANOIDE_H

#include "infraestrutura/objetoComFuncoesOpenGL.h"
#include "enumeradores/enummembro.h"
#include "enumeradores/enumeixo.h"
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
    void rotacione_membro(EnumEixo eixo, int angulo);

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
    Osso* _cabeca_com_pescoco;
    Osso* _braco_esquerdo_com_antebra_esquerdo;
    Osso* _braco_direito_com_antebra_direito;
    Osso* _pescoco_com_braco_esquerdo;
    Osso* _pescoco_com_braco_direito;
    Osso* _pescoco_com_tronco;
    Osso* _tronco_com_ilio_esquerdo;
    Osso* _tronco_com_ilio_direito;
    Osso* _ilio_esquerdo_com_coxa_esquerda;
    Osso* _ilio_direito_com_coxa_direita;
    Osso* _coxa_esquerda_com_canela_esquerda;
    Osso* _coxa_direta_com_canela_direita;
    Osso* _canela_esquerda_com_pe_esquerdo;
    Osso* _canela_direita_com_pe_direito;
    EnumMembro _membro_selecionado;
};

}

#endif // HUMANOIDE_H
