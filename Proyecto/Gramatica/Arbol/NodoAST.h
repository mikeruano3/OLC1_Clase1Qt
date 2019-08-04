#ifndef NODOAST_H
#define NODOAST_H
#include <QString>
#include <qlist.h>
#include <qdebug.h>
#include "Entorno/entorno.h"
#include "Entorno/objeto.h"

class NodoAST
{
public:
    QString tipo;
    Objeto valor;
    int fila;
    int columna;
    NodoAST();
    NodoAST(int l, int c, QString t, Objeto *v);
    virtual QString getTipo()=0;
    virtual Objeto *ejecutar(Entorno *ent)=0;

    int getFila();
    int getColumna();
};

#endif // NODOAST_H
