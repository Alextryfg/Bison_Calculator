%{
#include "definiciones.h"
#include "tabladesimbolos.h"
#include "sintactico.tab.h"
#include "lex.yy.h"
void errorlex(int linea);
void dobleLoad();
%}

%option noyywrap
%option nounput
/*Opcion para que detecte la varibale yylval de Bison */
%option yylineno
/* Opcion para que no nos de el error de 'input' unused*/
%option noinput


   //En este apartado se realizan las declaraciones de las funciones que se van a utilizar en el analizador léxico.
   //Estas expresiones regulares serán detectadas por flex y cada una de ellas realizará la operacion que se le indicará
   //en el siguiente apartado del fichero.


ALFA [a-zA-Z_]
DIGIT [0-9]
BREAK_LINE \n
SPACES [ \t\r]+


VARIABLE {ALFA}({ALFA}|{DIGIT})*

OPERADORESSIMPLES (\(|\)|\*|\+|\-|\/|\;|\<|\>|\^|\=)

MAS_IGUAL                     \+=
MENOS_IGUAL                   \-=
MULT_IGUAL                    \*=
DIV_IGUAL                     \/=
IGUAL_IGUAL                   \=\=
MAYOR_IGUAL                   \>\=
MENOR_IGUAL                   \<\=
DIFERENTE_IGUAL               \!\=
MAS_MAS                       \+\+
MENOS_MENOS                   \-\-

/* e+1, e+2, e+3*/
EXPONENCIAL [eE][+-]?{DIGIT}+


/* 1e+1, .55, .55e+2, 2.57, 4.566e+10*/
FLOAT {DIGIT}*[.]{DIGIT}*{EXPONENCIAL}?|\.{DIGIT}{EXPONENCIAL}?|{DIGIT}{EXPONENCIAL}

/* 121, 1234, 1234567890 */
INTEGER {DIGIT}+

/* xxx.x, xxx.xx, xxx.xxx, xxx.xxx... */
FILE {VARIABLE}\.{ALFA}+

NUMBER {FLOAT}|{INTEGER}

FUNC ("sin"|"cos"|"tan"|"sqrt"|"log"|"exp")

COMMAND1 ("exit"|"simbolos"|"workspace"|"clear"|"help")

COMMAND2 ("load")


%%

{SPACES}

{COMMAND1}          { yylval.str = strdup(yytext); return (TOKEN_COMMAND1);}

{COMMAND2}          { yylval.str = strdup(yytext); return (TOKEN_COMMAND2);}

{FUNC}              { yylval.str = strdup(yytext); return (TOKEN_FUNC);}


{BREAK_LINE}        {return ((int)*yytext);}

{NUMBER}           {
                        /* Covertimos el string a su valor numérico y lo metemos en la estructura definida en bison  */
                        yylval.val=atof(yytext);
                        /* Devolvemos el token correspondiente */
                        return (TOKEN_NUM);
                    }

{VARIABLE}          {   
                        yylval.str = strdup(yytext);
                            
                        /* Devolvemos el token correspondiente */
                        return (TOKEN_VARIABLE);   
                    }

{FILE}              {   
                        yylval.str = strdup(yytext);
                        /* Devolvemos el token correspondiente */
                        return (TOKEN_FILE);   
                    }

{MAS_IGUAL}         {return (TOKEN_MAS_IGUAL);}
{MENOS_IGUAL}       {return (TOKEN_MENOS_IGUAL);}
{MULT_IGUAL}        {return (TOKEN_MULT_IGUAL);}
{DIV_IGUAL}         {return (TOKEN_DIV_IGUAL);}
{IGUAL_IGUAL}       {return (TOKEN_IGUAL_IGUAL);}
{MAYOR_IGUAL}       {return (TOKEN_MAYOR_IGUAL);}
{MENOR_IGUAL}       {return (TOKEN_MENOR_IGUAL);}
{DIFERENTE_IGUAL}   {return (TOKEN_DIFERENTE_IGUAL);}
{MAS_MAS}           {return (TOKEN_MAS_MAS);}
{MENOS_MENOS}       {return (TOKEN_MENOS_MENOS);}

{OPERADORESSIMPLES} {return ((int)*yytext);}

.                   {errorlex(yylineno);}

<<EOF>>             {fclose(yyin); yyrestart(stdin); dobleLoad(); return (TOKEN_EOF);}


%%

/* Estas seran nuestras funciones personales que se volcarán automaticamente en el archivo lex.yy.c */

double load(char *nombreArchivo){
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if(archivo == NULL){
        printf("Error al abrir el archivo %s \n", nombreArchivo);
        yyin = stdin;
        dobleLoad();
        return 0;
    }
    
    //Para no permnitir que se cargue dos veces un load.
    dobleLoad();

    // Mover el puntero de archivo al final
    fseek(archivo, 0, SEEK_END);

    // Comprobar si el último carácter es un salto de línea
    int ultimoCaracter = fgetc(archivo);
    if (ultimoCaracter != '\n' && ultimoCaracter == EOF) {
        // Si no es un salto de línea, escribir uno
        fputc('\n', archivo);
    }

    // Mover el puntero de archivo al principio
    fseek(archivo, 0, SEEK_SET);
    

    yyin = archivo;
    return 1;
}

/* Funcion para salir del programa */
double exitC(){
    yylex_destroy();
    yyterminate();
    return 1;
}

/* Funcion para imprimir el error lexico con la linea del mismo */
void errorlex(int linea){
    printf("\x1b[31m""Error: Error lexico en la linea => %d\n""\x1b[0m", linea);
}
