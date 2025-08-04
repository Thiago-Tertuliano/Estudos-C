#include <stdio.h>

// Declaração da função
int validar_intervalo(int numero, int minimo, int maximo);

int main() {
    int numero, minimo, maximo;
    
    printf("=== Validador de Intervalo ===\n\n");
    
    // Entrada de dados
    printf("Digite o número a ser validado: ");
    scanf("%d", &numero);
    
    printf("Digite o valor mínimo do intervalo: ");
    scanf("%d", &minimo);
    
    printf("Digite o valor máximo do intervalo: ");
    scanf("%d", &maximo);
    
    // Validação do intervalo
    if (minimo > maximo) {
        printf("Erro: Valor mínimo maior que máximo!\n");
        return 1;
    }
    
    // Chamada da função
    int resultado = validar_intervalo(numero, minimo, maximo);
    
    // Saída do resultado
    printf("\n--- Resultado ---\n");
    printf("Número: %d\n", numero);
    printf("Intervalo: [%d, %d]\n", minimo, maximo);
    
    if (resultado) {
        printf("Status: VÁLIDO ✓\n");
        printf("O número %d está dentro do intervalo [%d, %d]\n", numero, minimo, maximo);
    } else {
        printf("Status: INVÁLIDO ✗\n");
        printf("O número %d está fora do intervalo [%d, %d]\n", numero, minimo, maximo);
    }
    
    // Testes adicionais
    printf("\n--- Testes Adicionais ---\n");
    
    int testes[] = {5, 10, 15, 20, 25};
    int min_teste = 10, max_teste = 20;
    
    printf("Testando números no intervalo [%d, %d]:\n", min_teste, max_teste);
    for (int i = 0; i < 5; i++) {
        if (validar_intervalo(testes[i], min_teste, max_teste)) {
            printf("%d: VÁLIDO\n", testes[i]);
        } else {
            printf("%d: INVÁLIDO\n", testes[i]);
        }
    }
    
    return 0;
}

// Definição da função
int validar_intervalo(int numero, int minimo, int maximo) {
    return (numero >= minimo && numero <= maximo);
} 