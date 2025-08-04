#include <stdio.h>
#include <stdlib.h>

// Funções matemáticas básicas
int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

int divisao(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    return 0;  // Erro: divisão por zero
}

// Funções de comparação
int comparar_crescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int comparar_decrescente(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Funções de transformação
int dobrar(int valor) {
    return valor * 2;
}

int triplicar(int valor) {
    return valor * 3;
}

int quadrado(int valor) {
    return valor * valor;
}

// Função que executa operação via ponteiro para função
int executar_operacao(int (*operacao)(int, int), int a, int b) {
    return operacao(a, b);
}

// Função que aplica transformação em array
void aplicar_transformacao(int *array, int tamanho, int (*transformacao)(int)) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = transformacao(array[i]);
    }
}

// Função que ordena array usando ponteiro para função
void ordenar_array(int *array, int tamanho, int (*comparar)(const void*, const void*)) {
    // Implementação simples de bubble sort
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (comparar(&array[j], &array[j + 1]) > 0) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Função que processa array com múltiplas operações
void processar_array(int *array, int tamanho, 
                    int (*operacao1)(int, int), 
                    int (*operacao2)(int, int),
                    int valor) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = operacao1(array[i], valor);
        array[i] = operacao2(array[i], valor);
    }
}

// Função que retorna ponteiro para função baseado em operação
int (*selecionar_operacao(char operacao))(int, int) {
    switch (operacao) {
        case '+': return soma;
        case '-': return subtracao;
        case '*': return multiplicacao;
        case '/': return divisao;
        default: return soma;
    }
}

int main() {
    printf("=== Ponteiros para Funções ===\n\n");
    
    // Declaração de ponteiros para funções
    int (*ptr_soma)(int, int) = soma;
    int (*ptr_multiplicacao)(int, int) = multiplicacao;
    
    // Array de ponteiros para funções
    int (*operacoes[])(int, int) = {soma, subtracao, multiplicacao, divisao};
    char *nomes_operacoes[] = {"Soma", "Subtração", "Multiplicação", "Divisão"};
    
    printf("1. Uso Direto de Ponteiros para Funções:\n");
    int a = 10, b = 5;
    printf("   a = %d, b = %d\n", a, b);
    printf("   Soma via ponteiro: %d\n", ptr_soma(a, b));
    printf("   Multiplicação via ponteiro: %d\n", ptr_multiplicacao(a, b));
    printf("\n");
    
    printf("2. Array de Ponteiros para Funções:\n");
    for (int i = 0; i < 4; i++) {
        printf("   %s: %d\n", nomes_operacoes[i], operacoes[i](a, b));
    }
    printf("\n");
    
    printf("3. Função que Executa Operação:\n");
    printf("   Soma: %d\n", executar_operacao(soma, a, b));
    printf("   Subtração: %d\n", executar_operacao(subtracao, a, b));
    printf("   Multiplicação: %d\n", executar_operacao(multiplicacao, a, b));
    printf("   Divisão: %d\n", executar_operacao(divisao, a, b));
    printf("\n");
    
    printf("4. Transformação de Arrays:\n");
    int array_transform[] = {1, 2, 3, 4, 5};
    int tamanho_transform = 5;
    
    printf("   Array original: ");
    for (int i = 0; i < tamanho_transform; i++) {
        printf("%d ", array_transform[i]);
    }
    printf("\n");
    
    // Aplicar diferentes transformações
    int array_temp[5];
    for (int i = 0; i < tamanho_transform; i++) {
        array_temp[i] = array_transform[i];
    }
    
    aplicar_transformacao(array_temp, tamanho_transform, dobrar);
    printf("   Array dobrado: ");
    for (int i = 0; i < tamanho_transform; i++) {
        printf("%d ", array_temp[i]);
    }
    printf("\n");
    
    for (int i = 0; i < tamanho_transform; i++) {
        array_temp[i] = array_transform[i];
    }
    
    aplicar_transformacao(array_temp, tamanho_transform, quadrado);
    printf("   Array ao quadrado: ");
    for (int i = 0; i < tamanho_transform; i++) {
        printf("%d ", array_temp[i]);
    }
    printf("\n\n");
    
    printf("5. Ordenação com Ponteiros para Funções:\n");
    int array_ordenar[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    int tamanho_ordenar = 9;
    
    printf("   Array original: ");
    for (int i = 0; i < tamanho_ordenar; i++) {
        printf("%d ", array_ordenar[i]);
    }
    printf("\n");
    
    // Ordenar crescente
    int array_crescente[9];
    for (int i = 0; i < tamanho_ordenar; i++) {
        array_crescente[i] = array_ordenar[i];
    }
    ordenar_array(array_crescente, tamanho_ordenar, comparar_crescente);
    printf("   Array crescente: ");
    for (int i = 0; i < tamanho_ordenar; i++) {
        printf("%d ", array_crescente[i]);
    }
    printf("\n");
    
    // Ordenar decrescente
    int array_decrescente[9];
    for (int i = 0; i < tamanho_ordenar; i++) {
        array_decrescente[i] = array_ordenar[i];
    }
    ordenar_array(array_decrescente, tamanho_ordenar, comparar_decrescente);
    printf("   Array decrescente: ");
    for (int i = 0; i < tamanho_ordenar; i++) {
        printf("%d ", array_decrescente[i]);
    }
    printf("\n\n");
    
    printf("6. Processamento Múltiplo:\n");
    int array_processo[] = {1, 2, 3, 4, 5};
    int tamanho_processo = 5;
    
    printf("   Array original: ");
    for (int i = 0; i < tamanho_processo; i++) {
        printf("%d ", array_processo[i]);
    }
    printf("\n");
    
    processar_array(array_processo, tamanho_processo, soma, multiplicacao, 2);
    printf("   Array processado (soma + mult por 2): ");
    for (int i = 0; i < tamanho_processo; i++) {
        printf("%d ", array_processo[i]);
    }
    printf("\n\n");
    
    printf("7. Seleção Dinâmica de Operação:\n");
    char operacoes_chars[] = {'+', '-', '*', '/'};
    
    for (int i = 0; i < 4; i++) {
        int (*operacao_selecionada)(int, int) = selecionar_operacao(operacoes_chars[i]);
        printf("   %c: %d\n", operacoes_chars[i], operacao_selecionada(a, b));
    }
    printf("\n");
    
    printf("8. Callbacks com Ponteiros para Funções:\n");
    int array_callback[] = {10, 5, 8, 3, 7};
    int tamanho_callback = 5;
    
    printf("   Array antes do callback: ");
    for (int i = 0; i < tamanho_callback; i++) {
        printf("%d ", array_callback[i]);
    }
    printf("\n");
    
    // Aplicar callback de transformação
    aplicar_transformacao(array_callback, tamanho_callback, triplicar);
    
    printf("   Array após callback (triplicado): ");
    for (int i = 0; i < tamanho_callback; i++) {
        printf("%d ", array_callback[i]);
    }
    printf("\n\n");
    
    printf("9. Ponteiros para Funções com Diferentes Tipos:\n");
    // Ponteiro para função que retorna void
    void (*ptr_imprimir)(const char*) = printf;
    
    ptr_imprimir("   Função via ponteiro: Olá, mundo!\n");
    
    // Ponteiro para função que não recebe parâmetros
    int (*ptr_gerar_numero)(void) = rand;
    printf("   Número aleatório: %d\n", ptr_gerar_numero());
    printf("\n");
    
    printf("10. Demonstração de Flexibilidade:\n");
    int (*operacoes_avancadas[])(int, int) = {
        soma, subtracao, multiplicacao, divisao
    };
    
    int valores[] = {20, 4};
    printf("   Valores: %d, %d\n", valores[0], valores[1]);
    
    for (int i = 0; i < 4; i++) {
        printf("   Operação %d: %d\n", i + 1, operacoes_avancadas[i](valores[0], valores[1]));
    }
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 