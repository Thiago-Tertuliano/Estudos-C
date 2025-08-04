#include <stdio.h>

// Declaração da função
float calcular_area_retangulo(float base, float altura);

int main() {
    float base, altura, area;
    
    printf("=== Calculadora de Área de Retângulo ===\n\n");
    
    // Entrada de dados
    printf("Digite a base do retângulo: ");
    scanf("%f", &base);
    
    printf("Digite a altura do retângulo: ");
    scanf("%f", &altura);
    
    // Chamada da função
    area = calcular_area_retangulo(base, altura);
    
    // Saída do resultado
    printf("\nResultado:\n");
    printf("Base: %.2f\n", base);
    printf("Altura: %.2f\n", altura);
    printf("Área do retângulo: %.2f\n", area);
    
    // Teste com valores fixos
    printf("\n--- Testes Adicionais ---\n");
    printf("Área de retângulo 5x3: %.2f\n", calcular_area_retangulo(5.0, 3.0));
    printf("Área de retângulo 10x7: %.2f\n", calcular_area_retangulo(10.0, 7.0));
    printf("Área de retângulo 2.5x4.2: %.2f\n", calcular_area_retangulo(2.5, 4.2));
    
    return 0;
}

// Definição da função
float calcular_area_retangulo(float base, float altura) {
    return base * altura;
} 