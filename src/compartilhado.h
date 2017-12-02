#ifndef COMPARTILHADO_H
#define COMPARTILHADO_H

#include <GL/gl.h>
#include "enumeradores/enumeixo.h"

using namespace enumeradores;

int OPERACAO_EXECUTADA_DO_MENU = 0;

int ROTACAO_CAMERA_X = 1;
int ROTACAO_CAMERA_Y = 1;
int ROTACAO_CAMERA_Z = 1;

GLfloat ROTACAO_X = 0;
GLfloat ROTACAO_Y = 0;
GLfloat ROTACAO_Z = 1;

EnumEixo EIXO_SELECIONADO;

#endif // COMPARTILHADO_H
