#include <stdio.h>

// Declaração da função
int fatorial_recursivo(int n);

int main() {
    int n;
    
    printf("=== Cálculo de Fatorial Recursivo ===\n\n");
    
    // Entrada de dados
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &n);
    
    // Validação
    if (n < 0) {
        printf("Erro: Fatorial não é definido para números negativos!\n");
        return 1;
    }
    
    if (n > 12) {
        printf("Aviso: Valores muito grandes podem causar overflow!\n");
    }
    
    // Cálculo e exibição
    int resultado = fatorial_recursivo(n);
    printf("\nFatorial de %d = %d\n", n, resultado);
    
    // Demonstração do processo
    printf("\n--- Demonstração do Processo ---\n");
    for (int i = 0; i <= n; i++) {
        printf("Fatorial(%d) = %d\n", i, fatorial_recursivo(i));
    }
    
    return 0;
}

// Definição da função recursiva
int fatorial_recursivo(int n) {
    // Caso base
    if (n <= 1) {
        return 1;
    }
    
    // Caso recursivo
    return n * fatorial_recursivo(n - 1);
} 