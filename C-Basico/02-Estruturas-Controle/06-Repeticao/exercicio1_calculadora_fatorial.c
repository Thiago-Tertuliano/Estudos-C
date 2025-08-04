#include <stdio.h>

int main() {
    int numero;
    long long fatorial = 1;
    
    printf("=== CALCULADORA DE FATORIAL ===\n");
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);
    
    // Validando se o número é positivo
    if (numero < 0) {
        printf("Erro: O número deve ser positivo!\n");
        return 1;
    }
    
    // Calculando o fatorial
    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }
    
    printf("\n=== RESULTADO ===\n");
    printf("Fatorial de %d = %lld\n", numero, fatorial);
    
    // Mostrando o cálculo
    printf("\nCálculo: ");
    for (int i = 1; i <= numero; i++) {
        printf("%d", i);
        if (i < numero) {
            printf(" x ");
        }
    }
    printf(" = %lld\n", fatorial);
    
    return 0;
} 