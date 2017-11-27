#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

#include "infraestrutura/utilitarios/excecao.h"
#include "infraestrutura/cilindro.h"
#include "infraestrutura/janela.h"

using namespace std;
using namespace infraestrutura;

void render()
{
}

int main(int argc, char *argv[])
{
    try
    {
        glutInit(&argc, argv);

        Janela* janela = new Janela(500, 500, "Título");

        //janela->set_renderizacao(render);

        glutDisplayFunc(render);

        glutMainLoop();
    }
    catch(Excecao* erro)
    {
        cout << erro->get_mensagem() << endl;
    }

    return 0;
}
