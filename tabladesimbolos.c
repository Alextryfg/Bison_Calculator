#include <stdio.h>
#include "abb.h"
#include "definiciones.h"

/*Se trata del arbol en el que se almacenará la tabla de simbolos*/
abb tabla;

/*
 * Funcion encargada de inicializar la tabla de simbolos
 */
void initTabla() {

    /* Creo la tabla */
    crear(&tabla);

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
        new->type = VAR;//Tipo de la variable
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