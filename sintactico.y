%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <math.h>
    #include "abb.h"
    #include "definiciones.h"
    #include "tabladesimbolos.h"
    #include "lex.yy.h"

    void yyerror(char *s);  /* prototipo de la función de error  */
    extern int yylex(void); /* Esto se utilizará desde otros archivos por eso lleva el extern */

%}

/* El union es para que el parser pueda devolver un valor de cualquier tipo */

%union {
    double val;
    char *str;
}

/* Definición de los tokens */

//%start in

%token <val> TOKEN_NUM
%token <str> TOKEN_VARIABLE
%token TOKEN_MAS_IGUAL
%token TOKEN_MENOS_IGUAL
%token TOKEN_MULT_IGUAL
%token TOKEN_DIV_IGUAL
%token TOKEN_IGUAL_IGUAL
%token TOKEN_MAYOR_IGUAL
%token TOKEN_MENOR_IGUAL
%token TOKEN_DIFERENTE_IGUAL
%token TOKEN_MAS_MAS
%token TOKEN_MENOS_MENOS
%token TOKEN_ASIGNACION

/* COMANDOS ESPECIALES */

%token <str> TOKEN_EXIT
%token <str> TOKEN_WORKSPACE
%token <str> TOKEN_HELP
%token <str> TOKEN_CLEAR_WORKSPACE
%token <str> TOKEN_SIMBOLOS
%token <str> TOKEN_LOAD
%token <str> TOKEN_IMPORT

/* Simbolos no terminales */

%type <val> exp

/*
%type <val> assign
%type <val> function
*/

/* Asociatividad de los operadores */

%right '=' TOKEN_ASIGNACION
%left '-' '+' TOKEN_MAS_IGUAL TOKEN_MENOS_IGUAL
%left '*' '/' TOKEN_MULT_IGUAL TOKEN_DIV_IGUAL
%left '>' '<' TOKEN_IGUAL_IGUAL TOKEN_MAYOR_IGUAL TOKEN_MENOR_IGUAL TOKEN_DIFERENTE_IGUAL
%left NEG /* Negacion--menos unario */
%right '^' /* Exponenciacion */

%%

/* Definición de las reglas */
/*
in
: %empty {printf("$>");}
;
*/




exp
: TOKEN_NUM            { $$ = $1;}
| exp '+' exp       { $$ = $1 + $3;}
| exp '-' exp       { $$ = $1 - $3;}
| exp '*' exp       { $$ = $1 * $3;}
| exp '/' exp       { $$ = $1 / $3;}
| '-' exp %prec NEG { $$ = -$2;}
| exp '^' exp       { $$ = 999 ;}
| '(' exp ')'       { $$ = $2;}
;


%%

/* Función de error */
void yyerror(char *s){
    printf("%s\n", s);
}




