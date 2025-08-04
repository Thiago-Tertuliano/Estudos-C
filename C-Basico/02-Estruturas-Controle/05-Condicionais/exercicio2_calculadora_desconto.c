#include <stdio.h>

int main() {
    float valor_compra, desconto, valor_final;
    float percentual_desconto;
    
    printf("=== CALCULADORA DE DESCONTO ===\n");
    printf("Digite o valor da compra: R$ ");
    scanf("%f", &valor_compra);
    
    // Validando valor da compra
    if (valor_compra < 0) {
        printf("Erro: Valor da compra não pode ser negativo!\n");
        return 1;
    }
    
    // Calculando desconto baseado no valor
    if (valor_compra <= 100.0) {
        percentual_desconto = 10.0;
    } else if (valor_compra <= 500.0) {
        percentual_desconto = 15.0;
    } else {
        percentual_desconto = 20.0;
    }
    
    // Calculando valores
    desconto = valor_compra * (percentual_desconto / 100.0);
    valor_final = valor_compra - desconto;
    
    // Exibindo resultados
    printf("\n=== RESULTADO ===\n");
    printf("Valor original: R$ %.2f\n", valor_compra);
    printf("Percentual de desconto: %.1f%%\n", percentual_desconto);
    printf("Valor do desconto: R$ %.2f\n", desconto);
    printf("Valor final: R$ %.2f\n", valor_final);
    
    // Informações adicionais
    printf("\n=== INFORMAÇÕES ===\n");
    if (valor_compra <= 100.0) {
        printf("Faixa: Até R$ 100,00\n");
    } else if (valor_compra <= 500.0) {
        printf("Faixa: R$ 100,01 a R$ 500,00\n");
    } else {
        printf("Faixa: Acima de R$ 500,00\n");
    }
    
    return 0;
} 