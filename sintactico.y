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
    int isnan(double x);    /* Prototipo de la función isnan */
    int loadPrint = 0;       /* Variable que indica si se debe cargar un archivo */

%}

/* El union es para que el parser pueda devolver un valor de cualquier tipo */

%union {
    double val;
    char *str;
}

/* Definición de los tokens */

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

%token <str> TOKEN_ERROR
%token <str> TOKEN_EOF


/* Simbolos no terminales */

%type <val> exp
%type <str> command
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
:   %empty /* Produccion vacia que se ejecutara cuando no hay ninguna linea de entrada */
{
    prompt();
}
| start INICIO
;


INICIO  /* Si hay ; no se imprime, en caso contrario si */
: '\n'
{
    prompt();
}
| exp '\n'
{
    value($1);
    prompt();
}
| command '\n'
{
    prompt();
}
| assign '\n'
{
    if(isnan($1) || isnan(-$1)){
        print=0;
        printf("Error: El resultado es NaN\n");
    }
    value($1);
    prompt();
}
| exp ';' '\n'
{   
    print = 0;
    value($1);
    prompt();
}
| assign ';' '\n'
{   
    print = 0;
    value($1);
    prompt();
}
| error  /* El simbolo terminal error se reserva para la recuperacion de errores */
{   
    /* No detectamos ningun token valido, por lo tanto llegamos al token terminal error */
    /* Se debe limpiar el buffer de entrada */
    yyclearin;
    fail = 1;
}
;



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
    }

    free($1);

}           
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
        printf("Error: Division entre 0\n");
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
        printf("Error: El resultado es un NaN\n");
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
        printf("Error: La variable no ha sido declarada\n");
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
        printf("Error: La variable no ha sido declarada\n");
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
        printf("Error: La variable no ha sido declarada\n");
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
        printf("Error: La variable no ha sido declarada\n");
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
        printf("Error: La variable no ha sido declarada\n");
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
        printf("Error: La variable no ha sido declarada\n");
        print = 0;
    }

    free($1);

}
| TOKEN_FUNC '(' exp ')' 
{   
    simbol = getSimbol($1);

        double (*ptrFunc)(double) = simbol.data.func;
        if (ptrFunc != NULL) {
            $$ = (*(ptrFunc))($3);
        } else {
            printf("Error: El puntero a función es nulo.\n");
            print=0;
        }

    free($1);
}
;



command
: TOKEN_COMMAND1
{

    if(!fail){

        
        simbol = getSimbol($1);

        double (*ptrFunc)() = simbol.data.func;
        if (ptrFunc != NULL) {
            (*(ptrFunc))();
        } else {
            printf("Error: El puntero a función es nulo.\n");
        }

        if(strcmp($1, "exit") == 0){
            printf("Saliendo del programa...\n");
            return 1;
        }

    }
    
    fail = 0;
    free($1);

    

}
| TOKEN_COMMAND2 '(' TOKEN_FILE ')'
{
    if(!fail){
        
        simbol = getSimbol("load");

        double (*ptrFunc)(char *) = simbol.data.func;
        if (ptrFunc != NULL) {
            loadPrint = 1;
            (*(ptrFunc))($3);
        } else {
            printf("Error: El puntero a función es nulo.\n");
        }

    }

    free($1);
    free($3);
    fail = 0;

}
| TOKEN_COMMAND2
{
    if(!fail){
        printf("Error: No se ha especificado el nombre del archivo a importar\n");
        print = 0;
    }

} 
| TOKEN_EOF
{
    if(!fail){
        loadPrint = 0;
        printf("Archivo cargado con exito");
    }
}
;


assign
: TOKEN_VARIABLE '=' exp 
{   

    //printf("entro a assign");
    simbol = getSimbol($1);

    if(!fail){

        if(simbol.lexema != NULL){ 
            if(simbol.type == ID_CONST){
                printf("Error: No se puede asignar un valor a una constante\n");
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
    if(!fail){
        printf("Error: No se puede asignar una funcion a una variable o constante\n");
        print = 0;
    }

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
    if(!loadPrint)
        printf("\033[32m$>\033[0m");
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

int isnan(double x){
    return x != x;
}




