#include <stdio.h>

// Declarações das funções
void incrementar_por_referencia(int *x);
void dobrar_por_referencia(int *x);
void trocar_valores(int *a, int *b);
void calcular_media(float a, float b, float c, float *media);

int main() {
    int numero = 10;
    int a = 5, b = 15;
    float nota1 = 8.5, nota2 = 7.0, nota3 = 9.2, media;
    
    printf("=== Passagem por Referência ===\n\n");
    
    // Teste 1: Incrementar
    printf("Teste 1 - Incrementar:\n");
    printf("Antes da função: %d\n", numero);
    incrementar_por_referencia(&numero);
    printf("Depois da função: %d\n", numero);
    printf("(Valor original foi alterado!)\n\n");
    
    // Teste 2: Dobrar
    printf("Teste 2 - Dobrar:\n");
    printf("Antes da função: %d\n", numero);
    dobrar_por_referencia(&numero);
    printf("Depois da função: %d\n", numero);
    printf("(Valor original foi alterado!)\n\n");
    
    // Teste 3: Trocar valores
    printf("Teste 3 - Trocar valores:\n");
    printf("Antes: a = %d, b = %d\n", a, b);
    trocar_valores(&a, &b);
    printf("Depois: a = %d, b = %d\n", a, b);
    printf("(Valores foram trocados!)\n\n");
    
    // Teste 4: Calcular média
    printf("Teste 4 - Calcular média:\n");
    printf("Notas: %.1f, %.1f, %.1f\n", nota1, nota2, nota3);
    calcular_media(nota1, nota2, nota3, &media);
    printf("Média calculada: %.2f\n", media);
    
    return 0;
}

// Função que incrementa por referência
void incrementar_por_referencia(int *x) {
    *x = *x + 1;
    printf("Dentro da função: %d\n", *x);
}

// Função que dobra por referência
void dobrar_por_referencia(int *x) {
    *x = *x * 2;
    printf("Dentro da função: %d\n", *x);
}

// Função que troca valores
void trocar_valores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Dentro da função: a = %d, b = %d\n", *a, *b);
}

// Função que calcula média
void calcular_media(float a, float b, float c, float *media) {
    *media = (a + b + c) / 3.0;
    printf("Dentro da função: média = %.2f\n", *media);
} 