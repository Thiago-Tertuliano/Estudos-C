#include <stdio.h>

int main() {
    int numeros[8] = {15, 8, 22, 3, 17, 9, 12, 6};
    int valor_busca, encontrado = 0, posicao = -1;
    
    printf("=== Busca em Array ===\n\n");
    
    // Exibindo array
    printf("Array disponível: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n\n");
    
    // Entrada do valor a ser buscado
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valor_busca);
    
    // Busca sequencial
    for (int i = 0; i < 8; i++) {
        if (numeros[i] == valor_busca) {
            encontrado = 1;
            posicao = i;
            break; // Encontrou o primeiro
        }
    }
    
    // Exibição do resultado
    printf("\n=== Resultado da Busca ===\n");
    if (encontrado) {
        printf("✓ Valor %d ENCONTRADO!\n", valor_busca);
        printf("Posição: %d (índice %d)\n", posicao + 1, posicao);
    } else {
        printf("✗ Valor %d NÃO ENCONTRADO!\n", valor_busca);
    }
    
    // Busca de todas as ocorrências
    printf("\n=== Todas as Ocorrências ===\n");
    int ocorrencias = 0;
    printf("Posições onde %d aparece: ", valor_busca);
    
    for (int i = 0; i < 8; i++) {
        if (numeros[i] == valor_busca) {
            printf("%d ", i + 1);
            ocorrencias++;
        }
    }
    
    if (ocorrencias == 0) {
        printf("Nenhuma ocorrência encontrada");
    } else {
        printf("\nTotal de ocorrências: %d", ocorrencias);
    }
    printf("\n");
    
    // Valores próximos
    printf("\n=== Valores Próximos ===\n");
    printf("Valores próximos a %d (±2): ", valor_busca);
    for (int i = 0; i < 8; i++) {
        if (numeros[i] >= valor_busca - 2 && numeros[i] <= valor_busca + 2 && numeros[i] != valor_busca) {
            printf("%d ", numeros[i]);
        }
    }
    printf("\n");
    
    return 0;
} 