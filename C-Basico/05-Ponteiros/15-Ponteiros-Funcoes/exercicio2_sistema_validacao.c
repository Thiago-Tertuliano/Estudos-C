#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Ponteiros para funções de validação
typedef int (*ValidadorInt)(int, int, int);
typedef int (*ValidadorFloat)(float, float, float);
typedef int (*ValidadorString)(const char*, int, int);

// Funções de validação para inteiros
int validar_intervalo_int(int valor, int min, int max) {
    return (valor >= min && valor <= max);
}

int validar_par_int(int valor, int min, int max) {
    return (valor % 2 == 0);
}

int validar_impar_int(int valor, int min, int max) {
    return (valor % 2 != 0);
}

int validar_positivo_int(int valor, int min, int max) {
    return (valor > 0);
}

int validar_negativo_int(int valor, int min, int max) {
    return (valor < 0);
}

// Funções de validação para float
int validar_intervalo_float(float valor, float min, float max) {
    return (valor >= min && valor <= max);
}

int validar_positivo_float(float valor, float min, float max) {
    return (valor > 0);
}

int validar_negativo_float(float valor, float min, float max) {
    return (valor < 0);
}

int validar_precisao_float(float valor, float min, float max) {
    return (valor == (int)valor);  // Verifica se é inteiro
}

// Funções de validação para strings
int validar_comprimento_string(const char *str, int min, int max) {
    int len = strlen(str);
    return (len >= min && len <= max);
}

int validar_apenas_letras(const char *str, int min, int max) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) return 0;
    }
    return 1;
}

int validar_apenas_digitos(const char *str, int min, int max) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int validar_email(const char *str, int min, int max) {
    int tem_arroba = 0, tem_ponto = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '@') tem_arroba = 1;
        if (str[i] == '.' && tem_arroba) tem_ponto = 1;
    }
    return (tem_arroba && tem_ponto);
}

// Função que valida e ajusta valor
int validar_e_ajustar_int(int *valor, int min, int max, ValidadorInt validador) {
    if (valor == NULL) return 0;
    
    if (!validador(*valor, min, max)) {
        // Ajustar valor baseado no tipo de validação
        if (*valor < min) *valor = min;
        else if (*valor > max) *valor = max;
        else if (validador == validar_par_int && *valor % 2 != 0) *valor += 1;
        else if (validador == validar_impar_int && *valor % 2 == 0) *valor += 1;
        else if (validador == validar_positivo_int && *valor <= 0) *valor = 1;
        else if (validador == validar_negativo_int && *valor >= 0) *valor = -1;
        
        return 0;  // Inválido, mas ajustado
    }
    return 1;  // Válido
}

// Função que valida e ajusta float
int validar_e_ajustar_float(float *valor, float min, float max, ValidadorFloat validador) {
    if (valor == NULL) return 0;
    
    if (!validador(*valor, min, max)) {
        // Ajustar valor baseado no tipo de validação
        if (*valor < min) *valor = min;
        else if (*valor > max) *valor = max;
        else if (validador == validar_positivo_float && *valor <= 0) *valor = 0.1;
        else if (validador == validar_negativo_float && *valor >= 0) *valor = -0.1;
        else if (validador == validar_precisao_float && *valor != (int)*valor) *valor = (int)*valor;
        
        return 0;  // Inválido, mas ajustado
    }
    return 1;  // Válido
}

// Função que valida string
int validar_string(const char *str, int min, int max, ValidadorString validador) {
    if (str == NULL) return 0;
    return validador(str, min, max);
}

// Função que valida múltiplos campos
void validar_formulario(int *idade, float *altura, char *nome, char *email) {
    printf("=== Validação de Formulário ===\n");
    
    // Validar idade
    if (validar_e_ajustar_int(idade, 0, 120, validar_intervalo_int)) {
        printf("Idade válida: %d\n", *idade);
    } else {
        printf("Idade ajustada para: %d\n", *idade);
    }
    
    // Validar altura
    if (validar_e_ajustar_float(altura, 0.5, 2.5, validar_intervalo_float)) {
        printf("Altura válida: %.2f\n", *altura);
    } else {
        printf("Altura ajustada para: %.2f\n", *altura);
    }
    
    // Validar nome
    if (validar_string(nome, 2, 50, validar_comprimento_string) && 
        validar_string(nome, 0, 0, validar_apenas_letras)) {
        printf("Nome válido: %s\n", nome);
    } else {
        printf("Nome inválido: %s\n", nome);
    }
    
    // Validar email
    if (validar_string(email, 5, 100, validar_comprimento_string) && 
        validar_string(email, 0, 0, validar_email)) {
        printf("Email válido: %s\n", email);
    } else {
        printf("Email inválido: %s\n", email);
    }
}

// Função que valida array de valores
void validar_array_valores(int *array, int tamanho, int min, int max, ValidadorInt validador) {
    if (array == NULL) return;
    
    printf("Validando array de %d elementos:\n", tamanho);
    int validos = 0, ajustados = 0;
    
    for (int i = 0; i < tamanho; i++) {
        int valor_original = array[i];
        if (validar_e_ajustar_int(&array[i], min, max, validador)) {
            validos++;
        } else {
            ajustados++;
            printf("  Posição %d: %d -> %d\n", i, valor_original, array[i]);
        }
    }
    
    printf("Resultado: %d válidos, %d ajustados\n", validos, ajustados);
}

// Função que retorna ponteiro para função de validação
ValidadorInt selecionar_validador_int(int tipo) {
    switch (tipo) {
        case 1: return validar_intervalo_int;
        case 2: return validar_par_int;
        case 3: return validar_impar_int;
        case 4: return validar_positivo_int;
        case 5: return validar_negativo_int;
        default: return validar_intervalo_int;
    }
}

// Função que valida dados de entrada do usuário
void validar_entrada_usuario() {
    int idade, opcao;
    float altura;
    char nome[51], email[101];
    
    printf("=== Validação de Entrada do Usuário ===\n");
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);
    
    printf("Digite seu nome: ");
    scanf(" %50[^\n]", nome);
    
    printf("Digite seu email: ");
    scanf(" %100[^\n]", email);
    
    printf("\nEscolha o tipo de validação para idade:\n");
    printf("1. Intervalo (0-120)\n");
    printf("2. Número par\n");
    printf("3. Número ímpar\n");
    printf("4. Positivo\n");
    printf("5. Negativo\n");
    scanf("%d", &opcao);
    
    ValidadorInt validador_escolhido = selecionar_validador_int(opcao);
    
    printf("\nResultados da validação:\n");
    
    if (validar_e_ajustar_int(&idade, 0, 120, validador_escolhido)) {
        printf("Idade válida: %d\n", idade);
    } else {
        printf("Idade ajustada para: %d\n", idade);
    }
    
    if (validar_e_ajustar_float(&altura, 0.5, 2.5, validar_intervalo_float)) {
        printf("Altura válida: %.2f\n", altura);
    } else {
        printf("Altura ajustada para: %.2f\n", altura);
    }
    
    if (validar_string(nome, 2, 50, validar_comprimento_string)) {
        printf("Nome válido: %s\n", nome);
    } else {
        printf("Nome inválido: %s\n", nome);
    }
    
    if (validar_string(email, 5, 100, validar_comprimento_string) && 
        validar_string(email, 0, 0, validar_email)) {
        printf("Email válido: %s\n", email);
    } else {
        printf("Email inválido: %s\n", email);
    }
}

int main() {
    printf("=== Sistema de Validação com Ponteiros ===\n\n");
    
    int opcao;
    
    do {
        printf("=== Menu de Validação ===\n");
        printf("1. Validar Formulário\n");
        printf("2. Validar Array de Valores\n");
        printf("3. Validar Entrada do Usuário\n");
        printf("4. Teste de Validações Específicas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                printf("\n=== Validação de Formulário ===\n");
                int idade = 25;
                float altura = 1.75;
                char nome[] = "João Silva";
                char email[] = "joao@email.com";
                
                validar_formulario(&idade, &altura, nome, email);
                break;
            }
            
            case 2: {
                printf("\n=== Validação de Array ===\n");
                int array[] = {15, -5, 30, 7, 12, 25, 8, 18};
                int tamanho = 8;
                
                printf("Array original: ");
                for (int i = 0; i < tamanho; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                
                printf("Escolha o tipo de validação:\n");
                printf("1. Intervalo (0-30)\n");
                printf("2. Números pares\n");
                printf("3. Números ímpares\n");
                printf("4. Números positivos\n");
                int tipo_validacao;
                scanf("%d", &tipo_validacao);
                
                ValidadorInt validador = selecionar_validador_int(tipo_validacao);
                validar_array_valores(array, tamanho, 0, 30, validador);
                
                printf("Array após validação: ");
                for (int i = 0; i < tamanho; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            }
            
            case 3: {
                printf("\n");
                validar_entrada_usuario();
                break;
            }
            
            case 4: {
                printf("\n=== Teste de Validações Específicas ===\n");
                
                // Teste de validações de string
                const char *testes_string[] = {
                    "abc123", "abcdef", "123456", "teste@email.com", "a@b.c"
                };
                
                printf("Testando validações de string:\n");
                for (int i = 0; i < 5; i++) {
                    printf("'%s':\n", testes_string[i]);
                    printf("  Comprimento (2-10): %s\n", 
                           validar_string(testes_string[i], 2, 10, validar_comprimento_string) ? "Válido" : "Inválido");
                    printf("  Apenas letras: %s\n", 
                           validar_string(testes_string[i], 0, 0, validar_apenas_letras) ? "Válido" : "Inválido");
                    printf("  Apenas dígitos: %s\n", 
                           validar_string(testes_string[i], 0, 0, validar_apenas_digitos) ? "Válido" : "Inválido");
                    printf("  Email: %s\n", 
                           validar_string(testes_string[i], 0, 0, validar_email) ? "Válido" : "Inválido");
                    printf("\n");
                }
                
                // Teste de validações de float
                float testes_float[] = {3.14, -2.5, 0.0, 1.0, 2.7};
                printf("Testando validações de float:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%.2f:\n", testes_float[i]);
                    printf("  Intervalo (0-5): %s\n", 
                           validar_intervalo_float(testes_float[i], 0, 5) ? "Válido" : "Inválido");
                    printf("  Positivo: %s\n", 
                           validar_positivo_float(testes_float[i], 0, 0) ? "Válido" : "Inválido");
                    printf("  Precisão: %s\n", 
                           validar_precisao_float(testes_float[i], 0, 0) ? "Válido" : "Inválido");
                    printf("\n");
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