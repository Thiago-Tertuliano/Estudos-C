#include <stdio.h>
#include <string.h>

int main() {
    char texto[100], invertido[100];
    
    printf("=== Inversor de String ===\n\n");
    
    // Entrada de dados
    printf("Digite uma string: ");
    scanf(" %[^\n]", texto);
    
    printf("\nString original: \"%s\"\n", texto);
    printf("Tamanho: %lu caracteres\n", strlen(texto));
    
    // Invertendo a string
    int tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        invertido[i] = texto[tamanho - 1 - i];
    }
    invertido[tamanho] = '\0';
    
    // Exibindo resultado
    printf("String invertida: \"%s\"\n", invertido);
    
    // Demonstração do processo
    printf("\n=== Demonstração do Processo ===\n");
    printf("Posição original -> Posição invertida:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("texto[%d] = '%c' -> invertido[%d] = '%c'\n", 
               i, texto[i], i, invertido[i]);
    }
    
    // Verificação se é palíndromo
    printf("\n=== Verificação de Palíndromo ===\n");
    if (strcmp(texto, invertido) == 0) {
        printf("✓ \"%s\" é um palíndromo!\n", texto);
    } else {
        printf("✗ \"%s\" não é um palíndromo!\n", texto);
    }
    
    // Inversão in-place (modificando a string original)
    printf("\n=== Inversão In-Place ===\n");
    char texto_copia[100];
    strcpy(texto_copia, texto);
    
    printf("Antes da inversão: \"%s\"\n", texto_copia);
    
    // Algoritmo de inversão in-place
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = texto_copia[i];
        texto_copia[i] = texto_copia[tamanho - 1 - i];
        texto_copia[tamanho - 1 - i] = temp;
    }
    
    printf("Após inversão: \"%s\"\n", texto_copia);
    
    // Demonstração das trocas
    printf("\n=== Demonstração das Trocas ===\n");
    char demo[] = "ABCDE";
    int tamanho_demo = strlen(demo);
    
    printf("String inicial: %s\n", demo);
    
    for (int i = 0; i < tamanho_demo / 2; i++) {
        char temp = demo[i];
        demo[i] = demo[tamanho_demo - 1 - i];
        demo[tamanho_demo - 1 - i] = temp;
        
        printf("Após troca %d: %s\n", i + 1, demo);
    }
    
    // Testes adicionais
    printf("\n=== Testes Adicionais ===\n");
    char testes[][50] = {"Olá", "C", "12345", "Ana", "Roma", "A man a plan a canal Panama"};
    
    for (int i = 0; i < 6; i++) {
        int tamanho_teste = strlen(testes[i]);
        char invertido_teste[50];
        
        // Invertendo
        for (int j = 0; j < tamanho_teste; j++) {
            invertido_teste[j] = testes[i][tamanho_teste - 1 - j];
        }
        invertido_teste[tamanho_teste] = '\0';
        
        printf("Original: \"%s\"\n", testes[i]);
        printf("Invertida: \"%s\"\n", invertido_teste);
        
        // Verificando palíndromo
        if (strcmp(testes[i], invertido_teste) == 0) {
            printf("✓ É palíndromo\n");
        } else {
            printf("✗ Não é palíndromo\n");
        }
        printf("---\n");
    }
    
    return 0;
} 