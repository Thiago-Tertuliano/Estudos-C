#include <stdio.h>

// Variáveis globais
int contador_global = 0;
float pi_global = 3.14159;

void funcao1() {
    // Variáveis locais
    int contador_local = 10;
    float pi_local = 3.14;
    
    contador_global++;
    printf("Função 1:\n");
    printf("  Local - contador: %d, pi: %.2f\n", contador_local, pi_local);
    printf("  Global - contador: %d, pi: %.5f\n", contador_global, pi_global);
}

void funcao2() {
    // Variável local com mesmo nome da global
    int contador_global = 100; // Esta é uma variável local!
    float pi_local = 3.1416;
    
    printf("Função 2:\n");
    printf("  Local - contador: %d, pi: %.4f\n", contador_global, pi_local);
    printf("  Global - contador: %d, pi: %.5f\n", ::contador_global, pi_global);
}

void funcao3() {
    // Acessando apenas variáveis globais
    contador_global += 5;
    pi_global = 3.14159265359;
    
    printf("Função 3:\n");
    printf("  Modificou global - contador: %d, pi: %.11f\n", contador_global, pi_global);
}

int main() {
    printf("=== Demonstração de Escopo de Variáveis ===\n\n");
    
    printf("Início do programa:\n");
    printf("  Global - contador: %d, pi: %.5f\n\n", contador_global, pi_global);
    
    funcao1();
    printf("\n");
    
    funcao2();
    printf("\n");
    
    funcao3();
    printf("\n");
    
    printf("Fim do programa:\n");
    printf("  Global - contador: %d, pi: %.11f\n", contador_global, pi_global);
    
    return 0;
} 