#include <stdio.h>

int main() {
    float num1, num2, resultado;
    char operacao;
    
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);
    
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    
    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("Erro: Divisão por zero!\n");
            }
            break;
        default:
            printf("Operação inválida!\n");
    }
    
    return 0;
} 