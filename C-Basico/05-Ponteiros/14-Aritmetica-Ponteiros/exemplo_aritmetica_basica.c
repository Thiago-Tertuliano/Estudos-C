#include <stdio.h>

int main() {
    printf("=== Aritmética Básica de Ponteiros ===\n\n");
    
    // Declaração de arrays de diferentes tipos
    int array_int[5] = {10, 20, 30, 40, 50};
    char array_char[5] = {'A', 'B', 'C', 'D', 'E'};
    float array_float[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    // Ponteiros para os arrays
    int *ptr_int = array_int;
    char *ptr_char = array_char;
    float *ptr_float = array_float;
    
    printf("1. Arrays originais:\n");
    printf("   Array int: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array_int[i]);
    }
    printf("\n");
    
    printf("   Array char: ");
    for (int i = 0; i < 5; i++) {
        printf("%c ", array_char[i]);
    }
    printf("\n");
    
    printf("   Array float: ");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", array_float[i]);
    }
    printf("\n\n");
    
    printf("2. Operações de Incremento:\n");
    printf("   ptr_int inicial: %p, valor: %d\n", (void*)ptr_int, *ptr_int);
    ptr_int++;
    printf("   ptr_int após ++: %p, valor: %d\n", (void*)ptr_int, *ptr_int);
    
    printf("   ptr_char inicial: %p, valor: %c\n", (void*)ptr_char, *ptr_char);
    ptr_char++;
    printf("   ptr_char após ++: %p, valor: %c\n", (void*)ptr_char, *ptr_char);
    
    printf("   ptr_float inicial: %p, valor: %.1f\n", (void*)ptr_float, *ptr_float);
    ptr_float++;
    printf("   ptr_float após ++: %p, valor: %.1f\n", (void*)ptr_float, *ptr_float);
    printf("\n");
    
    printf("3. Operações de Decremento:\n");
    ptr_int--;
    printf("   ptr_int após --: %p, valor: %d\n", (void*)ptr_int, *ptr_int);
    ptr_char--;
    printf("   ptr_char após --: %p, valor: %c\n", (void*)ptr_char, *ptr_char);
    ptr_float--;
    printf("   ptr_float após --: %p, valor: %.1f\n", (void*)ptr_float, *ptr_float);
    printf("\n");
    
    printf("4. Adição de Inteiros:\n");
    printf("   ptr_int atual: %p, valor: %d\n", (void*)ptr_int, *ptr_int);
    ptr_int = ptr_int + 2;
    printf("   ptr_int + 2: %p, valor: %d\n", (void*)ptr_int, *ptr_int);
    
    printf("   ptr_char atual: %p, valor: %c\n", (void*)ptr_char, *ptr_char);
    ptr_char = ptr_char + 3;
    printf("   ptr_char + 3: %p, valor: %c\n", (void*)ptr_char, *ptr_char);
    
    printf("   ptr_float atual: %p, valor: %.1f\n", (void*)ptr_float, *ptr_float);
    ptr_float = ptr_float + 1;
    printf("   ptr_float + 1: %p, valor: %.1f\n", (void*)ptr_float, *ptr_float);
    printf("\n");
    
    printf("5. Subtração de Inteiros:\n");
    ptr_int = ptr_int - 1;
    printf("   ptr_int - 1: %p, valor: %d\n", (void*)ptr_int, *ptr_int);
    ptr_char = ptr_char - 2;
    printf("   ptr_char - 2: %p, valor: %c\n", (void*)ptr_char, *ptr_char);
    ptr_float = ptr_float - 1;
    printf("   ptr_float - 1: %p, valor: %.1f\n", (void*)ptr_float, *ptr_float);
    printf("\n");
    
    printf("6. Diferença entre Ponteiros:\n");
    int *ptr_inicio = array_int;
    int *ptr_fim = &array_int[4];
    
    printf("   ptr_inicio: %p, valor: %d\n", (void*)ptr_inicio, *ptr_inicio);
    printf("   ptr_fim: %p, valor: %d\n", (void*)ptr_fim, *ptr_fim);
    printf("   Diferença (ptr_fim - ptr_inicio): %ld\n", ptr_fim - ptr_inicio);
    printf("\n");
    
    printf("7. Comparações de Ponteiros:\n");
    int *ptr1 = &array_int[1];
    int *ptr2 = &array_int[3];
    
    printf("   ptr1: %p, valor: %d\n", (void*)ptr1, *ptr1);
    printf("   ptr2: %p, valor: %d\n", (void*)ptr2, *ptr2);
    printf("   ptr1 < ptr2? %s\n", (ptr1 < ptr2) ? "Sim" : "Não");
    printf("   ptr1 == ptr2? %s\n", (ptr1 == ptr2) ? "Sim" : "Não");
    printf("   ptr1 != ptr2? %s\n", (ptr1 != ptr2) ? "Sim" : "Não");
    printf("\n");
    
    printf("8. Acesso via Notação de Array:\n");
    printf("   ptr_int[0] = %d\n", ptr_int[0]);
    printf("   ptr_int[1] = %d\n", ptr_int[1]);
    printf("   ptr_int[2] = %d\n", ptr_int[2]);
    printf("\n");
    
    printf("9. Modificação via Ponteiros:\n");
    printf("   Antes: array_int[2] = %d\n", array_int[2]);
    *(ptr_int + 2) = 999;
    printf("   Depois de *(ptr_int + 2) = 999: array_int[2] = %d\n", array_int[2]);
    printf("\n");
    
    printf("10. Navegação Completa do Array:\n");
    int *ptr_nav = array_int;
    printf("   Navegando pelo array int:\n");
    for (int i = 0; i < 5; i++) {
        printf("   Posição %d: %d (endereço: %p)\n", i, *ptr_nav, (void*)ptr_nav);
        ptr_nav++;
    }
    printf("\n");
    
    printf("11. Análise de Tamanhos:\n");
    printf("   Tamanho de int: %zu bytes\n", sizeof(int));
    printf("   Tamanho de char: %zu bytes\n", sizeof(char));
    printf("   Tamanho de float: %zu bytes\n", sizeof(float));
    printf("   Tamanho de int*: %zu bytes\n", sizeof(int*));
    printf("   Tamanho de char*: %zu bytes\n", sizeof(char*));
    printf("   Tamanho de float*: %zu bytes\n", sizeof(float*));
    printf("\n");
    
    printf("12. Demonstração de Incremento por Tipo:\n");
    int *ptr_int_demo = array_int;
    char *ptr_char_demo = array_char;
    
    printf("   ptr_int_demo: %p\n", (void*)ptr_int_demo);
    ptr_int_demo++;
    printf("   ptr_int_demo++: %p (avançou %zu bytes)\n", (void*)ptr_int_demo, sizeof(int));
    
    printf("   ptr_char_demo: %p\n", (void*)ptr_char_demo);
    ptr_char_demo++;
    printf("   ptr_char_demo++: %p (avançou %zu bytes)\n", (void*)ptr_char_demo, sizeof(char));
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 