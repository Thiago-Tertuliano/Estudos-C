#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char texto[200] = "Programação em C é muito interessante e divertida";
    char palavra[50], substring[100];
    char texto_upper[200], texto_lower[200];
    
    printf("=== Manipulação Avançada de Strings ===\n\n");
    
    // Exibindo texto original
    printf("Texto original: %s\n", texto);
    printf("Tamanho: %lu caracteres\n", strlen(texto));
    
    // Copiando parte da string
    printf("\n=== Copiando Parte da String ===\n");
    strncpy(palavra, texto, 11);
    palavra[11] = '\0';
    printf("Primeira palavra: %s\n", palavra);
    
    // Buscando substring
    printf("\n=== Buscando Substring ===\n");
    char *posicao = strstr(texto, "interessante");
    if (posicao != NULL) {
        printf("'interessante' encontrado na posição: %ld\n", posicao - texto);
        strcpy(substring, posicao);
        printf("Substring a partir da posição: %s\n", substring);
    }
    
    // Convertendo para maiúsculas e minúsculas
    printf("\n=== Conversão de Case ===\n");
    strcpy(texto_upper, texto);
    strcpy(texto_lower, texto);
    
    // Convertendo para maiúsculas
    for (int i = 0; texto_upper[i] != '\0'; i++) {
        texto_upper[i] = toupper(texto_upper[i]);
    }
    printf("Texto em maiúsculas: %s\n", texto_upper);
    
    // Convertendo para minúsculas
    for (int i = 0; texto_lower[i] != '\0'; i++) {
        texto_lower[i] = tolower(texto_lower[i]);
    }
    printf("Texto em minúsculas: %s\n", texto_lower);
    
    // Contando palavras
    printf("\n=== Contando Palavras ===\n");
    int palavras = 0;
    int caracteres = strlen(texto);
    
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == ' ' && texto[i-1] != ' ') {
            palavras++;
        }
    }
    palavras++; // Última palavra
    
    printf("Número de palavras: %d\n", palavras);
    printf("Número de caracteres: %d\n", caracteres);
    printf("Média de caracteres por palavra: %.2f\n", (float)caracteres / palavras);
    
    // Substituindo caracteres
    printf("\n=== Substituindo Caracteres ===\n");
    char texto_modificado[200];
    strcpy(texto_modificado, texto);
    
    for (int i = 0; texto_modificado[i] != '\0'; i++) {
        if (texto_modificado[i] == 'a') {
            texto_modificado[i] = '@';
        }
    }
    printf("Texto com 'a' substituído por '@': %s\n", texto_modificado);
    
    // Verificando se é palíndromo (simplificado)
    printf("\n=== Verificação de Palíndromo ===\n");
    char palavra_teste[] = "ana";
    int tamanho = strlen(palavra_teste);
    int eh_palindromo = 1;
    
    for (int i = 0; i < tamanho / 2; i++) {
        if (palavra_teste[i] != palavra_teste[tamanho - 1 - i]) {
            eh_palindromo = 0;
            break;
        }
    }
    
    if (eh_palindromo) {
        printf("'%s' é um palíndromo\n", palavra_teste);
    } else {
        printf("'%s' não é um palíndromo\n", palavra_teste);
    }
    
    return 0;
} 