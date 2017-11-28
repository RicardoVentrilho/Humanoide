#include "humanoide.h"

negocio::Humanoide::Humanoide()
{

}

void negocio::Humanoide::set_desenhe(void (*funcao)())
{
    get_desenhe = funcao;
}

void negocio::Humanoide::set_evento_clicar_mouse(void (*funcao)(int, int, int, int))
{
    get_evento_mouse_click = funcao;
}

void negocio::Humanoide::set_evento_mover_mouse(void (*funcao)(int, int))
{
    get_evento_mover_mouse = funcao;
}

void negocio::Humanoide::set_evento_clicar_tecla(void (*funcao)(unsigned char, int, int))
{
    get_evento_clicar_tecla = funcao;
}

void negocio::Humanoide::set_evento_clicar_tecla_especial(void (*funcao)(int, int, int))
{
    get_evento_clicar_tecla_especial = funcao;
}
