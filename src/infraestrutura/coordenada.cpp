#include "coordenada.h"

infraestrutura::Coordenada::Coordenada(int x, int y, int z)
    : _x(x), _y(y), _z(z)
{
}

int infraestrutura::Coordenada::get_x()
{
    return _x;
}

int infraestrutura::Coordenada::get_y()
{
    return _y;
}

int infraestrutura::Coordenada::get_z()
{
    return _z;
}
