#include <stdio.h>

int main() {
    float nota;
    
    printf("=== SISTEMA DE NOTAS ===\n");
    printf("Digite uma nota de 0 a 10: ");
    scanf("%f", &nota);
    
    // Validando se a nota está no intervalo correto
    if (nota < 0 || nota > 10) {
        printf("Erro: A nota deve estar entre 0 e 10!\n");
        return 1;
    }
    
    printf("\n=== CLASSIFICAÇÃO ===\n");
    printf("Nota: %.1f\n", nota);
    printf("Classificação: ");
    
    // Classificando a nota usando if-else aninhada
    if (nota >= 9.0) {
        printf("A - Excelente\n");
    } else if (nota >= 7.0) {
        printf("B - Bom\n");
    } else if (nota >= 5.0) {
        printf("C - Regular\n");
    } else {
        printf("D - Insuficiente\n");
    }
    
    // Informações adicionais
    if (nota >= 7.0) {
        printf("Status: Aprovado\n");
    } else {
        printf("Status: Reprovado\n");
    }
    
    return 0;
} 