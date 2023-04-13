#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "abb.h"
#include "definiciones.h"
#include "lex.yy.h"
#include "sintactico.tab.h"

/* Se trata del arbol en el que se almacenará la tablaSimbolos de simbolos*/
abb tablaSimbolos;

/* Creamos los prototipos de funciones para ser detectadas por initialC */

double workspace();
double help();
double clear();
double simbolos();
void success();

/* En initialC, almacenare los distintos comandos especiales, de manera que alberguen un puntero a la función que invocarán */

tipoelem initial[] = {
    {"pi", ID_CONST, .data.val = 3.14159265358979323846},
    {"e", ID_CONST, .data.val = 2.71828182845904523536},
    {"exit", ID_EXIT, .data.func = exitC}, 
    {"workspace", ID_WORKSPACE, .data.func = workspace},
    {"help", ID_HELP, .data.func = help},
    {"clear", ID_CLEAR_WORKSPACE, .data.func = clear},
    {"simbolos", ID_SIMBOLOS, .data.func = simbolos},
    {"load", ID_LOAD, .data.func = load},
    {"sin", ID_FUNC, .data.func = sin},
    {"cos", ID_FUNC, .data.func = cos},
    {"tan", ID_FUNC, .data.func = tan},
    {"sqrt", ID_FUNC, .data.func = sqrt},
    {"exp", ID_FUNC, .data.func = exp},
    {"log", ID_FUNC, .data.func= log},
    {NULL,0, .data.func = NULL}
    };

/*
 * Funcion encargada de inicializar la tablaSimbolos de simbolos
 */
void initTablaSimbolos() {

    //MEJOR VUELVE A CREARLE UNA FUNCION PARA CREAR LA TABLA DE SIMBOLOS

    /* Creo la tablaSimbolos */
    crear(&tablaSimbolos);

    /* Inserto sus elementos */
    for (int i = 0; initial[i].lexema != NULL ; i++)
        insertar(&tablaSimbolos, initial[i]);
        

}



/*
 * Funcion encargada de la destruccion del arbol
 */
void destruirTablaSimbolos(){
    destruir(&tablaSimbolos);
}

/*
 * Funcion encargada de averiguar si existe un simbolo en la tablaSimbolos
 */
int existeSimbolo(char* lex){
    return es_miembro_clave(tablaSimbolos, lex);
}

/*
 * Funcion encargada de crear una variable en la tablaSimbolos
 */
void insertarSimbolo(char* lex, double val){
    tipoelem s = {lex, ID_VAR, .data.val = val};
    insertar(&tablaSimbolos,s);

}

/*
 * Funcion de actualizacion del valor de un simbolo
 */
void actualizarSimbolo(char* lex, double val){
    tipoelem s = {lex, ID_VAR, .data.val = val, .initVal = 1};
    suprimir(&tablaSimbolos, s); //AQUI NO SE SUPRIME EL QUE ESTA EN LA TABLA, SE SUPRIME EL QUE SE LE PASA COMO PARAMETRO
    insertar(&tablaSimbolos, s);
    
}

/*
 * Funcion encargada de obtener el valor de un simbolo
 */
double obtenerValorSimbolo(char* lex){
    tipoelem s;
    buscar_nodo(tablaSimbolos, lex , &s);
    if(s.lexema != NULL){
        return s.data.val;
    }
    return 0;
}

/*
 * Funcion encargada de obtener el simbolo de la tablaSimbolos
 */
tipoelem getSimbol(char* lex){
    tipoelem s;
    s.lexema = NULL;
    buscar_nodo(tablaSimbolos, lex , &s);
    return s;
}

/*
 * Funcion que imprime la tablaSimbolos, invocando a la recursiva de abb.h
 */
void printTablaSimbolos(){
    printf("═══════════════════════════════TABLA DE SIMBOLOS════════════════════════════════════════════════");
    _printTabla(tablaSimbolos);
    printf("\n════════════════════════════════════════════════════════════════════════════════════════════════\n");
}

/*
 * Funcion que imprime el workspace, invocando a la recursiva de abb.h
 */
void printWorkspace(){
    printf("═══════════════════════════════WORKSPACE════════════════════════════════════════════════════════");
    _printWorkspace(&tablaSimbolos);
    printf("\n════════════════════════════════════════════════════════════════════════════════════════════════\n");
}

/*
 * Funcion que limpia el workspace
 */
void clearWorkspace(){
    _clearWorkspace(&tablaSimbolos);
}

/*
 * Print de bienvenida
 */
void welcome(){
    printf("╔════════════════════════════════╗\n");
    printf("║         BIENVENIDO A LA        ║\n");
    printf("║           CALCULADORA          ║\n");
    printf("║                                ║\n");
    printf("║ Para obtener ayuda, introduce  ║\n");
    printf("║        el comando 'help'.      ║\n");
    printf("╚════════════════════════════════╝\n");

}

/* Funciones que se invocaran cuando FLEX detecte las palabras clave.*/

/*
* Funcion encargada de imprimir el workspace
*/
double workspace(){
    printWorkspace();
    return 1;
}

/*
* Funcion encargada de imprimir la ayuda
*/
double  help(){ 
    FILE* archivo = fopen("ayuda.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }
    
    char linea[150];
    while (fgets(linea, 150, archivo) != NULL) {
        printf("%s", linea);
    }
    
    fclose(archivo);
    return 1;
    
}

/*
* Funcion encargada de limpiar el workspace
*/
double  clear(){
    clearWorkspace();
    success("Exito: Workspace limpiado correctamente\n");
    return 1;
}

/*
* Funcion encargada de imprimir la tabla de simbolos
*/
double  simbolos(){
    printTablaSimbolos();
    return 1;
}