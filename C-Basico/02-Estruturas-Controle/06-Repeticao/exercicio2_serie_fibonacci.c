#include <stdio.h>

int main() {
    int n, soma = 0;
    long long primeiro = 0, segundo = 1, proximo;
    
    printf("=== SÉRIE DE FIBONACCI ===\n");
    printf("Quantos termos da série você quer ver? ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Erro: O número de termos deve ser positivo!\n");
        return 1;
    }
    
    printf("\n=== SÉRIE DE FIBONACCI ===\n");
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%lld", primeiro);
            soma += primeiro;
        } else if (i == 2) {
            printf(", %lld", segundo);
            soma += segundo;
        } else {
            proximo = primeiro + segundo;
            printf(", %lld", proximo);
            soma += proximo;
            primeiro = segundo;
            segundo = proximo;
        }
    }
    
    printf("\n\n=== RESUMO ===\n");
    printf("Número de termos: %d\n", n);
    printf("Soma dos termos: %d\n", soma);
    
    return 0;
} 