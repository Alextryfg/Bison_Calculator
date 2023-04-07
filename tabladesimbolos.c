#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "definiciones.h"
#include "lex.yy.h"

/* Se trata del arbol en el que se almacenará la tablaSimbolos de simbolos*/
abb tablaSimbolos;

/* Creamos una estructura para las constantes que solo albergarán nombre y valor. Esto tambien
podria realizarse sin ellas, sin embargo facilitará el trabajo a la hora de insertar en el arbol*/
typedef struct{
    char *nombre;
    double valor;
}constante;

/* Lo mismo de antes pero para una estructura de comandos que apuntan a funciones */
typedef struct{
    char* nombre;
    int id;
    double (*func)(); //funcion del token
}comandos;



/* Creamos los prototipos de funciones para ser detectadas por initialC */
double workspace();
double help();
double clear();
double simbolos();
double load();
double import();

/* En initialConst se alamacenarán las constantes de las que dispondremos en la tabla d esimbolos inicial */

constante initialConst[] = {
    {"pi", 3.14159265358979},
    {"e", 2.71828182845904},
    {NULL, 0}
};

/* En initialC, almacenare los distintos comandos especiales, de manera que alberguen un puntero a la función que invocarán */

comandos initialC[] = {
    {"exit", ID_EXIT, exitC}, 
    {"workspace", ID_WORKSPACE, workspace},
    {"help", ID_HELP, help},
    {"clear", ID_CLEAR_WORKSPACE, clear},
    {"simbolos", ID_SIMBOLOS, simbolos},
    {"load", ID_LOAD, load},
    {"import", ID_IMPORT, import},
    {NULL, 0, NULL}
    };

/*
 * Funcion encargada de inicializar la tablaSimbolos de simbolos
 */
void initTablaSimbolos() {

    /* Creo la tablaSimbolos */
    crear(&tablaSimbolos);

    /* Inserto sus elementos */
    for (int i = 0; initialC[i].nombre != NULL ; i++)
        insertarComando(&tablaSimbolos, initialC[i].nombre, initialC[i].id, initialC[i].func);
    
    for (int i = 0; initialConst[i].nombre != NULL ; i++)
        insertarVar(&tablaSimbolos, initialConst[i].nombre, ID_CONST, initialConst[i].valor);
        

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
    insertarVar(&tablaSimbolos, lex, ID_VAR, val);
}

/*
 * Funcion de actualizacion del valor de un simbolo
 */
void actualizarSimbolo(char* lex, double val){
    tipoelem *s = NULL;
    buscar_nodo(tablaSimbolos, lex , s);
    if(s != NULL){
        s->data.val = val;
    }
}

/*
 * Funcion encargada de obtener el valor de un simbolo
 */
double obtenerValorSimbolo(char* lex){
    tipoelem *s = NULL;
    buscar_nodo(tablaSimbolos, lex , s);
    if(s != NULL){
        return s->data.val;
    }
    return 0;
}

/*
 * Funcion encargada de encontrar un lexema dentro de el arbol. Si el elemento no esta en la tablaSimbolos, se introducirá
 */
int findSimbol(char* lex){

    tipoelem *s = NULL;
    //Se busca el nodo por medio del lexema almacenandolo en s
    buscar_nodo(tablaSimbolos, lex , s);

    if(s != NULL){
        //Si el nodo existe, se devuelve su codigo
        free(lex);
        return s->type;
    }else{
        // En caso de no existir, se crea
        tipoelem *new = NULL;
        new->lexema = lex;
        new->type = ID_VAR;//Tipo de la variable
        new->data.val = 0; //Valor de la variable
        insertar(&tablaSimbolos, *new);
        return new->type;
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