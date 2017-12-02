#ifndef JUNTA_H
#define JUNTA_H

#include <vector>
#include <GL/glut.h>

#include "osso.h"
#include "infraestrutura/coordenada.h"
#include "infraestrutura/rotacaonoseixos.h"
#include "enumeradores/enumeixo.h"

using namespace infraestrutura;
using namespace enumeradores;
using std::vector;

namespace negocio
{

class Junta
{
public:
    Junta(int x, int y, int z);
    ~Junta();
    void adicione_junta(Junta* junta_filha);
    Coordenada* get_posicao();
    RotacaoNosEixos* get_rotacao();
    void desenhe();
    void selecione();
    void solte();
    bool esta_selecionado();
    vector<Junta*> get_juntas_adjacentes();
    void adicione_rotacao(EnumEixo eixo, int angulo);
    void aplique_rotacao(RotacaoNosEixos *rotacao);

private:
    vector<Junta*> _juntas_adjacentes;
    vector<Osso*> _ossos;
    Coordenada* _posicao;
    bool _esta_selecionado;
    int _angulo;
    RotacaoNosEixos* _rotacao_nos_eixos;
    void desenhe_opengl();
    void desenhe_ossos();
};

}

#endif // JUNTA_H
