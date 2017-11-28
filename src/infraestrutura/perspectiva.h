#ifndef PERSPECTIVA_H
#define PERSPECTIVA_H

#include <GL/glut.h>

namespace infraestrutura
{

class Perspectiva
{
public:
    Perspectiva(int tamanho);
    void aplique();

private:
    int _tamanho;
};

}


#endif // PERSPECTIVA_H
