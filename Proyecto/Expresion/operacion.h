#ifndef OPERACION_H
#define OPERACION_H
#include "Expresion/operacion.h"
#include "Expresion/expresion.h"
#include "Gramatica/Arbol/NodoAST.h"
#include <string>

class Operacion: public NodoAST
{
public:
    NodoAST *nodo_izq;
    NodoAST *nodo_der;
    NodoAST *nodo_unico;
    QString valor;

    Operacion(NodoAST *unico, QString tipo_op, int fila ,int columna);
    Operacion(const char *unico, QString tipo_op, int fila ,int columna);
    Operacion(NodoAST *izq, NodoAST *der, QString tipo_op, int fila, int columna);
    Objeto *ejecutar(Entorno *ent);
    QString getTipo();

    Objeto *suma(NodoAST *nodo_izq, NodoAST *nodo_der, Entorno *ent);
    Objeto *resta(NodoAST *nodo_izq, NodoAST *nodo_der, Entorno *ent);
    Objeto *igualigual(NodoAST *nodo_izq, NodoAST *nodo_der, Entorno *ent);
};

#endif // OPERACION_H
