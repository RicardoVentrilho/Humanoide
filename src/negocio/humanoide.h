#ifndef HUMANOIDE_H
#define HUMANOIDE_H

#include "infraestrutura/objeto3DComFuncoes.h"
#include "junta.h"
#include "osso.h"

using namespace infraestrutura;

namespace negocio
{

class Humanoide : public Objeto3DComFuncoes
{
public:
    Humanoide(int x, int y, int z);
    Junta* get_raiz();
    void set_desenhe(void (*funcao)());
    void set_evento_clicar_mouse(void (*funcao)(int, int, int, int));
    void set_evento_mover_mouse(void (*funcao)(int, int));
    void set_evento_clicar_tecla(void (*funcao)(unsigned char, int, int));
    void set_evento_clicar_tecla_especial(void (*funcao)(int, int, int));
    void desenhe();
    void cria_esqueleto(int x, int y, int z);

private:
    Junta* _raiz;
};

}

#endif // HUMANOIDE_H
