%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <math.h>
    #include "abb.h"
    #include "definiciones.h"
    #include "tabladesimbolos.h"

    void yyerror(char *s);  /* prototipo de la función de error  */
    extern int yylex(void); /* Esto se utilizará desde otros archivos por eso lleva el extern */
    void help?();

%}

/* El union es para que el parser pueda devolver un valor de cualquier tipo */

%union {
    double val;
    char *str;
}

/* Definición de los tokens */

%start in

%token <val> NUM
%token <str> ID
%token ID_MAS_IGUAL
%token ID_MENOS_IGUAL
%token ID_MULT_IGUAL
%token ID_DIV_IGUAL
%token ID_IGUAL_IGUAL
%token ID_MAYOR_IGUAL
%token ID_MENOR_IGUAL
%token ID_DIFERENTE_IGUAL
%token ID_MAS_MAS
%token ID_MENOS_MENOS
%token ID_ASIGNACION

/* COMANDOS ESPECIALES */

%token <str> EXIT
%token <str> WORKSPACE
%token <str> HELP
%token <str> CLEAR_WORKSPACE
%token <str> SIMBOLOS
%token <str> LOAD
%token <str> IMPORT

/* Simbolos no terminales */

%type <val> exp

%type <val> assign
%type <val> function

/* Asociatividad de los operadores */

%right '=' ID_ASIGNACION
%left '-' '+' ID_MAS_IGUAL ID_MENOS_IGUAL
%left '*' '/' ID_MULT_IGUAL ID_DIV_IGUAL
%left '>' '<' ID_IGUAL_IGUAL ID_MAYOR_IGUAL ID_MENOR_IGUAL ID_DIFERENTE_IGUAL
%left NEG /* Negacion--menos unario */
%right '^' /* Exponenciacion */

%%

/* Definición de las reglas */
in: %empty {printf("$>");}
    | in line




exp: NUM            { $$ = $1;}
| exp ’+’ exp       { $$ = $1 + $3;}
| exp ’-’ exp       { $$ = $1 - $3;}
| exp ’*’ exp       { $$ = $1 * $3;}
| exp ’/’ exp       { $$ = $1 / $3;}
| ’-’ exp %prec NEG { $$ = -$2;}
| exp ’^’ exp       { $$ = pow ($1, $3);}
| ’(’ exp ’)’       { $$ = $2;}
;


%%




