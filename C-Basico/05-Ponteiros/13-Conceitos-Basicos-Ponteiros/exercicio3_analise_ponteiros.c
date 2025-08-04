#include <stdio.h>

// Função para analisar um ponteiro
void analisar_ponteiro(const char *nome, void *ptr, const char *tipo) {
    printf("=== Análise do Ponteiro: %s ===\n", nome);
    printf("   Tipo: %s\n", tipo);
    printf("   Endereço do ponteiro: %p\n", (void*)&ptr);
    printf("   Valor do ponteiro: %p\n", ptr);
    printf("   Tamanho do ponteiro: %zu bytes\n", sizeof(ptr));
    
    if (ptr == NULL) {
        printf("   Status: NULL (não aponta para nada)\n");
    } else {
        printf("   Status: Válido (aponta para endereço válido)\n");
    }
    printf("\n");
}

// Função para comparar dois ponteiros
void comparar_ponteiros(const char *nome1, void *ptr1, const char *nome2, void *ptr2) {
    printf("=== Comparação: %s vs %s ===\n", nome1, nome2);
    printf("   %s: %p\n", nome1, ptr1);
    printf("   %s: %p\n", nome2, ptr2);
    
    if (ptr1 == ptr2) {
        printf("   Resultado: Apontam para o mesmo endereço\n");
    } else if (ptr1 < ptr2) {
        printf("   Resultado: %s vem antes de %s na memória\n", nome1, nome2);
    } else {
        printf("   Resultado: %s vem depois de %s na memória\n", nome1, nome2);
    }
    printf("\n");
}

int main() {
    printf("=== Análise Detalhada de Ponteiros ===\n\n");
    
    // Declaração de variáveis de diferentes tipos
    int numero = 42;
    float decimal = 3.14;
    char caractere = 'A';
    double precisao = 2.71828;
    
    // Declaração de ponteiros
    int *ptr_int = &numero;
    float *ptr_float = &decimal;
    char *ptr_char = &caractere;
    double *ptr_double = &precisao;
    int *ptr_nulo = NULL;
    
    printf("1. Análise Individual dos Ponteiros:\n\n");
    
    analisar_ponteiro("ptr_int", ptr_int, "int*");
    analisar_ponteiro("ptr_float", ptr_float, "float*");
    analisar_ponteiro("ptr_char", ptr_char, "char*");
    analisar_ponteiro("ptr_double", ptr_double, "double*");
    analisar_ponteiro("ptr_nulo", ptr_nulo, "int*");
    
    printf("2. Comparação de Endereços:\n\n");
    
    comparar_ponteiros("ptr_int", ptr_int, "ptr_float", ptr_float);
    comparar_ponteiros("ptr_float", ptr_float, "ptr_char", ptr_char);
    comparar_ponteiros("ptr_char", ptr_char, "ptr_double", ptr_double);
    
    printf("3. Análise de Valores Apontados:\n\n");
    
    printf("   ptr_int aponta para: %d\n", *ptr_int);
    printf("   ptr_float aponta para: %.2f\n", *ptr_float);
    printf("   ptr_char aponta para: %c\n", *ptr_char);
    printf("   ptr_double aponta para: %.5f\n", *ptr_double);
    printf("\n");
    
    printf("4. Demonstração de Ponteiros para Ponteiros:\n\n");
    
    int **ptr_ptr_int = &ptr_int;
    printf("   ptr_int aponta para: %p\n", (void*)ptr_int);
    printf("   ptr_ptr_int aponta para: %p\n", (void*)ptr_ptr_int);
    printf("   *ptr_ptr_int = %p\n", (void*)*ptr_ptr_int);
    printf("   **ptr_ptr_int = %d\n", **ptr_ptr_int);
    printf("\n");
    
    printf("5. Análise de Tamanhos:\n\n");
    
    printf("   Tamanho de int: %zu bytes\n", sizeof(int));
    printf("   Tamanho de float: %zu bytes\n", sizeof(float));
    printf("   Tamanho de char: %zu bytes\n", sizeof(char));
    printf("   Tamanho de double: %zu bytes\n", sizeof(double));
    printf("   Tamanho de int*: %zu bytes\n", sizeof(int*));
    printf("   Tamanho de float*: %zu bytes\n", sizeof(float*));
    printf("   Tamanho de char*: %zu bytes\n", sizeof(char*));
    printf("   Tamanho de double*: %zu bytes\n", sizeof(double*));
    printf("\n");
    
    printf("6. Demonstração de Ponteiros Void:\n\n");
    
    void *ptr_void = &numero;
    printf("   ptr_void aponta para: %p\n", ptr_void);
    printf("   *(int*)ptr_void = %d\n", *(int*)ptr_void);
    
    ptr_void = &decimal;
    printf("   ptr_void agora aponta para: %p\n", ptr_void);
    printf("   *(float*)ptr_void = %.2f\n", *(float*)ptr_void);
    printf("\n");
    
    printf("7. Análise de Ponteiros Constantes:\n\n");
    
    const int valor_const = 100;
    const int *ptr_const = &valor_const;
    int *const ptr_const_end = &numero;
    
    printf("   valor_const = %d\n", valor_const);
    printf("   *ptr_const = %d\n", *ptr_const);
    printf("   ptr_const aponta para: %p\n", (void*)ptr_const);
    printf("   ptr_const_end aponta para: %p\n", (void*)ptr_const_end);
    printf("   *ptr_const_end = %d\n", *ptr_const_end);
    printf("\n");
    
    printf("8. Demonstração de Aritmética de Ponteiros:\n\n");
    
    int array[5] = {10, 20, 30, 40, 50};
    int *ptr_array = array;
    
    printf("   Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    printf("   ptr_array aponta para: %p\n", (void*)ptr_array);
    printf("   *ptr_array = %d\n", *ptr_array);
    
    ptr_array++;
    printf("   Após ptr_array++:\n");
    printf("   ptr_array aponta para: %p\n", (void*)ptr_array);
    printf("   *ptr_array = %d\n", *ptr_array);
    
    ptr_array += 2;
    printf("   Após ptr_array += 2:\n");
    printf("   ptr_array aponta para: %p\n", (void*)ptr_array);
    printf("   *ptr_array = %d\n", *ptr_array);
    printf("\n");
    
    printf("9. Verificação de Integridade:\n\n");
    
    printf("   ptr_int é válido? %s\n", (ptr_int != NULL) ? "Sim" : "Não");
    printf("   ptr_float é válido? %s\n", (ptr_float != NULL) ? "Sim" : "Não");
    printf("   ptr_char é válido? %s\n", (ptr_char != NULL) ? "Sim" : "Não");
    printf("   ptr_double é válido? %s\n", (ptr_double != NULL) ? "Sim" : "Não");
    printf("   ptr_nulo é válido? %s\n", (ptr_nulo != NULL) ? "Sim" : "Não");
    printf("\n");
    
    printf("10. Demonstração de Modificação via Ponteiros:\n\n");
    
    printf("   Valores originais:\n");
    printf("   numero = %d\n", numero);
    printf("   decimal = %.2f\n", decimal);
    printf("   caractere = %c\n", caractere);
    printf("   precisao = %.5f\n", precisao);
    printf("\n");
    
    *ptr_int = 100;
    *ptr_float = 2.718;
    *ptr_char = 'Z';
    *ptr_double = 3.14159;
    
    printf("   Após modificação via ponteiros:\n");
    printf("   numero = %d\n", numero);
    printf("   decimal = %.2f\n", decimal);
    printf("   caractere = %c\n", caractere);
    printf("   precisao = %.5f\n", precisao);
    printf("\n");
    
    printf("11. Resumo Final:\n\n");
    
    printf("   Total de ponteiros analisados: 5\n");
    printf("   Ponteiros válidos: 4\n");
    printf("   Ponteiros NULL: 1\n");
    printf("   Tamanho médio de ponteiro: %zu bytes\n", sizeof(void*));
    printf("\n");
    
    printf("=== Fim da Análise ===\n");
    
    return 0;
} 