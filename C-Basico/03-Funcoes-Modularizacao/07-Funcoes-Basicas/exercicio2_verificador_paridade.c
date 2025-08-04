#include <stdio.h>

// Declaração da função
int eh_par(int numero);

int main() {
    int numero;
    
    printf("=== Verificador de Paridade ===\n\n");
    
    // Entrada de dados
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    
    // Chamada da função e verificação do resultado
    if (eh_par(numero)) {
        printf("O número %d é PAR\n", numero);
    } else {
        printf("O número %d é ÍMPAR\n", numero);
    }
    
    // Teste com vários números
    printf("\n--- Testes Adicionais ---\n");
    int numeros_teste[] = {0, 1, 2, 3, 4, 5, 10, 15, 20, 25};
    
    for (int i = 0; i < 10; i++) {
        if (eh_par(numeros_teste[i])) {
            printf("%d é par\n", numeros_teste[i]);
        } else {
            printf("%d é ímpar\n", numeros_teste[i]);
        }
    }
    
    return 0;
}

// Definição da função
int eh_par(int numero) {
    return (numero % 2 == 0);
} 