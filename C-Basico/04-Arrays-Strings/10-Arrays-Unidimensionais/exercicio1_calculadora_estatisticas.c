#include <stdio.h>

int main() {
    int numeros[10];
    int soma = 0, maximo, minimo;
    float media;
    
    printf("=== Calculadora de Estatísticas ===\n\n");
    
    // Entrada de dados
    printf("Digite 10 números inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    // Inicialização do máximo e mínimo
    maximo = numeros[0];
    minimo = numeros[0];
    
    // Cálculo das estatísticas
    for (int i = 0; i < 10; i++) {
        soma += numeros[i];
        
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
        
        if (numeros[i] < minimo) {
            minimo = numeros[i];
        }
    }
    
    media = (float)soma / 10;
    
    // Exibição dos resultados
    printf("\n=== Resultados ===\n");
    printf("Números digitados: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", media);
    printf("Máximo: %d\n", maximo);
    printf("Mínimo: %d\n", minimo);
    
    // Números maiores que a média
    printf("\nNúmeros maiores que a média (%.2f):\n", media);
    for (int i = 0; i < 10; i++) {
        if (numeros[i] > media) {
            printf("%d ", numeros[i]);
        }
    }
    printf("\n");
    
    // Números menores que a média
    printf("\nNúmeros menores que a média (%.2f):\n", media);
    for (int i = 0; i < 10; i++) {
        if (numeros[i] < media) {
            printf("%d ", numeros[i]);
        }
    }
    printf("\n");
    
    return 0;
} 