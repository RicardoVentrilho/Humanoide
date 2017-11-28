#ifndef JANELA_H
#define JANELA_H

#include <string>
#include <GL/glut.h>

#include "infraestrutura/configuracoes.h"
#include "infraestrutura/objeto3DComFuncoes.h"
#include "infraestrutura/perspectiva.h"

using namespace std;

namespace infraestrutura
{

class Janela
{
public:
    Janela(int altura, int largura, string titulo);
    ~Janela();
    void set_objeto(Objeto3DComFuncoes* objeto);
    void set_perspectiva(Perspectiva* perspectiva);
    void aplique_perspectiva();
    void aplique_configuracao_padrao();
    void loop();

private:
    int _altura, _largura;
    string _titulo;
    Objeto3DComFuncoes* _objeto;
    Perspectiva* _perspectiva;
};

}

#endif // JANELA_H
