#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura para retornar múltiplos valores
typedef struct {
    int min, max;
    float media;
    int soma;
} Estatisticas;

// Função que retorna múltiplos valores via ponteiros
void calcular_estatisticas_completas(int array[], int tamanho, 
                                    int *min, int *max, float *media, int *soma) {
    if (array == NULL || min == NULL || max == NULL || media == NULL || soma == NULL) {
        return;
    }
    
    *min = array[0];
    *max = array[0];
    *soma = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] < *min) *min = array[i];
        if (array[i] > *max) *max = array[i];
        *soma += array[i];
    }
    *media = (float)*soma / tamanho;
}

// Função que retorna estrutura com múltiplos valores
Estatisticas calcular_estatisticas_estrutura(int array[], int tamanho) {
    Estatisticas stats = {0, 0, 0.0, 0};
    
    if (array == NULL || tamanho <= 0) {
        return stats;
    }
    
    stats.min = array[0];
    stats.max = array[0];
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] < stats.min) stats.min = array[i];
        if (array[i] > stats.max) stats.max = array[i];
        stats.soma += array[i];
    }
    stats.media = (float)stats.soma / tamanho;
    
    return stats;
}

// Função que retorna ponteiro para estrutura
Estatisticas* criar_estatisticas(int array[], int tamanho) {
    Estatisticas *stats = malloc(sizeof(Estatisticas));
    if (stats == NULL) return NULL;
    
    if (array == NULL || tamanho <= 0) {
        stats->min = stats->max = stats->soma = 0;
        stats->media = 0.0;
        return stats;
    }
    
    stats->min = array[0];
    stats->max = array[0];
    stats->soma = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] < stats->min) stats->min = array[i];
        if (array[i] > stats->max) stats->max = array[i];
        stats->soma += array[i];
    }
    stats->media = (float)stats->soma / tamanho;
    
    return stats;
}

// Função que resolve equação quadrática
int resolver_equacao_quadratica(float a, float b, float c, 
                               float *x1, float *x2) {
    if (x1 == NULL || x2 == NULL) return 0;
    
    float discriminante = b * b - 4 * a * c;
    
    if (discriminante < 0) {
        return 0;  // Sem raízes reais
    } else if (discriminante == 0) {
        *x1 = *x2 = -b / (2 * a);
        return 1;  // Uma raiz real
    } else {
        *x1 = (-b + sqrt(discriminante)) / (2 * a);
        *x2 = (-b - sqrt(discriminante)) / (2 * a);
        return 2;  // Duas raízes reais
    }
}

// Função que converte coordenadas cartesianas para polares
void cartesiano_para_polar(float x, float y, float *raio, float *angulo) {
    if (raio == NULL || angulo == NULL) return;
    
    *raio = sqrt(x * x + y * y);
    *angulo = atan2(y, x);
}

// Função que encontra múltiplos elementos em array
void encontrar_elementos(int array[], int tamanho, int valor, 
                        int *primeira_pos, int *ultima_pos, int *quantidade) {
    if (array == NULL || primeira_pos == NULL || ultima_pos == NULL || quantidade == NULL) {
        return;
    }
    
    *primeira_pos = -1;
    *ultima_pos = -1;
    *quantidade = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valor) {
            if (*primeira_pos == -1) {
                *primeira_pos = i;
            }
            *ultima_pos = i;
            (*quantidade)++;
        }
    }
}

// Função que aloca e preenche array
int* criar_array_preenchido(int tamanho, int valor_inicial, int incremento) {
    int *array = malloc(tamanho * sizeof(int));
    if (array == NULL) return NULL;
    
    for (int i = 0; i < tamanho; i++) {
        array[i] = valor_inicial + (i * incremento);
    }
    return array;
}

// Função que retorna múltiplos arrays
void criar_arrays_multiplos(int tamanho, int **array1, int **array2, int **array3) {
    if (array1 == NULL || array2 == NULL || array3 == NULL) return;
    
    *array1 = malloc(tamanho * sizeof(int));
    *array2 = malloc(tamanho * sizeof(int));
    *array3 = malloc(tamanho * sizeof(int));
    
    if (*array1 != NULL && *array2 != NULL && *array3 != NULL) {
        for (int i = 0; i < tamanho; i++) {
            (*array1)[i] = i;
            (*array2)[i] = i * 2;
            (*array3)[i] = i * i;
        }
    }
}

// Função que processa string e retorna estatísticas
void analisar_string(const char *str, int *comprimento, int *vogais, int *consoantes, int *digitos) {
    if (str == NULL || comprimento == NULL || vogais == NULL || consoantes == NULL || digitos == NULL) {
        return;
    }
    
    *comprimento = 0;
    *vogais = 0;
    *consoantes = 0;
    *digitos = 0;
    
    while (*str != '\0') {
        (*comprimento)++;
        
        char c = tolower(*str);
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                (*vogais)++;
            } else {
                (*consoantes)++;
            }
        } else if (c >= '0' && c <= '9') {
            (*digitos)++;
        }
        str++;
    }
}

int main() {
    printf("=== Retorno de Múltiplos Valores ===\n\n");
    
    // Teste 1: Múltiplos valores via ponteiros
    printf("1. Múltiplos Valores via Ponteiros:\n");
    int array[] = {3, 7, 1, 9, 4, 6, 2, 8, 5};
    int tamanho = 9;
    int min, max, soma;
    float media;
    
    printf("   Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    calcular_estatisticas_completas(array, tamanho, &min, &max, &media, &soma);
    printf("   Mínimo: %d\n", min);
    printf("   Máximo: %d\n", max);
    printf("   Média: %.2f\n", media);
    printf("   Soma: %d\n", soma);
    printf("\n");
    
    // Teste 2: Retorno via estrutura
    printf("2. Retorno via Estrutura:\n");
    Estatisticas stats = calcular_estatisticas_estrutura(array, tamanho);
    printf("   Mínimo: %d\n", stats.min);
    printf("   Máximo: %d\n", stats.max);
    printf("   Média: %.2f\n", stats.media);
    printf("   Soma: %d\n", stats.soma);
    printf("\n");
    
    // Teste 3: Retorno via ponteiro para estrutura
    printf("3. Retorno via Ponteiro para Estrutura:\n");
    Estatisticas *ptr_stats = criar_estatisticas(array, tamanho);
    if (ptr_stats != NULL) {
        printf("   Mínimo: %d\n", ptr_stats->min);
        printf("   Máximo: %d\n", ptr_stats->max);
        printf("   Média: %.2f\n", ptr_stats->media);
        printf("   Soma: %d\n", ptr_stats->soma);
        free(ptr_stats);
    }
    printf("\n");
    
    // Teste 4: Equação quadrática
    printf("4. Resolução de Equação Quadrática:\n");
    float a = 1, b = -5, c = 6;
    float x1, x2;
    int num_raizes = resolver_equacao_quadratica(a, b, c, &x1, &x2);
    
    printf("   Equação: %.1fx² + %.1fx + %.1f = 0\n", a, b, c);
    if (num_raizes == 0) {
        printf("   Sem raízes reais\n");
    } else if (num_raizes == 1) {
        printf("   Uma raiz real: x = %.2f\n", x1);
    } else {
        printf("   Duas raízes reais: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    printf("\n");
    
    // Teste 5: Conversão de coordenadas
    printf("5. Conversão de Coordenadas:\n");
    float x = 3, y = 4;
    float raio, angulo;
    
    cartesiano_para_polar(x, y, &raio, &angulo);
    printf("   Coordenadas cartesianas: (%.1f, %.1f)\n", x, y);
    printf("   Coordenadas polares: raio = %.2f, ângulo = %.2f rad\n", raio, angulo);
    printf("\n");
    
    // Teste 6: Busca de múltiplos elementos
    printf("6. Busca de Múltiplos Elementos:\n");
    int array_busca[] = {1, 2, 3, 2, 4, 2, 5, 6, 2, 7};
    int tamanho_busca = 10;
    int primeira_pos, ultima_pos, quantidade;
    
    printf("   Array: ");
    for (int i = 0; i < tamanho_busca; i++) {
        printf("%d ", array_busca[i]);
    }
    printf("\n");
    
    encontrar_elementos(array_busca, tamanho_busca, 2, &primeira_pos, &ultima_pos, &quantidade);
    printf("   Elemento 2: primeira posição = %d, última posição = %d, quantidade = %d\n", 
           primeira_pos, ultima_pos, quantidade);
    printf("\n");
    
    // Teste 7: Criação de array dinâmico
    printf("7. Criação de Array Dinâmico:\n");
    int tamanho_array = 5;
    int *array_dinamico = criar_array_preenchido(tamanho_array, 10, 5);
    
    if (array_dinamico != NULL) {
        printf("   Array criado: ");
        for (int i = 0; i < tamanho_array; i++) {
            printf("%d ", array_dinamico[i]);
        }
        printf("\n");
        free(array_dinamico);
    }
    printf("\n");
    
    // Teste 8: Múltiplos arrays
    printf("8. Criação de Múltiplos Arrays:\n");
    int *array1, *array2, *array3;
    int tamanho_multiplos = 4;
    
    criar_arrays_multiplos(tamanho_multiplos, &array1, &array2, &array3);
    
    if (array1 != NULL && array2 != NULL && array3 != NULL) {
        printf("   Array 1: ");
        for (int i = 0; i < tamanho_multiplos; i++) {
            printf("%d ", array1[i]);
        }
        printf("\n");
        
        printf("   Array 2: ");
        for (int i = 0; i < tamanho_multiplos; i++) {
            printf("%d ", array2[i]);
        }
        printf("\n");
        
        printf("   Array 3: ");
        for (int i = 0; i < tamanho_multiplos; i++) {
            printf("%d ", array3[i]);
        }
        printf("\n");
        
        free(array1);
        free(array2);
        free(array3);
    }
    printf("\n");
    
    // Teste 9: Análise de string
    printf("9. Análise de String:\n");
    const char *texto = "Hello World 123!";
    int comprimento, vogais, consoantes, digitos;
    
    analisar_string(texto, &comprimento, &vogais, &consoantes, &digitos);
    printf("   Texto: \"%s\"\n", texto);
    printf("   Comprimento: %d\n", comprimento);
    printf("   Vogais: %d\n", vogais);
    printf("   Consoantes: %d\n", consoantes);
    printf("   Dígitos: %d\n", digitos);
    printf("\n");
    
    // Teste 10: Demonstração de flexibilidade
    printf("10. Demonstração de Flexibilidade:\n");
    int valores[] = {15, 25, 35, 45, 55};
    int tamanho_valores = 5;
    
    // Usando diferentes métodos para a mesma operação
    int min1, max1;
    float media1;
    calcular_estatisticas_completas(valores, tamanho_valores, &min1, &max1, &media1, NULL);
    printf("   Método 1 - Mínimo: %d, Máximo: %d, Média: %.2f\n", min1, max1, media1);
    
    Estatisticas stats2 = calcular_estatisticas_estrutura(valores, tamanho_valores);
    printf("   Método 2 - Mínimo: %d, Máximo: %d, Média: %.2f\n", 
           stats2.min, stats2.max, stats2.media);
    
    Estatisticas *ptr_stats2 = criar_estatisticas(valores, tamanho_valores);
    if (ptr_stats2 != NULL) {
        printf("   Método 3 - Mínimo: %d, Máximo: %d, Média: %.2f\n", 
               ptr_stats2->min, ptr_stats2->max, ptr_stats2->media);
        free(ptr_stats2);
    }
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 