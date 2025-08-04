#include <stdio.h>

int main() {
    int idades[5];
    float alturas[5];
    char nomes[5][50]; // Array de strings
    
    printf("=== Entrada e Saída de Arrays ===\n\n");
    
    // Entrada de dados
    printf("Digite os dados de 5 pessoas:\n\n");
    
    for (int i = 0; i < 5; i++) {
        printf("--- Pessoa %d ---\n", i + 1);
        
        printf("Nome: ");
        scanf(" %[^\n]", nomes[i]);
        
        printf("Idade: ");
        scanf("%d", &idades[i]);
        
        printf("Altura (metros): ");
        scanf("%f", &alturas[i]);
        
        printf("\n");
    }
    
    // Saída dos dados
    printf("=== Dados Coletados ===\n\n");
    
    for (int i = 0; i < 5; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("  Nome: %s\n", nomes[i]);
        printf("  Idade: %d anos\n", idades[i]);
        printf("  Altura: %.2f metros\n", alturas[i]);
        printf("\n");
    }
    
    // Estatísticas básicas
    int soma_idades = 0;
    float soma_alturas = 0;
    
    for (int i = 0; i < 5; i++) {
        soma_idades += idades[i];
        soma_alturas += alturas[i];
    }
    
    printf("=== Estatísticas ===\n");
    printf("Idade média: %.1f anos\n", (float)soma_idades / 5);
    printf("Altura média: %.2f metros\n", soma_alturas / 5);
    
    return 0;
} 