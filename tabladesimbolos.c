#include <stdio.h>
#include "abb.h"
#include "definiciones.h"
#include "lex.yy.h"

/*Se trata del arbol en el que se almacenará la tablaSimbolos de simbolos*/
abb tablaSimbolos;

typedef struct{
    char* nombre;
    int id;
    double (*func)(); //funcion del token
}comandos;

typedef struct{
    char *nombre;
    double valor;
}constante;


constante initialConst[] = {
    {"pi", 3.14159265358979},
    {"e", 2.71828182845904},
    {NULL, 0}
};

/* En initial, almacenare los distintos comandos especiales, de manera que alberguen un puntero a la función que invocarán */

comandos initialC[] = {
    {"exit", ID_EXIT, exit}, 
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

/* Funciones que se invocaran cuando FLEX detecte las palabras clave.*/

void workspace(){
    printf("workspace ejecutado correctamente");
    printTablaSimbolos();
}

void help(){
    printf("Help ejecutado correctamente");
}

void clear(){
    system("clear");
}

void simbolos(){
    printf("simbolos ejecutado correctamente");
    printTablaSimbolos();
}

void load(){
    printf("load ejecutado correctamente");
}

void import(){
    printf("import ejecutado correctamente");
}



/*
 * Funcion encargada de la destruccion del arbol
 */
void destruirTablaSimbolos(){
    destruir(&tablaSimbolos);
}

/*
 * Funcion encargada de encontrar un lexema dentro de el arbol. Si el elemento no esta en la tablaSimbolos, se introducirá
 */
int findComando(char* lex){

    tipoelem *s;
    //Se busca el nodo por medio del lexema almacenandolo en s
    buscar_nodo(tablaSimbolos, lex , s);

    if(s != NULL){
        //Si el nodo existe, se devuelve su codigo
        free(lex);
        return s->type;
    }else{
        // En caso de no existir, se crea
        tipoelem *new;
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
    printf("\n*************TABLA DE SIMBOLOS*************");
    _printTabla(&tablaSimbolos);
    printf("\n*******************************************\n");
}