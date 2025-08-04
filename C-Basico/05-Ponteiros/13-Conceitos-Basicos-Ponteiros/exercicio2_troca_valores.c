#include <stdio.h>

// Função para trocar valores usando ponteiros
void trocar_valores(int *ptr_a, int *ptr_b) {
    if (ptr_a == NULL || ptr_b == NULL) {
        printf("Erro: Ponteiros inválidos!\n");
        return;
    }
    
    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

// Função para trocar valores de diferentes tipos
void trocar_floats(float *ptr_a, float *ptr_b) {
    if (ptr_a == NULL || ptr_b == NULL) {
        printf("Erro: Ponteiros inválidos!\n");
        return;
    }
    
    float temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

// Função para trocar caracteres
void trocar_chars(char *ptr_a, char *ptr_b) {
    if (ptr_a == NULL || ptr_b == NULL) {
        printf("Erro: Ponteiros inválidos!\n");
        return;
    }
    
    char temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

int main() {
    printf("=== Troca de Valores com Ponteiros ===\n\n");
    
    // Teste 1: Troca de inteiros
    printf("1. Troca de Valores Inteiros:\n");
    int a = 10, b = 20;
    int *ptr_a = &a;
    int *ptr_b = &b;
    
    printf("   Antes da troca:\n");
    printf("   a = %d (endereço: %p)\n", a, (void*)ptr_a);
    printf("   b = %d (endereço: %p)\n", b, (void*)ptr_b);
    
    trocar_valores(ptr_a, ptr_b);
    
    printf("   Depois da troca:\n");
    printf("   a = %d\n", a);
    printf("   b = %d\n", b);
    printf("\n");
    
    // Teste 2: Troca de floats
    printf("2. Troca de Valores Float:\n");
    float x = 3.14, y = 2.71;
    float *ptr_x = &x;
    float *ptr_y = &y;
    
    printf("   Antes da troca:\n");
    printf("   x = %.2f (endereço: %p)\n", x, (void*)ptr_x);
    printf("   y = %.2f (endereço: %p)\n", y, (void*)ptr_y);
    
    trocar_floats(ptr_x, ptr_y);
    
    printf("   Depois da troca:\n");
    printf("   x = %.2f\n", x);
    printf("   y = %.2f\n", y);
    printf("\n");
    
    // Teste 3: Troca de caracteres
    printf("3. Troca de Caracteres:\n");
    char c1 = 'A', c2 = 'Z';
    char *ptr_c1 = &c1;
    char *ptr_c2 = &c2;
    
    printf("   Antes da troca:\n");
    printf("   c1 = %c (endereço: %p)\n", c1, (void*)ptr_c1);
    printf("   c2 = %c (endereço: %p)\n", c2, (void*)ptr_c2);
    
    trocar_chars(ptr_c1, ptr_c2);
    
    printf("   Depois da troca:\n");
    printf("   c1 = %c\n", c1);
    printf("   c2 = %c\n", c2);
    printf("\n");
    
    // Teste 4: Entrada do usuário
    printf("4. Troca com Entrada do Usuário:\n");
    int num1, num2;
    int *ptr_num1 = &num1;
    int *ptr_num2 = &num2;
    
    printf("   Digite o primeiro número: ");
    scanf("%d", ptr_num1);
    
    printf("   Digite o segundo número: ");
    scanf("%d", ptr_num2);
    
    printf("   Antes da troca: num1 = %d, num2 = %d\n", num1, num2);
    
    trocar_valores(ptr_num1, ptr_num2);
    
    printf("   Depois da troca: num1 = %d, num2 = %d\n", num1, num2);
    printf("\n");
    
    // Teste 5: Troca múltipla
    printf("5. Troca Múltipla:\n");
    int valores[3] = {100, 200, 300};
    int *ptr_v1 = &valores[0];
    int *ptr_v2 = &valores[1];
    int *ptr_v3 = &valores[2];
    
    printf("   Valores iniciais:\n");
    printf("   valores[0] = %d\n", valores[0]);
    printf("   valores[1] = %d\n", valores[1]);
    printf("   valores[2] = %d\n", valores[2]);
    
    // Troca 1 <-> 3
    trocar_valores(ptr_v1, ptr_v3);
    printf("   Após trocar posições 0 e 2:\n");
    printf("   valores[0] = %d\n", valores[0]);
    printf("   valores[1] = %d\n", valores[1]);
    printf("   valores[2] = %d\n", valores[2]);
    
    // Troca 1 <-> 2
    trocar_valores(ptr_v1, ptr_v2);
    printf("   Após trocar posições 0 e 1:\n");
    printf("   valores[0] = %d\n", valores[0]);
    printf("   valores[1] = %d\n", valores[1]);
    printf("   valores[2] = %d\n", valores[2]);
    printf("\n");
    
    // Teste 6: Verificação de ponteiros NULL
    printf("6. Teste com Ponteiros NULL:\n");
    int *ptr_nulo = NULL;
    int valor = 42;
    int *ptr_valor = &valor;
    
    printf("   Tentando trocar com ponteiro NULL:\n");
    trocar_valores(ptr_nulo, ptr_valor);
    printf("   valor permanece: %d\n", valor);
    printf("\n");
    
    // Teste 7: Troca usando ponteiros para ponteiros
    printf("7. Troca usando Ponteiros para Ponteiros:\n");
    int m = 50, n = 60;
    int *ptr_m = &m;
    int *ptr_n = &n;
    int **ptr_ptr_m = &ptr_m;
    int **ptr_ptr_n = &ptr_n;
    
    printf("   Antes da troca:\n");
    printf("   m = %d, n = %d\n", m, n);
    printf("   *ptr_m = %d, *ptr_n = %d\n", *ptr_m, *ptr_n);
    printf("   **ptr_ptr_m = %d, **ptr_ptr_n = %d\n", **ptr_ptr_m, **ptr_ptr_n);
    
    trocar_valores(*ptr_ptr_m, *ptr_ptr_n);
    
    printf("   Depois da troca:\n");
    printf("   m = %d, n = %d\n", m, n);
    printf("   *ptr_m = %d, *ptr_n = %d\n", *ptr_m, *ptr_n);
    printf("   **ptr_ptr_m = %d, **ptr_ptr_n = %d\n", **ptr_ptr_m, **ptr_ptr_n);
    printf("\n");
    
    // Teste 8: Análise de endereços
    printf("8. Análise de Endereços:\n");
    printf("   Endereço de m: %p\n", (void*)&m);
    printf("   Endereço de n: %p\n", (void*)&n);
    printf("   ptr_m aponta para: %p\n", (void*)ptr_m);
    printf("   ptr_n aponta para: %p\n", (void*)ptr_n);
    printf("   ptr_ptr_m aponta para: %p\n", (void*)ptr_ptr_m);
    printf("   ptr_ptr_n aponta para: %p\n", (void*)ptr_ptr_n);
    printf("\n");
    
    printf("=== Fim do Programa ===\n");
    
    return 0;
} 