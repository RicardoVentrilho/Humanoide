#include "rotacaonoseixos.h"

infraestrutura::RotacaoNosEixos::RotacaoNosEixos(int rotacao_x, int rotacao_y, int rotacao_z)
    : _rotacao_x(rotacao_x), _rotacao_y(rotacao_y), _rotacao_z(rotacao_z)
{
}

int infraestrutura::RotacaoNosEixos::get_rotacao_no_eixo_x()
{
    return _rotacao_x;
}

int infraestrutura::RotacaoNosEixos::get_rotacao_no_eixo_y()
{
    return _rotacao_y;
}

int infraestrutura::RotacaoNosEixos::get_rotacao_no_eixo_z()
{
    return _rotacao_z;
}

void infraestrutura::RotacaoNosEixos::adione_rotacao_em_x(int angulo)
{
    _rotacao_x = (_rotacao_x + angulo) % 360;
}

void infraestrutura::RotacaoNosEixos::adione_rotacao_em_y(int angulo)
{
    _rotacao_y = (_rotacao_y + angulo) % 360;
}

void infraestrutura::RotacaoNosEixos::adione_rotacao_em_z(int angulo)
{
    _rotacao_z = (_rotacao_z + angulo) % 360;
}
