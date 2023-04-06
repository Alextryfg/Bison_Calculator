#include <stdio.h>
#include "abb.h"
#include "definiciones.h"

/*Se trata del arbol en el que se almacenará la tabla de simbolos*/
abb tabla;

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
 * Funcion encargada de inicializar la tabla de simbolos
 */
void initTabla() {

    /* Creo la tabla */
    crear(&tabla);

    /* Inserto sus elementos */
    for (int i = 0; initialC[i].nombre != NULL ; i++)
        insertarComando(&tabla, initialC[i].nombre, initialC[i].id, initialC[i].func);
    
    for (int i = 0; initialConst[i].nombre != NULL ; i++)
        insertarVar(&tabla, initialConst[i].nombre, ID_CONST, initialConst[i].valor);
        

}

/*
 * Funcion encargada de la destruccion del arbol
 */
void destruirTabla(){
    destruir(&tabla);
}

/*
 * Funcion encargada de encontrar un lexema dentro de el arbol. Si el elemento no esta en la tabla, se introducirá
 */
tipoelem* findSimbol(char* lex){

    tipoelem *s;
    //Se busca el nodo por medio del lexema almacenandolo en s
    buscar_nodo(tabla, lex , s);

    if(s != NULL){
        //Si el nodo existe, se devuelve el puntero a el
        free(lex);
        return s;
    }else{
        // En caso de no existir, se crea
        tipoelem *new;
        new->lexema = lex;
        new->type = ID_VAR;//Tipo de la variable
        new->data.val = 0; //Valor de la variable
        insertar(&tabla, *new);
        return new;
    }
}

/*
 * Funcion que imprime la tabla, invocando a la recursiva de abb.h
 */
void printTabla(){
    printf("\n*************TABLA DE SIMBOLOS*************");
    _printTabla(&tabla);
    printf("\n*******************************************\n");
}