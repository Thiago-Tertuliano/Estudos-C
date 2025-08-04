#include <stdio.h>

// Declaração da função
int potencia(int base, int expoente);

int main() {
    int base, expoente, resultado;
    
    printf("=== Calculadora de Potência ===\n\n");
    
    // Entrada de dados
    printf("Digite a base: ");
    scanf("%d", &base);
    
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    // Validação do expoente
    if (expoente < 0) {
        printf("Erro: Expoente deve ser não negativo!\n");
        return 1;
    }
    
    // Chamada da função
    resultado = potencia(base, expoente);
    
    // Saída do resultado
    printf("\nResultado:\n");
    printf("%d elevado a %d = %d\n", base, expoente, resultado);
    
    // Teste com diferentes valores
    printf("\n--- Testes Adicionais ---\n");
    printf("2^0 = %d\n", potencia(2, 0));
    printf("2^1 = %d\n", potencia(2, 1));
    printf("2^2 = %d\n", potencia(2, 2));
    printf("2^3 = %d\n", potencia(2, 3));
    printf("2^4 = %d\n", potencia(2, 4));
    printf("2^5 = %d\n", potencia(2, 5));
    printf("3^3 = %d\n", potencia(3, 3));
    printf("5^2 = %d\n", potencia(5, 2));
    printf("10^3 = %d\n", potencia(10, 3));
    
    return 0;
}

// Definição da função
int potencia(int base, int expoente) {
    int resultado = 1;
    
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    
    return resultado;
} 