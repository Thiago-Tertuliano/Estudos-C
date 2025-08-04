#include <stdio.h>

int main() {
    float celsius, fahrenheit, kelvin;
    float metros, centimetros, quilometros, milhas;
    
    printf("=== CONVERSOR DE UNIDADES ===\n\n");
    
    // Conversão de temperatura
    printf("--- CONVERSÃO DE TEMPERATURA ---\n");
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);
    
    // Calculando temperaturas
    fahrenheit = celsius * 9.0/5.0 + 32.0;
    kelvin = celsius + 273.15;
    
    printf("Temperatura em Celsius: %.1f°C\n", celsius);
    printf("Temperatura em Fahrenheit: %.1f°F\n", fahrenheit);
    printf("Temperatura em Kelvin: %.1f K\n", kelvin);
    
    printf("\n--- CONVERSÃO DE DISTÂNCIA ---\n");
    printf("Digite a distância em metros: ");
    scanf("%f", &metros);
    
    // Calculando distâncias usando operadores de atribuição
    centimetros = metros;
    centimetros *= 100;
    
    quilometros = metros;
    quilometros /= 1000;
    
    milhas = metros;
    milhas /= 1609.34;  // 1 milha = 1609.34 metros
    
    printf("Distância em metros: %.2f m\n", metros);
    printf("Distância em centímetros: %.2f cm\n", centimetros);
    printf("Distância em quilômetros: %.4f km\n", quilometros);
    printf("Distância em milhas: %.4f mi\n", milhas);
    
    return 0;
} 