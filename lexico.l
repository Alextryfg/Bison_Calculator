%{
#include "definiciones.h"
#include "errores.h"
#include "tabladesimbolos.h"
#include "sintactico.tab.h"
%}

%option noyywrap
%option nounput
/*Opcion para que detecte la varibale yylval de Bison */
%option yylineno
/* Opcion para que no nos de el error de 'input' unused*/
%option noinput

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


EXPONENCIAL [eE][+-]?{DIGIT}+

FLOAT {DIGIT}*\.{DIGIT}+({EXPONENCIAL})?|\.{DIGIT}+({EXPONENCIAL})?

INTEGER {DIGIT}+

FILE ({ALFA|DIGIT}+\.)*{ALFA|DIGIT}+

LIB <{ALFA|DIGIT}+\.h>


%%

{SPACES}

"exit"              {return (TOKEN_EXIT);}

"simbolos"          {return (TOKEN_SIMBOLOS);}

"workspace"         {return (TOKEN_WORKSPACE);}

"load"              {return (TOKEN_LOAD);}

"import"            {return (TOKEN_IMPORT);}

"clear"             {return (TOKEN_CLEAR_WORKSPACE);}

{BREAK_LINE}        {return ((int)*yytext);}

{INTEGER}           {
                        /* Covertimos el string a su valor numérico y lo metemos en la estructura definida en bison  */
                        yylval.val=atoi(yytext);
                        /* Devolvemos el token correspondiente */
                        return (TOKEN_NUM);
                    }

{VARIABLE}          {   
                        yylval.str = strdup(yytext);

                        /* Devolvemos el token correspondiente */
                        return (TOKEN_VARIABLE);   
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

.*                   {return (TOKEN_ERROR);}

<<EOF>>             {yyrestart(yyin); return (EOF);}


%%

/* Estas seran nuestras funciones personales que se volcarán automaticamente en el archivo lex.yy.c */

void openFile(char *nombreArchivo){
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL){
        errorD(1);
    }
    yyin = archivo;
}

void closeFile(){
    fclose(yyin);
    yylex_destroy();
}

unsigned exitC(){
    yylex_destroy();
    yyterminate();
    return 1;
}
