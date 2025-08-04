#include <stdio.h>

int main() {
    printf("=== Ponteiros e Múltiplas Variáveis ===\n\n");
    
    // Declaração de variáveis
    int idade = 25;
    float altura = 1.75;
    char genero = 'M';
    double peso = 70.5;
    
    // Ponteiro genérico que pode apontar para diferentes variáveis
    int *ptr_int = NULL;
    float *ptr_float = NULL;
    char *ptr_char = NULL;
    double *ptr_double = NULL;
    
    printf("1. Valores iniciais das variáveis:\n");
    printf("   idade = %d\n", idade);
    printf("   altura = %.2f\n", altura);
    printf("   genero = %c\n", genero);
    printf("   peso = %.1f\n", peso);
    printf("\n");
    
    printf("2. Ponteiro apontando para diferentes variáveis:\n");
    
    // Ponteiro aponta para idade
    ptr_int = &idade;
    printf("   ptr_int aponta para idade:\n");
    printf("   - Endereço: %p\n", (void*)ptr_int);
    printf("   - Valor: %d\n", *ptr_int);
    printf("\n");
    
    // Ponteiro aponta para altura
    ptr_float = &altura;
    printf("   ptr_float aponta para altura:\n");
    printf("   - Endereço: %p\n", (void*)ptr_float);
    printf("   - Valor: %.2f\n", *ptr_float);
    printf("\n");
    
    // Ponteiro aponta para genero
    ptr_char = &genero;
    printf("   ptr_char aponta para genero:\n");
    printf("   - Endereço: %p\n", (void*)ptr_char);
    printf("   - Valor: %c\n", *ptr_char);
    printf("\n");
    
    // Ponteiro aponta para peso
    ptr_double = &peso;
    printf("   ptr_double aponta para peso:\n");
    printf("   - Endereço: %p\n", (void*)ptr_double);
    printf("   - Valor: %.1f\n", *ptr_double);
    printf("\n");
    
    printf("3. Modificando valores via ponteiros:\n");
    
    // Modificando idade
    *ptr_int = 30;
    printf("   *ptr_int = 30: idade = %d\n", idade);
    
    // Modificando altura
    *ptr_float = 1.80;
    printf("   *ptr_float = 1.80: altura = %.2f\n", altura);
    
    // Modificando genero
    *ptr_char = 'F';
    printf("   *ptr_char = 'F': genero = %c\n", genero);
    
    // Modificando peso
    *ptr_double = 65.0;
    printf("   *ptr_double = 65.0: peso = %.1f\n", peso);
    printf("\n");
    
    printf("4. Demonstração de ponteiro que muda de alvo:\n");
    
    int valor1 = 100, valor2 = 200, valor3 = 300;
    int *ptr_dinamico = &valor1;
    
    printf("   Inicialmente ptr_dinamico aponta para valor1:\n");
    printf("   - valor1 = %d\n", valor1);
    printf("   - *ptr_dinamico = %d\n", *ptr_dinamico);
    printf("   - Endereço: %p\n", (void*)ptr_dinamico);
    printf("\n");
    
    // Mudando o ponteiro para valor2
    ptr_dinamico = &valor2;
    printf("   Agora ptr_dinamico aponta para valor2:\n");
    printf("   - valor2 = %d\n", valor2);
    printf("   - *ptr_dinamico = %d\n", *ptr_dinamico);
    printf("   - Endereço: %p\n", (void*)ptr_dinamico);
    printf("\n");
    
    // Mudando o ponteiro para valor3
    ptr_dinamico = &valor3;
    printf("   Agora ptr_dinamico aponta para valor3:\n");
    printf("   - valor3 = %d\n", valor3);
    printf("   - *ptr_dinamico = %d\n", *ptr_dinamico);
    printf("   - Endereço: %p\n", (void*)ptr_dinamico);
    printf("\n");
    
    printf("5. Comparando endereços de memória:\n");
    printf("   Endereço de valor1: %p\n", (void*)&valor1);
    printf("   Endereço de valor2: %p\n", (void*)&valor2);
    printf("   Endereço de valor3: %p\n", (void*)&valor3);
    printf("   ptr_dinamico atual: %p\n", (void*)ptr_dinamico);
    printf("\n");
    
    printf("6. Demonstração de ponteiros para ponteiros:\n");
    
    int numero = 42;
    int *ptr1 = &numero;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    
    printf("   numero = %d\n", numero);
    printf("   *ptr1 = %d\n", *ptr1);
    printf("   **ptr2 = %d\n", **ptr2);
    printf("   ***ptr3 = %d\n", ***ptr3);
    printf("\n");
    
    printf("   Endereços:\n");
    printf("   - &numero = %p\n", (void*)&numero);
    printf("   - ptr1 = %p\n", (void*)ptr1);
    printf("   - ptr2 = %p\n", (void*)ptr2);
    printf("   - ptr3 = %p\n", (void*)ptr3);
    printf("\n");
    
    printf("7. Modificando valor através de múltiplos níveis:\n");
    ***ptr3 = 100;
    printf("   ***ptr3 = 100\n");
    printf("   numero = %d\n", numero);
    printf("   *ptr1 = %d\n", *ptr1);
    printf("   **ptr2 = %d\n", **ptr2);
    printf("   ***ptr3 = %d\n", ***ptr3);
    printf("\n");
    
    printf("8. Demonstração de ponteiros void:\n");
    
    void *ptr_void = &numero;
    printf("   ptr_void aponta para numero\n");
    printf("   Endereço: %p\n", ptr_void);
    printf("   Para acessar o valor, precisamos fazer cast:\n");
    printf("   *(int*)ptr_void = %d\n", *(int*)ptr_void);
    printf("\n");
    
    // Mudando ptr_void para apontar para float
    ptr_void = &altura;
    printf("   ptr_void agora aponta para altura\n");
    printf("   Endereço: %p\n", ptr_void);
    printf("   *(float*)ptr_void = %.2f\n", *(float*)ptr_void);
    printf("\n");
    
    printf("9. Resumo final dos dados pessoais:\n");
    printf("   Idade: %d anos\n", idade);
    printf("   Altura: %.2f m\n", altura);
    printf("   Gênero: %c\n", genero);
    printf("   Peso: %.1f kg\n", peso);
    printf("\n");
    
    printf("10. Verificação de integridade:\n");
    printf("    Todos os ponteiros são válidos? ");
    printf("%s\n", (ptr_int != NULL && ptr_float != NULL && 
                    ptr_char != NULL && ptr_double != NULL) ? "Sim" : "Não");
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 