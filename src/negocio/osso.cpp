#include "osso.h"

negocio::Osso::Osso(Coordenada *posicao_inicial, Coordenada *posicao_final)
{
    _posicao_inicial = posicao_inicial;
    _posicao_final = posicao_final;
}

negocio::Osso::~Osso()
{
    ////TODO: Remover posições
}

Coordenada *negocio::Osso::get_posicao_incial()
{
    return _posicao_inicial;
}

Coordenada *negocio::Osso::get_posicao_final()
{
    return _posicao_final;
}

void negocio::Osso::desenhe()
{
    glLineWidth(5);
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);

    glVertex3f(_posicao_inicial->get_x(), _posicao_inicial->get_y(), _posicao_inicial->get_z());
    glVertex3f(_posicao_final->get_x(), _posicao_final->get_y(), _posicao_final->get_z());
    glEnd();
}
