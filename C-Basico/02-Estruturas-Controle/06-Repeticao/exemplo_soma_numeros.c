#include <stdio.h>

int main() {
    int n, soma = 0;
    
    printf("Quantos números você quer somar? ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int numero;
        printf("Digite o %dº número: ", i);
        scanf("%d", &numero);
        soma += numero;
    }
    
    printf("A soma dos %d números é: %d\n", n, soma);
    
    return 0;
} 