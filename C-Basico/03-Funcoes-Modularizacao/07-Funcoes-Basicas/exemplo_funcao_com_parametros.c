#include <stdio.h>

// Declarações das funções (protótipos)
int soma(int a, int b);
float media(float a, float b, float c);
int maximo(int a, int b, int c);

int main() {
    int num1 = 15, num2 = 25;
    float nota1 = 8.5, nota2 = 7.0, nota3 = 9.2;
    int x = 10, y = 20, z = 15;
    
    printf("=== Funções com Parâmetros e Retorno ===\n\n");
    
    // Testando função soma
    int resultado_soma = soma(num1, num2);
    printf("Soma de %d + %d = %d\n", num1, num2, resultado_soma);
    
    // Testando função media
    float media_final = media(nota1, nota2, nota3);
    printf("Média das notas %.1f, %.1f, %.1f = %.2f\n", 
           nota1, nota2, nota3, media_final);
    
    // Testando função maximo
    int maior = maximo(x, y, z);
    printf("Máximo entre %d, %d, %d = %d\n", x, y, z, maior);
    
    return 0;
}

// Definição da função soma
int soma(int a, int b) {
    return a + b;
}

// Definição da função media
float media(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

// Definição da função maximo
int maximo(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
} 