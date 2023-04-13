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
    int fail = 0;       /* Variable que indica si se ha producido un error y no se debe imprimir el resultado de la operación */
    int print = 1;      /* Variable que indica si se debe imprimir el resultado de la operación */
    int nerror=0;       /* Variable que indica si se ha producido un error y printear el salto */
    int dobleLoadVar = 0; /* Variable para gestionar que no haya doble load */
    
    void dobleLoad();   /* Prototipo de la función dobleLoad */
    void yyerror(char *s);  /* prototipo de la función de error  */
    extern int yylex(void); /* Esto se utilizará desde otros archivos por eso lleva el extern */
    int yywrap();       /* Esto se utilizará desde otros archivos por eso lleva el extern */
    void value(double val);       /* Prototipo de la función value para imprimir resultados*/
    double potencia(double base, double exponente);    /* Prototipo de la función potencia */
    int isnan(double x);    /* Prototipo de la función isnan */
    void success(char *s);  /* Prototipo de la función success */
    

%}

/* El union es para que el parser pueda devolver un valor de cualquier tipo */

%union {
    double val;
    char *str;
}

/* Definición de los tokens */

/* Se trata de la definicion del simbolo de arranque de bison */

%start start

/* Tipos de variables */

%token <val> TOKEN_NUM
%token <str> TOKEN_VARIABLE
%token <str> TOKEN_CONSTANTE
%token <str> TOKEN_FILE

/* Operaciones */

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

/* Funciones matemáticas */

%token <str> TOKEN_FUNC

/* COMANDOS ESPECIALES */

%token <str> TOKEN_COMMAND1
%token <str> TOKEN_COMMAND2

/* Tokens de gestion de EOF y errores */

%token <str> TOKEN_ERROR
%token <str> TOKEN_EOF


/* Simbolos no terminales */

%type <val> exp
%type <str> command
%type <val> assign

/* Asociatividad de los operadores */

%left '-' '+' TOKEN_MAS_IGUAL TOKEN_MENOS_IGUAL
%left '*' '/' TOKEN_MULT_IGUAL TOKEN_DIV_IGUAL
%left '>' '<' TOKEN_IGUAL_IGUAL TOKEN_MAYOR_IGUAL TOKEN_MENOR_IGUAL TOKEN_DIFERENTE_IGUAL
%left NEG /* Negacion--menos unario */
%right '^' /* Exponenciacion */

%%

/* Definición de las reglas */

/* La regla de inicion comienza con el simbolo de arranque y se llama start */

start
:INICIO
| start INICIO
;


INICIO  /* Si hay ; no se imprime, en caso contrario si */
: '\n'
| exp '\n'
{
    value($1);
    
}
| command '\n'
{

}
| assign '\n'
{
    // Se comprueba que no sea un NaN
    if(isnan($1) || isnan(-$1)){
        print=0;
        yyerror("Error: El resultado es NaN\n");
    }

    value($1);
    
}
| exp ';' '\n'
{   
    print = 0;
    value($1);
    
}
| assign ';' '\n'
{   
    print = 0;
    value($1);
    
}
| error  /* El simbolo terminal error se reserva para la recuperacion de errores */
{
    if(!nerror)
        printf("\n");

    yyerror("Error: Sintaxis incorrecta\n");

    nerror=1;
}
;


/* Reglas para las expresiones matematicas */

exp
: TOKEN_NUM  
| TOKEN_VARIABLE 
{   

    /* Si nos llega una variable, se comprueba que exista en la tabla de simbolos y se carga su valor para operar con ella */

    simbol = getSimbol($1);

    if(simbol.lexema != NULL){
        $$ = simbol.data.val;
    }else{
        yyerror("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free($1);

}   
/* A partir de aqui solo serán reglas de operaciones con calculos totalmente sencillo por lo que no será necesario entrar en detalle a comentarlos */        
| exp '+' exp       
{ 
    $$ = $1 + $3;
    if(isnan($$)){
        print = 0;
    }
}
| exp '-' exp       
{ 
    $$ = $1 - $3;
    if(isnan($$)){
        print = 0;
    }
}
| exp '*' exp       
{ 
    $$ = $1 * $3;
    if(isnan($$)){
        print = 0;
    }
}
| exp '/' exp       
{ 
    
    $$ = $1 / $3;
    //Caso de nan y -nan
    if(isnan($$)){
        print = 0;
    }
    if($3 == 0){
        yyerror("Error: Division entre 0\n");
        print = 0;
    }
}
| '-' exp %prec NEG 
{ 
    $$ = -$2;
}
| exp '^' exp       
{ 
    $$ = potencia($1, $3);
    if(isnan($$)){
        yyerror("Error: El resultado es un NaN\n");
        print = 0;
    }
}
| '(' exp ')'       
{ 
    $$ = $2;
}
| exp '<' exp       
{ 
    $$ = $1 < $3;
    if(!fail){
        if($$ == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
| exp '>' exp       
{ 
    $$ = $1 > $3;
    if(!fail){
        if($$ == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;

}
| exp TOKEN_IGUAL_IGUAL exp       
{ 
    $$ = $1 == $3;
    if(!fail){
        if($$ == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
| exp TOKEN_MAYOR_IGUAL exp       
{ 
    $$ = $1 >= $3;
    if(!fail){
        if($$ == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
| exp TOKEN_MENOR_IGUAL exp       
{ 
    $$ = $1 <= $3;
    if(!fail){
        if($$ == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
| exp TOKEN_DIFERENTE_IGUAL exp       
{ 
    $$ = $1 != $3;
    if(!fail){
        if($$ == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
    print = 0;
    fail = 0;
}
| TOKEN_VARIABLE TOKEN_MAS_MAS
{
    simbol = getSimbol($1);

    if(simbol.lexema != NULL){
        $$ = simbol.data.val;
        $$++;
        actualizarSimbolo($1, $$);
    }else{
        yyerror("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free($1);

}
| TOKEN_VARIABLE TOKEN_MENOS_MENOS
{
    simbol = getSimbol($1);

    if(simbol.lexema != NULL){
        $$ = simbol.data.val;
        $$--;
        actualizarSimbolo($1, $$);
    }else{
        yyerror("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free($1);

}
| TOKEN_VARIABLE TOKEN_DIV_IGUAL exp
{
    simbol = getSimbol($1);

    if(simbol.lexema != NULL){
        $$ = simbol.data.val;
        $$ /= $3;
        actualizarSimbolo($1, $$);
    }else{
        yyerror("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free($1);

}
| TOKEN_VARIABLE TOKEN_MULT_IGUAL exp
{
    simbol = getSimbol($1);

    if(simbol.lexema != NULL){
        $$ = simbol.data.val;
        $$ *= $3;
        actualizarSimbolo($1, $$);
    }else{
        yyerror("Error: La variable no ha sido declarada\n");
        print = 0;
    }


    free($1);


}
| TOKEN_VARIABLE TOKEN_MAS_IGUAL exp
{
    simbol = getSimbol($1);

    if(simbol.lexema != NULL){
        $$ = simbol.data.val;
        $$ += $3;
        actualizarSimbolo($1, $$);
    }else{
        yyerror("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free($1);

}
| TOKEN_VARIABLE TOKEN_MENOS_IGUAL exp
{
    simbol = getSimbol($1);

    if(simbol.lexema != NULL){
        $$ = simbol.data.val;
        $$ -= $3;
        actualizarSimbolo($1, $$);
    }else{
        yyerror("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free($1);

}
| TOKEN_FUNC '(' exp ')' 
{   

    /* En el momento en el que se detecte una función, será necesario buscarla en la tabla de símbolos.
    y ejecutrala mediante un puntero a dicha funcion. En caso de ser nulo el puntero no se realizará
    ninguna ejecucion y se liberará la memoria */

    simbol = getSimbol($1);

        double (*ptrFunc)(double) = simbol.data.func;
        if (ptrFunc != NULL) {
            $$ = (*(ptrFunc))($3);
        } else {
            yyerror("Error: El puntero a función es nulo.\n");
            print=0;
        }

    free($1);
}
;

/* Esta es la definicion de los distintos comandos que se pueden ejecutar en el lenguaje.
    En este caso los dividimos en dos grupos, los que no requieren de parametros y los que si. 
*/

command
: TOKEN_COMMAND1
{

    /* La unica diferencia entre el COMMAND1 y el COMMAND2 es que el primero no requiere de parametros
        por lo que no se introducirá ningun parametro detectable en su definicion, luego la ejecucion
        es similar a la de las funciones explicada anteriormente. */

    if(!fail){

        
        simbol = getSimbol($1);

        double (*ptrFunc)() = simbol.data.func;
        if (ptrFunc != NULL) {
            (*(ptrFunc))();
        } else {
            yyerror("Error: El puntero a función es nulo.\n");
        }

        if(strcmp($1, "exit") == 0){
            success("Exito: Saliendo del programa...\n");
            free($1);
            return 1;
        }

    }
    
    fail = 0;
    free($1);

    

}
| TOKEN_COMMAND2 '(' TOKEN_FILE ')'
{
    if(!fail){
        if (!dobleLoadVar){
            simbol = getSimbol($1);
            double (*ptrFunc)(char *) = simbol.data.func;
            if (ptrFunc != NULL) {
                (*(ptrFunc))($3);
            } else {
                yyerror("Error: El puntero a función es nulo.\n");
            }

        }else{
            yyerror("Error: No es posible cargar un script dentro de otro.\n");
        }
        

    }
    
    /* Es importante observar que la reserva de memroia realizada en el analizador lexico es liberada siempre,
       despues de realizar las operaciones pertinentes. */

    free($1);
    free($3);
    fail = 0;

}
| TOKEN_COMMAND2
{
    if(!fail){
        yyerror("Error: No se ha especificado el nombre del archivo a importar\n");
        print = 0;
    }
    free($1);

} 
| TOKEN_EOF
{   
    fail = 0;
    success("Exito: Se ha terminado de leer el archivo. Pulse ENTER para continuar");

}
| TOKEN_ERROR
{
    yyerror("\nError: Lexema mal formado\n");
}
;

/* De nuevo las reglas de asignacion, no tienen nada de especial, solo se realiza la comprobacion de que
    la variable no sea una constante y se realiza la asignacion en codigo c. */

assign
: TOKEN_VARIABLE '=' exp 
{   


    simbol = getSimbol($1);

    if(!fail){

        if(simbol.lexema != NULL){ 
            if(simbol.type == ID_CONST){
                yyerror("Error: No se puede asignar un valor a una constante\n");
                print = 0;
                fail = 1;
            }

        }
        
    
        if(!fail){

            if(!existeSimbolo($1)){
                insertarSimbolo($1, $3);
            }else{
                actualizarSimbolo($1, $3);
            }

        }
        
        

    }
    
    free($1);
    fail = 0;
    $$ = $3;

}
| TOKEN_VARIABLE '=' command
{   

    /* Además se añade un error en caso de intentar asignar una funcion a una variable o constante */

    if(!fail){
        yyerror("Error: No se puede asignar una funcion a una variable o constante\n");
        print = 0;
    }

    free($1);
}
;

%%

/* Simplemente es como un interruptor, que cambia al valor opuesto cada vez que se llama a la función */
void dobleLoad(){
    if(dobleLoadVar){
        dobleLoadVar = 0;
    }else{
        dobleLoadVar = 1;
    }
}

/* Función de error */
void yyerror(char *s){
    printf("\x1b[31m""%s""\x1b[0m", s);
}

/* Función de éxito */
void success(char *s){
    printf("\x1b[32m""%s""\x1b[0m", s);
}

/* Función que se ejecuta al final del programa */
int yywrap(){
    return 1;
}

/* Funcion que muestra los resultados de las operaciones */
void value(double val){
    if(print){
        printf("\x1b[33m""%lf\n""\x1b[0m", val);
    }else{
        print = 1;
    }
}

/* Funcion para calcular la potencia */
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

/* Funcion para saber si un numero es o no nan */
int isnan(double x){
    return x != x;
}




