#include "humanoide.h"

negocio::Humanoide::Humanoide(int x, int y, int z)
{
    _selecionado = NULL;
    cria_esqueleto(x, y, z);
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

void negocio::Humanoide::desenhe(int rotacao_x, int rotacao_y)
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glRotatef(rotacao_x, 1, 0, 0);
     glRotatef(rotacao_y, 0, 1, 0);
     glRotatef(1, 0, 0, 1);

    _cabeca->desenhe();

    glutSwapBuffers();
}

void negocio::Humanoide::selecione_junta(EnumMembro membro)
{
    if(_selecionado != NULL)
    {
        _selecionado->solte();
    }

    switch (membro)
    {
        case CABECA:
            _selecionado = _cabeca;
            _cabeca->selecione();
            break;
        case PESCOCO:
            _selecionado = _pescoco;
            _pescoco->selecione();
            break;
        case TRONCO:
            _selecionado = _tronco;
            _tronco->selecione();
            break;
        case BRACO_DIREITO:
            _selecionado = _braco_direito;
            _braco_direito->selecione();
            break;
        case BRACO_ESQUERDO:
            _selecionado = _braco_esquerdo;
            _braco_esquerdo->selecione();
            break;
        case ANTEBRACO_DIREITO:
            _selecionado = _antebraco_direito;
            _antebraco_direito->selecione();
            break;
        case ANTEBRACO_ESQUERDO:
            _selecionado = _antebraco_esquerdo;
            _antebraco_esquerdo->selecione();
            break;
        case ILIO_DIREITO:
            _selecionado = _ilio_direito;
            _ilio_direito->selecione();
            break;
        case ILIO_ESQUERDO:
            _selecionado = _ilio_esquerdo;
            _ilio_esquerdo->selecione();
            break;
        case COXA_DIREITA:
            _selecionado = _coxa_direita;
            _coxa_direita->selecione();
            break;
        case COXA_ESQUERDA:
            _selecionado = _coxa_esquerda;
            _coxa_esquerda->selecione();
            break;
        case CANELA_DIREITA:
            _selecionado = _canela_direita;
            _canela_direita->selecione();
            break;
        case CANELA_ESQUERDA:
            _selecionado = _canela_esquerda;
            _canela_esquerda->selecione();
            break;
        case PE_DIREITO:
            _selecionado = _pe_direito;
            _pe_direito->selecione();
            break;
        case PE_ESQUERDO:
            _selecionado = _pe_esquerdo;
            _pe_esquerdo->selecione();
            break;
        default:
            break;
    }
}

void negocio::Humanoide::cria_esqueleto(int x, int y, int z)
{
    _cabeca = new Junta(x, 10 + y, z);

    _pescoco = new Junta(x, y, z);

    _cabeca->adicione_junta(_pescoco);

    _braco_esquerdo = new Junta(-10 + x, -5 + y, z);
    _braco_direito = new Junta(10 + x, -5 + y, z);

    _antebraco_direito = new Junta(20 + x, y, z);
    _antebraco_esquerdo = new Junta(-20 + x, y, z);

    _braco_esquerdo->adicione_junta(_antebraco_esquerdo);
    _braco_direito->adicione_junta(_antebraco_direito);

    _pescoco->adicione_junta(_braco_esquerdo);
    _pescoco->adicione_junta(_braco_direito);

    _tronco = new Junta(x, -25 + y, z);

    _pescoco->adicione_junta(_tronco);

    _ilio_esquerdo = new Junta(-5 + x, -25 + y, z);
    _ilio_direito = new Junta(5 + x, -25 + y, z);

    _tronco->adicione_junta(_ilio_esquerdo);
    _tronco->adicione_junta(_ilio_direito);

    _coxa_esquerda = new Junta(-5 + x, -40 + y, z);
    _coxa_direita = new Junta(5 + x, -40 + y, z);

    _ilio_esquerdo->adicione_junta(_coxa_esquerda);
    _ilio_direito->adicione_junta(_coxa_direita);

    _canela_esquerda = new Junta(-5 + x, -55 + y, z);
    _canela_direita = new Junta(5 + x, -55 + y, z);

    _ilio_esquerdo->adicione_junta(_canela_esquerda);
    _ilio_direito->adicione_junta(_canela_direita);

    _pe_esquerdo = new Junta(-10 + x, -60 + y, z);
    _pe_direito = new Junta(10 + x, -60 + y, z);

    _canela_esquerda->adicione_junta(_pe_esquerdo);
    _canela_direita->adicione_junta(_pe_direito);
}

negocio::Junta *negocio::Humanoide::get_cabeca()
{
    return _cabeca;
}

negocio::Junta *negocio::Humanoide::get_braco_direto()
{
    return _braco_direito;
}
