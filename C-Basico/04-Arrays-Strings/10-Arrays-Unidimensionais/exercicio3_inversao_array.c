#include <stdio.h>

int main() {
    int numeros[6] = {10, 20, 30, 40, 50, 60};
    int invertido[6];
    
    printf("=== Inversão de Array ===\n\n");
    
    // Exibindo array original
    printf("Array original: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    // Invertendo o array
    for (int i = 0; i < 6; i++) {
        invertido[i] = numeros[5 - i];
    }
    
    // Exibindo array invertido
    printf("Array invertido: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", invertido[i]);
    }
    printf("\n\n");
    
    // Demonstração do processo
    printf("=== Demonstração do Processo ===\n");
    printf("Posição original -> Posição invertida:\n");
    for (int i = 0; i < 6; i++) {
        printf("numeros[%d] = %d -> invertido[%d] = %d\n", 
               i, numeros[i], i, invertido[i]);
    }
    
    // Inversão in-place (modificando o array original)
    printf("\n=== Inversão In-Place ===\n");
    printf("Array antes da inversão: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    // Algoritmo de inversão in-place
    for (int i = 0; i < 3; i++) { // Metade do array
        int temp = numeros[i];
        numeros[i] = numeros[5 - i];
        numeros[5 - i] = temp;
    }
    
    printf("Array após inversão: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    // Demonstração das trocas
    printf("\n=== Demonstração das Trocas ===\n");
    int demo[6] = {1, 2, 3, 4, 5, 6};
    
    printf("Array inicial: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", demo[i]);
    }
    printf("\n");
    
    for (int i = 0; i < 3; i++) {
        int temp = demo[i];
        demo[i] = demo[5 - i];
        demo[5 - i] = temp;
        
        printf("Após troca %d: ", i + 1);
        for (int j = 0; j < 6; j++) {
            printf("%d ", demo[j]);
        }
        printf("\n");
    }
    
    return 0;
} 