#ifndef LISTANODOAST_H
#define LISTANODOAST_H

#include "NodoAST.h"
#include <QList>

class ListaNodoAST
{
public:
    QList<NodoAST*> misNodos;
    ListaNodoAST();
    ListaNodoAST(QList<NodoAST*> nodos);
    void addNodo(NodoAST* nuevo);
};

#endif // LISTANODOAST_H
