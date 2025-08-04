#include <stdio.h>

// Declarações das funções
void soma(float a, float b, float *resultado);
void subtracao(float a, float b, float *resultado);
void multiplicacao(float a, float b, float *resultado);
void divisao(float a, float b, float *resultado);

int main() {
    float num1, num2, resultado;
    int opcao;
    
    printf("=== Calculadora com Passagem por Referência ===\n\n");
    
    // Entrada de dados
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    
    printf("\nEscolha a operação:\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("5 - Todas as operações\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    printf("\n--- Resultados ---\n");
    
    switch(opcao) {
        case 1:
            soma(num1, num2, &resultado);
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 2:
            subtracao(num1, num2, &resultado);
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 3:
            multiplicacao(num1, num2, &resultado);
            printf("%.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 4:
            if (num2 != 0) {
                divisao(num1, num2, &resultado);
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("Erro: Divisão por zero!\n");
            }
            break;
        case 5:
            // Todas as operações
            soma(num1, num2, &resultado);
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
            
            subtracao(num1, num2, &resultado);
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
            
            multiplicacao(num1, num2, &resultado);
            printf("%.2f * %.2f = %.2f\n", num1, num2, resultado);
            
            if (num2 != 0) {
                divisao(num1, num2, &resultado);
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("Erro: Divisão por zero!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
    }
    
    return 0;
}

// Definição da função soma
void soma(float a, float b, float *resultado) {
    *resultado = a + b;
}

// Definição da função subtração
void subtracao(float a, float b, float *resultado) {
    *resultado = a - b;
}

// Definição da função multiplicação
void multiplicacao(float a, float b, float *resultado) {
    *resultado = a * b;
}

// Definição da função divisão
void divisao(float a, float b, float *resultado) {
    *resultado = a / b;
} 