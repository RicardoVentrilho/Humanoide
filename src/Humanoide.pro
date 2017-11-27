TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lGL -lGLU -lglut

SOURCES += \
    main.cpp \
    infraestrutura/cilindro.cpp \
    infraestrutura/utilitarios/excecao.cpp \
    infraestrutura/objeto3D.cpp \
    infraestrutura/janela.cpp

HEADERS += \
    infraestrutura/cilindro.h \
    infraestrutura/utilitarios/excecao.h \
    infraestrutura/objeto3D.h \
    infraestrutura/janela.h
