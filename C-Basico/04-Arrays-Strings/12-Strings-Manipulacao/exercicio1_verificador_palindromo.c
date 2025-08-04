#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char texto[100], texto_limpo[100];
    
    printf("=== Verificador de Palíndromo ===\n\n");
    
    // Entrada de dados
    printf("Digite uma palavra ou frase: ");
    scanf(" %[^\n]", texto);
    
    printf("\nTexto original: \"%s\"\n", texto);
    printf("Tamanho: %lu caracteres\n", strlen(texto));
    
    // Limpando a string (removendo espaços e convertendo para minúsculas)
    int j = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) { // Apenas letras
            texto_limpo[j] = tolower(texto[i]);
            j++;
        }
    }
    texto_limpo[j] = '\0';
    
    printf("Texto limpo: \"%s\"\n", texto_limpo);
    printf("Tamanho limpo: %lu caracteres\n", strlen(texto_limpo));
    
    // Verificando se é palíndromo
    int tamanho = strlen(texto_limpo);
    int eh_palindromo = 1;
    
    for (int i = 0; i < tamanho / 2; i++) {
        if (texto_limpo[i] != texto_limpo[tamanho - 1 - i]) {
            eh_palindromo = 0;
            break;
        }
    }
    
    // Exibindo resultado
    printf("\n=== Resultado ===\n");
    if (eh_palindromo) {
        printf("✓ \"%s\" É um palíndromo!\n", texto);
    } else {
        printf("✗ \"%s\" NÃO é um palíndromo!\n", texto);
    }
    
    // Demonstração do processo
    printf("\n=== Demonstração do Processo ===\n");
    printf("Comparando caracteres:\n");
    for (int i = 0; i < tamanho / 2; i++) {
        char esq = texto_limpo[i];
        char dir = texto_limpo[tamanho - 1 - i];
        printf("Posição %d: '%c' vs '%c' ", i, esq, dir);
        
        if (esq == dir) {
            printf("✓ iguais\n");
        } else {
            printf("✗ diferentes\n");
        }
    }
    
    // Testes adicionais
    printf("\n=== Testes Adicionais ===\n");
    char testes[][50] = {"ana", "ovo", "radar", "osso", "arara", "ama", "casa"};
    
    for (int i = 0; i < 7; i++) {
        int tamanho_teste = strlen(testes[i]);
        int eh_palindromo_teste = 1;
        
        for (int k = 0; k < tamanho_teste / 2; k++) {
            if (testes[i][k] != testes[i][tamanho_teste - 1 - k]) {
                eh_palindromo_teste = 0;
                break;
            }
        }
        
        if (eh_palindromo_teste) {
            printf("'%s' é palíndromo\n", testes[i]);
        } else {
            printf("'%s' não é palíndromo\n", testes[i]);
        }
    }
    
    return 0;
} 