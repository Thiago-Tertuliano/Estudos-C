#include <stdio.h>

int main() {
    int matriz[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int soma_diagonal = 0, produto_diagonal = 1;
    int maximo_diagonal, minimo_diagonal;
    
    printf("=== Trabalhando com Diagonal Principal ===\n\n");
    
    // Exibindo matriz
    printf("Matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Inicialização do máximo e mínimo da diagonal
    maximo_diagonal = matriz[0][0];
    minimo_diagonal = matriz[0][0];
    
    // Cálculo da diagonal principal
    printf("Elementos da diagonal principal:\n");
    for (int i = 0; i < 4; i++) {
        printf("matriz[%d][%d] = %d\n", i, i, matriz[i][i]);
        soma_diagonal += matriz[i][i];
        produto_diagonal *= matriz[i][i];
        
        if (matriz[i][i] > maximo_diagonal) {
            maximo_diagonal = matriz[i][i];
        }
        
        if (matriz[i][i] < minimo_diagonal) {
            minimo_diagonal = matriz[i][i];
        }
    }
    
    // Exibição dos resultados
    printf("\n=== Estatísticas da Diagonal Principal ===\n");
    printf("Soma: %d\n", soma_diagonal);
    printf("Produto: %d\n", produto_diagonal);
    printf("Máximo: %d\n", maximo_diagonal);
    printf("Mínimo: %d\n", minimo_diagonal);
    printf("Média: %.2f\n", (float)soma_diagonal / 4);
    
    // Elementos pares e ímpares da diagonal
    printf("\n=== Análise de Paridade da Diagonal ===\n");
    int pares = 0, impares = 0;
    
    for (int i = 0; i < 4; i++) {
        if (matriz[i][i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    
    printf("Elementos pares: %d\n", pares);
    printf("Elementos ímpares: %d\n", impares);
    
    // Elementos pares da diagonal
    printf("\nElementos pares da diagonal: ");
    for (int i = 0; i < 4; i++) {
        if (matriz[i][i] % 2 == 0) {
            printf("%d ", matriz[i][i]);
        }
    }
    printf("\n");
    
    // Elementos ímpares da diagonal
    printf("Elementos ímpares da diagonal: ");
    for (int i = 0; i < 4; i++) {
        if (matriz[i][i] % 2 != 0) {
            printf("%d ", matriz[i][i]);
        }
    }
    printf("\n");
    
    return 0;
} 