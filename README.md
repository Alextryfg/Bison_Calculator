# Calculadora_Bison

Pasos para ejecutar:

1. cd Calculadora_Bison-main/P3Compiladores/
2. flex lexico.l
3. bison -d sintactico.y
4. gcc -Wall *.c -o calculadora -lfl
5. ./calculadora
