#include <stdio.h>
#include <string.h>

// Declarações das funções
void inverter_string_recursivo(char str[], int inicio, int fim);
void inverter_string(char str[]);

int main() {
    char str[100];
    
    printf("=== Inversão de String Recursiva ===\n\n");
    
    // Entrada de dados
    printf("Digite uma string: ");
    scanf(" %[^\n]", str);
    
    // Exibição da string original
    printf("\nString original: \"%s\"\n", str);
    printf("Tamanho: %d caracteres\n", (int)strlen(str));
    
    // Inversão da string
    inverter_string(str);
    
    // Exibição da string invertida
    printf("String invertida: \"%s\"\n", str);
    
    // Testes adicionais
    printf("\n--- Testes Adicionais ---\n");
    
    char testes[][50] = {
        "Olá", "C", "12345", "Ana", "Roma", "A man a plan a canal Panama"
    };
    
    for (int i = 0; i < 6; i++) {
        printf("Original: \"%s\"\n", testes[i]);
        inverter_string(testes[i]);
        printf("Invertida: \"%s\"\n", testes[i]);
        printf("---\n");
    }
    
    return 0;
}

// Função auxiliar para inverter string
void inverter_string(char str[]) {
    int tamanho = strlen(str);
    inverter_string_recursivo(str, 0, tamanho - 1);
}

// Definição da função recursiva
void inverter_string_recursivo(char str[], int inicio, int fim) {
    // Caso base
    if (inicio >= fim) {
        return;
    }
    
    // Troca os caracteres nas posições inicio e fim
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    
    // Caso recursivo
    inverter_string_recursivo(str, inicio + 1, fim - 1);
} 