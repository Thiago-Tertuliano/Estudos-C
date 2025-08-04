#include <stdio.h>

int main() {
    float capital, taxa, tempo, juros, montante;
    
    printf("=== CALCULADORA DE JUROS SIMPLES ===\n");
    
    printf("Digite o capital inicial: R$ ");
    scanf("%f", &capital);
    
    printf("Digite a taxa de juros (em %%): ");
    scanf("%f", &taxa);
    
    printf("Digite o tempo (em meses): ");
    scanf("%f", &tempo);
    
    // Convertendo taxa de porcentagem para decimal
    taxa = taxa / 100;
    
    // Calculando juros simples
    juros = capital * taxa * tempo;
    
    // Calculando montante final
    montante = capital + juros;
    
    printf("\n=== RESULTADO ===\n");
    printf("Capital inicial: R$ %.2f\n", capital);
    printf("Taxa de juros: %.1f%% ao mês\n", taxa * 100);
    printf("Tempo: %.0f meses\n", tempo);
    printf("\nJuros simples: R$ %.2f\n", juros);
    printf("Montante final: R$ %.2f\n", montante);
    printf("\nFórmula utilizada:\n");
    printf("J = C * i * t\n");
    printf("M = C + J\n");
    
    return 0;
} 