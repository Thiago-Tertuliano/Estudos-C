#include <stdio.h>

// Função para imprimir array usando ponteiros
void imprimir_array(int *ptr, int tamanho) {
    printf("   Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

// Função para preencher array usando ponteiros
void preencher_array(int *ptr, int tamanho, int valor_inicial) {
    for (int i = 0; i < tamanho; i++) {
        *ptr = valor_inicial + i;
        ptr++;
    }
}

// Função para buscar elemento usando ponteiros
int* buscar_elemento(int *ptr, int tamanho, int valor) {
    int *ptr_fim = ptr + tamanho;
    
    while (ptr < ptr_fim) {
        if (*ptr == valor) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

// Função para copiar array usando ponteiros
void copiar_array(int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        *destino = *origem;
        origem++;
        destino++;
    }
}

// Função para inverter array usando ponteiros
void inverter_array(int *ptr, int tamanho) {
    int *inicio = ptr;
    int *fim = ptr + tamanho - 1;
    
    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main() {
    printf("=== Navegação em Arrays com Ponteiros ===\n\n");
    
    // Declaração de arrays
    int array1[10] = {0};
    int array2[10] = {0};
    int array3[5] = {1, 2, 3, 4, 5};
    
    // Ponteiros para os arrays
    int *ptr1 = array1;
    int *ptr2 = array2;
    int *ptr3 = array3;
    
    printf("1. Preenchimento de Array:\n");
    printf("   Array1 antes: ");
    imprimir_array(ptr1, 10);
    
    preencher_array(ptr1, 10, 10);
    printf("   Array1 depois: ");
    imprimir_array(ptr1, 10);
    printf("\n");
    
    printf("2. Cópia de Array:\n");
    printf("   Array2 antes: ");
    imprimir_array(ptr2, 10);
    
    copiar_array(ptr1, ptr2, 10);
    printf("   Array2 depois da cópia: ");
    imprimir_array(ptr2, 10);
    printf("\n");
    
    printf("3. Busca de Elemento:\n");
    printf("   Array3: ");
    imprimir_array(ptr3, 5);
    
    int valor_busca = 3;
    int *resultado = buscar_elemento(ptr3, 5, valor_busca);
    
    if (resultado != NULL) {
        printf("   Elemento %d encontrado na posição %ld\n", valor_busca, resultado - ptr3);
    } else {
        printf("   Elemento %d não encontrado\n", valor_busca);
    }
    
    valor_busca = 10;
    resultado = buscar_elemento(ptr3, 5, valor_busca);
    
    if (resultado != NULL) {
        printf("   Elemento %d encontrado na posição %ld\n", valor_busca, resultado - ptr3);
    } else {
        printf("   Elemento %d não encontrado\n", valor_busca);
    }
    printf("\n");
    
    printf("4. Inversão de Array:\n");
    printf("   Array3 antes da inversão: ");
    imprimir_array(ptr3, 5);
    
    inverter_array(ptr3, 5);
    printf("   Array3 depois da inversão: ");
    imprimir_array(ptr3, 5);
    printf("\n");
    
    printf("5. Navegação Bidirecional:\n");
    int array_bid[6] = {1, 2, 3, 4, 5, 6};
    int *ptr_inicio = array_bid;
    int *ptr_fim = array_bid + 5;
    
    printf("   Array bidirecional: ");
    imprimir_array(ptr_inicio, 6);
    
    printf("   Navegando do início ao fim:\n");
    while (ptr_inicio <= ptr_fim) {
        printf("   %d ", *ptr_inicio);
        ptr_inicio++;
    }
    printf("\n");
    
    printf("   Navegando do fim ao início:\n");
    ptr_fim = array_bid + 5;
    while (ptr_fim >= array_bid) {
        printf("   %d ", *ptr_fim);
        ptr_fim--;
    }
    printf("\n\n");
    
    printf("6. Operações com Múltiplos Ponteiros:\n");
    int array_multi[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int *ptr_par = array_multi;
    int *ptr_impar = array_multi + 1;
    
    printf("   Array original: ");
    imprimir_array(array_multi, 8);
    
    printf("   Elementos pares: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", *ptr_par);
        ptr_par += 2;
    }
    printf("\n");
    
    printf("   Elementos ímpares: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", *ptr_impar);
        ptr_impar += 2;
    }
    printf("\n\n");
    
    printf("7. Modificação Seletiva:\n");
    int array_mod[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr_mod = array_mod;
    
    printf("   Array antes: ");
    imprimir_array(array_mod, 10);
    
    // Multiplicar elementos pares por 2
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            *ptr_mod *= 2;
        }
        ptr_mod++;
    }
    
    printf("   Array depois (pares * 2): ");
    imprimir_array(array_mod, 10);
    printf("\n");
    
    printf("8. Análise de Endereços:\n");
    int array_analise[4] = {100, 200, 300, 400};
    int *ptr_analise = array_analise;
    
    printf("   Endereços e valores:\n");
    for (int i = 0; i < 4; i++) {
        printf("   Posição %d: endereço %p, valor %d\n", 
               i, (void*)ptr_analise, *ptr_analise);
        ptr_analise++;
    }
    printf("\n");
    
    printf("9. Demonstração de Limites:\n");
    int array_limite[5] = {1, 2, 3, 4, 5};
    int *ptr_limite = array_limite;
    int *ptr_fim_limite = array_limite + 5;
    
    printf("   Navegando com verificação de limite:\n");
    while (ptr_limite < ptr_fim_limite) {
        printf("   %d ", *ptr_limite);
        ptr_limite++;
    }
    printf("\n");
    
    printf("   Ponteiro após navegação: %p\n", (void*)ptr_limite);
    printf("   Limite do array: %p\n", (void*)ptr_fim_limite);
    printf("   Ponteiro == limite? %s\n", (ptr_limite == ptr_fim_limite) ? "Sim" : "Não");
    printf("\n");
    
    printf("10. Operações Matemáticas com Ponteiros:\n");
    int array_math[6] = {2, 4, 6, 8, 10, 12};
    int *ptr_math = array_math;
    
    printf("   Array: ");
    imprimir_array(array_math, 6);
    
    // Soma dos elementos
    int soma = 0;
    for (int i = 0; i < 6; i++) {
        soma += *ptr_math;
        ptr_math++;
    }
    printf("   Soma dos elementos: %d\n", soma);
    
    // Média dos elementos
    ptr_math = array_math;
    float media = 0;
    for (int i = 0; i < 6; i++) {
        media += *ptr_math;
        ptr_math++;
    }
    media /= 6;
    printf("   Média dos elementos: %.2f\n", media);
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 