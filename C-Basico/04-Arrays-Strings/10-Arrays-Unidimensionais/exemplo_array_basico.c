#include <stdio.h>

int main() {
    printf("=== Arrays Básicos ===\n\n");
    
    // Declaração e inicialização de arrays
    int numeros[5] = {10, 20, 30, 40, 50};
    float precos[4] = {15.50, 22.30, 8.75, 12.00};
    char letras[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    
    // Exibindo array de inteiros
    printf("Array de números inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }
    printf("\n");
    
    // Exibindo array de floats
    printf("Array de preços:\n");
    for (int i = 0; i < 4; i++) {
        printf("precos[%d] = %.2f\n", i, precos[i]);
    }
    printf("\n");
    
    // Exibindo array de caracteres
    printf("Array de letras:\n");
    for (int i = 0; i < 6; i++) {
        printf("letras[%d] = %c\n", i, letras[i]);
    }
    printf("\n");
    
    // Acesso direto a elementos
    printf("Acesso direto a elementos:\n");
    printf("Primeiro número: %d\n", numeros[0]);
    printf("Último número: %d\n", numeros[4]);
    printf("Preço do meio: %.2f\n", precos[2]);
    printf("Terceira letra: %c\n", letras[2]);
    
    return 0;
} 