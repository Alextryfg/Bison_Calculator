#include <stdio.h>
#include "tabladesimbolos.h"
#include "lex.yy.h"
#include "sintactico.tab.h"

int main(int argc, char **argv) {

    //valgrind --leak-check=full --show-leak-kinds=all  -s ./calculadora
    //Mensaje de bienvenida
    welcome();
    //Se inicializa la tabla de simbolos
    initTablaSimbolos();
    //Se comienza con el analisis
    yyparse();
    //Destruimos la tabla de simbolos
    destruirTablaSimbolos();
    printf("Tabla de simbolos destruida correctamente\n");

}