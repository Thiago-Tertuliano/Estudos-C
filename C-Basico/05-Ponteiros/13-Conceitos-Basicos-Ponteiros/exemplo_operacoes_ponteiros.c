#include <stdio.h>

int main() {
    printf("=== Operações com Ponteiros ===\n\n");
    
    // Declaração de variáveis
    int a = 10, b = 20, c = 30;
    float x = 5.5, y = 10.5;
    
    // Declaração de ponteiros
    int *ptr_a = &a;
    int *ptr_b = &b;
    int *ptr_c = &c;
    float *ptr_x = &x;
    float *ptr_y = &y;
    
    printf("1. Valores iniciais:\n");
    printf("   a = %d, b = %d, c = %d\n", a, b, c);
    printf("   x = %.1f, y = %.1f\n", x, y);
    printf("\n");
    
    printf("2. Operações aritméticas via ponteiros:\n");
    
    // Soma via ponteiros
    *ptr_a = *ptr_a + *ptr_b;
    printf("   *ptr_a = *ptr_a + *ptr_b\n");
    printf("   Resultado: a = %d\n", a);
    
    // Multiplicação via ponteiros
    *ptr_c = *ptr_a * *ptr_b;
    printf("   *ptr_c = *ptr_a * *ptr_b\n");
    printf("   Resultado: c = %d\n", c);
    
    // Operações com floats
    *ptr_x = *ptr_x * 2.0;
    *ptr_y = *ptr_y / 2.0;
    printf("   *ptr_x = *ptr_x * 2.0\n");
    printf("   *ptr_y = *ptr_y / 2.0\n");
    printf("   Resultado: x = %.1f, y = %.1f\n", x, y);
    printf("\n");
    
    printf("3. Incremento e decremento via ponteiros:\n");
    (*ptr_a)++;  // Parênteses são importantes!
    (*ptr_b)--;
    printf("   (*ptr_a)++: a = %d\n", a);
    printf("   (*ptr_b)--: b = %d\n", b);
    printf("\n");
    
    printf("4. Operações de atribuição composta:\n");
    *ptr_a += 5;
    *ptr_b -= 3;
    *ptr_c *= 2;
    printf("   *ptr_a += 5: a = %d\n", a);
    printf("   *ptr_b -= 3: b = %d\n", b);
    printf("   *ptr_c *= 2: c = %d\n", c);
    printf("\n");
    
    printf("5. Comparações usando ponteiros:\n");
    printf("   *ptr_a > *ptr_b? %s\n", (*ptr_a > *ptr_b) ? "Sim" : "Não");
    printf("   *ptr_a == *ptr_b? %s\n", (*ptr_a == *ptr_b) ? "Sim" : "Não");
    printf("   *ptr_x < *ptr_y? %s\n", (*ptr_x < *ptr_y) ? "Sim" : "Não");
    printf("\n");
    
    printf("6. Cálculos complexos com ponteiros:\n");
    // Média de três números
    float media = (*ptr_a + *ptr_b + *ptr_c) / 3.0;
    printf("   Média de a, b, c: %.2f\n", media);
    
    // Soma dos quadrados
    int soma_quadrados = (*ptr_a * *ptr_a) + (*ptr_b * *ptr_b) + (*ptr_c * *ptr_c);
    printf("   Soma dos quadrados: %d\n", soma_quadrados);
    
    // Produto dos floats
    float produto = *ptr_x * *ptr_y;
    printf("   Produto de x e y: %.2f\n", produto);
    printf("\n");
    
    printf("7. Demonstração de ponteiros para ponteiros:\n");
    int **ptr_ptr_a = &ptr_a;  // Ponteiro para ponteiro
    printf("   ptr_a aponta para: %p\n", (void*)ptr_a);
    printf("   ptr_ptr_a aponta para: %p\n", (void*)ptr_ptr_a);
    printf("   **ptr_ptr_a = %d\n", **ptr_ptr_a);
    printf("\n");
    
    printf("8. Operações com ponteiros NULL:\n");
    int *ptr_nulo = NULL;
    printf("   ptr_nulo = %p\n", (void*)ptr_nulo);
    
    // Verificação antes de usar
    if (ptr_nulo != NULL) {
        printf("   *ptr_nulo = %d\n", *ptr_nulo);
    } else {
        printf("   ptr_nulo é NULL - não pode ser desreferenciado\n");
    }
    printf("\n");
    
    printf("9. Demonstração de ponteiros constantes:\n");
    const int valor_constante = 100;
    const int *ptr_const = &valor_constante;
    printf("   valor_constante = %d\n", valor_constante);
    printf("   *ptr_const = %d\n", *ptr_const);
    printf("   ptr_const aponta para: %p\n", (void*)ptr_const);
    printf("   NOTA: Não podemos modificar *ptr_const\n");
    printf("\n");
    
    printf("10. Resumo final dos valores:\n");
    printf("    a = %d, b = %d, c = %d\n", a, b, c);
    printf("    x = %.1f, y = %.1f\n", x, y);
    printf("    Média: %.2f\n", media);
    printf("    Soma dos quadrados: %d\n", soma_quadrados);
    printf("    Produto: %.2f\n", produto);
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 