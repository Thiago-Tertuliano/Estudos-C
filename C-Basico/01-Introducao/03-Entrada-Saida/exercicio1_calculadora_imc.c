#include <stdio.h>
#include <math.h>

int main() {
    float peso, altura, imc;
    
    printf("=== CALCULADORA DE IMC ===\n");
    
    printf("Digite seu peso (em kg): ");
    scanf("%f", &peso);
    
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);
    
    // Calculando o IMC
    imc = peso / (altura * altura);
    
    printf("\n=== RESULTADO ===\n");
    printf("Peso: %.1f kg\n", peso);
    printf("Altura: %.2f metros\n", altura);
    printf("IMC: %.1f\n", imc);
    
    // Classificação do IMC
    printf("\nClassificação: ");
    if(imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if(imc < 25) {
        printf("Peso normal\n");
    } else if(imc < 30) {
        printf("Sobrepeso\n");
    } else if(imc < 35) {
        printf("Obesidade grau I\n");
    } else if(imc < 40) {
        printf("Obesidade grau II\n");
    } else {
        printf("Obesidade grau III\n");
    }
    
    return 0;
} 