#include <stdio.h>

// Função para demonstrar operações básicas
void demonstrar_operacoes_basicas() {
    printf("=== Operações Básicas ===\n");
    
    int array[5] = {10, 20, 30, 40, 50};
    int *ptr = array;
    
    printf("Array original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    printf("1. Incremento (++):\n");
    printf("   ptr inicial: %p, valor: %d\n", (void*)ptr, *ptr);
    ptr++;
    printf("   ptr++: %p, valor: %d\n", (void*)ptr, *ptr);
    printf("\n");
    
    printf("2. Decremento (--):\n");
    ptr--;
    printf("   ptr--: %p, valor: %d\n", (void*)ptr, *ptr);
    printf("\n");
    
    printf("3. Adição (+):\n");
    ptr = ptr + 2;
    printf("   ptr + 2: %p, valor: %d\n", (void*)ptr, *ptr);
    printf("\n");
    
    printf("4. Subtração (-):\n");
    ptr = ptr - 1;
    printf("   ptr - 1: %p, valor: %d\n", (void*)ptr, *ptr);
    printf("\n");
    
    printf("5. Diferença entre ponteiros:\n");
    int *ptr_inicio = array;
    int *ptr_fim = &array[4];
    printf("   ptr_inicio: %p, valor: %d\n", (void*)ptr_inicio, *ptr_inicio);
    printf("   ptr_fim: %p, valor: %d\n", (void*)ptr_fim, *ptr_fim);
    printf("   ptr_fim - ptr_inicio: %ld\n", ptr_fim - ptr_inicio);
    printf("\n");
}

// Função para demonstrar comparações
void demonstrar_comparacoes() {
    printf("=== Comparações de Ponteiros ===\n");
    
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr1 = &array[1];
    int *ptr2 = &array[3];
    int *ptr3 = &array[1];
    
    printf("ptr1: %p, valor: %d\n", (void*)ptr1, *ptr1);
    printf("ptr2: %p, valor: %d\n", (void*)ptr2, *ptr2);
    printf("ptr3: %p, valor: %d\n", (void*)ptr3, *ptr3);
    printf("\n");
    
    printf("ptr1 < ptr2? %s\n", (ptr1 < ptr2) ? "Sim" : "Não");
    printf("ptr1 > ptr2? %s\n", (ptr1 > ptr2) ? "Sim" : "Não");
    printf("ptr1 == ptr3? %s\n", (ptr1 == ptr3) ? "Sim" : "Não");
    printf("ptr1 != ptr2? %s\n", (ptr1 != ptr2) ? "Sim" : "Não");
    printf("ptr1 <= ptr2? %s\n", (ptr1 <= ptr2) ? "Sim" : "Não");
    printf("ptr1 >= ptr2? %s\n", (ptr1 >= ptr2) ? "Sim" : "Não");
    printf("\n");
}

// Função para demonstrar diferentes tipos
void demonstrar_tipos_diferentes() {
    printf("=== Diferentes Tipos de Ponteiros ===\n");
    
    int array_int[3] = {100, 200, 300};
    char array_char[3] = {'A', 'B', 'C'};
    float array_float[3] = {1.1, 2.2, 3.3};
    
    int *ptr_int = array_int;
    char *ptr_char = array_char;
    float *ptr_float = array_float;
    
    printf("Tamanhos dos tipos:\n");
    printf("   int: %zu bytes\n", sizeof(int));
    printf("   char: %zu bytes\n", sizeof(char));
    printf("   float: %zu bytes\n", sizeof(float));
    printf("\n");
    
    printf("Incremento por tipo:\n");
    printf("   ptr_int: %p\n", (void*)ptr_int);
    ptr_int++;
    printf("   ptr_int++: %p (avançou %zu bytes)\n", (void*)ptr_int, sizeof(int));
    
    printf("   ptr_char: %p\n", (void*)ptr_char);
    ptr_char++;
    printf("   ptr_char++: %p (avançou %zu bytes)\n", (void*)ptr_char, sizeof(char));
    
    printf("   ptr_float: %p\n", (void*)ptr_float);
    ptr_float++;
    printf("   ptr_float++: %p (avançou %zu bytes)\n", (void*)ptr_float, sizeof(float));
    printf("\n");
}

// Função para demonstrar navegação
void demonstrar_navegacao() {
    printf("=== Navegação com Ponteiros ===\n");
    
    int array[10] = {0};
    int *ptr = array;
    
    // Preencher array
    printf("Preenchendo array:\n");
    for (int i = 0; i < 10; i++) {
        *ptr = i * 10;
        printf("   Posição %d: %d\n", i, *ptr);
        ptr++;
    }
    printf("\n");
    
    // Navegar de volta
    printf("Navegando de volta:\n");
    ptr = array + 9;  // Último elemento
    for (int i = 9; i >= 0; i--) {
        printf("   Posição %d: %d\n", i, *ptr);
        ptr--;
    }
    printf("\n");
    
    // Navegação com saltos
    printf("Navegação com saltos:\n");
    ptr = array;
    for (int i = 0; i < 5; i++) {
        printf("   Posição %d: %d\n", i * 2, *ptr);
        ptr += 2;
    }
    printf("\n");
}

// Função para demonstrar operações matemáticas
void demonstrar_operacoes_matematicas() {
    printf("=== Operações Matemáticas ===\n");
    
    int array[6] = {2, 4, 6, 8, 10, 12};
    int *ptr = array;
    
    printf("Array: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    // Soma
    int soma = 0;
    for (int i = 0; i < 6; i++) {
        soma += *ptr;
        ptr++;
    }
    printf("Soma: %d\n", soma);
    
    // Média
    ptr = array;
    float media = 0;
    for (int i = 0; i < 6; i++) {
        media += *ptr;
        ptr++;
    }
    media /= 6;
    printf("Média: %.2f\n", media);
    
    // Produto
    ptr = array;
    int produto = 1;
    for (int i = 0; i < 6; i++) {
        produto *= *ptr;
        ptr++;
    }
    printf("Produto: %d\n", produto);
    printf("\n");
}

// Função para demonstrar modificações
void demonstrar_modificacoes() {
    printf("=== Modificações via Ponteiros ===\n");
    
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr = array;
    
    printf("Array original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Multiplicar por 2
    for (int i = 0; i < 5; i++) {
        *ptr *= 2;
        ptr++;
    }
    
    printf("Array após multiplicar por 2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Adicionar 10
    ptr = array;
    for (int i = 0; i < 5; i++) {
        *ptr += 10;
        ptr++;
    }
    
    printf("Array após adicionar 10: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

// Função para demonstrar limites
void demonstrar_limites() {
    printf("=== Demonstração de Limites ===\n");
    
    int array[5] = {10, 20, 30, 40, 50};
    int *ptr = array;
    int *ptr_fim = array + 5;
    
    printf("Navegando com verificação de limite:\n");
    while (ptr < ptr_fim) {
        printf("   %d ", *ptr);
        ptr++;
    }
    printf("\n");
    
    printf("Ponteiro após navegação: %p\n", (void*)ptr);
    printf("Limite do array: %p\n", (void*)ptr_fim);
    printf("Ponteiro == limite? %s\n", (ptr == ptr_fim) ? "Sim" : "Não");
    printf("\n");
}

int main() {
    printf("=== Calculadora de Ponteiros ===\n\n");
    
    demonstrar_operacoes_basicas();
    demonstrar_comparacoes();
    demonstrar_tipos_diferentes();
    demonstrar_navegacao();
    demonstrar_operacoes_matematicas();
    demonstrar_modificacoes();
    demonstrar_limites();
    
    printf("=== Resumo das Operações ===\n");
    printf("✓ Incremento (++)\n");
    printf("✓ Decremento (--)\n");
    printf("✓ Adição (+)\n");
    printf("✓ Subtração (-)\n");
    printf("✓ Diferença entre ponteiros\n");
    printf("✓ Comparações (<, >, ==, !=, <=, >=)\n");
    printf("✓ Navegação em arrays\n");
    printf("✓ Modificações via ponteiros\n");
    printf("✓ Verificação de limites\n");
    printf("\n");
    
    printf("=== Fim da Calculadora ===\n");
    
    return 0;
} 