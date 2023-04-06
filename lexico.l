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

ALFA [a-zA-Z]
LETTER [ALFA]|_
DIGIT [0-9]
BREAK_LINE \n
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

{DIGIT}             {
                    /* Covertimos el string a su valor numérico y lo metemos en la estructura definida en bison  */
                    yylval.val=atof(yytext); 
                    /* Devolvemos el token correspondiente */
                    return (TOKEN_NUM);}

{VARIABLE}          {   
                        /*yylval es la estructura definida en el sitactico por mi mismp de str y val*/
                        yylval.str = strdup(yytext);
                        yylval.val = findComando(yylval.str);
                        /* Busco en la tabla de simbolos inicial, el tipo o id de la variable que entra */
                        /* Dependiendo del tipo de variable, se devolverá un token u otro */
                        /* Flex devuelve a Bison un Token con el que realizará unas reglas gramáticales establecidas */
                        if(yylval.val == ID_EXIT){
                            return (TOKEN_EXIT);
                        }else if(yylval.val == ID_WORKSPACE){
                            return (TOKEN_WORKSPACE);
                        }else if(yylval.val == ID_HELP){
                            return (TOKEN_HELP);
                        }else if(yylval.val == ID_CLEAR_WORKSPACE){
                            return (TOKEN_CLEAR_WORKSPACE);
                        }else if(yylval.val == ID_SIMBOLOS){
                            return (TOKEN_SIMBOLOS);
                        }else if(yylval.val == ID_LOAD){
                            return (TOKEN_LOAD);
                        }else if(yylval.val == ID_IMPORT){
                            return (TOKEN_IMPORT);
                        }else{
                            return (TOKEN_VARIABLE);
                        }
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
{ASIGNACION}        {return (TOKEN_ASIGNACION);}

{OPERADORESSIMPLES} {return ((int)*yytext);}

.                       {errorD(6);}

<<EOF>>              {yyrestart(yyin); return (EOF);}


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

double exitC(){
    yylex_destroy();
    return 0;
}

void closeFile(){
    fclose(yyin);
    yylex_destroy();
}