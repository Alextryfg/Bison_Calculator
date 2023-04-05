%{
#include "definiciones.h"
#include "errores.h"
#include "tabladesimbolos.h"
%}

%option noyywrap
%option nounput

ALFA [a-zA-Z]
LETTER [ALFA]|_
DIGIT [0-9]
LINE_BREAK \n
SPACES [ \t\r]+


VARIABLE {LETTER}({LETTER}|{DIGIT})*

OPERADORESSIMPLES (\(|\)|\*|\+|\-|\/|\;|\,|\<|\>|\^)

MAS_IGUAL                     \+=
MENOS_IGUAL                   \-=
MULT_IGUAL                    \*=
DIV_IGUAL                     \/=
IGUAL_IGUAL                   \=\=
MAYOR_IGUAL                   \>\=
MENOR_IGUAL                   \<\=
DIFERENTE_IGUAL               \!\=
MAS_MAS                      \+\+
MENOS_MENOS                   \-\-
ASIGNACION                    \=


EXPONENCIAL [eE][+-]?{DIGITO}+

FLOAT {DIGITO}*\.{DIGITO}+({EXPONENCIAL})?|\.{DIGITO}+({EXPONENCIAL})?

INTEGER {DIGITO}+

FILE ({LETTER|DIGIT}+\.)*{LETTER|DIGIT}+

LIB <{LETTER|DIGIT}+\.h>


%%

{SPACES}

"exit"              {yyterminate();}

"open"              {return (READ);}

{BREAK_LINE}        {return ((int)*yytext);}

{DIGIT}             {yyval.val=atof(yytext); return (NUMBER);}

{VARIABLE}          {char* lexema;
                        lexema = strdup(yytext);
                        yylval.elem = findSimbol(lexema);
                        if(yylval.elem->tipo == ID_FUNC){
                            return (FUNCION);
                        }else if(yylval.elem->tipo == ID_FUNCVOID){
                            return (FUNCIONVOID);
                        }else if(yylval.elem->tipo == ID_VAR){
                            return (VARIABLE);
                        }else if(yylval.elem->tipo == ID_CONST){
                            return (CONSTANTE);
                        }
                    }

{FILE}

{MAS_IGUAL}         {return (MAS_IGUAL);}
{MENOS_IGUAL}       {return (MENOS_IGUAL);}
{MULT_IGUAL}        {return (MULT_IGUAL);}
{DIV_IGUAL}         {return (DIV_IGUAL);}
{IGUAL_IGUAL}       {return (IGUAL_IGUAL);}
{MAYOR_IGUAL}       {return (MAYOR_IGUAL);}
{MENOR_IGUAL}       {return (MENOR_IGUAL);}
{DIFERENTE_IGUAL}   {return (DIFERENTE_IGUAL);}
{MAS_MAS}           {return (MAS_MAS);}
{MENOS_MENOS}       {return (MENOS_MENOS);}
{ASIGNACION}        {return (ASIGNACION);}

{OPERADORESSIMPLES} {return ((int)*yytext);}

.                       {errorD(6);}

<<EOF>>              {closeFile(); yyrestart(yyin); return (EOF);}


%%

/* Estas seran nuestras funciones personales que se volcarán automaticamente en el archivo lex.yy.c */

double openFile(char *nombreArchivo){
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL){
        errorD(1);
    }
    yyin = archivo;
}

double exit(){
    yylex_destroy();
    return -1;
}



void closeFile(){
    fclose(yyin);
    yylex_destroy();
}