#ifndef JANELA_H
#define JANELA_H

#include <string>
#include <GL/glut.h>

#include "enumeradores/enummembro.h"
#include "infraestrutura/configuracoes.h"
#include "infraestrutura/objetoComFuncoesOpenGL.h"
#include "infraestrutura/perspectiva.h"

using namespace std;
using namespace enumeradores;

namespace infraestrutura
{

class Janela
{
public:
    Janela(int altura, int largura, string titulo);
    ~Janela();
    void set_objeto(ObjetoComFuncoesOpenGL* objeto);
    void set_perspectiva(Perspectiva* perspectiva);
    void aplique_perspectiva();
    void aplique_configuracao_padrao();
    void loop();
    void adicione_itens_no_menu(Menu* menu);

private:
    int _altura, _largura;
    string _titulo;
    ObjetoComFuncoesOpenGL* _objeto;
    Perspectiva* _perspectiva;
};

}

#endif // JANELA_H
