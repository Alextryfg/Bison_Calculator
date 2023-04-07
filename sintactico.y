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
    int yywrap();       /* Esto se utilizará desde otros archivos por eso lleva el extern */
    void prompt();      /* Prototipo de la función prompt */

%}

/* El union es para que el parser pueda devolver un valor de cualquier tipo */

%union {
    double val;
    char *str;
}

/* Definición de los tokens */

%start start

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
%type <val> assign

/*

%type <val> function
*/

/* Asociatividad de los operadores */

%left '-' '+' TOKEN_MAS_IGUAL TOKEN_MENOS_IGUAL
%left '*' '/' TOKEN_MULT_IGUAL TOKEN_DIV_IGUAL
%left '>' '<' TOKEN_IGUAL_IGUAL TOKEN_MAYOR_IGUAL TOKEN_MENOR_IGUAL TOKEN_DIFERENTE_IGUAL
%left NEG /* Negacion--menos unario */
%right '^' /* Exponenciacion */

%%

/* Definición de las reglas */

start
:   %empty /* Produccion vacia que se ejecutara cuando no hay ninguna linea d eentrada */
{
    prompt();
}
| start INICIO
;

INICIO
: '\n'
{
    prompt();
}
| exp '\n'
{
    printf("%lf\n", $1);
    prompt();
}
| assign '\n'
{
    printf("%lf\n", $1);
    prompt();
}

exp
: TOKEN_NUM           
| exp '+' exp       
{ 
    $$ = $1 + $3;
}
| exp '-' exp       
{ 
    $$ = $1 - $3;
}
| exp '*' exp       
{ 
    $$ = $1 * $3;
}
| exp '/' exp       
{ 
    $$ = $1 / $3;
}
| '-' exp %prec NEG 
{ 
    $$ = -$2;
}
| exp '^' exp       
{ 
    $$ = 999 ;
}
| '(' exp ')'       
{ 
    $$ = $2;
}
;

assign
: TOKEN_VARIABLE '=' exp 
{   
    if(!existeSimbolo($1)){
        insertarSimbolo($1, $3);
    }else{
        actualizarSimbolo($1, $3);
    }
    $$ = $3;
}
| TOKEN_VARIABLE '=' TOKEN_VARIABLE
{   
    if(!existeSimbolo($1)){
        insertarSimbolo($1, obtenerValorSimbolo($3));
    }else if(!existeSimbolo($1)){
        insertarSimbolo($1, obtenerValorSimbolo($3));
    }else{
        actualizarSimbolo($1, obtenerValorSimbolo($3));
    }
    $$ = obtenerValorSimbolo($3);
}
;

%%

/* Función de error */
void yyerror(char *s){
    printf("%s\n", s);
}

int yywrap(){
    return 1;
}

void prompt(){
    printf("$>");
}




