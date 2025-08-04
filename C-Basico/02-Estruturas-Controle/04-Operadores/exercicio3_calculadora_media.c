#include <stdio.h>

int main() {
    float nota1, nota2, nota3, nota4;
    float media_aritmetica, media_ponderada;
    
    printf("=== CALCULADORA DE MÉDIAS ===\n");
    
    // Entrada das notas
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);
    
    printf("Digite a quarta nota: ");
    scanf("%f", &nota4);
    
    // Cálculo da média aritmética
    media_aritmetica = (nota1 + nota2 + nota3 + nota4) / 4;
    
    // Cálculo da média ponderada (pesos: 2, 3, 3, 2)
    media_ponderada = (nota1 * 2 + nota2 * 3 + nota3 * 3 + nota4 * 2) / 10;
    
    printf("\n=== RESULTADOS ===\n");
    printf("Nota 1: %.1f\n", nota1);
    printf("Nota 2: %.1f\n", nota2);
    printf("Nota 3: %.1f\n", nota3);
    printf("Nota 4: %.1f\n", nota4);
    printf("\n");
    printf("Média Aritmética: %.2f\n", media_aritmetica);
    printf("Média Ponderada: %.2f\n", media_ponderada);
    printf("\nPesos utilizados na média ponderada:\n");
    printf("Nota 1: peso 2\n");
    printf("Nota 2: peso 3\n");
    printf("Nota 3: peso 3\n");
    printf("Nota 4: peso 2\n");
    
    return 0;
} 