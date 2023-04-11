#ifndef LEXX_YY_H_
#define LEXX_YY_H_
#include "abb.h"

/*
* Funcion de inicializacion del sistema de entrada donde se abrira el archivo
*/
double load(char *nombreArchivo);
/*
 * Funcion encargada de cerrar la calculadora
 */
double exitC();

/*
* Funcion encargada de imprimir el error lexico y su linea
*/
void error_lexico(int linea);


#endif /* DEFINITIONS_H_ */