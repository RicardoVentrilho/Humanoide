#ifndef JUNTA_H
#define JUNTA_H

#include <vector>

#include "osso.h"

using std::vector;

namespace negocio
{

class Junta
{
public:
    Junta();

private:
    vector<Junta*> juntas_adjacentes;
    vector<Osso*> ossos;
};

}

#endif // JUNTA_H
