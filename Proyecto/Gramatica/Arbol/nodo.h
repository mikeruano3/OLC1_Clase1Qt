#ifndef NODO
#define NODO
#include <QString>
#include <qlist.h>
class Nodo
{
public:
    QString tipo;
    QString valor;
    int fila;
    int columna;
    QList<Nodo> hijos;
    int tipo_;

    Nodo(); // Constructor
    Nodo(int linea, int columna, QString tipo, QString valor);


    void insertarHijos(Nodo nd);
    int getTipo();
    int getFila();
    int getColumna();
};

#endif // NODOAST_H
