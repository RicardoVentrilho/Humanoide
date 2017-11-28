#include "perspectiva.h"

infraestrutura::Perspectiva::Perspectiva(int tamanho)
    : _tamanho(tamanho)
{
}

void infraestrutura::Perspectiva::aplique()
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(-_tamanho, _tamanho, -_tamanho, _tamanho, -_tamanho, _tamanho);
    glMatrixMode(GL_MODELVIEW);
}
