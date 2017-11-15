#ifndef CILINDRO_H
#define CILINDRO_H

#include "utilitarios/excecao.h"
#include "objeto3D.h"

namespace infraestrutura
{

class Cilindro : public Objeto3D
{
public:
    Cilindro();
    void desenhe();
};

}

#endif // CILINDRO_H
