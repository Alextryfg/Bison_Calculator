#ifndef LEXX_YY_H_
#define LEXX_YY_H_
#include "abb.h"

/*
* Funcion de inicializacion del sistema de entrada donde se abrira el archivo
*/
void openFile(char *nombreArchivo);

/*
 * Funcion encargada de devolver el componente lexico que será procesado por el Analizador sintáctico
 */
double exitC();

/*
 * Funcion encargada de cerrar el archivo y liberar memoria
 */
void closeFile();


#endif /* DEFINITIONS_H_ */