#ifndef SI_H
#define SI_H
#include "Gramatica/Arbol/NodoAST.h"
#include "Entorno/entorno.h"
#include "Entorno/objeto.h"
#include <qlist.h>

class Si:public NodoAST
{
public:
    NodoAST *condicion;
    QList<NodoAST*> elseifs;
    QList<NodoAST*> accionesSi;
    QList<NodoAST*> accionesNo;
    int fila;
    int getFila();
    int columna;

    Si(NodoAST *cond, QList<NodoAST *> accionesSi, QList<NodoAST *> accionesNo, int f, int c);
    ~Si();

    Objeto *ejecutar(Entorno *ent);
    QString getTipo();
};

#endif // SI_H
