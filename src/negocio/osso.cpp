#include "osso.h"

negocio::Osso::Osso(Coordenada *posicao_inicial, Coordenada *posicao_final)
{
    _posicao_inicial = posicao_inicial;
    _posicao_final = posicao_final;
}

negocio::Osso::~Osso()
{

}

Coordenada *negocio::Osso::get_posicao_incial()
{
    return _posicao_inicial;
}

Coordenada *negocio::Osso::get_posicao_final()
{
    return _posicao_final;
}
