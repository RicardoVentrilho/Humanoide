#ifndef JANELA_H
#define JANELA_H

#include <string>
#include <GL/glut.h>

#include "infraestrutura/objeto3DComFuncoes.h"

using namespace std;

namespace infraestrutura
{

class Janela
{
public:
    Janela(int altura, int largura, string titulo);
    void set_objeto(Objeto3DComFuncoes* objeto);
    void loop();

private:
    int _altura, _largura;
    string _titulo;
    Objeto3DComFuncoes* _objeto;
};

}

#endif // JANELA_H
