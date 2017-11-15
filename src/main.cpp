#include <iostream>
#include "infraestrutura/utilitarios/excecao.h"
#include "infraestrutura/cilindro.h"

using namespace std;
using namespace infraestrutura;

int main(int argc, char *argv[])
{
    try
    {
        Objeto3D* cilindro = new Cilindro();
        cilindro->desenhe();
    }
    catch(Excecao* erro)
    {
        cout << erro->get_mensagem() << endl;
    }

    return 0;
}
