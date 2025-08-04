#include <stdio.h>

// Função para buscar elemento usando ponteiros
int* buscar_elemento(int *array, int tamanho, int valor) {
    int *ptr = array;
    int *ptr_fim = array + tamanho;
    
    while (ptr < ptr_fim) {
        if (*ptr == valor) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

// Função para buscar todos os elementos iguais
void buscar_todos_elementos(int *array, int tamanho, int valor) {
    int *ptr = array;
    int encontrados = 0;
    
    printf("   Procurando por %d:\n", valor);
    
    for (int i = 0; i < tamanho; i++) {
        if (*ptr == valor) {
            printf("   Encontrado na posição %d (endereço: %p)\n", i, (void*)ptr);
            encontrados++;
        }
        ptr++;
    }
    
    if (encontrados == 0) {
        printf("   Elemento não encontrado\n");
    } else {
        printf("   Total encontrado: %d\n", encontrados);
    }
}

// Função para buscar elemento usando busca binária
int* busca_binaria(int *array, int tamanho, int valor) {
    int *inicio = array;
    int *fim = array + tamanho - 1;
    
    while (inicio <= fim) {
        int *meio = inicio + (fim - inicio) / 2;
        
        if (*meio == valor) {
            return meio;
        } else if (*meio < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return NULL;
}

// Função para ordenar array usando ponteiros
void ordenar_array(int *array, int tamanho) {
    int *ptr1, *ptr2;
    
    for (ptr1 = array; ptr1 < array + tamanho - 1; ptr1++) {
        for (ptr2 = ptr1 + 1; ptr2 < array + tamanho; ptr2++) {
            if (*ptr1 > *ptr2) {
                int temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
            }
        }
    }
}

// Função para imprimir array usando ponteiros
void imprimir_array(int *array, int tamanho) {
    printf("   Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função para imprimir array com endereços
void imprimir_array_com_enderecos(int *array, int tamanho) {
    printf("   Array com endereços:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("   [%d]: %d (endereço: %p)\n", i, array[i], (void*)&array[i]);
    }
}

int main() {
    printf("=== Busca em Array com Ponteiros ===\n\n");
    
    // Declaração de arrays
    int array1[10] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    int array2[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int array3[6] = {1, 3, 5, 7, 9, 11};
    
    printf("1. Busca Linear Simples:\n");
    imprimir_array(array1, 10);
    
    int valor_busca = 8;
    int *resultado = buscar_elemento(array1, 10, valor_busca);
    
    if (resultado != NULL) {
        printf("   Elemento %d encontrado na posição %ld\n", 
               valor_busca, resultado - array1);
    } else {
        printf("   Elemento %d não encontrado\n", valor_busca);
    }
    printf("\n");
    
    printf("2. Busca de Múltiplos Elementos:\n");
    int array_duplicados[10] = {1, 2, 3, 2, 4, 2, 5, 6, 2, 7};
    imprimir_array(array_duplicados, 10);
    
    buscar_todos_elementos(array_duplicados, 10, 2);
    printf("\n");
    
    printf("3. Busca Binária (Array Ordenado):\n");
    imprimir_array(array3, 6);
    
    valor_busca = 7;
    resultado = busca_binaria(array3, 6, valor_busca);
    
    if (resultado != NULL) {
        printf("   Elemento %d encontrado na posição %ld\n", 
               valor_busca, resultado - array3);
    } else {
        printf("   Elemento %d não encontrado\n", valor_busca);
    }
    
    valor_busca = 6;
    resultado = busca_binaria(array3, 6, valor_busca);
    
    if (resultado != NULL) {
        printf("   Elemento %d encontrado na posição %ld\n", 
               valor_busca, resultado - array3);
    } else {
        printf("   Elemento %d não encontrado\n", valor_busca);
    }
    printf("\n");
    
    printf("4. Ordenação e Busca:\n");
    printf("   Array antes da ordenação: ");
    imprimir_array(array1, 10);
    
    ordenar_array(array1, 10);
    printf("   Array depois da ordenação: ");
    imprimir_array(array1, 10);
    
    valor_busca = 5;
    resultado = busca_binaria(array1, 10, valor_busca);
    
    if (resultado != NULL) {
        printf("   Elemento %d encontrado na posição %ld\n", 
               valor_busca, resultado - array1);
    } else {
        printf("   Elemento %d não encontrado\n", valor_busca);
    }
    printf("\n");
    
    printf("5. Análise de Endereços:\n");
    imprimir_array_com_enderecos(array2, 8);
    printf("\n");
    
    printf("6. Busca com Entrada do Usuário:\n");
    int array_usuario[10] = {15, 25, 35, 45, 55, 65, 75, 85, 95, 105};
    imprimir_array(array_usuario, 10);
    
    int valor_usuario;
    printf("   Digite um valor para buscar: ");
    scanf("%d", &valor_usuario);
    
    resultado = buscar_elemento(array_usuario, 10, valor_usuario);
    
    if (resultado != NULL) {
        printf("   Elemento %d encontrado na posição %ld\n", 
               valor_usuario, resultado - array_usuario);
    } else {
        printf("   Elemento %d não encontrado\n", valor_usuario);
    }
    printf("\n");
    
    printf("7. Demonstração de Busca Sequencial:\n");
    int array_seq[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    imprimir_array(array_seq, 12);
    
    printf("   Buscando elementos de 1 a 15:\n");
    for (int i = 1; i <= 15; i++) {
        resultado = buscar_elemento(array_seq, 12, i);
        if (resultado != NULL) {
            printf("   %d: encontrado na posição %ld\n", i, resultado - array_seq);
        } else {
            printf("   %d: não encontrado\n", i);
        }
    }
    printf("\n");
    
    printf("8. Comparação de Métodos de Busca:\n");
    int array_comp[1000];
    int *ptr_comp = array_comp;
    
    // Preencher array
    for (int i = 0; i < 1000; i++) {
        *ptr_comp = i * 2;
        ptr_comp++;
    }
    
    printf("   Array com 1000 elementos (0, 2, 4, ..., 1998)\n");
    
    // Busca linear
    valor_busca = 1000;
    resultado = buscar_elemento(array_comp, 1000, valor_busca);
    
    if (resultado != NULL) {
        printf("   Busca linear: %d encontrado na posição %ld\n", 
               valor_busca, resultado - array_comp);
    } else {
        printf("   Busca linear: %d não encontrado\n", valor_busca);
    }
    
    // Busca binária (array já está ordenado)
    resultado = busca_binaria(array_comp, 1000, valor_busca);
    
    if (resultado != NULL) {
        printf("   Busca binária: %d encontrado na posição %ld\n", 
               valor_busca, resultado - array_comp);
    } else {
        printf("   Busca binária: %d não encontrado\n", valor_busca);
    }
    printf("\n");
    
    printf("9. Demonstração de Ponteiros para Ponteiros:\n");
    int *arrays[] = {array1, array2, array3};
    int tamanhos[] = {10, 8, 6};
    char *nomes[] = {"Array1", "Array2", "Array3"};
    
    for (int i = 0; i < 3; i++) {
        printf("   %s: ", nomes[i]);
        imprimir_array(arrays[i], tamanhos[i]);
        
        valor_busca = 5;
        resultado = buscar_elemento(arrays[i], tamanhos[i], valor_busca);
        
        if (resultado != NULL) {
            printf("   %d encontrado em %s na posição %ld\n", 
                   valor_busca, nomes[i], resultado - arrays[i]);
        } else {
            printf("   %d não encontrado em %s\n", valor_busca, nomes[i]);
        }
    }
    printf("\n");
    
    printf("10. Estatísticas de Busca:\n");
    int array_stats[20] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 
                           21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
    
    imprimir_array(array_stats, 20);
    
    int encontrados = 0;
    int nao_encontrados = 0;
    
    for (int i = 0; i <= 40; i++) {
        resultado = buscar_elemento(array_stats, 20, i);
        if (resultado != NULL) {
            encontrados++;
        } else {
            nao_encontrados++;
        }
    }
    
    printf("   Elementos encontrados: %d\n", encontrados);
    printf("   Elementos não encontrados: %d\n", nao_encontrados);
    printf("   Taxa de sucesso: %.1f%%\n", (float)encontrados / 41 * 100);
    printf("\n");
    
    printf("=== Fim da Busca ===\n");
    
    return 0;
} 