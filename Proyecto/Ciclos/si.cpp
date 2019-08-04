#include "Ciclos\si.h"

Si::Si(NodoAST *cond, QList<NodoAST *> accionesSi, QList<NodoAST *> accionesNo, int f, int c){
    this->condicion = cond;
    this->accionesSi = accionesSi;
    this->accionesNo = accionesNo;
    this->fila = f;
    this->columna = c;
}

Objeto *Si::ejecutar(Entorno *ent){
    Objeto *cn = this->condicion->ejecutar(ent);
    if(cn->tipo == "booleano"){
        if(cn->valor_booleano == true){
            ent->consola->append("Es verdad");
        }else{
            ent->consola->append("Es mentira");
        }
    }
}

QString Si::getTipo(){

}

