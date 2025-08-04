#include <stdio.h>

int main() {
    float reais, dolares, euros;
    const float COTACAO_DOLAR = 5.20;  // Cotação fixa
    const float COTACAO_EURO = 5.80;    // Cotação fixa
    
    printf("=== CONVERSOR DE MOEDAS ===\n");
    
    printf("Digite o valor em reais: R$ ");
    scanf("%f", &reais);
    
    // Calculando as conversões
    dolares = reais / COTACAO_DOLAR;
    euros = reais / COTACAO_EURO;
    
    printf("\n=== RESULTADO ===\n");
    printf("Valor em Reais: R$ %.2f\n", reais);
    printf("Valor em Dólares: $ %.2f\n", dolares);
    printf("Valor em Euros: € %.2f\n", euros);
    printf("\nCotações utilizadas:\n");
    printf("1 Dólar = R$ %.2f\n", COTACAO_DOLAR);
    printf("1 Euro = R$ %.2f\n", COTACAO_EURO);
    
    return 0;
} 