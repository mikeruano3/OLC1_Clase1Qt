#ifndef IMPRIMIR_H
#define IMPRIMIR_H
#include "Gramatica/Arbol/NodoAST.h"
#include "Expresion/expresion.h"
#include "qdebug.h"
#include <iostream>
#include <string>
#include <QTextEdit>

class Imprimir: public NodoAST
{
public:
    NodoAST *exp;
    Imprimir(NodoAST *exp, int f, int c);
    Objeto *ejecutar(Entorno *ent);
    QString getTipo();
};

#endif // IMPRIMIR_H
