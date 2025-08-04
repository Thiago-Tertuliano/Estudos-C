#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ponteiros para funções matemáticas
typedef double (*FuncaoMatematica)(double);
typedef double (*FuncaoMatematica2)(double, double);
typedef int (*FuncaoInt)(int, int);

// Estrutura para armazenar informações de função
typedef struct {
    char nome[50];
    FuncaoMatematica funcao;
    char descricao[100];
} FuncaoInfo;

// Estrutura para armazenar informações de função com dois parâmetros
typedef struct {
    char nome[50];
    FuncaoMatematica2 funcao;
    char descricao[100];
} FuncaoInfo2;

// Funções matemáticas básicas
double seno(double x) { return sin(x); }
double cosseno(double x) { return cos(x); }
double tangente(double x) { return tan(x); }
double logaritmo(double x) { return (x > 0) ? log(x) : 0; }
double raiz_quadrada(double x) { return (x >= 0) ? sqrt(x) : 0; }
double valor_absoluto(double x) { return fabs(x); }
double exponencial(double x) { return exp(x); }
double potencia_2(double x) { return pow(x, 2); }
double potencia_3(double x) { return pow(x, 3); }
double inverso(double x) { return (x != 0) ? 1.0 / x : 0; }

// Funções matemáticas com dois parâmetros
double soma(double a, double b) { return a + b; }
double subtracao(double a, double b) { return a - b; }
double multiplicacao(double a, double b) { return a * b; }
double divisao(double a, double b) { return (b != 0) ? a / b : 0; }
double potencia(double a, double b) { return pow(a, b); }
double raiz_n(double a, double b) { return (b != 0 && a >= 0) ? pow(a, 1.0/b) : 0; }
double logaritmo_base(double a, double b) { return (a > 0 && b > 0 && b != 1) ? log(a) / log(b) : 0; }
double media(double a, double b) { return (a + b) / 2.0; }
double maximo(double a, double b) { return (a > b) ? a : b; }
double minimo(double a, double b) { return (a < b) ? a : b; }

// Funções inteiras
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mmc(int a, int b) {
    return (a * b) / mdc(a, b);
}

int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Arrays de funções
FuncaoInfo funcoes_unarias[] = {
    {"seno", seno, "Calcula o seno de um ângulo em radianos"},
    {"cosseno", cosseno, "Calcula o cosseno de um ângulo em radianos"},
    {"tangente", tangente, "Calcula a tangente de um ângulo em radianos"},
    {"logaritmo", logaritmo, "Calcula o logaritmo natural"},
    {"raiz_quadrada", raiz_quadrada, "Calcula a raiz quadrada"},
    {"valor_absoluto", valor_absoluto, "Calcula o valor absoluto"},
    {"exponencial", exponencial, "Calcula e elevado ao valor"},
    {"potencia_2", potencia_2, "Eleva o valor ao quadrado"},
    {"potencia_3", potencia_3, "Eleva o valor ao cubo"},
    {"inverso", inverso, "Calcula o inverso (1/x)"}
};

FuncaoInfo2 funcoes_binarias[] = {
    {"soma", soma, "Soma dois números"},
    {"subtracao", subtracao, "Subtrai dois números"},
    {"multiplicacao", multiplicacao, "Multiplica dois números"},
    {"divisao", divisao, "Divide dois números"},
    {"potencia", potencia, "Eleva o primeiro ao segundo"},
    {"raiz_n", raiz_n, "Calcula a raiz n-ésima"},
    {"logaritmo_base", logaritmo_base, "Calcula logaritmo em base específica"},
    {"media", media, "Calcula a média aritmética"},
    {"maximo", maximo, "Retorna o maior valor"},
    {"minimo", minimo, "Retorna o menor valor"}
};

// Função que executa função matemática
double executar_funcao(FuncaoMatematica funcao, double valor) {
    return funcao(valor);
}

// Função que executa função matemática com dois parâmetros
double executar_funcao2(FuncaoMatematica2 funcao, double a, double b) {
    return funcao(a, b);
}

// Função que executa função inteira
int executar_funcao_int(FuncaoInt funcao, int a, int b) {
    return funcao(a, b);
}

// Função que lista todas as funções disponíveis
void listar_funcoes() {
    printf("=== Funções Unárias ===\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - %s\n", i + 1, funcoes_unarias[i].nome, funcoes_unarias[i].descricao);
    }
    
    printf("\n=== Funções Binárias ===\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - %s\n", i + 1, funcoes_binarias[i].nome, funcoes_binarias[i].descricao);
    }
    
    printf("\n=== Funções Inteiras ===\n");
    printf("11. MDC - Máximo Divisor Comum\n");
    printf("12. MMC - Mínimo Múltiplo Comum\n");
    printf("13. Fatorial - Calcula o fatorial\n");
    printf("14. Fibonacci - Calcula o n-ésimo termo\n");
}

// Função que calcula múltiplos resultados
void calcular_resultados_multiplos(double valor, double *sen, double *cos, double *tan, double *log) {
    if (sen != NULL) *sen = seno(valor);
    if (cos != NULL) *cos = cosseno(valor);
    if (tan != NULL) *tan = tangente(valor);
    if (log != NULL) *log = logaritmo(valor);
}

// Função que processa array com função matemática
void processar_array_matematico(double *array, int tamanho, FuncaoMatematica funcao) {
    if (array == NULL) return;
    
    for (int i = 0; i < tamanho; i++) {
        array[i] = funcao(array[i]);
    }
}

// Função que retorna ponteiro para função baseado em nome
FuncaoMatematica buscar_funcao_unaria(const char *nome) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(funcoes_unarias[i].nome, nome) == 0) {
            return funcoes_unarias[i].funcao;
        }
    }
    return NULL;
}

FuncaoMatematica2 buscar_funcao_binaria(const char *nome) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(funcoes_binarias[i].nome, nome) == 0) {
            return funcoes_binarias[i].funcao;
        }
    }
    return NULL;
}

// Função que calcula estatísticas usando funções matemáticas
void calcular_estatisticas_avancadas(double array[], int tamanho, 
                                   double *min, double *max, double *media, double *soma) {
    if (array == NULL || tamanho <= 0) return;
    
    *min = *max = *soma = array[0];
    
    for (int i = 1; i < tamanho; i++) {
        *min = minimo(*min, array[i]);
        *max = maximo(*max, array[i]);
        *soma += array[i];
    }
    *media = *soma / tamanho;
}

int main() {
    printf("=== Biblioteca de Funções Matemáticas ===\n\n");
    
    int opcao, tipo_funcao;
    double valor, a, b;
    int a_int, b_int;
    
    do {
        printf("=== Menu Principal ===\n");
        printf("1. Funções Unárias\n");
        printf("2. Funções Binárias\n");
        printf("3. Funções Inteiras\n");
        printf("4. Múltiplos Resultados\n");
        printf("5. Processamento de Array\n");
        printf("6. Estatísticas Avançadas\n");
        printf("7. Listar Todas as Funções\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                printf("\n=== Funções Unárias ===\n");
                printf("Digite um valor: ");
                scanf("%lf", &valor);
                
                printf("Escolha a função:\n");
                for (int i = 0; i < 10; i++) {
                    printf("%d. %s\n", i + 1, funcoes_unarias[i].nome);
                }
                scanf("%d", &tipo_funcao);
                
                if (tipo_funcao >= 1 && tipo_funcao <= 10) {
                    double resultado = executar_funcao(funcoes_unarias[tipo_funcao - 1].funcao, valor);
                    printf("Resultado: %.6f\n", resultado);
                } else {
                    printf("Função inválida!\n");
                }
                break;
            }
            
            case 2: {
                printf("\n=== Funções Binárias ===\n");
                printf("Digite o primeiro valor: ");
                scanf("%lf", &a);
                printf("Digite o segundo valor: ");
                scanf("%lf", &b);
                
                printf("Escolha a função:\n");
                for (int i = 0; i < 10; i++) {
                    printf("%d. %s\n", i + 1, funcoes_binarias[i].nome);
                }
                scanf("%d", &tipo_funcao);
                
                if (tipo_funcao >= 1 && tipo_funcao <= 10) {
                    double resultado = executar_funcao2(funcoes_binarias[tipo_funcao - 1].funcao, a, b);
                    printf("Resultado: %.6f\n", resultado);
                } else {
                    printf("Função inválida!\n");
                }
                break;
            }
            
            case 3: {
                printf("\n=== Funções Inteiras ===\n");
                printf("Digite o primeiro número: ");
                scanf("%d", &a_int);
                printf("Digite o segundo número: ");
                scanf("%d", &b_int);
                
                printf("Escolha a função:\n");
                printf("1. MDC\n");
                printf("2. MMC\n");
                printf("3. Fatorial (primeiro número)\n");
                printf("4. Fibonacci (primeiro número)\n");
                scanf("%d", &tipo_funcao);
                
                int resultado;
                switch (tipo_funcao) {
                    case 1:
                        resultado = executar_funcao_int(mdc, a_int, b_int);
                        printf("MDC(%d, %d) = %d\n", a_int, b_int, resultado);
                        break;
                    case 2:
                        resultado = executar_funcao_int(mmc, a_int, b_int);
                        printf("MMC(%d, %d) = %d\n", a_int, b_int, resultado);
                        break;
                    case 3:
                        resultado = fatorial(a_int);
                        printf("%d! = %d\n", a_int, resultado);
                        break;
                    case 4:
                        resultado = fibonacci(a_int);
                        printf("Fibonacci(%d) = %d\n", a_int, resultado);
                        break;
                    default:
                        printf("Função inválida!\n");
                        break;
                }
                break;
            }
            
            case 4: {
                printf("\n=== Múltiplos Resultados ===\n");
                printf("Digite um valor: ");
                scanf("%lf", &valor);
                
                double sen, cos, tan, log;
                calcular_resultados_multiplos(valor, &sen, &cos, &tan, &log);
                
                printf("sen(%.2f) = %.6f\n", valor, sen);
                printf("cos(%.2f) = %.6f\n", valor, cos);
                printf("tan(%.2f) = %.6f\n", valor, tan);
                printf("ln(%.2f) = %.6f\n", valor, log);
                break;
            }
            
            case 5: {
                printf("\n=== Processamento de Array ===\n");
                double array[5];
                printf("Digite 5 números:\n");
                for (int i = 0; i < 5; i++) {
                    printf("Número %d: ", i + 1);
                    scanf("%lf", &array[i]);
                }
                
                printf("Array original: ");
                for (int i = 0; i < 5; i++) {
                    printf("%.2f ", array[i]);
                }
                printf("\n");
                
                printf("Escolha a função para aplicar:\n");
                printf("1. Valor absoluto\n");
                printf("2. Raiz quadrada\n");
                printf("3. Potência ao quadrado\n");
                printf("4. Inverso\n");
                scanf("%d", &tipo_funcao);
                
                FuncaoMatematica funcao_escolhida;
                switch (tipo_funcao) {
                    case 1: funcao_escolhida = valor_absoluto; break;
                    case 2: funcao_escolhida = raiz_quadrada; break;
                    case 3: funcao_escolhida = potencia_2; break;
                    case 4: funcao_escolhida = inverso; break;
                    default: funcao_escolhida = valor_absoluto; break;
                }
                
                processar_array_matematico(array, 5, funcao_escolhida);
                
                printf("Array processado: ");
                for (int i = 0; i < 5; i++) {
                    printf("%.2f ", array[i]);
                }
                printf("\n");
                break;
            }
            
            case 6: {
                printf("\n=== Estatísticas Avançadas ===\n");
                int tamanho;
                printf("Digite o tamanho do array: ");
                scanf("%d", &tamanho);
                
                if (tamanho > 0 && tamanho <= 20) {
                    double *array = malloc(tamanho * sizeof(double));
                    if (array != NULL) {
                        printf("Digite %d números:\n", tamanho);
                        for (int i = 0; i < tamanho; i++) {
                            printf("Número %d: ", i + 1);
                            scanf("%lf", &array[i]);
                        }
                        
                        double min, max, media, soma;
                        calcular_estatisticas_avancadas(array, tamanho, &min, &max, &media, &soma);
                        
                        printf("Estatísticas:\n");
                        printf("Mínimo: %.2f\n", min);
                        printf("Máximo: %.2f\n", max);
                        printf("Média: %.2f\n", media);
                        printf("Soma: %.2f\n", soma);
                        
                        free(array);
                    }
                } else {
                    printf("Tamanho inválido!\n");
                }
                break;
            }
            
            case 7: {
                printf("\n");
                listar_funcoes();
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