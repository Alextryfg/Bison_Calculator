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
    if(existeSimbolo($1)){
        $$ = obtenerValorSimbolo($1);
    }else{
        printf("Error: La variable '%s' no ha sido declarada\n", $1);
        print = 0;
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
    if(isdigit($3) == 0){
        printf("$3 es una variable\n");
    }else{
        printf("$3 es un numero\n");
    }

    
    if(strcmp($1, "pi") == 0 || strcmp($1, "e") == 0){
        printf("Error: No se puede asignar un valor a las constantes\n");
        print = 0;
    }else if(!existeSimbolo($1)){
        insertarSimbolo($1, $3);
    }else{
        actualizarSimbolo($1, $3);
    }
    $$ = $3;

}

| TOKEN_VARIABLE '=' TOKEN_VARIABLE
{   
    if(!existeSimbolo($1) && !existeSimbolo($3)){ //Si las variables no existen se crean y se le asigna el valor de la variable 3

        printf("Error: Las variables no han sido declaradas\n");
        print = 0;
        
    }else if(!existeSimbolo($1)){ //Si la vaiable uno no existe se crea y se le asigna el valor de la variable 3

        insertarSimbolo($1, obtenerValorSimbolo($3));
        $$ = obtenerValorSimbolo($3);

    }else if(!existeSimbolo($3)){ //Si la variable 3 no existe se imprime un error

        printf("Error: La variable '%s' no ha sido declarada", $3);
        print = 0;

    }else{ //Si la variable 1 existe se actualiza con el valor de la variable 2

        actualizarSimbolo($1, obtenerValorSimbolo($3));
        $$ = obtenerValorSimbolo($3);
    }
    
}
;


command
: TOKEN_WORKSPACE
{
    printTablaSimbolos();
}
| TOKEN_CLEAR_WORKSPACE
{
    //limpiarTablaSimbolos();
}
| TOKEN_SIMBOLOS
{
    printTablaSimbolos();
}
| TOKEN_LOAD '(' TOKEN_VARIABLE ')'
{
    printf("Cargando archivo...\n");
}
| TOKEN_IMPORT '(' TOKEN_VARIABLE ')'
{
    printf("Importando archivo...\n");
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




