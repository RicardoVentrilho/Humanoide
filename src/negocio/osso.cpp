#include "osso.h"

negocio::Osso::Osso(Junta *junta_inicial, Junta *junta_final)
{
    _junta_inicial = junta_inicial;
    _junta_final = junta_final;
}

negocio::Osso::~Osso()
{
    ////TODO: Remover posições
}

void negocio::Osso::desenhe()
{
    glLineWidth(5);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex3f(_junta_inicial->get_posicao()->get_x(), _junta_inicial->get_posicao()->get_y(), _junta_inicial->get_posicao()->get_z());
    glVertex3f(_junta_final->get_posicao()->get_x(), _junta_final->get_posicao()->get_y(), _junta_final->get_posicao()->get_z());
    glEnd();
}
