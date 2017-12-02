#include "menu.h"

infraestrutura::Menu::Menu(void (*funcao)(int))
{
    glutCreateMenu(funcao);
}

void infraestrutura::Menu::adicione_item(string descricao, int opcao)
{
    glutAddMenuEntry(descricao.c_str(), opcao);
}

void infraestrutura::Menu::adicione_evento(int evento)
{
    glutAttachMenu(evento);
}
