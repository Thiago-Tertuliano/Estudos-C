#include <stdio.h>

int main() {
    printf("=== Ponteiros Básicos ===\n\n");
    
    // Declaração de variáveis
    int numero = 42;
    float preco = 19.99;
    char letra = 'A';
    
    // Declaração de ponteiros
    int *ptr_int = NULL;
    float *ptr_float = NULL;
    char *ptr_char = NULL;
    
    printf("1. Declaração e Inicialização:\n");
    printf("   Variáveis originais:\n");
    printf("   - numero = %d\n", numero);
    printf("   - preco = %.2f\n", preco);
    printf("   - letra = %c\n", letra);
    printf("   - Ponteiros inicializados com NULL\n\n");
    
    // Inicialização dos ponteiros
    ptr_int = &numero;
    ptr_float = &preco;
    ptr_char = &letra;
    
    printf("2. Após inicialização dos ponteiros:\n");
    printf("   - ptr_int aponta para: %p\n", (void*)ptr_int);
    printf("   - ptr_float aponta para: %p\n", (void*)ptr_float);
    printf("   - ptr_char aponta para: %p\n", (void*)ptr_char);
    printf("\n");
    
    printf("3. Acessando valores via ponteiros:\n");
    printf("   - *ptr_int = %d\n", *ptr_int);
    printf("   - *ptr_float = %.2f\n", *ptr_float);
    printf("   - *ptr_char = %c\n", *ptr_char);
    printf("\n");
    
    printf("4. Comparando acesso direto vs via ponteiro:\n");
    printf("   Acesso direto: numero = %d\n", numero);
    printf("   Via ponteiro: *ptr_int = %d\n", *ptr_int);
    printf("   São iguais? %s\n", (numero == *ptr_int) ? "Sim" : "Não");
    printf("\n");
    
    printf("5. Endereços de memória:\n");
    printf("   Endereço de 'numero': %p\n", (void*)&numero);
    printf("   Valor de 'ptr_int': %p\n", (void*)ptr_int);
    printf("   São iguais? %s\n", (&numero == ptr_int) ? "Sim" : "Não");
    printf("\n");
    
    printf("6. Tamanhos dos ponteiros:\n");
    printf("   Tamanho de ptr_int: %zu bytes\n", sizeof(ptr_int));
    printf("   Tamanho de ptr_float: %zu bytes\n", sizeof(ptr_float));
    printf("   Tamanho de ptr_char: %zu bytes\n", sizeof(ptr_char));
    printf("   Tamanho de int: %zu bytes\n", sizeof(int));
    printf("   Tamanho de float: %zu bytes\n", sizeof(float));
    printf("   Tamanho de char: %zu bytes\n", sizeof(char));
    printf("\n");
    
    printf("7. Modificando valores via ponteiros:\n");
    printf("   Antes: numero = %d\n", numero);
    *ptr_int = 100;
    printf("   Depois de *ptr_int = 100: numero = %d\n", numero);
    
    printf("   Antes: preco = %.2f\n", preco);
    *ptr_float = 29.99;
    printf("   Depois de *ptr_float = 29.99: preco = %.2f\n", preco);
    
    printf("   Antes: letra = %c\n", letra);
    *ptr_char = 'Z';
    printf("   Depois de *ptr_char = 'Z': letra = %c\n", letra);
    printf("\n");
    
    printf("8. Demonstração de ponteiros nulos:\n");
    int *ptr_nulo = NULL;
    printf("   ptr_nulo = %p\n", (void*)ptr_nulo);
    printf("   ptr_nulo é NULL? %s\n", (ptr_nulo == NULL) ? "Sim" : "Não");
    printf("   IMPORTANTE: Nunca desreferenciar um ponteiro NULL!\n");
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 