#include <stdio.h>

int main() {
    int a = 10, b = 3;
    float resultado;
    
    printf("=== OPERADORES ARITMÉTICOS ===\n");
    printf("a = %d, b = %d\n\n", a, b);
    
    // Operações básicas
    printf("Adição: %d + %d = %d\n", a, b, a + b);
    printf("Subtração: %d - %d = %d\n", a, b, a - b);
    printf("Multiplicação: %d * %d = %d\n", a, b, a * b);
    printf("Divisão: %d / %d = %d\n", a, b, a / b);
    printf("Módulo: %d %% %d = %d\n", a, b, a % b);
    
    // Divisão com float
    resultado = (float)a / b;
    printf("Divisão real: %d / %d = %.2f\n", a, b, resultado);
    
    return 0;
} 