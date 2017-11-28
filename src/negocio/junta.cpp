#include "junta.h"

negocio::Junta::Junta(int x, int y, int z)
{
    _posicao = new Coordenada(x, y, z);
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
