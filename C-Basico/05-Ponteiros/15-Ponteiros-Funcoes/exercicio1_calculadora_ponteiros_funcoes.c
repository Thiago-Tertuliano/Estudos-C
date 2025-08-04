#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ponteiros para funções matemáticas
typedef int (*OperacaoInt)(int, int);
typedef float (*OperacaoFloat)(float, float);
typedef double (*OperacaoDouble)(double, double);

// Funções matemáticas básicas
int soma_int(int a, int b) { return a + b; }
int subtracao_int(int a, int b) { return a - b; }
int multiplicacao_int(int a, int b) { return a * b; }
int divisao_int(int a, int b) { return (b != 0) ? a / b : 0; }
int modulo_int(int a, int b) { return (b != 0) ? a % b : 0; }

float soma_float(float a, float b) { return a + b; }
float subtracao_float(float a, float b) { return a - b; }
float multiplicacao_float(float a, float b) { return a * b; }
float divisao_float(float a, float b) { return (b != 0) ? a / b : 0; }

double potencia_double(double a, double b) { return pow(a, b); }
double raiz_double(double a, double b) { return (b != 0) ? pow(a, 1.0/b) : 0; }
double logaritmo_double(double a, double b) { return (a > 0 && b > 0) ? log(a) / log(b) : 0; }

// Funções trigonométricas
double seno(double a, double b) { return sin(a); }
double cosseno(double a, double b) { return cos(a); }
double tangente(double a, double b) { return tan(a); }

// Array de ponteiros para funções inteiras
OperacaoInt operacoes_int[] = {soma_int, subtracao_int, multiplicacao_int, divisao_int, modulo_int};
char *nomes_operacoes_int[] = {"Soma", "Subtração", "Multiplicação", "Divisão", "Módulo"};

// Array de ponteiros para funções float
OperacaoFloat operacoes_float[] = {soma_float, subtracao_float, multiplicacao_float, divisao_float};
char *nomes_operacoes_float[] = {"Soma", "Subtração", "Multiplicação", "Divisão"};

// Array de ponteiros para funções double
OperacaoDouble operacoes_double[] = {potencia_double, raiz_double, logaritmo_double, seno, cosseno, tangente};
char *nomes_operacoes_double[] = {"Potência", "Raiz", "Logaritmo", "Seno", "Cosseno", "Tangente"};

// Função que executa operação inteira
int executar_operacao_int(OperacaoInt operacao, int a, int b) {
    return operacao(a, b);
}

// Função que executa operação float
float executar_operacao_float(OperacaoFloat operacao, float a, float b) {
    return operacao(a, b);
}

// Função que executa operação double
double executar_operacao_double(OperacaoDouble operacao, double a, double b) {
    return operacao(a, b);
}

// Função que calcula múltiplos resultados
void calcular_resultados_multiplos(int a, int b, 
                                 int *soma, int *subtracao, int *multiplicacao, int *divisao) {
    if (soma != NULL) *soma = soma_int(a, b);
    if (subtracao != NULL) *subtracao = subtracao_int(a, b);
    if (multiplicacao != NULL) *multiplicacao = multiplicacao_int(a, b);
    if (divisao != NULL) *divisao = (b != 0) ? divisao_int(a, b) : 0;
}

// Função que valida entrada
int validar_entrada(int *valor, int min, int max) {
    if (valor == NULL) return 0;
    
    if (*valor < min || *valor > max) {
        *valor = (min + max) / 2;
        return 0;  // Inválido
    }
    return 1;  // Válido
}

// Função que retorna ponteiro para função baseado em operação
OperacaoInt selecionar_operacao_int(char operacao) {
    switch (operacao) {
        case '+': return soma_int;
        case '-': return subtracao_int;
        case '*': return multiplicacao_int;
        case '/': return divisao_int;
        case '%': return modulo_int;
        default: return soma_int;
    }
}

// Função que processa array com operação
void processar_array_operacao(int *array, int tamanho, OperacaoInt operacao, int valor) {
    if (array == NULL) return;
    
    for (int i = 0; i < tamanho; i++) {
        array[i] = operacao(array[i], valor);
    }
}

// Função que calcula estatísticas usando ponteiros para funções
void calcular_estatisticas_avancadas(int array[], int tamanho, 
                                   int *min, int *max, int *soma, float *media) {
    if (array == NULL || tamanho <= 0) return;
    
    *min = *max = *soma = array[0];
    
    for (int i = 1; i < tamanho; i++) {
        *min = (*min < array[i]) ? *min : array[i];
        *max = (*max > array[i]) ? *max : array[i];
        *soma += array[i];
    }
    *media = (float)*soma / tamanho;
}

int main() {
    printf("=== Calculadora com Ponteiros para Funções ===\n\n");
    
    int opcao, tipo_operacao;
    int a_int, b_int;
    float a_float, b_float;
    double a_double, b_double;
    
    do {
        printf("=== Menu Principal ===\n");
        printf("1. Operações com Inteiros\n");
        printf("2. Operações com Float\n");
        printf("3. Operações com Double\n");
        printf("4. Múltiplos Resultados\n");
        printf("5. Processamento de Array\n");
        printf("6. Estatísticas Avançadas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                printf("\n=== Operações com Inteiros ===\n");
                printf("Digite o primeiro número: ");
                scanf("%d", &a_int);
                printf("Digite o segundo número: ");
                scanf("%d", &b_int);
                
                printf("\nOperações disponíveis:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s\n", i + 1, nomes_operacoes_int[i]);
                }
                printf("Escolha a operação: ");
                scanf("%d", &tipo_operacao);
                
                if (tipo_operacao >= 1 && tipo_operacao <= 5) {
                    int resultado = executar_operacao_int(operacoes_int[tipo_operacao - 1], a_int, b_int);
                    printf("Resultado: %d\n", resultado);
                } else {
                    printf("Operação inválida!\n");
                }
                break;
            }
            
            case 2: {
                printf("\n=== Operações com Float ===\n");
                printf("Digite o primeiro número: ");
                scanf("%f", &a_float);
                printf("Digite o segundo número: ");
                scanf("%f", &b_float);
                
                printf("\nOperações disponíveis:\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d. %s\n", i + 1, nomes_operacoes_float[i]);
                }
                printf("Escolha a operação: ");
                scanf("%d", &tipo_operacao);
                
                if (tipo_operacao >= 1 && tipo_operacao <= 4) {
                    float resultado = executar_operacao_float(operacoes_float[tipo_operacao - 1], a_float, b_float);
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("Operação inválida!\n");
                }
                break;
            }
            
            case 3: {
                printf("\n=== Operações com Double ===\n");
                printf("Digite o primeiro número: ");
                scanf("%lf", &a_double);
                printf("Digite o segundo número: ");
                scanf("%lf", &b_double);
                
                printf("\nOperações disponíveis:\n");
                for (int i = 0; i < 6; i++) {
                    printf("%d. %s\n", i + 1, nomes_operacoes_double[i]);
                }
                printf("Escolha a operação: ");
                scanf("%d", &tipo_operacao);
                
                if (tipo_operacao >= 1 && tipo_operacao <= 6) {
                    double resultado = executar_operacao_double(operacoes_double[tipo_operacao - 1], a_double, b_double);
                    printf("Resultado: %.4f\n", resultado);
                } else {
                    printf("Operação inválida!\n");
                }
                break;
            }
            
            case 4: {
                printf("\n=== Múltiplos Resultados ===\n");
                printf("Digite o primeiro número: ");
                scanf("%d", &a_int);
                printf("Digite o segundo número: ");
                scanf("%d", &b_int);
                
                int soma, subtracao, multiplicacao, divisao;
                calcular_resultados_multiplos(a_int, b_int, &soma, &subtracao, &multiplicacao, &divisao);
                
                printf("Soma: %d\n", soma);
                printf("Subtração: %d\n", subtracao);
                printf("Multiplicação: %d\n", multiplicacao);
                printf("Divisão: %d\n", divisao);
                break;
            }
            
            case 5: {
                printf("\n=== Processamento de Array ===\n");
                int array[5];
                printf("Digite 5 números:\n");
                for (int i = 0; i < 5; i++) {
                    printf("Número %d: ", i + 1);
                    scanf("%d", &array[i]);
                }
                
                printf("Array original: ");
                for (int i = 0; i < 5; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                
                printf("Escolha a operação para aplicar no array:\n");
                printf("1. Somar 5\n");
                printf("2. Multiplicar por 2\n");
                printf("3. Dividir por 2\n");
                scanf("%d", &tipo_operacao);
                
                OperacaoInt operacao_escolhida;
                int valor_operacao;
                switch (tipo_operacao) {
                    case 1: operacao_escolhida = soma_int; valor_operacao = 5; break;
                    case 2: operacao_escolhida = multiplicacao_int; valor_operacao = 2; break;
                    case 3: operacao_escolhida = divisao_int; valor_operacao = 2; break;
                    default: operacao_escolhida = soma_int; valor_operacao = 0; break;
                }
                
                processar_array_operacao(array, 5, operacao_escolhida, valor_operacao);
                
                printf("Array processado: ");
                for (int i = 0; i < 5; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            }
            
            case 6: {
                printf("\n=== Estatísticas Avançadas ===\n");
                int tamanho;
                printf("Digite o tamanho do array: ");
                scanf("%d", &tamanho);
                
                if (validar_entrada(&tamanho, 1, 20)) {
                    int *array = malloc(tamanho * sizeof(int));
                    if (array != NULL) {
                        printf("Digite %d números:\n", tamanho);
                        for (int i = 0; i < tamanho; i++) {
                            printf("Número %d: ", i + 1);
                            scanf("%d", &array[i]);
                        }
                        
                        int min, max, soma;
                        float media;
                        calcular_estatisticas_avancadas(array, tamanho, &min, &max, &soma, &media);
                        
                        printf("Estatísticas:\n");
                        printf("Mínimo: %d\n", min);
                        printf("Máximo: %d\n", max);
                        printf("Soma: %d\n", soma);
                        printf("Média: %.2f\n", media);
                        
                        free(array);
                    }
                } else {
                    printf("Tamanho inválido! Usando valor padrão: %d\n", tamanho);
                }
                break;
            }
            
            case 0:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
                break;
        }
        
        printf("\n");
        
    } while (opcao != 0);
    
    printf("=== Fim do Programa ===\n");
    
    return 0;
} 