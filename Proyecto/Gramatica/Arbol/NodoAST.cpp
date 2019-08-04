#include "Gramatica/Arbol/NodoAST.h"

NodoAST::NodoAST()
{
    tipo ="";
    valor = NULL;
    fila = 0;
    columna = 0;
}

NodoAST::NodoAST(int l, int c, QString t, Objeto *v)
{
    fila = l;
    columna = c;
    tipo = t;
    valor = v;
}

