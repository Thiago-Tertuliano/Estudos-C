#include <stdio.h>

int main() {
    int numero = 10;
    
    printf("=== OPERADORES DE ATRIBUIÇÃO ===\n");
    printf("Valor inicial: %d\n\n", numero);
    
    // Operadores de atribuição
    numero += 5;
    printf("Após += 5: %d\n", numero);
    
    numero -= 3;
    printf("Após -= 3: %d\n", numero);
    
    numero *= 2;
    printf("Após *= 2: %d\n", numero);
    
    numero /= 4;
    printf("Após /= 4: %d\n", numero);
    
    numero %= 3;
    printf("Após %%= 3: %d\n", numero);
    
    return 0;
} 