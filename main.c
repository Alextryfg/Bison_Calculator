#include "tabladesimbolos.h"
#include "errores.h"
#include "lex.yy.h"

int main(int argc, char **argv) {

    //Mensaje de bienvenida
    welcome();
    //Se inicializa la tabla de simbolos
    initTabla();
    //Se comienza con el analisis
    yyparse();

}