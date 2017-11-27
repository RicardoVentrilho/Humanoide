#ifndef JANELA_H
#define JANELA_H

#include <string>
#include <GL/glut.h>

using namespace std;

namespace infraestrutura
{

class Janela
{
public:
    Janela(int altura, int largura, string titulo);
    void set_renderizacao();
private:
    int _altura, _largura;
    string _titulo;
};

}

#endif // JANELA_H
