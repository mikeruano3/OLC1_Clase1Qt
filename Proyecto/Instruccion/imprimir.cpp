#include "imprimir.h"

Imprimir::Imprimir(NodoAST *exp, int f, int c)
{
    this->fila = f;
    this->columna = c;
    this->exp = exp;
}

Objeto *Imprimir::ejecutar(Entorno *ent){
    Objeto *res = exp->ejecutar(ent);
    if(res->tipo == "entero")
        ent->consola->append(QString::number(res->valor_entero, 10));
    else if(res->tipo == "doble")
        ent->consola->append(QString::number(res->valor_doble));
    else if(res->tipo == "booleano"){
        if(QString::number(res->valor_booleano) == 0)
            ent->consola->append("true");
        else
            ent->consola->append("false");
    }
    else if(res->tipo == "caracter")
        ent->consola->append(QChar(res->valor_caracter));
    else if(res->tipo == "cadena")
        ent->consola->append(res->valor_cadena);
    else
        ent->consola->append("INFO::No se puede imprimir el tipo: "+res->tipo);
    return new Objeto();
}

QString Imprimir::getTipo(){
    return "";
}
