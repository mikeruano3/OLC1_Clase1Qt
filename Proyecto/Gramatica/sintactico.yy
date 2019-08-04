%{
using namespace std;
#include "scanner.h"
#include "qdebug.h"
#include <iostream>
#include <string>
#include <QTextEdit>
#include "Arbol/nodo.h"
#include "Arbol/NodoAST.h"
#include "Arbol/listanodoast.h"
#include "Expresion/expresion.h"
#include "Expresion/operacion.h"
#include "Instruccion/imprimir.h"
#include "Ciclos/si.h"
#include "qlist.h"

extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
extern ListaNodoAST *raiz; // Raiz del arbol
extern int nLine;


//salida
QTextEdit *salida;
QTextEdit *dot;
extern void setSalida(QTextEdit* sal, QTextEdit* grafo) {
    //metodo que asigna el valor al QTextEdit de salida
    salida=sal;
    dot=grafo;
}

int yyerror(const char* mens){
    cout<<mens<<endl;
    return 0;
}

//Grafo
QString cadGrafo="digraph G {\nnodesep=0.3;\nranksep=0.2;\nmargin=0.1;\nnode [shape=circle];\nedge [arrowsize=0.8];\n";

%}

//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%error-verbose
%locations


%union{ 
    char TEXT[256];//Caracter!
    class Nodo *NOD;
    class NodoAST *ND;
    class ListaNodoAST *LISTND;
}

//TERMINALES DE TIPO TEXT, SON STRINGS
%token<TEXT> tEntero
%token<TEXT> tDecimal
%token<TEXT> tCaracter
%token<TEXT> tBooleano
%token<TEXT> tCadena
%token<TEXT> tId
%token<TEXT> tPari
%token<TEXT> tPard
%token<TEXT> tSuma
%token<TEXT> tMenos
%token<TEXT> tMulti
%token<TEXT> tDivision
%token<TEXT> tPotencia
%token<TEXT> tPuntocoma
%token<TEXT> tImprimir
%token<TEXT> tIgual
%token<TEXT> tAnd
%token<TEXT> tOr
%token<TEXT> tLlavi
%token<TEXT> tLlavd
%token<TEXT> tSi
%token<TEXT> tSino
%token<TEXT> tIgualIgual
%token<TEXT> tDiferenteIgual
%token<TEXT> tMenorQue
%token<TEXT> tMayorQue

/*No terimanesl*/
%type<LISTND> INICIO
%type<ND> EXPA
%type<ND> IMPRIMIR
%type<ND> SISINO
%type<LISTND> LISTASENTENCIAS
%type<ND> SENTENCIA

%left tOr
%left tAnd
%left tIgualIgual tDiferenteIgual tMenorQue tMayorQue
%left tSuma tMenos
%left tMulti tDivision
%left tPotencia

/*SIMBOLO CON EL QUE INICIA*/
%start INICIO

%%

INICIO : LISTASENTENCIAS {raiz = $$; raiz = $1;};

LISTASENTENCIAS : LISTASENTENCIAS SENTENCIA{ $$->addNodo($2); }
            | SENTENCIA{ QList<NodoAST*> nodos; nodos.append($1); $$ = new ListaNodoAST(nodos); }
            ;

SENTENCIA : IMPRIMIR { $$ = $1; }
          | SISINO { $$ = $1; }
          | error tPuntocoma
          ;

SISINO  : tSi tPari EXPA tPard tLlavi LISTASENTENCIAS tLlavd tSino tLlavi LISTASENTENCIAS tLlavd {Si *ssi = new Si($3, $6->misNodos, $10->misNodos, @1.first_line, @1.first_column); $$ = ssi;}
    ;

IMPRIMIR: tImprimir tPari EXPA tPard tPuntocoma {Imprimir *imp = new Imprimir($3, @1.first_line, @1.first_column); $$ = imp;}
        ;

EXPA://Nodo *nod = new Nodo(@1.first_line, @1.first_column,"suma",$2);  nod->insertarHijos(*$1); nod->insertarHijos(*$3); $$=nod;
 EXPA tSuma EXPA {    Operacion *op = new Operacion($1, $3, "suma", yylineno, columna); $$ = op;}
|EXPA tMenos EXPA {   Operacion *op = new Operacion($1, $3, "resta", yylineno, columna); $$ = op;}
|EXPA tMulti EXPA {   Operacion *op = new Operacion($1, $3, "multi", yylineno, columna); $$ = op;}
|EXPA tDivision EXPA {Operacion *op = new Operacion($1, $3, "div", yylineno, columna); $$ = op;}
|EXPA tPotencia EXPA{ Operacion *op = new Operacion($1, $3, "pot", yylineno, columna); $$ = op;}

|EXPA tAnd EXPA{ Operacion *op = new Operacion($1, $3, "and", yylineno, columna); $$ = op;}
|EXPA tOr EXPA{ Operacion *op = new Operacion($1, $3, "or", yylineno, columna); $$ = op;}
|EXPA tIgualIgual EXPA  { Operacion *op = new Operacion($1, $3, "igualigual", yylineno, columna); $$ = op;}
|EXPA tDiferenteIgual EXPA{ Operacion *op = new Operacion($1, $3, "diferenteigual", yylineno, columna); $$ = op;}
|EXPA tMenorQue EXPA  { Operacion *op = new Operacion($1, $3, "menorque", yylineno, columna); $$ = op;}
|EXPA tMayorQue EXPA  { Operacion *op = new Operacion($1, $3, "mayorque", yylineno, columna); $$ = op;}

|tMenos EXPA { Operacion *op = new Operacion($2, "menos", yylineno, columna); $$ = op;}
|tEntero {     Operacion *op = new Operacion($1, "entero", yylineno, columna); $$ = op;}
|tCaracter {   Operacion *op = new Operacion($1, "caracter", yylineno, columna); $$ = op;}
|tDecimal {    Operacion *op = new Operacion($1, "doble", yylineno, columna); $$ = op;}
|tBooleano {   Operacion *op = new Operacion($1, "booleano", yylineno, columna); $$ = op;}
|tCadena {     Operacion *op = new Operacion($1, "cadena", yylineno, columna); $$ = op;}
|tPari EXPA tPard{$$=$2;}
;

%%
