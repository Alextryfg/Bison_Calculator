#include <stdio.h>
#include "tabladesimbolos.h"
#include "errores.h"
#include "lex.yy.h"
#include "sintactico.tab.h"

int main(int argc, char **argv) {

    //Mensaje de bienvenida
    welcome();
    //Se inicializa la tabla de simbolos
    initTablaSimbolos();
    //Se comienza con el analisis
    yyparse();

}