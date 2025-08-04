#include <stdio.h>

int main() {
    int numero, soma_divisores = 0;
    
    printf("=== VERIFICADOR DE NÚMEROS PERFEITOS ===\n");
    printf("Digite um número para verificar se é perfeito: ");
    scanf("%d", &numero);
    
    if (numero <= 0) {
        printf("Erro: O número deve ser positivo!\n");
        return 1;
    }
    
    printf("\n=== ANÁLISE ===\n");
    printf("Número: %d\n", numero);
    printf("Divisores: ");
    
    // Encontrando e listando os divisores
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            printf("%d", i);
            soma_divisores += i;
            
            // Verificando se não é o último divisor
            if (i < numero / 2) {
                printf(", ");
            }
        }
    }
    
    printf("\nSoma dos divisores: %d\n", soma_divisores);
    
    // Verificando se é perfeito
    if (soma_divisores == numero) {
        printf("\nRESULTADO: %d é um número perfeito!\n", numero);
        printf("Definição: Um número é perfeito quando a soma de seus divisores próprios é igual ao próprio número.\n");
    } else {
        printf("\nRESULTADO: %d não é um número perfeito.\n", numero);
        printf("Para ser perfeito, a soma dos divisores deveria ser %d.\n", numero);
    }
    
    return 0;
} 