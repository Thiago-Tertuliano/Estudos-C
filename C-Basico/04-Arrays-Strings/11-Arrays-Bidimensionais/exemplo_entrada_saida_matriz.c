#include <stdio.h>

int main() {
    int matriz[3][3];
    
    printf("=== Entrada e Saída de Matriz ===\n\n");
    
    // Entrada de dados
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Saída da matriz
    printf("\nMatriz digitada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Soma de cada linha
    printf("\nSoma de cada linha:\n");
    for (int i = 0; i < 3; i++) {
        int soma_linha = 0;
        for (int j = 0; j < 3; j++) {
            soma_linha += matriz[i][j];
        }
        printf("Linha %d: %d\n", i + 1, soma_linha);
    }
    
    // Soma de cada coluna
    printf("\nSoma de cada coluna:\n");
    for (int j = 0; j < 3; j++) {
        int soma_coluna = 0;
        for (int i = 0; i < 3; i++) {
            soma_coluna += matriz[i][j];
        }
        printf("Coluna %d: %d\n", j + 1, soma_coluna);
    }
    
    // Elementos da diagonal principal
    printf("\nElementos da diagonal principal:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", matriz[i][i]);
    }
    printf("\n");
    
    // Elementos da diagonal secundária
    printf("\nElementos da diagonal secundária:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", matriz[i][2 - i]);
    }
    printf("\n");
    
    return 0;
} 