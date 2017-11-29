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
    vector<Junta*> get_juntas_adjacentes();

private:
    vector<Junta*> _juntas_adjacentes;
    vector<Osso*> _ossos;
    Coordenada* _posicao;
    bool _esta_selecionado;
    void desenhe_opengl();
    void desenhe_recursivo(Junta* junta);
    void desenhe_ossos();
};

}

#endif // JUNTA_H
