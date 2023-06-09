#ifndef ABB_H
#define ABB_H

/**
 * Tipo de dato abstracto para arbol binario con clave de
 * ordenacion y elemento de celda.
 */
#define L 20
typedef char *tipoclave;

/* Esta será la estructura que almacenará los distintos simbolos utilizados a lo largo de nuestro intérprete */

typedef struct{
    char *lexema; //lexema del token
    int type;   //tipo del token
    int initVal; //flag para saber si el token esta inicializado
    union{
        float val; //valor del token
        double (*func)(); //funcion del token
    }data;
}tipoelem;

typedef struct celda * abb;//tipo opaco

//FUNCIONES DE CREACIÓN Y DESTRUCCIÓN DEL ÁRBOL
/**
 * Crea el arbol vacio.
 * @param A Puntero al arbol. Debe estar inicializado.
 */
void crear(abb *A);

/**
 * Destruye el arbol recursivamente
 * @param A El arbol que queremos destruir
 */
void destruir(abb *A);

//FUNCIONES DE INFORMACIÓN
/**
 * Comprueba si el arbol esta vacio
 * @param A El arbol binario
 */
unsigned es_vacio(abb A);

/**
 * Devuelve el subarbol izquierdo de A
 * @param A - Arbol original
 */
abb izq(abb A);
/**
 * Devuelve el subarbol derecho de A
 * @param A - Arbol original
 */
abb der(abb A);
/**
 * Recupera la informacion de la celda de la raiz del arbol
 * @param A
 * @param E Puntero al nodo que apuntara a la informacion
 */
void leer(abb A, tipoelem *E);

/**
 * Comprueba si el elemento <E> existe en el arbol <A>
 * @param A
 * @param E
 */
unsigned es_miembro(abb A, tipoelem E);

/**
 * Comprueba si la clave <cl> existe en el arbol <A>
 * @param A
 * @param cl
 */
unsigned es_miembro_clave(abb A, tipoclave cl);

/**
 * Busca un nodo con clave <cl> en el arbol y, si existe
 * modifica el puntero <nodo> para que lo apunte.
 * @param A Arbol binario en el que se busca el nodo.
 * @param cl Clave que se buscara.
 * @param nodo Puntero a un tipoelem.
 */
void buscar_nodo(abb A, tipoclave cl, tipoelem *nodo);

//FUNCIONES DE MODIFICACIÓN
/**
 * Inserta un nuevo nodo en el arbol para el elemento E
 * del que toma su clave. Esta clave no debe existir en
 * el arbol.
 * @param A Arbol binario
 * @param E Informacion del nuevo nodo.
 */
void insertar(abb *A, tipoelem E);

/**
 * Suprime el nodo del arbol <A>
 * @param A
 * @param E
 */
void suprimir(abb *A,tipoelem E);
/**
 * Busca el nodo con clave la del nodo y lo modifica.
 * @param A
 * @param nodo
 */
void modificar(abb A, tipoelem nodo);

/*
 * Funcion auxiliar recursiva de print de la tabla
 * @param A
 */
void _printTabla(abb A);

/**
 * Funcion que imprime las variables del arbol A
 * @param A
 */
void _printWorkspace(abb *A);

/**
 * Borra todas las variables del arbol A
 * @param A
 */
void _clearWorkspace(abb *A);


#endif	// ABB_H

