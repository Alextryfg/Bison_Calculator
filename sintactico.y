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

    tipoelem simbol = {};
    int fail = 0;
    void yyerror(char *s);  /* prototipo de la función de error  */
    extern int yylex(void); /* Esto se utilizará desde otros archivos por eso lleva el extern */
    int yywrap();       /* Esto se utilizará desde otros archivos por eso lleva el extern */
    void prompt();      /* Prototipo de la función prompt */
    void value(double val);       /* Prototipo de la función value para imprimir resultados*/
    double potencia(double base, double exponente);    /* Prototipo de la función potencia */
    int print = 1;      /* Variable que indica si se debe imprimir el resultado de la operación */

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
%token <str> TOKEN_CONSTANTE
%token <str> TOKEN_FILE
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
%type <str> command

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
    value($1);
    prompt();
}
| assign '\n'
{
    value($1);
    prompt();
}
| command '\n'
{
    prompt();
}

exp
: TOKEN_NUM  
| TOKEN_VARIABLE 
{   
    simbol = getSimbol($1);

    if(simbol.lexema != NULL){
        $$ = simbol.data.val;
    }else{
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
        fail = 1;
    }

}           
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
    $$ = potencia($1, $3);
}
| '(' exp ')'       
{ 
    $$ = $2;
}
;

assign
//COMO HAGO PARA PODER ASIGNAR EXPRESIONES A VARIABLES?

: TOKEN_VARIABLE '=' exp 
{   

    simbol = getSimbol($1);

    if(simbol.type == ID_CONST){
        printf("Error: No se puede asignar un valor a una constante\n");
        print = 0;
        fail = 1;
    }
    
    if(!fail){
        
        if(!existeSimbolo($1)){
            insertarSimbolo($1, $3);
        }else{
            actualizarSimbolo($1, $3);
        }

    }
    
    
    fail = 0;
    $$ = $3;

}
/*
| TOKEN_CONSTANTE '=' exp 
{   

    if(!fail){
        
        printf("Error: No se puede asignar un valor a una constante\n");
        print = 0;

    }
    
    fail = 0;
    $$ = $3;

}
*/
;


command
: TOKEN_WORKSPACE
{

    simbol = getSimbol("workspace");

    printf("El directorio de trabajo es: %s\n", simbol.lexema);
    printf("La funcion es: %p\n", simbol.data.func);

    unsigned (*ptrFunc)() = simbol.data.func;
    if (ptrFunc != NULL) {
        (*(ptrFunc))();
    } else {
        printf("Error: El puntero a función es nulo.\n");
    }

    free($1);
}
| TOKEN_CLEAR_WORKSPACE
{
    simbol = getSimbol($1);
    //Invoco la funcion contenida en su puntero
    (*(simbol.data.func))();
    free($1);
}
| TOKEN_SIMBOLOS
{
    printTablaSimbolos();
}
| TOKEN_LOAD '(' TOKEN_FILE ')'
{
    simbol = getSimbol($1);
    //Invoco la funcion contenida en su puntero
    (*(simbol.data.func))();
    free($1);
}
| TOKEN_IMPORT '(' TOKEN_VARIABLE ')'
{
    simbol = getSimbol($1);
    //Invoco la funcion contenida en su puntero
    (*(simbol.data.func))();
    free($1);
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

void value(double val){
    if(print){
        printf("%lf\n", val);
    }else{
        print = 1;
    }
}

double potencia(double base, double exponente){
        double resultado = 1;
    int i;

    // Si el exponente es positivo, multiplica la base el número de veces del exponente
    if (exponente > 0) {
        for (i = 1; i <= exponente; i++) {
            resultado *= base;
        }
    }
    // Si el exponente es negativo, divide la base el número de veces del exponente absoluto
    else {
        int exponenteAbsoluto = -exponente;
        for (i = 1; i <= exponenteAbsoluto; i++) {
            resultado /= base;
        }
    }

    return resultado;
}




