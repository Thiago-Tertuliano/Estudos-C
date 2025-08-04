#include <stdio.h>

int main() {
    // Declarando variáveis com valores fixos
    int numero1 = 15;
    int numero2 = 3;
    
    printf("=== CALCULADORA SIMPLES ===\n");
    printf("Número 1: %d\n", numero1);
    printf("Número 2: %d\n", numero2);
    printf("\n");
    
    // Realizando as operações
    printf("Soma: %d + %d = %d\n", numero1, numero2, numero1 + numero2);
    printf("Subtração: %d - %d = %d\n", numero1, numero2, numero1 - numero2);
    printf("Multiplicação: %d * %d = %d\n", numero1, numero2, numero1 * numero2);
    printf("Divisão: %d / %d = %d\n", numero1, numero2, numero1 / numero2);
    
    return 0;
} 