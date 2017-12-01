#ifndef COORDENADA_H
#define COORDENADA_H

namespace infraestrutura
{

class Coordenada
{
public:
    Coordenada(int x, int y, int z);
    int get_x();
    int get_y();
    int get_z();

private:
    int _x, _y, _z;
};

}

#endif // COORDENADA_H
