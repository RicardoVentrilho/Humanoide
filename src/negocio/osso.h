#ifndef OSSO_H
#define OSSO_H

#include "infraestrutura/coordenada.h"

using namespace infraestrutura;

namespace negocio
{

class Osso
{
public:
    Osso(Coordenada* posicao_inicial, Coordenada* posicao_final);
    ~Osso();
    Coordenada* get_posicao_incial();
    Coordenada* get_posicao_final();

private:
    Coordenada* _posicao_inicial;
    Coordenada* _posicao_final;
};

}

#endif // OSSO_H
