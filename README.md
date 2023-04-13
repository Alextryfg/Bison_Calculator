# Calculadora_Bison
## Pasos para Compilar y ejecutar
Para ejecutar la calculadora es necesario seguir los siguientes pasos:

1. Acceder a la carpeta Calculadora_Bison-main/P3Compiladores/ mediante la consola con el comando cd Calculadora_Bison-main/P3Compiladores/.
2. Ejecutar el comando flex lexico.l para generar el analizador léxico.
3. Ejecutar el comando bison -d sintactico.y para generar el analizador sintáctico.
4. Compilar el programa con el comando gcc -Wall *.c -o calculadora -lfl.
5. Ejecutar el programa con el comando ./calculadora, siendo el archivo de entrada opcional.
6. En caso de duda sobre el funcionamiento del programa, se puede ejecutar el comando help para obtener información adicional.

Para simplificar el proceso de compilación, se ha incluido un script llamado **'compilar.sh'** que automatiza estos pasos. Para ejecutarlo, basta con introducir el comando **'bash compilar.sh'** en la consola. Es importante tener en cuenta que, para cargar archivos, éstos deben tener **permisos de escritura y lectura**. Esto se debe a que en caso de que el usuario no haya introducido un salto de línea antes del final del archivo, el programa lo añadirá automáticamente. Es por eso que para evitar problemas, se recomienda utilizar el archivo fichero.txt, que ya cuenta con los permisos necesarios.
