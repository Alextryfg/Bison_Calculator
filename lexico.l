%{
#include "definiciones.h"
#include "tabladesimbolos.h"
#include "sintactico.tab.h"
#include "lex.yy.h"
void error_lexico(int linea);
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

FLOAT {DIGIT}*[.]{DIGIT}*{EXPONENCIAL}?|\.{DIGIT}{EXPONENCIAL}?|{DIGIT}{EXPONENCIAL}

INTEGER {DIGIT}+

FILE {VARIABLE}\.{ALFA}+

LIB <{ALFA|DIGIT}+\.h>

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

.                   { error_lexico(yylineno); return (TOKEN_ERROR);}

<<EOF>>             {fclose(yyin); yyrestart(stdin); return (TOKEN_EOF);}


%%

/* Estas seran nuestras funciones personales que se volcarán automaticamente en el archivo lex.yy.c */

double load(char *nombreArchivo){
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL){
        printf("Error al abrir el archivo %s \n", nombreArchivo);
        yyin = stdin;
        return 0;
    }
    yyin = archivo;
    return 1;
}

double exitC(){
    yylex_destroy();
    yyterminate();
    return 1;
}

void error_lexico(int linea){
    printf("Error lexico en la linea %d\n", linea);
}
