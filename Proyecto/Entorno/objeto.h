#ifndef OBJETO_H
#define OBJETO_H

#include <stdio.h>
#include <stdlib.h>
#include <QString>
#include <QChar>
using namespace std;

class Objeto
{
public:
    QString tipo;
    int valor_entero = 0;
    double valor_doble = 0.0;
    QString valor_cadena = NULL;
    char valor_caracter = '\0';
    bool valor_booleano = NULL;
    Objeto();
    Objeto(int valor_entero);
    Objeto(double valor_doble);
    Objeto(QString valor_cadena);
    Objeto(char valor_caracter);
    Objeto(bool valor_booleano);
};

#endif // OBJETO_H
