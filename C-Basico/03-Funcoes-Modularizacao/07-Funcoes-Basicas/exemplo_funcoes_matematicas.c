#include <stdio.h>
#include <math.h>

// Declarações das funções matemáticas
int fatorial(int n);
int potencia(int base, int expoente);
float area_circulo(float raio);
int eh_primo(int numero);

int main() {
    printf("=== Funções Matemáticas ===\n\n");
    
    // Testando fatorial
    int n = 5;
    int fat = fatorial(n);
    printf("Fatorial de %d = %d\n", n, fat);
    
    // Testando potência
    int base = 2, exp = 8;
    int pot = potencia(base, exp);
    printf("%d elevado a %d = %d\n", base, exp, pot);
    
    // Testando área do círculo
    float raio = 5.0;
    float area = area_circulo(raio);
    printf("Área do círculo com raio %.1f = %.2f\n", raio, area);
    
    // Testando números primos
    int numeros[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Verificação de números primos:\n");
    for (int i = 0; i < 9; i++) {
        if (eh_primo(numeros[i])) {
            printf("%d é primo\n", numeros[i]);
        } else {
            printf("%d não é primo\n", numeros[i]);
        }
    }
    
    return 0;
}

// Função para calcular fatorial
int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

// Função para calcular potência
int potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

// Função para calcular área do círculo
float area_circulo(float raio) {
    return 3.14159 * raio * raio;
}

// Função para verificar se um número é primo
int eh_primo(int numero) {
    if (numero <= 1) return 0;
    if (numero <= 3) return 1;
    if (numero % 2 == 0 || numero % 3 == 0) return 0;
    
    for (int i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
} 