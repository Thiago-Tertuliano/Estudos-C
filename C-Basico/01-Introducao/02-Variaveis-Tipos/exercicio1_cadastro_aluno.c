#include <stdio.h>

int main() {
    // Declaração de variáveis para cadastro do aluno
    char nome[100] = "Ana Silva";
    int idade = 20;
    float altura = 1.65;
    float peso = 58.5;
    float nota_media = 8.7;
    
    // Exibindo as informações formatadas
    printf("=== CADASTRO DO ALUNO ===\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);
    printf("Peso: %.1f kg\n", peso);
    printf("Nota Média: %.1f\n", nota_media);
    printf("========================\n");
    
    return 0;
} 