#include <stdio.h>

int main() {
    printf("=== Matrizes Básicas ===\n\n");
    
    // Declaração e inicialização de matrizes
    int matriz1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float matriz2[2][4] = {{1.5, 2.3, 4.1, 5.7}, {8.2, 9.4, 3.6, 7.8}};
    char matriz3[3][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};
    
    // Exibindo matriz de inteiros
    printf("Matriz 3x3 de inteiros:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Exibindo matriz de floats
    printf("Matriz 2x4 de floats:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.1f ", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Exibindo matriz de caracteres
    printf("Matriz 3x3 de caracteres:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", matriz3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Acesso direto a elementos
    printf("Acesso direto a elementos:\n");
    printf("matriz1[0][0] = %d\n", matriz1[0][0]);
    printf("matriz1[1][1] = %d\n", matriz1[1][1]);
    printf("matriz1[2][2] = %d\n", matriz1[2][2]);
    printf("matriz2[0][2] = %.1f\n", matriz2[0][2]);
    printf("matriz3[1][0] = %c\n", matriz3[1][0]);
    
    return 0;
} 