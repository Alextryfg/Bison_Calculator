# Calculadora_Bison

Pasos para ejecutar:

1. cd Calculadora_Bison-main/P3Compiladores/
2. flex lexico.l
3. bison -d sintactico.y
4. gcc -Wall *.c -o calculadora -lfl
5. ./calculadora

Todos estos pasos estan contenidos dentro del script 'compilar.sh' que se podra ejecutar por medio del comando 'bash compilar.sh'. Una vez compilado, podremos probar a ejecutarlo mediante './calculadora <fichero>', siendo el fichero insertado opcional.
