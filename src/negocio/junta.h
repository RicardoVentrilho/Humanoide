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

class Osso;

class Junta
{
public:
    Junta(int x, int y, int z);
    ~Junta();    Coordenada* get_posicao();
    RotacaoNosEixos* get_rotacao();
    void desenhe();
    void selecione();
    void solte();
    bool esta_selecionado();
    void adicione_rotacao(EnumEixo eixo, int angulo);
    void aplique_rotacao(RotacaoNosEixos *rotacao);

private:
    Coordenada* _posicao;
    RotacaoNosEixos* _rotacao_nos_eixos;
    bool _esta_selecionado;
    int _angulo;
    void desenhe_opengl();
};

}

#endif // JUNTA_H
