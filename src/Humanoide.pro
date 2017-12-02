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
    negocio/junta.cpp \
    negocio/osso.cpp \
    infraestrutura/perspectiva.cpp \
    infraestrutura/coordenada.cpp \
    infraestrutura/menu.cpp \
    infraestrutura/objetoComFuncoesOpenGL.h.cpp \
    infraestrutura/rotacaonoseixos.cpp

HEADERS += \
    infraestrutura/utilitarios/excecao.h \
    infraestrutura/janela.h \
    negocio/humanoide.h \
    negocio/junta.h \
    negocio/osso.h \
    infraestrutura/perspectiva.h \
    infraestrutura/configuracoes.h \
    infraestrutura/coordenada.h \
    infraestrutura/menu.h \
    infraestrutura/objetoComFuncoesOpenGL.h \
    compartilhado.h \
    enumeradores/enummembro.h \
    enumeradores/enumeixo.h \
    infraestrutura/rotacaonoseixos.h
