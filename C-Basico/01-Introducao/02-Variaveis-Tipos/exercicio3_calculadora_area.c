#include <stdio.h>

int main() {
    // Declaração das variáveis para base e altura
    float base = 10.5;
    float altura = 6.0;
    float area, perimetro;
    
    // Cálculo da área do retângulo
    area = base * altura;
    
    // Cálculo do perímetro do retângulo
    perimetro = 2 * (base + altura);
    
    // Exibindo os resultados
    printf("=== CALCULADORA DE ÁREA ===\n");
    printf("Base do retângulo: %.1f unidades\n", base);
    printf("Altura do retângulo: %.1f unidades\n", altura);
    printf("\n");
    printf("Área do retângulo: %.2f unidades²\n", area);
    printf("Perímetro do retângulo: %.2f unidades\n", perimetro);
    printf("==========================\n");
    
    return 0;
} 