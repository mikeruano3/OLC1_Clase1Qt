#include "Gramatica/Arbol/nodo.h"
#include <qdebug.h>

Nodo::Nodo()
{
    tipo ="";
    valor = "";
    fila = 0;
    columna = 0;
    hijos =  QList<Nodo>();
}

Nodo::Nodo(int l, int c, QString t, QString v)
{
    fila = l;
    columna = c;
    tipo = t;
    valor = v;
    //tipo_ = getTipo();
    hijos = QList<Nodo>();
}

void Nodo::insertarHijos(Nodo nd)
{
    this->hijos.append(nd);
}

int Nodo::getTipo()
{
    if(this->tipo=="int"){return 1;}
    if(this->tipo=="string"){return 2;}
    if(this->tipo=="bool"){return 3;}
    if(this->tipo=="char"){return 4;}
    if(this->tipo=="double"){return 5;}
    if(this->tipo=="suma"){return 6;}
    if(this->tipo=="resta"){return 7;}
    if(this->tipo=="multi"){return 8;}
    if(this->tipo=="div"){return 9;}
    if(this->tipo=="potencia"){return 10;}
    if(this->tipo=="operacion"){return 11;}
    if(this->tipo=="lexp"){return 12;}
    return 0;
}
