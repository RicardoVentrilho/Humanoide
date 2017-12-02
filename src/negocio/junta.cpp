#include "junta.h"
#include <iostream>

negocio::Junta::Junta(int x, int y, int z)
    : _angulo(0)
{
    _posicao = new Coordenada(x, y, z);
    _esta_selecionado = false;
}

negocio::Junta::~Junta()
{
    delete _posicao;
    ////TODO: Excluir listas de ossos e juntas;
}

void negocio::Junta::adicione_junta(negocio::Junta *junta_filha)
{
    _juntas_adjacentes.push_back(junta_filha);

    Osso* osso = new Osso(_posicao, junta_filha->get_posicao());

    _ossos.push_back(osso);
}

Coordenada *negocio::Junta::get_posicao()
{
    return _posicao;
}

void negocio::Junta::desenhe()
{
    desenhe_ossos();

    glPushMatrix();

    desenhe_opengl();

    desenhe_recursivo(this);
}

void negocio::Junta::selecione()
{
    _esta_selecionado = true;
}

void negocio::Junta::solte()
{
    _esta_selecionado = false;
}

bool negocio::Junta::esta_selecionado()
{
    return _esta_selecionado;
}

vector<negocio::Junta *> negocio::Junta::get_juntas_adjacentes()
{
    return _juntas_adjacentes;
}

void negocio::Junta::set_rotacoes(GLfloat rotacao_x, GLfloat rotacao_y, GLfloat rotacao_z)
{
    _rotacao_x = rotacao_x;
    _rotacao_y = rotacao_y;
    _rotacao_z = rotacao_z;
}

void negocio::Junta::subtraia_angulo(int angulo_adicional)
{
    _angulo = (_angulo - angulo_adicional) % 360;
}

void negocio::Junta::adicione_angulo(int angulo_adicional)
{
    _angulo = (_angulo + angulo_adicional) % 360;
}

void negocio::Junta::desenhe_opengl()
{
    glPushMatrix();

    glTranslatef(_posicao->get_x(), _posicao->get_y(), _posicao->get_z());

    //glTranslatef(0, 20, 0);
    std::cerr << "Angulo:" << _angulo << std::endl;
    glRotatef((GLfloat)_angulo, _rotacao_x, _rotacao_y, _rotacao_z);
    glTranslatef(-1 * _posicao->get_x(), -1 * _posicao->get_y(), -1 * _posicao->get_z());

    esta_selecionado() ? glColor3f(1, 0, 0) : glColor3f(0, 0, 1);

    glutSolidSphere(2, 40, 40);

    glPopMatrix();
}

void negocio::Junta::desenhe_recursivo(negocio::Junta *junta)
{
    for(auto juntaSelecionada : junta->get_juntas_adjacentes())
    {
        juntaSelecionada->desenhe();
    }
}

void negocio::Junta::desenhe_ossos()
{
    for(auto osso : _ossos)
    {
        osso->desenhe();
    }
}
