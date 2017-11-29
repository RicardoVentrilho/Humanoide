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
    glClearColor(1, 1, 1, 0);
}

infraestrutura::Janela::~Janela()
{
    delete _perspectiva;
}

void infraestrutura::Janela::set_objeto(ObjetoComFuncoesOpenGL *objeto)
{
    glutDisplayFunc(objeto->get_desenhe);
    glutMouseFunc(objeto->get_evento_mouse_click);
    glutMotionFunc(objeto->get_evento_mover_mouse);
    glutKeyboardFunc(objeto->get_evento_clicar_tecla);
    glutSpecialFunc(objeto->get_evento_clicar_tecla_especial);
}

void infraestrutura::Janela::set_perspectiva(Perspectiva *perspectiva)
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

void infraestrutura::Janela::adicione_itens_no_menu(infraestrutura::Menu *menu)
{
    menu->adicione_item("Cabeca", CABECA);
    menu->adicione_item("Pescoco", PESCOCO);
    menu->adicione_item("Tronco", TRONCO);
    menu->adicione_item("Braco Direito", BRACO_DIREITO);
    menu->adicione_item("Braco Esquerdo", BRACO_ESQUERDO);
    menu->adicione_item("Antebraco Direito", ANTEBRACO_DIREITO);
    menu->adicione_item("Antebraco Esquerdo", ANTEBRACO_ESQUERDO);
    menu->adicione_item("Ilio Direito", ILIO_DIREITO);
    menu->adicione_item("Ilio Esquerdo", ILIO_ESQUERDO);
    menu->adicione_item("Coxa Direita", COXA_DIREITA);
    menu->adicione_item("Coxa Esquerda", COXA_ESQUERDA);
    menu->adicione_item("Canela Direita", CANELA_DIREITA);
    menu->adicione_item("Canela Esquerda", CANELA_ESQUERDA);
    menu->adicione_item("Pe Direito", PE_DIREITO);
    menu->adicione_item("Pe Esquerdo", PE_ESQUERDO);

    menu->adicione_evento(GLUT_RIGHT_BUTTON);
}
