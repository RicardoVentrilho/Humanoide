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

void negocio::Junta::desenhe()
{
    desenhe_ossos();

    desenhe_opengl();

    desenhe_recursivo(this);
}

vector<negocio::Junta *> negocio::Junta::get_juntas_adjacentes()
{
    return _juntas_adjacentes;
}

void negocio::Junta::desenhe_opengl()
{
    glPushMatrix();
    glRotatef(30, 0.f, 1.f, 0.f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(1, 1, 0, 0);
    glRotatef(1, 0, 1, 0);
    glRotatef(1, 0, 0, 1);

    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(_posicao->get_x(), _posicao->get_y(), _posicao->get_z());
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
