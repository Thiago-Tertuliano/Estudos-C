#include <stdio.h>

int main() {
    // Declaração de variáveis
    int idade = 25;
    float altura = 1.75;
    char nome[50] = "João";
    double salario = 3500.75;
    
    // Exibindo os valores
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);
    printf("Salário: R$ %.2f\n", salario);
    
    return 0;
} 