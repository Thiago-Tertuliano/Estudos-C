#include <stdio.h>

// Declaração da função
int fibonacci_recursivo(int n);

int main() {
    int n;
    
    printf("=== Série de Fibonacci Recursiva ===\n\n");
    
    // Entrada de dados
    printf("Digite quantos termos da série Fibonacci deseja ver: ");
    scanf("%d", &n);
    
    // Validação
    if (n < 0) {
        printf("Erro: Número de termos deve ser não negativo!\n");
        return 1;
    }
    
    if (n > 40) {
        printf("Aviso: Valores muito grandes podem ser lentos!\n");
    }
    
    // Exibição da série
    printf("\nSérie de Fibonacci:\n");
    for (int i = 0; i < n; i++) {
        printf("F(%d) = %d\n", i, fibonacci_recursivo(i));
    }
    
    // Soma dos termos
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += fibonacci_recursivo(i);
    }
    printf("\nSoma dos %d primeiros termos = %d\n", n, soma);
    
    return 0;
}

// Definição da função recursiva
int fibonacci_recursivo(int n) {
    // Casos base
    if (n <= 1) {
        return n;
    }
    
    // Caso recursivo
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
} 