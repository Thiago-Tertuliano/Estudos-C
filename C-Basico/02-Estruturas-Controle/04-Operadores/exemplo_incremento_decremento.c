#include <stdio.h>

int main() {
    int a = 5, b;
    
    printf("=== INCREMENTO E DECREMENTO ===\n");
    printf("Valor inicial de a: %d\n\n", a);
    
    // Pós-incremento
    b = a++;
    printf("b = a++: b = %d, a = %d\n", b, a);
    
    // Pré-incremento
    b = ++a;
    printf("b = ++a: b = %d, a = %d\n", b, a);
    
    // Pós-decremento
    b = a--;
    printf("b = a--: b = %d, a = %d\n", b, a);
    
    // Pré-decremento
    b = --a;
    printf("b = --a: b = %d, a = %d\n", b, a);
    
    return 0;
} 