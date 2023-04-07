#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H
#include "abb.h"

/*
 * Funcion encargada de inicializar la tablaSimbolos de simbolos
 */
void initTablaSimbolos();

/*
 * Funcion encargada de la destruccion del arbol
 */
void destruirTablaSimbolos();

/*
 * Funcion encargada de averiguar si existe un simbolo en la tablaSimbolos
 * @param lex es el lexema del simbolo
 * @return 1 si existe, 0 si no existe
 */
int existeSimbolo(char* lex);

/*
 * Funcion encargada de crear una variable en la tablaSimbolos
 * @param lex es el lexema del simbolo
 * @param val es el valor del simbolo
 * 
 */
void insertarSimbolo(char* lex, double val);

/*
 * Funcion de actualizacion del valor de un simbolo
 * @param lex es el lexema del simbolo
 * @param val es el valor del simbolo
 */
void actualizarSimbolo(char* lex, double val);

/*
 * Funcion encargada de obtener el valor de un simbolo
 * @param lex es el lexema del simbolo
 */
double obtenerValorSimbolo(char* lex);

/*
 * Funcion encargada de encontrar un lexema dentro de el arbol. Si el elemento no esta en la tablaSimbolos, se introducirá
 * @return el codigo del simbolo
 */
int findSimbol(char* lex);

/*
 * Funcion que imprime la tablaSimbolos, invocando a la recursiva de abb.h
 */
void printTablaSimbolos();

/*
*
*/
void welcome();

double workspace();
double help();
double clear();
double simbolos();
double load();
double import();


#endif	// TABLADESIMBOLOS_H