#include <stdio.h>

int main() {
    int numero;
    
    printf("Digite um número: ");
    scanf("%d", &numero);
    
    // Usando operador ternário
    char* resultado = (numero % 2 == 0) ? "par" : "ímpar";
    printf("O número %d é %s.\n", numero, resultado);
    
    // Outro exemplo
    int maior = (numero > 10) ? numero : 10;
    printf("O maior valor entre %d e 10 é: %d\n", numero, maior);
    
    // Verificando se é positivo, negativo ou zero
    char* sinal = (numero > 0) ? "positivo" : (numero < 0) ? "negativo" : "zero";
    printf("O número %d é %s.\n", numero, sinal);
    
    return 0;
} 