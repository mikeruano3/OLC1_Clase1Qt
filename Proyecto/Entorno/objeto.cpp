#include "objeto.h"

Objeto::Objeto(){
    this->tipo = "indefinido";
}

Objeto::Objeto(int valor_entero){
    this->valor_entero = valor_entero;
    this->tipo = "entero";
}
Objeto::Objeto(double valor_doble){
    this->valor_doble = valor_doble;
    this->tipo = "doble";
}
Objeto::Objeto(QString valor_cadena){
    this->valor_cadena = valor_cadena;
    this->tipo = "cadena";
}
Objeto::Objeto(char valor_caracter){
    this->valor_caracter = valor_caracter;
    this->tipo = "caracter";
}
Objeto::Objeto(bool valor_booleano){
    this->valor_booleano = valor_booleano;
    this->tipo = "booleano";
}
