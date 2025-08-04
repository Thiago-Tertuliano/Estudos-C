#include <stdio.h>

// Declarações das funções
void incrementar_por_valor(int x);
void dobrar_por_valor(int x);
void modificar_string_por_valor(char str[]);

int main() {
    int numero = 10;
    char texto[] = "Olá";
    
    printf("=== Passagem por Valor ===\n\n");
    
    // Teste 1: Incrementar
    printf("Teste 1 - Incrementar:\n");
    printf("Antes da função: %d\n", numero);
    incrementar_por_valor(numero);
    printf("Depois da função: %d\n", numero);
    printf("(Valor original não foi alterado)\n\n");
    
    // Teste 2: Dobrar
    printf("Teste 2 - Dobrar:\n");
    printf("Antes da função: %d\n", numero);
    dobrar_por_valor(numero);
    printf("Depois da função: %d\n", numero);
    printf("(Valor original não foi alterado)\n\n");
    
    // Teste 3: String (arrays são passados por referência!)
    printf("Teste 3 - String:\n");
    printf("Antes da função: %s\n", texto);
    modificar_string_por_valor(texto);
    printf("Depois da função: %s\n", texto);
    printf("(String foi alterada porque arrays são passados por referência)\n");
    
    return 0;
}

// Função que tenta incrementar por valor
void incrementar_por_valor(int x) {
    x = x + 1;
    printf("Dentro da função: %d\n", x);
}

// Função que tenta dobrar por valor
void dobrar_por_valor(int x) {
    x = x * 2;
    printf("Dentro da função: %d\n", x);
}

// Função que modifica string
void modificar_string_por_valor(char str[]) {
    str[0] = 'X';
    printf("Dentro da função: %s\n", str);
} 