#include <stdio.h>
#include "tabladesimbolos.h"
#include "lex.yy.h"
#include "sintactico.tab.h"

int main(int argc, char **argv) {

    //Mensaje de bienvenida
    welcome();

    //Se inicializa la tabla de simbolos
    initTablaSimbolos();

    if(argc == 2){
        int result = load(argv[1]);
        if(result == 0){
            return 1;
        }
    }

    if(argc > 3){
        printf("Demasiados argumentos.\n");
        printf("Uso: ./calculadora <fichero>\n");
        return 0;
    }

    //Se comienza con el analisis
    yyparse();
    //Destruimos la tabla de simbolos
    destruirTablaSimbolos();
    return 1;



}
