#include "junta.h"

negocio::Junta::Junta(int x, int y, int z)
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

void negocio::Junta::desenhe(int rotacao_x, int rotacao_y)
{
    desenhe_ossos();

    desenhe_opengl(rotacao_x, rotacao_y);

    desenhe_recursivo(this, rotacao_x, rotacao_y);
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

void negocio::Junta::desenhe_opengl(int rotacao_x, int rotacao_y)
{
    glPushMatrix();
    esta_selecionado() ? glColor3f(1, 0, 0) : glColor3f(0, 0, 1);
    glTranslatef(_posicao->get_x(), _posicao->get_y(), _posicao->get_z());
    glutSolidSphere(2, 40, 40);

    glPopMatrix();
}

void negocio::Junta::desenhe_recursivo(negocio::Junta *junta, int rotacao_x, int rotacao_y)
{
    for(auto juntaSelecionada : junta->get_juntas_adjacentes())
    {
        juntaSelecionada->desenhe(rotacao_x, rotacao_y);
    }
}

void negocio::Junta::desenhe_ossos()
{
    for(auto osso : _ossos)
    {
        osso->desenhe();
    }
}
