#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H
#include "abb.h"

/*
 * Funcion encargada de inicializar la tablaSimbolos de simbolos
 */
void initTablaSimbolos();

void workspace();

void help();

void clear();

void simbolos();

void load();

void import();

/*
 * Funcion encargada de la destruccion del arbol
 */
void destruirTablaSimbolos();

/*
 * Funcion encargada de encontrar un lexema dentro de el arbol. Si el elemento no esta en la tablaSimbolos, se introducirá
 */
int findComando(char* lex);

/*
 * Funcion que imprime la tablaSimbolos, invocando a la recursiva de abb.h
 */
void printTablaSimbolos();

/*
*
*/
void welcome();


#endif	// TABLADESIMBOLOS_H