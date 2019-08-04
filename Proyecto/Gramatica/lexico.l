%option case-insensitive
%option yylineno
%{
#include <iostream>
#include <stdlib.h>
#include <string>
#include "parser.h"
#include <cstdlib>
#include "parser.h"
#include <QString>
#include <stdio.h>
#include <iostream>
#include <Gramatica/Arbol/nodo.h>
#include "qlist.h"

int yylex();
void yyerror(const char *s);
int linea=0; // Para contar lineas
int columna = 1; // para las columnas
int anterior = 0;

bool imprimir = true;
void imprimirEnConsola(const char *mensaje, const char *tkn){
    if(imprimir){
        std::cout << mensaje <<" : "<<tkn <<std::endl;
    }
}

Nodo *raiz;
%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput


letra [a-zñA-ZÑ]+
entero [0-9]+
booleano ("verdadero"|"falso"|"true"|"false")
decimal [0-9]+"."[0-9]+
caracter [\']([^\']|[\\][^\'])?[\']
iden {letra}({letra}|{numero}|"_")*
cadena "\""[^"\""]*"\""

%x COMSIMP COMMULT

 /****************
  * *********** / */

%%
INITIAL
{
"//" {  BEGIN(COMSIMP); }
"/*" {  BEGIN (COMMULT); }
{entero}   {   columna=columna+anterior; anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("entero", yytext); return tEntero;}
{decimal}  {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("decimal", yytext); return tDecimal;}
{caracter} {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("caracter", yytext); return tCaracter;}
{booleano} {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("booleano", yytext); return tBooleano;}
{cadena}   {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("cadena", yytext); return tCadena;}
"("        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("ParIzq", yytext); return tPari; }
")"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("ParDer", yytext); return tPard; }
"{"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("LlavIzq", yytext); return tLlavi; }
"}"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("LlavDer", yytext); return tLlavd; }
";"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("PuntoComa", yytext); return tPuntocoma; }
"+"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("suma", yytext); return tSuma; }
"-"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("menos", yytext); return tMenos; }
"*"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("multi", yytext); return tMulti; }
"/"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("division", yytext); return tDivision; }
"^"        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("potencia", yytext); return tPotencia; }
"&&"       {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("and", yytext); return tAnd; }
"||"       {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("or", yytext); return tOr; }
"="        {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("igual", yytext); return tIgual; }
"=="       {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("igualigual", yytext); return tIgualIgual; }
"!="       {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("diferenteigual", yytext); return tDiferenteIgual; }
">"       {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("mayorque", yytext); return tMayorQue; }
"<"       {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("menorque", yytext); return tMenorQue; }
"imprimir" {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("imprimir", yytext); return tImprimir; }
"si"       {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("si", yytext); return tSi; }
"sino"     {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); imprimirEnConsola("sino", yytext); return tSino; }

[[:blank:]] { columna++; /*Se ignoran*/ }
"\n"        {linea++; columna = 0; anterior = 0;}

.        {
                     columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);
 /*                  errorT *nuevoE = new errorT("Lexico",yytext,linea, columna);
                     listaErrores->append(*nuevoE);
 */
                     std::cout <<yytext <<" Error Lexico en la linea "<< linea << " Columna:"<< columna<<  std::endl;
         }
}
<COMMULT>"*/" { BEGIN INITIAL; }
<COMMULT>"\n" { linea++; }
<COMMULT>.
<COMMULT><<EOF>> { yyerror("Comentario Multilinea no Cerrado"); }

<COMSIMP>"\n" { linea++; columna = 0; BEGIN INITIAL; }
<COMSIMP>.

%%
