#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "definiciones.h"
#include "lex.yy.h"

/* Se trata del arbol en el que se almacenará la tablaSimbolos de simbolos*/
abb tablaSimbolos;

/* Creamos los prototipos de funciones para ser detectadas por initialC */
double workspace();
double help();
double clear();
double simbolos();
double load();
double import();



/* En initialC, almacenare los distintos comandos especiales, de manera que alberguen un puntero a la función que invocarán */

tipoelem initial[] = {
    {"pi", ID_CONST, .data.val = 3.14159265358979},
    {"e", ID_CONST, .data.val = 2.71828182845904},
    {"exit", ID_EXIT, .data.func = exitC}, 
    {"workspace", ID_WORKSPACE, .data.func = workspace},
    {"help", ID_HELP, .data.func = help},
    {"clear", ID_CLEAR_WORKSPACE, .data.func = clear},
    {"simbolos", ID_SIMBOLOS, .data.func = simbolos},
    {"load", ID_LOAD, .data.func = load},
    {"import", ID_IMPORT, .data.func = import},
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
    tipoelem s = {lex, ID_VAR, .data.val = val};
    modificar (tablaSimbolos, s);
    
}

/*
 * Funcion encargada de obtener el valor de un simbolo
 */
double obtenerValorSimbolo(char* lex){
    tipoelem s = {};
    buscar_nodo(tablaSimbolos, lex , &s);
    if(s.lexema != NULL){
        return s.data.val;
    }
    return 0;
}

/*
 * Funcion encargada de encontrar un lexema dentro de el arbol. Si el elemento no esta en la tablaSimbolos, se introducirá
 */
int findSimbolType(char* lex){

    tipoelem s = {};
    //Se busca el nodo por medio del lexema almacenandolo en s
    buscar_nodo(tablaSimbolos, lex , &s);

    if(s.lexema != NULL){
        //Si el nodo existe, se devuelve su codigo
        free(lex);
        return s.type;
    }else{
        // En caso de no existir, se crea
        tipoelem new = {lex, ID_VAR, .data.val = 0};
        insertar(&tablaSimbolos, new);
        return new.type;
    }
}

/*
 * Funcion que imprime la tablaSimbolos, invocando a la recursiva de abb.h
 */
void printTablaSimbolos(){
    printf("═══════════════════════════════TABLA DE SIMBOLOS════════════════════════════════════════════════");
    _printTabla(&tablaSimbolos);
    printf("\n════════════════════════════════════════════════════════════════════════════════════════════════\n");
}

/*
 * Print de bienvenida
 */
void welcome(){
    printf("╔════════════════════════════════╗\n");
    printf("║         BIENVENIDO A LA        ║\n");
    printf("║           CALCULADORA          ║\n");
    printf("╚════════════════════════════════╝\n");
}

/* Funciones que se invocaran cuando FLEX detecte las palabras clave.*/

double workspace(){
    printf("workspace ejecutado correctamente");
    printTablaSimbolos();
    return 0;
}

double help(){
    printf("Help ejecutado correctamente");
    return 0;
}

double clear(){
    system("clear");
    return 0;
}

double simbolos(){
    printf("simbolos ejecutado correctamente");
    printTablaSimbolos();
    return 0;
}

double load(){
    printf("load ejecutado correctamente");
    return 0;
}

double import(){
    printf("import ejecutado correctamente");
    return 0;
}