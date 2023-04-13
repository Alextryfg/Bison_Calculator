#include <stdio.h>
#include "tabladesimbolos.h"
#include "lex.yy.h"
#include "sintactico.tab.h"

int main(int argc, char **argv) {

    //Mensaje de bienvenida
    welcome();

    //Se inicializa la tabla de simbolos
    initTablaSimbolos();
    
    //Se comprueba si se ha pasado un fichero como argumento
    if(argc == 2){

        //Se carga el fichero
        int result = load(argv[1]);

        //Si el fichero no se ha cargado correctamente, se sale
        if(result == 0){
            return 0;
        }
    }

    //Si se han pasado mas de 2 argumentos, se sale y se explica el motivo
    if(argc > 2){
        printf("Demasiados argumentos.\n");
        printf("Uso: ./calculadora <fichero>\n");
        return 0;
    }

    //Si todo ha ido bien, se inicia el analisis sintactico
    yyparse();

    //Destruimos la tabla de simbolos cuando acabe el programa
    destruirTablaSimbolos();

    
    return 1;



}
