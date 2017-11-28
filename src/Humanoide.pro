TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lGL -lGLU -lglut

SOURCES += \
    main.cpp \
    infraestrutura/utilitarios/excecao.cpp \
    infraestrutura/janela.cpp \
    negocio/humanoide.cpp \
    infraestrutura/objeto3DComFuncoes.cpp \
    negocio/junta.cpp \
    negocio/osso.cpp \
    infraestrutura/perspectiva.cpp \
    infraestrutura/coordenada.cpp

HEADERS += \
    infraestrutura/utilitarios/excecao.h \
    infraestrutura/janela.h \
    negocio/humanoide.h \
    infraestrutura/objeto3DComFuncoes.h \
    negocio/junta.h \
    negocio/osso.h \
    infraestrutura/perspectiva.h \
    infraestrutura/configuracoes.h \
    infraestrutura/coordenada.h
