#ifndef POLIGONO_H
#define POLIGONO_H

#include "menu.h"

namespace infraestrutura
{

class ObjetoComFuncoesOpenGL
{
public:
    ObjetoComFuncoesOpenGL();
    void (*get_desenhe)();
    void (*get_evento_mouse_click)(int, int, int, int);
    void (*get_evento_mover_mouse)(int, int);
    void (*get_evento_clicar_tecla)(unsigned char, int, int);
    void (*get_evento_clicar_tecla_especial)(int, int, int);
    virtual Menu* get_menu() = 0;
    virtual void set_menu(Menu* menu) = 0;
};

}

#endif // POLIGONO_H
