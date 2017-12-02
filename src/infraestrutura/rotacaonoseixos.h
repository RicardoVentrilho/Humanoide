#ifndef ROTACAONOSEIXOS_H
#define ROTACAONOSEIXOS_H

namespace infraestrutura
{
class RotacaoNosEixos
{
public:
    RotacaoNosEixos(int rotacao_x, int rotacao_y, int rotacao_z);
    int get_rotacao_no_eixo_x();
    int get_rotacao_no_eixo_y();
    int get_rotacao_no_eixo_z();
    void adione_rotacao_em_x(int angulo);
    void adione_rotacao_em_y(int angulo);
    void adione_rotacao_em_z(int angulo);
private:
    int _rotacao_x;
    int _rotacao_y;
    int _rotacao_z;
};

}


#endif // ROTACAONOSEIXOS_H
