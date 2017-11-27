#include "janela.h"

infraestrutura::Janela::Janela(int altura, int largura, string titulo)
    : _altura(altura), _largura(largura), _titulo(titulo)
{
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(_altura, _largura);
    glutCreateWindow("Humanoide");

}

void infraestrutura::Janela::set_renderizacao()
{

}
