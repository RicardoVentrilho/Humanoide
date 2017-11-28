#ifndef POLIGONO_H
#define POLIGONO_H

namespace infraestrutura
{

class Objeto3DComFuncoes
{
public:
    Objeto3DComFuncoes();
    void (*get_desenhe)();
    void (*get_evento_mouse_click)(int, int, int, int);
    void (*get_evento_mover_mouse)(int, int);
    void (*get_evento_clicar_tecla)(unsigned char, int, int);
    void (*get_evento_clicar_tecla_especial)(int, int, int);
};

}

#endif // POLIGONO_H
