#ifndef JUNTA_H
#define JUNTA_H

#include <vector>
#include <GL/glut.h>

#include "osso.h"
#include "infraestrutura/coordenada.h"

using namespace infraestrutura;
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
    void desenhe();
    void selecione();
    void solte();
    bool esta_selecionado();
    vector<Junta*> get_juntas_adjacentes();
    void set_rotacoes(GLfloat rotacao_x, GLfloat rotacao_y, GLfloat rotacao_z);
    void subtraia_angulo(int angulo_adicional);
    void adicione_angulo(int angulo_adicional);

private:
    vector<Junta*> _juntas_adjacentes;
    vector<Osso*> _ossos;
    Coordenada* _posicao;
    bool _esta_selecionado;
    int _angulo;
    GLfloat _rotacao_x, _rotacao_y, _rotacao_z;
    void desenhe_opengl();
    void desenhe_recursivo(Junta* junta);
    void desenhe_ossos();
};

}

#endif // JUNTA_H
