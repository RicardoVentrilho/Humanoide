#include "janela.h"

infraestrutura::Janela::Janela(int altura, int largura, string titulo)
    : _altura(altura), _largura(largura), _titulo(titulo)
{
    int argc = 0;
    char *argv;
    glutInit(&argc, &argv);

    glutInitDisplayMode(GLUT_STENCIL|GLUT_DEPTH|GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(_altura, _largura);
    glutCreateWindow(titulo.c_str());
}

infraestrutura::Janela::~Janela()
{
    delete _objeto;
    delete _perspectiva;
}

void infraestrutura::Janela::set_objeto(Objeto3DComFuncoes *objeto)
{
    glutDisplayFunc(objeto->get_desenhe);
    glutMouseFunc(objeto->get_evento_mouse_click);
    glutMotionFunc(objeto->get_evento_mover_mouse);
    glutKeyboardFunc(objeto->get_evento_clicar_tecla);
    glutSpecialFunc(objeto->get_evento_clicar_tecla_especial);
}

void infraestrutura::Janela::set_perspectiva(infraestrutura::Perspectiva *perspectiva)
{
    _perspectiva = perspectiva;
}

void infraestrutura::Janela::aplique_perspectiva()
{
    _perspectiva->aplique();
}

void infraestrutura::Janela::aplique_configuracao_padrao()
{
    GLfloat posicoes_light[] = {-25.f, 0.f, 50.f, 1.f};

    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, posicoes_light);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_DEPTH_TEST);
}

void infraestrutura::Janela::loop()
{
    glutMainLoop();
}
