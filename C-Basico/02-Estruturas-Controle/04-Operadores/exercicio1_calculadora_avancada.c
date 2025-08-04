#include <stdio.h>
#include <math.h>

int main() {
    float num1, num2;
    
    printf("=== CALCULADORA AVANÇADA ===\n");
    
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    
    printf("\n=== RESULTADOS ===\n");
    
    // Operações básicas
    printf("Adição: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
    printf("Subtração: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
    printf("Multiplicação: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
    
    if(num2 != 0) {
        printf("Divisão: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
    } else {
        printf("Divisão: Erro - Divisão por zero!\n");
    }
    
    // Potência (usando multiplicação)
    float potencia = 1;
    int expoente = (int)num2;
    for(int i = 0; i < expoente; i++) {
        potencia *= num1;
    }
    printf("Potência: %.2f ^ %.0f = %.2f\n", num1, num2, potencia);
    
    // Raiz quadrada (aproximação)
    if(num1 >= 0) {
        float raiz = num1;
        for(int i = 0; i < 10; i++) {
            raiz = (raiz + num1 / raiz) / 2;
        }
        printf("Raiz quadrada de %.2f = %.2f\n", num1, raiz);
    } else {
        printf("Raiz quadrada: Erro - Número negativo!\n");
    }
    
    // Módulo (para números inteiros)
    if(num2 != 0) {
        int resto = (int)num1 % (int)num2;
        printf("Módulo: %.0f %% %.0f = %d\n", num1, num2, resto);
    } else {
        printf("Módulo: Erro - Divisão por zero!\n");
    }
    
    return 0;
} 