#include <stdio.h>
#include <stdlib.h> // Para malloc e free

// Função que modifica valor via ponteiro
void incrementar(int *ptr) {
    if (ptr != NULL) {
        (*ptr)++;
        printf("   Dentro da função: valor incrementado para %d\n", *ptr);
    }
}

// Função que troca valores via ponteiros
void trocar_valores(int *ptr_a, int *ptr_b) {
    if (ptr_a != NULL && ptr_b != NULL) {
        int temp = *ptr_a;
        *ptr_a = *ptr_b;
        *ptr_b = temp;
        printf("   Dentro da função: valores trocados\n");
    }
}

// Função que calcula múltiplos valores
void calcular_estatisticas(int array[], int tamanho, 
                          int *min, int *max, float *media) {
    if (array == NULL || min == NULL || max == NULL || media == NULL) {
        return;
    }
    
    *min = array[0];
    *max = array[0];
    *media = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] < *min) *min = array[i];
        if (array[i] > *max) *max = array[i];
        *media += array[i];
    }
    *media /= tamanho;
}

// Função que valida entrada
int validar_entrada(int *valor, int min, int max) {
    if (valor == NULL) return 0;
    
    if (*valor < min || *valor > max) {
        *valor = (min + max) / 2;  // Valor padrão
        return 0;  // Inválido
    }
    return 1;  // Válido
}

// Função que processa array via ponteiro
void processar_array(int *array, int tamanho, int multiplicador) {
    if (array == NULL) return;
    
    for (int i = 0; i < tamanho; i++) {
        array[i] *= multiplicador;
    }
}

// Função que retorna ponteiro para maior valor
int* encontrar_maior(int *array, int tamanho) {
    if (array == NULL || tamanho <= 0) return NULL;
    
    int *maior = &array[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > *maior) {
            maior = &array[i];
        }
    }
    return maior;
}

// Função que aloca array dinamicamente
int* criar_array(int tamanho) {
    int *array = malloc(tamanho * sizeof(int));
    if (array != NULL) {
        for (int i = 0; i < tamanho; i++) {
            array[i] = i * 2;
        }
    }
    return array;
}

int main() {
    printf("=== Passagem por Referência ===\n\n");
    
    // Teste 1: Incremento via ponteiro
    printf("1. Incremento via Ponteiro:\n");
    int valor = 10;
    printf("   Antes: valor = %d\n", valor);
    incrementar(&valor);
    printf("   Depois: valor = %d\n", valor);
    printf("\n");
    
    // Teste 2: Troca de valores
    printf("2. Troca de Valores:\n");
    int a = 5, b = 10;
    printf("   Antes: a = %d, b = %d\n", a, b);
    trocar_valores(&a, &b);
    printf("   Depois: a = %d, b = %d\n", a, b);
    printf("\n");
    
    // Teste 3: Múltiplos retornos
    printf("3. Múltiplos Retornos:\n");
    int array[] = {3, 7, 1, 9, 4, 6, 2, 8, 5};
    int tamanho = 9;
    int min, max;
    float media;
    
    printf("   Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    calcular_estatisticas(array, tamanho, &min, &max, &media);
    printf("   Mínimo: %d\n", min);
    printf("   Máximo: %d\n", max);
    printf("   Média: %.2f\n", media);
    printf("\n");
    
    // Teste 4: Validação de entrada
    printf("4. Validação de Entrada:\n");
    int entrada = 15;
    printf("   Entrada: %d\n", entrada);
    
    if (validar_entrada(&entrada, 1, 10)) {
        printf("   Entrada válida: %d\n", entrada);
    } else {
        printf("   Entrada inválida, valor ajustado: %d\n", entrada);
    }
    printf("\n");
    
    // Teste 5: Processamento de array
    printf("5. Processamento de Array:\n");
    int array_processo[] = {1, 2, 3, 4, 5};
    int tamanho_processo = 5;
    
    printf("   Array antes: ");
    for (int i = 0; i < tamanho_processo; i++) {
        printf("%d ", array_processo[i]);
    }
    printf("\n");
    
    processar_array(array_processo, tamanho_processo, 3);
    
    printf("   Array depois (multiplicado por 3): ");
    for (int i = 0; i < tamanho_processo; i++) {
        printf("%d ", array_processo[i]);
    }
    printf("\n\n");
    
    // Teste 6: Retorno de ponteiro
    printf("6. Retorno de Ponteiro:\n");
    int array_busca[] = {3, 7, 1, 9, 4, 6, 2, 8, 5};
    int tamanho_busca = 9;
    
    printf("   Array: ");
    for (int i = 0; i < tamanho_busca; i++) {
        printf("%d ", array_busca[i]);
    }
    printf("\n");
    
    int *maior = encontrar_maior(array_busca, tamanho_busca);
    if (maior != NULL) {
        printf("   Maior valor: %d (posição: %ld)\n", *maior, maior - array_busca);
    }
    printf("\n");
    
    // Teste 7: Alocação dinâmica
    printf("7. Alocação Dinâmica:\n");
    int tamanho_aloc = 5;
    int *array_alocado = criar_array(tamanho_aloc);
    
    if (array_alocado != NULL) {
        printf("   Array alocado: ");
        for (int i = 0; i < tamanho_aloc; i++) {
            printf("%d ", array_alocado[i]);
        }
        printf("\n");
        free(array_alocado);
    } else {
        printf("   Falha na alocação\n");
    }
    printf("\n");
    
    // Teste 8: Ponteiros para ponteiros
    printf("8. Ponteiros para Ponteiros:\n");
    int **ptr_ptr = malloc(sizeof(int*));
    if (ptr_ptr != NULL) {
        *ptr_ptr = malloc(sizeof(int));
        if (*ptr_ptr != NULL) {
            **ptr_ptr = 42;
            printf("   Valor via ponteiro para ponteiro: %d\n", **ptr_ptr);
            free(*ptr_ptr);
        }
        free(ptr_ptr);
    }
    printf("\n");
    
    // Teste 9: Constantes em funções
    printf("9. Constantes em Funções:\n");
    const int array_const[] = {1, 2, 3, 4, 5};
    printf("   Array constante: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array_const[i]);
    }
    printf("\n");
    printf("   (Não pode ser modificado)\n");
    printf("\n");
    
    // Teste 10: Verificação de NULL
    printf("10. Verificação de NULL:\n");
    int *ptr_nulo = NULL;
    printf("   Tentando incrementar ponteiro NULL:\n");
    incrementar(ptr_nulo);
    printf("   (Função detectou ponteiro NULL)\n");
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 