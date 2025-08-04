#include <stdio.h>

int main() {
    float lado1, lado2, lado3;
    
    printf("=== VERIFICADOR DE TRIÂNGULO ===\n");
    
    printf("Digite o primeiro lado: ");
    scanf("%f", &lado1);
    
    printf("Digite o segundo lado: ");
    scanf("%f", &lado2);
    
    printf("Digite o terceiro lado: ");
    scanf("%f", &lado3);
    
    // Validando se os lados são positivos
    if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
        printf("Erro: Todos os lados devem ser positivos!\n");
        return 1;
    }
    
    // Verificando se é um triângulo válido
    // A soma de dois lados deve ser maior que o terceiro lado
    if (lado1 + lado2 > lado3 && 
        lado1 + lado3 > lado2 && 
        lado2 + lado3 > lado1) {
        
        printf("\n=== RESULTADO ===\n");
        printf("Lado 1: %.2f\n", lado1);
        printf("Lado 2: %.2f\n", lado2);
        printf("Lado 3: %.2f\n", lado3);
        printf("Status: Triângulo válido\n");
        
        // Classificando o triângulo
        printf("Classificação: ");
        
        if (lado1 == lado2 && lado2 == lado3) {
            printf("Equilátero (todos os lados iguais)\n");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("Isósceles (dois lados iguais)\n");
        } else {
            printf("Escaleno (todos os lados diferentes)\n");
        }
        
        // Verificando se é retângulo
        float a = lado1, b = lado2, c = lado3;
        if (a > b) { float temp = a; a = b; b = temp; }
        if (b > c) { float temp = b; b = c; c = temp; }
        if (a > b) { float temp = a; a = b; b = temp; }
        
        if (a * a + b * b == c * c) {
            printf("Tipo: Triângulo retângulo\n");
        } else {
            printf("Tipo: Triângulo não retângulo\n");
        }
        
    } else {
        printf("\nErro: Não é um triângulo válido!\n");
        printf("A soma de dois lados deve ser maior que o terceiro lado.\n");
    }
    
    return 0;
} 