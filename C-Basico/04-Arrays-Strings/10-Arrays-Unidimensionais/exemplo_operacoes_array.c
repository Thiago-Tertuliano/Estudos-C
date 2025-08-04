#include <stdio.h>

int main() {
    int valores[8] = {15, 8, 22, 3, 17, 9, 12, 6};
    int soma = 0, maximo = valores[0], minimo = valores[0];
    int pares = 0, impares = 0;
    
    printf("=== Operações com Arrays ===\n\n");
    
    // Exibindo array original
    printf("Array original: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n\n");
    
    // Cálculo de estatísticas
    for (int i = 0; i < 8; i++) {
        // Soma
        soma += valores[i];
        
        // Máximo e mínimo
        if (valores[i] > maximo) maximo = valores[i];
        if (valores[i] < minimo) minimo = valores[i];
        
        // Contagem de pares e ímpares
        if (valores[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    
    // Exibindo resultados
    printf("=== Estatísticas ===\n");
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", (float)soma / 8);
    printf("Máximo: %d\n", maximo);
    printf("Mínimo: %d\n", minimo);
    printf("Quantidade de pares: %d\n", pares);
    printf("Quantidade de ímpares: %d\n", impares);
    
    // Elementos maiores que a média
    float media = (float)soma / 8;
    printf("\nElementos maiores que a média (%.2f):\n", media);
    for (int i = 0; i < 8; i++) {
        if (valores[i] > media) {
            printf("%d ", valores[i]);
        }
    }
    printf("\n");
    
    // Elementos pares
    printf("\nElementos pares:\n");
    for (int i = 0; i < 8; i++) {
        if (valores[i] % 2 == 0) {
            printf("%d ", valores[i]);
        }
    }
    printf("\n");
    
    // Elementos ímpares
    printf("\nElementos ímpares:\n");
    for (int i = 0; i < 8; i++) {
        if (valores[i] % 2 != 0) {
            printf("%d ", valores[i]);
        }
    }
    printf("\n");
    
    return 0;
} 