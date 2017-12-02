#include "junta.h"
#include <iostream>

negocio::Junta::Junta(int x, int y, int z)
    : _angulo(0)
{
    _posicao = new Coordenada(x, y, z);
    _rotacao_nos_eixos = new RotacaoNosEixos(0, 0, 0);
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
}

Coordenada *negocio::Junta::get_posicao()
{
    return _posicao;
}

RotacaoNosEixos *negocio::Junta::get_rotacao()
{
    return _rotacao_nos_eixos;
}

void negocio::Junta::adicione_osso(negocio::Junta *junta_filha)
{
    Osso* osso = new Osso(this, junta_filha);

    _ossos.push_back(osso);
}

void negocio::Junta::desenhe()
{
    desenhe_ossos();

    desenhe_opengl();
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

void negocio::Junta::adicione_rotacao(EnumEixo eixo, int angulo)
{
    switch (eixo)
    {
        case EIXO_X:
            _rotacao_nos_eixos->adione_rotacao_em_x(angulo);
            break;
        case EIXO_Y:
            _rotacao_nos_eixos->adione_rotacao_em_y(angulo);
            break;
        case EIXO_Z:
            _rotacao_nos_eixos->adione_rotacao_em_z(angulo);
            break;
        default:
            break;
    }
}

void negocio::Junta::aplique_rotacao(RotacaoNosEixos* rotacao)
{
    glTranslatef(_posicao->get_x(), _posicao->get_y(), _posicao->get_z());

    glRotatef ((GLfloat) rotacao->get_rotacao_no_eixo_x(), 1, 0, 0);
    glRotatef ((GLfloat) rotacao->get_rotacao_no_eixo_y(), 0, 1, 0);
    glRotatef ((GLfloat) rotacao->get_rotacao_no_eixo_z(), 0, 0, 1);

    glTranslatef(-1 * _posicao->get_x(), -1 * _posicao->get_y(), -1 * _posicao->get_z());
}

void negocio::Junta::desenhe_opengl()
{
    glPushMatrix();

    esta_selecionado() ? glColor3f(1, 0, 0) : glColor3f(0, 0, 1);

    glBegin(GL_POINTS);
    glVertex3f(_posicao->get_x(), _posicao->get_y(), _posicao->get_z());
    glEnd();

    glPopMatrix();
}

void negocio::Junta::desenhe_ossos()
{
    for(auto osso : _ossos)
    {
        osso->desenhe();
    }
}
