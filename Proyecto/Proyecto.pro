#-------------------------------------------------
#
# Project created by QtCreator 2019-06-10T16:48:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Ciclos/si.cpp \
    Expresion/operacion.cpp \
    Gramatica/Arbol/nodo.cpp \
    Gramatica/Arbol/NodoAST.cpp \
    Gramatica/parser.cpp \
    Gramatica/scanner.cpp \
    Entorno/entorno.cpp \
    Entorno/objeto.cpp \
    Expresion/expresion.cpp \
    Instruccion/imprimir.cpp \
    Gramatica/Arbol/listanodoast.cpp

HEADERS += \
    Ciclos/si.h \
    Expresion/operacion.h \
    Gramatica/Arbol/nodo.h \
    Gramatica/Arbol/NodoAST.h \
    Gramatica/lexico.l \
    Gramatica/parser.h \
    Gramatica/scanner.h \
    Gramatica/sintactico.yy \
    mainwindow.h \
    Entorno/entorno.h \
    Entorno/objeto.h \
    Expresion/expresion.h \
    Instruccion/imprimir.h \
    Gramatica/Arbol/listanodoast.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    Gramatica/parser.output \
    comandos.txt \
    entrada.txt

SUBDIRS += \
    Proyecto.pro
