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

{BREAK_LINE}        {return ((int)*yytext);}

{DIGIT}             {yyval.val=atof(yytext); return (NUMBER);}

{VARIABLE}          {char* lexema;
                        lexema = strdup(yytext);
                        yylval.elem = findSimbol(lexema);
                        /* Busco en la tabla de simbolos inicial, el tipo o id de la variable que entra */
                        if(yylval.elem->tipo == ID_EXIT){
                            return (EXIT);
                        }else if(yylval.elem->tipo == ID_WORKSPACE){
                            return (WORKSPACE);
                        }else if(yylval.elem->tipo == ID_HELP){
                            return (HELP);
                        }else if(yylval.elem->tipo == ID_CLEAR_WORKSPACE){
                            return (CLEAR_WORKSPACE);
                        }else if(yylval.elem->tipo == ID_SIMBOLOS){
                            return (SIMBOLOS);
                        }else if(yylval.elem->tipo == ID_LOAD){
                            return (LOAD);
                        }else if(yylval.elem->tipo == ID_IMPORT){
                            return (IMPORT);
                        }else{
                            return (VARIABLE);
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