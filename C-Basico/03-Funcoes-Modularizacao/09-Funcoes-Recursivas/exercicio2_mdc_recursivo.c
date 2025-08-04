#include <stdio.h>

// Declaração da função
int mdc_recursivo(int a, int b);

int main() {
    int a, b;
    
    printf("=== Cálculo de MDC Recursivo (Algoritmo de Euclides) ===\n\n");
    
    // Entrada de dados
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    
    // Validação
    if (a == 0 && b == 0) {
        printf("Erro: MDC(0,0) não é definido!\n");
        return 1;
    }
    
    // Cálculo e exibição
    int resultado = mdc_recursivo(a, b);
    printf("\nMDC(%d, %d) = %d\n", a, b, resultado);
    
    // Verificação
    if (a % resultado == 0 && b % resultado == 0) {
        printf("✓ Verificação: %d é realmente divisor comum de %d e %d\n", resultado, a, b);
    }
    
    // Testes adicionais
    printf("\n--- Testes Adicionais ---\n");
    int testes[][2] = {
        {48, 18}, {54, 24}, {72, 36}, {120, 84}, {17, 13}
    };
    
    for (int i = 0; i < 5; i++) {
        int mdc = mdc_recursivo(testes[i][0], testes[i][1]);
        printf("MDC(%d, %d) = %d\n", testes[i][0], testes[i][1], mdc);
    }
    
    return 0;
}

// Definição da função recursiva
int mdc_recursivo(int a, int b) {
    // Caso base
    if (b == 0) {
        return a;
    }
    
    // Caso recursivo (Algoritmo de Euclides)
    return mdc_recursivo(b, a % b);
} 