#ifndef JUNTA_H
#define JUNTA_H

#include <vector>

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

private:
    vector<Junta*> _juntas_adjacentes;
    vector<Osso*> _ossos;
    Coordenada* _posicao;
};

}

#endif // JUNTA_H
