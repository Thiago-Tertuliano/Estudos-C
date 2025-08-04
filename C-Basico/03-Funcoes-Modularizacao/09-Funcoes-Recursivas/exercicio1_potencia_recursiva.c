#include <stdio.h>

// Declaração da função
int potencia_recursiva(int base, int expoente);

int main() {
    int base, expoente;
    
    printf("=== Cálculo de Potência Recursiva ===\n\n");
    
    // Entrada de dados
    printf("Digite a base: ");
    scanf("%d", &base);
    
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    // Validação
    if (expoente < 0) {
        printf("Erro: Expoente deve ser não negativo!\n");
        return 1;
    }
    
    if (expoente > 30) {
        printf("Aviso: Expoentes muito grandes podem causar overflow!\n");
    }
    
    // Cálculo e exibição
    int resultado = potencia_recursiva(base, expoente);
    printf("\n%d elevado a %d = %d\n", base, expoente, resultado);
    
    // Demonstração do processo
    printf("\n--- Demonstração do Processo ---\n");
    for (int i = 0; i <= expoente; i++) {
        printf("%d^%d = %d\n", base, i, potencia_recursiva(base, i));
    }
    
    // Testes adicionais
    printf("\n--- Testes Adicionais ---\n");
    printf("2^0 = %d\n", potencia_recursiva(2, 0));
    printf("2^1 = %d\n", potencia_recursiva(2, 1));
    printf("2^2 = %d\n", potencia_recursiva(2, 2));
    printf("2^3 = %d\n", potencia_recursiva(2, 3));
    printf("2^4 = %d\n", potencia_recursiva(2, 4));
    printf("2^5 = %d\n", potencia_recursiva(2, 5));
    printf("3^3 = %d\n", potencia_recursiva(3, 3));
    printf("5^2 = %d\n", potencia_recursiva(5, 2));
    
    return 0;
}

// Definição da função recursiva
int potencia_recursiva(int base, int expoente) {
    // Caso base
    if (expoente == 0) {
        return 1;
    }
    
    // Caso recursivo
    return base * potencia_recursiva(base, expoente - 1);
} 