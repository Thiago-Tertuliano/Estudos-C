#include <stdio.h>

int main() {
    int matriz[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int soma = 0, maximo = matriz[0][0], minimo = matriz[0][0];
    int soma_diagonal = 0, soma_diagonal_sec = 0;
    
    printf("=== Operações com Matrizes ===\n\n");
    
    // Exibindo matriz
    printf("Matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Cálculo de estatísticas
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            soma += matriz[i][j];
            if (matriz[i][j] > maximo) maximo = matriz[i][j];
            if (matriz[i][j] < minimo) minimo = matriz[i][j];
        }
    }
    
    // Soma das diagonais
    for (int i = 0; i < 4; i++) {
        soma_diagonal += matriz[i][i];
        soma_diagonal_sec += matriz[i][3 - i];
    }
    
    // Exibindo resultados
    printf("=== Estatísticas ===\n");
    printf("Soma total: %d\n", soma);
    printf("Média: %.2f\n", (float)soma / 16);
    printf("Máximo: %d\n", maximo);
    printf("Mínimo: %d\n", minimo);
    printf("Soma diagonal principal: %d\n", soma_diagonal);
    printf("Soma diagonal secundária: %d\n", soma_diagonal_sec);
    
    // Elementos pares e ímpares
    printf("\n=== Análise de Paridade ===\n");
    int pares = 0, impares = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] % 2 == 0) {
                pares++;
            } else {
                impares++;
            }
        }
    }
    
    printf("Elementos pares: %d\n", pares);
    printf("Elementos ímpares: %d\n", impares);
    
    // Maior elemento de cada linha
    printf("\n=== Maior Elemento por Linha ===\n");
    for (int i = 0; i < 4; i++) {
        int maior_linha = matriz[i][0];
        for (int j = 1; j < 4; j++) {
            if (matriz[i][j] > maior_linha) {
                maior_linha = matriz[i][j];
            }
        }
        printf("Linha %d: %d\n", i + 1, maior_linha);
    }
    
    // Menor elemento de cada coluna
    printf("\n=== Menor Elemento por Coluna ===\n");
    for (int j = 0; j < 4; j++) {
        int menor_coluna = matriz[0][j];
        for (int i = 1; i < 4; i++) {
            if (matriz[i][j] < menor_coluna) {
                menor_coluna = matriz[i][j];
            }
        }
        printf("Coluna %d: %d\n", j + 1, menor_coluna);
    }
    
    return 0;
} 