#include <stdio.h>

int main() {
    char nome[100];
    int idade;
    float altura;
    
    printf("=== CADASTRO DE PESSOA ===\n");
    
    printf("Digite seu nome: ");
    scanf("%s", nome);
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);
    
    printf("\n=== DADOS CADASTRADOS ===\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);
    
    return 0;
} 