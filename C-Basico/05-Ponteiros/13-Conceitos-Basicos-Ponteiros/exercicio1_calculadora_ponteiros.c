#include <stdio.h>

int main() {
    printf("=== Calculadora com Ponteiros ===\n\n");
    
    // Declaração de variáveis
    float num1, num2;
    float resultado;
    char operacao;
    
    // Declaração de ponteiros
    float *ptr_num1 = &num1;
    float *ptr_num2 = &num2;
    float *ptr_resultado = &resultado;
    
    printf("Digite o primeiro número: ");
    scanf("%f", ptr_num1);
    
    printf("Digite o segundo número: ");
    scanf("%f", ptr_num2);
    
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);
    
    printf("\n=== Resultados ===\n");
    printf("Número 1: %.2f (endereço: %p)\n", *ptr_num1, (void*)ptr_num1);
    printf("Número 2: %.2f (endereço: %p)\n", *ptr_num2, (void*)ptr_num2);
    printf("Operação: %c\n\n", operacao);
    
    // Realizando operações via ponteiros
    switch (operacao) {
        case '+':
            *ptr_resultado = *ptr_num1 + *ptr_num2;
            printf("Soma via ponteiros:\n");
            printf("*ptr_resultado = *ptr_num1 + *ptr_num2\n");
            printf("Resultado: %.2f\n", *ptr_resultado);
            break;
            
        case '-':
            *ptr_resultado = *ptr_num1 - *ptr_num2;
            printf("Subtração via ponteiros:\n");
            printf("*ptr_resultado = *ptr_num1 - *ptr_num2\n");
            printf("Resultado: %.2f\n", *ptr_resultado);
            break;
            
        case '*':
            *ptr_resultado = *ptr_num1 * *ptr_num2;
            printf("Multiplicação via ponteiros:\n");
            printf("*ptr_resultado = *ptr_num1 * *ptr_num2\n");
            printf("Resultado: %.2f\n", *ptr_resultado);
            break;
            
        case '/':
            if (*ptr_num2 != 0) {
                *ptr_resultado = *ptr_num1 / *ptr_num2;
                printf("Divisão via ponteiros:\n");
                printf("*ptr_resultado = *ptr_num1 / *ptr_num2\n");
                printf("Resultado: %.2f\n", *ptr_resultado);
            } else {
                printf("Erro: Divisão por zero!\n");
                return 1;
            }
            break;
            
        default:
            printf("Operação inválida!\n");
            return 1;
    }
    
    printf("\n=== Informações dos Ponteiros ===\n");
    printf("Tamanho de ptr_num1: %zu bytes\n", sizeof(ptr_num1));
    printf("Tamanho de ptr_num2: %zu bytes\n", sizeof(ptr_num2));
    printf("Tamanho de ptr_resultado: %zu bytes\n", sizeof(ptr_resultado));
    printf("Tamanho de float: %zu bytes\n", sizeof(float));
    
    printf("\n=== Verificações ===\n");
    printf("ptr_num1 é NULL? %s\n", (ptr_num1 == NULL) ? "Sim" : "Não");
    printf("ptr_num2 é NULL? %s\n", (ptr_num2 == NULL) ? "Sim" : "Não");
    printf("ptr_resultado é NULL? %s\n", (ptr_resultado == NULL) ? "Sim" : "Não");
    
    printf("\n=== Operações Adicionais ===\n");
    
    // Média dos números
    float media = (*ptr_num1 + *ptr_num2) / 2.0;
    printf("Média dos números: %.2f\n", media);
    
    // Maior valor
    float maior = (*ptr_num1 > *ptr_num2) ? *ptr_num1 : *ptr_num2;
    printf("Maior valor: %.2f\n", maior);
    
    // Menor valor
    float menor = (*ptr_num1 < *ptr_num2) ? *ptr_num1 : *ptr_num2;
    printf("Menor valor: %.2f\n", menor);
    
    // Soma dos quadrados
    float soma_quadrados = (*ptr_num1 * *ptr_num1) + (*ptr_num2 * *ptr_num2);
    printf("Soma dos quadrados: %.2f\n", soma_quadrados);
    
    printf("\n=== Modificações via Ponteiros ===\n");
    printf("Antes: num1 = %.2f, num2 = %.2f\n", num1, num2);
    
    // Incrementando via ponteiros
    (*ptr_num1)++;
    (*ptr_num2)++;
    
    printf("Depois de incremento: num1 = %.2f, num2 = %.2f\n", num1, num2);
    
    // Multiplicando por 2 via ponteiros
    *ptr_num1 *= 2;
    *ptr_num2 *= 2;
    
    printf("Depois de multiplicar por 2: num1 = %.2f, num2 = %.2f\n", num1, num2);
    
    printf("\n=== Fim do Programa ===\n");
    
    return 0;
} 