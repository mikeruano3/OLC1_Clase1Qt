#include "Expresion\operacion.h"
Operacion::Operacion(const char *unico, QString tipo_op, int fila, int columna){
    this->valor = QString::fromUtf8(unico);
    this->tipo = tipo_op;
    this->fila = fila;
    this->columna = columna;
}

Operacion::Operacion(NodoAST *unico, QString tipo_op, int fila, int columna){
    this->nodo_unico = unico;
    this->tipo = tipo_op;
    this->fila = fila;
    this->columna = columna;
}

Operacion::Operacion(NodoAST *izq, NodoAST *der, QString tipo_op, int fila, int columna){
    this->nodo_izq = izq;
    this->nodo_der = der;
    this->tipo = tipo_op;
    this->fila = fila;
    this->columna = columna;
}

QString Operacion::getTipo(){
    return "";
}

Objeto *Operacion::ejecutar(Entorno *ent){
    bool ok;
    if(this->tipo == "suma")
        return suma(nodo_izq, nodo_der, ent);
    else if(this->tipo == "resta")
        return resta(nodo_izq, nodo_der, ent);
    else if(this->tipo == "igualigual")
        return igualigual(nodo_izq, nodo_der, ent);

    else if(this->tipo == "entero")
        return new Objeto(this->valor.toInt(&ok, 10));
    else if(this->tipo == "doble")
        return new Objeto(this->valor.toDouble(&ok));
    else if(this->tipo == "caracter")
        return new Objeto(this->valor.at(0).toLatin1());
    else if(this->tipo == "booleano"){
        if(this->valor.toLower() == "verdadero"
                || this->valor.toLower() == "true"){
            return new Objeto(true);
        }
        else if(this->valor.toLower() == "falso"
                || this->valor.toLower() == "false"){
            return new Objeto(false);
        }
    }else if(this->tipo == "cadena")
        return new Objeto(this->valor);
    else
        ent->consola->append("INFO::Error de conversion desde getTipoChar() "+this->tipo);

    return new Objeto();
}

/*************************************************************
 *************************ARITMETICAS*************************
 * ***********************************************************/

Objeto *Operacion::suma(NodoAST *nodo_izq, NodoAST *nodo_der, Entorno *ent){
    Objeto *izq = nodo_izq->ejecutar(ent);
    Objeto *der = nodo_der->ejecutar(ent);
    if(izq->tipo == "entero"){
        if(der->tipo == "entero")
            return new Objeto(izq->valor_entero + der->valor_entero);
        else if(der->tipo == "doble")
            return new Objeto(static_cast<double>(izq->valor_entero) + der->valor_doble);
        else if(der->tipo == "caracter")
            return new Objeto(izq->valor_entero + static_cast<int>(der->valor_caracter));
        else if(der->tipo == "booleano")
            return new Objeto(izq->valor_entero + static_cast<int>(der->valor_booleano));
        else if(der->tipo == "cadena"){
            QString temp = QString::fromStdString(std::to_string(izq->valor_entero))  + der->valor_cadena;
            return new Objeto(temp.replace("\"",""));
        }else{
            ent->consola->append("INFO::Error del segundo tipo en f:"+QString::number(nodo_der->fila) + ", c:"+QString::number(nodo_der->columna));
        }
    }else if(izq->tipo == "doble"){

    }else if(izq->tipo == "caracter"){

    }else if(izq->tipo == "booleano"){

    }else if(izq->tipo == "cadena"){

    }else{
        ent->consola->append("INFO::Error del primer tipo en f:" +QString::number(nodo_izq->fila) + ", c:"+QString::number(nodo_izq->columna));
    }
    return new Objeto();
}


Objeto *Operacion::resta(NodoAST *nodo_izq, NodoAST *nodo_der, Entorno *ent){
    Objeto *izq = nodo_izq->ejecutar(ent);
    Objeto *der = nodo_der->ejecutar(ent);
}

/*************************************************************
 *************************CONDICIONALES***********************
 * ***********************************************************/

Objeto *Operacion::igualigual(NodoAST *nodo_izq, NodoAST *nodo_der, Entorno *ent){
    ent->consola->append("INFO::Haciendo igualigual");
    Objeto *izq = nodo_izq->ejecutar(ent);
    Objeto *der = nodo_der->ejecutar(ent);
    if(izq->tipo == "entero"){
        if(der->tipo == "entero"){
            if(izq->valor_entero == der->valor_entero)
                return new Objeto(true);
            else
                return new Objeto(false);
        }else if(der->tipo == "doble"){

        }else if(der->tipo == "caracter"){

        }else if(der->tipo == "booleano"){

        }else if(der->tipo == "cadena"){

        }else{
            ent->consola->append("INFO::Error del segundo tipo en f:"+QString::number(nodo_der->fila) + ", c:"+QString::number(nodo_der->columna));
        }
    }else if(izq->tipo == "doble"){

    }else if(izq->tipo == "caracter"){

    }else if(izq->tipo == "booleano"){
        if(izq->tipo == "entero"){

        }else if(izq->tipo == "doble"){

        }else if(izq->tipo == "caracter"){

        }else if(izq->tipo == "booleano"){
            if(izq->valor_booleano == der->valor_booleano)
                return new Objeto(true);
            else
                return new Objeto(false);
        }else if(izq->tipo == "cadena"){

        }else{
            ent->consola->append("INFO::Error del segundo tipo en f:"+QString::number(nodo_der->fila) + ", c:"+QString::number(nodo_der->columna));
        }
    }else if(izq->tipo == "cadena"){

    }else{
        ent->consola->append("INFO::Error del primer tipo en f:" +QString::number(nodo_izq->fila) + ", c:"+QString::number(nodo_izq->columna));
    }
}

