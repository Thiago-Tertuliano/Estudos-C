#include <stdio.h>

int main() {
    int matriz[3][3];
    int soma = 0, maximo, minimo;
    float media;
    
    printf("=== Calculadora de Estatísticas de Matriz ===\n\n");
    
    // Entrada de dados
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Inicialização do máximo e mínimo
    maximo = matriz[0][0];
    minimo = matriz[0][0];
    
    // Cálculo das estatísticas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += matriz[i][j];
            
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
            
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
            }
        }
    }
    
    media = (float)soma / 9;
    
    // Exibição da matriz
    printf("\nMatriz digitada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Exibição dos resultados
    printf("\n=== Estatísticas ===\n");
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", media);
    printf("Máximo: %d\n", maximo);
    printf("Mínimo: %d\n", minimo);
    
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
    
    return 0;
} 