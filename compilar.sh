flex lexico.l
bison -d sintactico.y
gcc -Wall *.c -o calculadora -lfl
./calculadora