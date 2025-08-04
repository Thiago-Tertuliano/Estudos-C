#include <stdio.h>

int main() {
    float num1, num2;
    char operacao;
    
    printf("=== CALCULADORA ===\n");
    
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);
    
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    
    printf("\nResultado: ");
    
    switch(operacao) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            if(num2 != 0)
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            else
                printf("Erro: Divisão por zero!\n");
            break;
        default:
            printf("Operação inválida!\n");
    }
    
    return 0;
} 