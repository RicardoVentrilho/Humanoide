#ifndef OSSO_H
#define OSSO_H

#include <GL/glut.h>
#include <GL/gl.h>
#include "infraestrutura/coordenada.h"
#include "negocio/junta.h"

using namespace infraestrutura;

namespace negocio
{

class Junta;

class Osso
{
public:
    Osso(Junta* junta_inicial, Junta* junta_final);
    ~Osso();
    void desenhe();

private:
    Junta* _junta_inicial;
    Junta* _junta_final;
};

}

#endif // OSSO_H
