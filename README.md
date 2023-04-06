# Calculadora_Bison

cd Calculadora_Bison-main/P3Compiladores/
flex lexico.l
bison -d sintactico.y
gcc -Wall *.c -o calculadora -lfl
./calculadora
