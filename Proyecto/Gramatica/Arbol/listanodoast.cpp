#include "listanodoast.h"

ListaNodoAST::ListaNodoAST(){

}
ListaNodoAST::ListaNodoAST(QList<NodoAST*> nodos){
    misNodos = nodos;
}
void ListaNodoAST::addNodo(NodoAST* nuevo){
    misNodos.append(nuevo);
}
