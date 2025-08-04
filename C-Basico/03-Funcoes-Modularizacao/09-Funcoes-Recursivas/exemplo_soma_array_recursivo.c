#include <stdio.h>

// Declarações das funções
int soma_array_recursivo(int arr[], int n);
void imprimir_array(int arr[], int n);

int main() {
    int n;
    
    printf("=== Soma de Array Recursiva ===\n\n");
    
    // Entrada do tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Erro: Tamanho deve ser positivo!\n");
        return 1;
    }
    
    // Declaração do array
    int arr[100]; // Tamanho máximo para simplificar
    
    // Entrada dos elementos
    printf("Digite os %d elementos do array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Exibição do array
    printf("\nArray digitado: ");
    imprimir_array(arr, n);
    
    // Cálculo da soma
    int soma = soma_array_recursivo(arr, n);
    printf("Soma dos elementos = %d\n", soma);
    
    // Demonstração do processo
    printf("\n--- Demonstração do Processo ---\n");
    for (int i = 1; i <= n; i++) {
        printf("Soma dos primeiros %d elementos = %d\n", 
               i, soma_array_recursivo(arr, i));
    }
    
    return 0;
}

// Definição da função recursiva
int soma_array_recursivo(int arr[], int n) {
    // Caso base
    if (n <= 0) {
        return 0;
    }
    
    // Caso recursivo
    return arr[n - 1] + soma_array_recursivo(arr, n - 1);
}

// Função auxiliar para imprimir array
void imprimir_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
} 