#include <stdio.h>

int main() {
    // Declaração da variável para temperatura em Celsius
    float celsius = 25.0;
    float fahrenheit, kelvin;
    
    // Cálculo da temperatura em Fahrenheit
    fahrenheit = celsius * 9.0/5.0 + 32.0;
    
    // Cálculo da temperatura em Kelvin
    kelvin = celsius + 273.15;
    
    // Exibindo os resultados
    printf("=== CONVERSÃO DE TEMPERATURA ===\n");
    printf("Temperatura em Celsius: %.1f°C\n", celsius);
    printf("Temperatura em Fahrenheit: %.1f°F\n", fahrenheit);
    printf("Temperatura em Kelvin: %.1f K\n", kelvin);
    printf("================================\n");
    
    return 0;
} 