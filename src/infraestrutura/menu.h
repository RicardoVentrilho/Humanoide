#ifndef MENU_H
#define MENU_H

#include <GL/glut.h>
#include <string>

using namespace std;

namespace infraestrutura
{

class Menu
{
public:
    Menu(void (*funcao)(int));
    void adicione_item(string descricao, int opcao);
    void adicione_evento(int evento);
};

}

#endif // MENU_H
