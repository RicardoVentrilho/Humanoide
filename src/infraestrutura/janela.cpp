#include "janela.h"

infraestrutura::Janela::Janela(int altura, int largura, string titulo)
    : _altura(altura), _largura(largura), _titulo(titulo)
{
    int argc = 0;
    char *argv = "";
    glutInit(&argc, &argv);

    glutInitDisplayMode(GLUT_STENCIL|GLUT_DEPTH|GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(_altura, _largura);
    glutCreateWindow("Humanoide");
}

void infraestrutura::Janela::set_objeto(Objeto3DComFuncoes *objeto)
{
    glutDisplayFunc(objeto->get_desenhe);
    glutMouseFunc(objeto->get_evento_mouse_click);
    glutMotionFunc(objeto->get_evento_mover_mouse);
    glutKeyboardFunc(objeto->get_evento_clicar_tecla);
    glutSpecialFunc(objeto->get_evento_clicar_tecla_especial);
}

void infraestrutura::Janela::loop()
{
    glutMainLoop();
}
