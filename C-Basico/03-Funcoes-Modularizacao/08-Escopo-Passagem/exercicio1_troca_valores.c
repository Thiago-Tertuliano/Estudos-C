#include <stdio.h>

// Declaração da função
void trocar_valores(int *a, int *b);

int main() {
    int num1, num2;
    
    printf("=== Função de Troca de Valores ===\n\n");
    
    // Entrada de dados
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    
    // Mostrar valores antes da troca
    printf("\nAntes da troca:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    
    // Chamar função de troca
    trocar_valores(&num1, &num2);
    
    // Mostrar valores depois da troca
    printf("\nDepois da troca:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    
    // Testes adicionais
    printf("\n--- Testes Adicionais ---\n");
    
    int a = 10, b = 20;
    printf("Antes: a = %d, b = %d\n", a, b);
    trocar_valores(&a, &b);
    printf("Depois: a = %d, b = %d\n", a, b);
    
    int x = 100, y = 50;
    printf("Antes: x = %d, y = %d\n", x, y);
    trocar_valores(&x, &y);
    printf("Depois: x = %d, y = %d\n", x, y);
    
    return 0;
}

// Definição da função
void trocar_valores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Dentro da função: valores trocados\n");
} 