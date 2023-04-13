# Calculadora_Bison

Pasos para ejecutar:

1. cd Calculadora_Bison-main/P3Compiladores/
2. flex lexico.l
3. bison -d sintactico.y
4. gcc -Wall *.c -o calculadora -lfl
5. ./calculadora

Todos estos pasos estan contenidos dentro del script 'compilar.sh' que se podra ejecutar por medio del comando 'bash compilar.sh'. Una vez compilado, podremos probar a ejecutarlo mediante './calculadora <fichero>', siendo el fichero insertado opcional. Una vez comenzada la ejecución sería de interes activar el comando 'help' que nos ayudará a entender el funcionamiento del programa.
  
IMPORTANTE: Para cargar los archivos, estes deberan tener permisos de escritura y lectura. Esto es debido a que el archivo debe contener un '\n' antes del EOF. En caso de que al usuario se le olvide introducirlo, el programa lo hará automáticamente. El 'fichero.txt' viene ya con todos los permisos necesarios, por lo que si es necesario cargar algun archivo, lo mas sencillo es introducirlo en este.
