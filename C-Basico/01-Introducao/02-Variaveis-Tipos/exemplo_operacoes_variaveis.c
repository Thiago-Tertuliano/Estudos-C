#include <stdio.h>

int main() {
    int a = 10, b = 5;
    float resultado;
    
    // Operações matemáticas
    resultado = a + b;
    printf("Soma: %d + %d = %.2f\n", a, b, resultado);
    
    resultado = a - b;
    printf("Subtração: %d - %d = %.2f\n", a, b, resultado);
    
    resultado = a * b;
    printf("Multiplicação: %d * %d = %.2f\n", a, b, resultado);
    
    resultado = (float)a / b;  // Cast para float
    printf("Divisão: %d / %d = %.2f\n", a, b, resultado);
    
    return 0;
} 