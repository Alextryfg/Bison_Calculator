#include "abb.h"
#include "definiciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

///////////////////////// ESTRUCTURAS DE DATOS

struct celda {
    tipoelem info;
    struct celda *izq, *der;
};

/////////////////////////// INICIO PARTE MODIFICABLE

/*Extraer la clave de una celda */
tipoclave _clave_elem(tipoelem *E) {
    return E->lexema;
}

/* Esta funcion puente nos permite modificar el tipo de
 * de datos del TAD sin tener que cambiar todas las
 * comparaciones del resto de la biblioteca y en su lugar
 * cambiando solo esta. */
int _comparar_claves(tipoclave cl1, tipoclave cl2) {
    return strcmp(cl1,cl2)==0 ? 0 : strcmp(cl1,cl2)>0 ? 1 : -1;
}

/* Si tipoelem tiene alguna estructura que necesite
 * destruirse ha de hacerse aqui. El uso de esta funcion
 * permite hacer mas eficiente la destruccion del arbol.*/
void _destruir_elem(tipoelem *E) {
    if(E != NULL){
        if (E->lexema != NULL) {//lexeme memory release
            free(E->lexema);
            E = NULL;
        }
    }

}

/////////////////////////// FIN PARTE MODIFICABLE
/////////////////////////////////////////////////////////////

//OPERACIONES DE CREACIÓN Y DESTRUCCIÓN

void crear(abb *A) {
    *A = NULL;
}


void destruir(abb *A) {
    if (*A != NULL) {
        destruir(&(*A)->izq);
        destruir(&(*A)->der);
        if((*A)->info.lexema != NULL){
            free((*A)->info.lexema);
            (*A)->info.lexema = NULL;
        }
    }
    free(*A);
    *A = NULL;
}



/*
void destruir(abb *A) {
    if (es_vacio(*A)) {
        *A = (abb) malloc(sizeof (struct celda));
        (*A)->info.lexema = (char)malloc(sizeof(char) (strlen(E.lexema) + 1));
        strcpy((*A)->info.lexema, E.lexema);
        if (*A) {
            (*A)->info.lexema[strlen(E.lex)] = '\0';
            (*A)->der = NULL;
            (*A)->der = NULL;
        }
    return;
    }
}
*/




//OPERACIONES DE INFORMACIÓN

unsigned es_vacio(abb A) {
    return A == NULL;
}

abb izq(abb A) {
    return A->izq;
}

abb der(abb A) {
    return A->der;
}

void leer(abb A, tipoelem *E) {
    *E = A->info;
}
// Función privada para comparar las claves

int _comparar_clave_elem(tipoclave cl, tipoelem E) {
    return _comparar_claves(cl, _clave_elem(&E));
}
//Función privada para informar si una clave está en el árbol

unsigned _es_miembro_clave(abb A, tipoclave cl) {
    if (es_vacio(A)) {
        return 0;
    }
    int comp = _comparar_clave_elem(cl, A->info);

    if (comp == 0) { //cl == A->info
        return 1;
    }
    if (comp > 0) { //cl > A->info
        return _es_miembro_clave(der(A), cl);
    }
    //cl < A->info
    return _es_miembro_clave(izq(A), cl);
}

//Funciones públicas

unsigned es_miembro(abb A, tipoelem E) {
    return _es_miembro_clave(A, _clave_elem(&E));
}

unsigned es_miembro_clave(abb A, tipoclave cl) {
    return _es_miembro_clave(A, cl);
}

void buscar_nodo(abb A, tipoclave cl, tipoelem *nodo) {
    if (es_vacio(A)) {
        return;
    }
    int comp = _comparar_clave_elem(cl, A->info);

    if (comp == 0) { // cl == A->info

        *nodo = A->info;

    } else if (comp < 0) { // cl < A->info
        buscar_nodo(A->izq, cl, nodo);
    } else { // cl > A->info
        buscar_nodo(A->der, cl, nodo);
    }
}

//OPERACIONES DE MODIFICACIÓN

/* Funcion recursiva para insertar un nuevo nodo
   en el arbol. Se presupone que no existe un nodo
   con la misma clave en el arbol. */
void insertar(abb *A, tipoelem E) {
    if (es_vacio(*A)) {
        *A = (abb) malloc(sizeof (struct celda));
        if (*A) {
            (*A)->info.lexema = (char*)malloc(sizeof(char)*(strlen(E.lexema) + 1));
            strcpy((*A)->info.lexema, E.lexema);
            (*A)->info.lexema[strlen(E.lexema)] = '\0';
            (*A)->info.type = E.type;
            (*A)->info.data = E.data;
            (*A)->info.initVal = 1;
            (*A)->izq = NULL;
            (*A)->der = NULL;
        }
        return;

    }
    tipoclave cl = _clave_elem(&E);
    int comp = _comparar_clave_elem(cl, (*A)->info);
    if (comp > 0) {
        insertar(&(*A)->der, E);
    } else {
        insertar(&(*A)->izq, E);
    }

    
}

/* Funcion privada que devuelve mínimo de subárbol dcho */
tipoelem _suprimir_min(abb * A) {//Se devuelve el elemento más a la izquierda
    abb aux;
    tipoelem ele;
    if (es_vacio((*A)->izq)) {//Si izquierda vacía, se devuelve valor nodo actual A
        ele = (*A)->info;
        aux = *A;
        *A = (*A)->der;
        free(aux);
        return ele;
    } else {
        return _suprimir_min(&(*A)->izq); //se vuelve a buscar mínimo rama izquierda
    }
}

/* Funcion que permite eliminar un nodo del arbol */
void suprimir(abb *A, tipoelem E) {
    abb aux;
    if (es_vacio(*A)) {
        return;
    }

    tipoclave cl = _clave_elem(&E);
    int comp = _comparar_clave_elem(cl, (*A)->info);
    if (comp < 0) { //if (E < (*A)->info) {
        suprimir(&(*A)->izq, E);
    } else if (comp > 0) { //(E > (*A)->info) {
        suprimir(&(*A)->der, E);
    } else if (es_vacio((*A)->izq) && es_vacio((*A)->der)) {
        _destruir_elem(&((*A)->info));
        free(*A);
        *A = NULL;
    } else if (es_vacio((*A)->izq)) { // pero no es vacio derecha
        aux = *A;
        *A = (*A)->der;
        _destruir_elem(&aux->info);
        free(aux);
    } else if (es_vacio((*A)->der)) { //pero no es vacio izquierda
        aux = *A;
        *A = (*A)->izq;
        _destruir_elem(&aux->info);
        free(aux);
    } else { //ni derecha ni izquierda esta vacio, busco mínimo subárbol derecho
        _destruir_elem(&(*A)->info); //elimino la info pero no libero el nodo,
        //pues en su sitio voy a poner el mínimo del subárbol derecho
        (*A)->info = _suprimir_min(&(*A)->der);
    }
}


/* Funcion privada para pasar la clave y no tener que
   extraerla del nodo en las llamadas recursivas.*/
void _modificar(abb A, tipoclave cl, tipoelem nodo) {
    if (es_vacio(A)) {
        return;
    }
    int comp = _comparar_clave_elem(cl, A->info);
    if (comp == 0) {
        A->info = nodo;
    } else if (comp < 0) {
        _modificar(A->izq, cl, nodo);
    } else {
        _modificar(A->der, cl, nodo);
    }
}


/* Permite modificar el nodo extrayendo del mismo la clave */
void modificar(abb A, tipoelem nodo) {
    tipoclave cl = _clave_elem(&nodo);
    _modificar(A, cl, nodo);
}

/*
 * Funcion auxiliar recursiva de print de la tabla
 * @param A
 */
void _printTabla(abb A){

    tipoelem lect;

    if (!es_vacio(A)) {
            _printTabla(A->izq);

                leer(A, &lect);

                printf("\nLexema: %14s", lect.lexema);
                printf("%15s: %-3d", "Codigo", lect.type);
                printf("%18s: %d", "Inicializado", lect.initVal);
            if (lect.type == ID_CONST || lect.type == ID_VAR) {
                printf("%13s: %-7f", "Valor", lect.data.val);
            } else {
                printf("%15s: %-3s", "Funcion", lect.lexema);
            }



            _printTabla(A->der);
    }

}

/**
 * Funcion que imprime las variables del arbol A
 * @param A
 */
void _printWorkspace(abb *A){

    tipoelem lect;

    if (!es_vacio(*A)) {

            _printWorkspace(&(*A)->izq);

            leer(*A, &lect);

            if(lect.type == ID_VAR){
                printf("\nLexema: %14s", lect.lexema);
                printf("%15s: %-3d", "Codigo", lect.type);
                printf("%18s: %d", "Inicializado", lect.initVal);
                printf("%13s: %-7f", "Valor", lect.data.val);
            }
            _printWorkspace(&(*A)->der);
    }

}

/**
 * Borra todas las variables del arbol A
 * @param A
 */
void _clearWorkspace(abb *A){
    
        tipoelem lect;
    
        if (!es_vacio(*A)) {
    
            _clearWorkspace(&(*A)->izq);
            _clearWorkspace(&(*A)->der);

            leer(*A, &lect);

            if(lect.type == ID_VAR){
                //elimino el nodo
                suprimir(A, lect);

                
            }

            
        }
    
}
