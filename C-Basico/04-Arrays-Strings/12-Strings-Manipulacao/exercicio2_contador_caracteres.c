#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char texto[200];
    int vogais = 0, consoantes = 0, espacos = 0, numeros = 0, outros = 0;
    int maiusculas = 0, minusculas = 0;
    
    printf("=== Contador de Caracteres ===\n\n");
    
    // Entrada de dados
    printf("Digite um texto: ");
    scanf(" %[^\n]", texto);
    
    printf("\nTexto digitado: \"%s\"\n", texto);
    printf("Tamanho total: %lu caracteres\n", strlen(texto));
    
    // Contagem de caracteres
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        
        if (isalpha(c)) { // É letra
            if (isupper(c)) {
                maiusculas++;
            } else {
                minusculas++;
            }
            
            // Verificar se é vogal
            char c_lower = tolower(c);
            if (c_lower == 'a' || c_lower == 'e' || c_lower == 'i' || 
                c_lower == 'o' || c_lower == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        } else if (isdigit(c)) { // É número
            numeros++;
        } else if (isspace(c)) { // É espaço
            espacos++;
        } else { // Outros caracteres
            outros++;
        }
    }
    
    // Exibição dos resultados
    printf("\n=== Estatísticas Detalhadas ===\n");
    printf("Vogais: %d\n", vogais);
    printf("Consoantes: %d\n", consoantes);
    printf("Números: %d\n", numeros);
    printf("Espaços: %d\n", espacos);
    printf("Outros caracteres: %d\n", outros);
    printf("Letras maiúsculas: %d\n", maiusculas);
    printf("Letras minúsculas: %d\n", minusculas);
    
    // Percentuais
    int total = strlen(texto);
    printf("\n=== Percentuais ===\n");
    printf("Vogais: %.1f%%\n", (float)vogais / total * 100);
    printf("Consoantes: %.1f%%\n", (float)consoantes / total * 100);
    printf("Números: %.1f%%\n", (float)numeros / total * 100);
    printf("Espaços: %.1f%%\n", (float)espacos / total * 100);
    printf("Outros: %.1f%%\n", (float)outros / total * 100);
    
    // Análise adicional
    printf("\n=== Análise Adicional ===\n");
    
    // Palavra mais longa
    int palavra_atual = 0, palavra_mais_longa = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            palavra_atual++;
        } else {
            if (palavra_atual > palavra_mais_longa) {
                palavra_mais_longa = palavra_atual;
            }
            palavra_atual = 0;
        }
    }
    if (palavra_atual > palavra_mais_longa) {
        palavra_mais_longa = palavra_atual;
    }
    
    printf("Palavra mais longa: %d caracteres\n", palavra_mais_longa);
    
    // Contagem de palavras
    int palavras = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i]) && (i == 0 || !isalpha(texto[i-1]))) {
            palavras++;
        }
    }
    printf("Número de palavras: %d\n", palavras);
    
    // Média de caracteres por palavra
    if (palavras > 0) {
        printf("Média de caracteres por palavra: %.2f\n", (float)(vogais + consoantes) / palavras);
    }
    
    // Caracteres mais frequentes
    printf("\n=== Caracteres Mais Frequentes ===\n");
    int frequencia[128] = {0}; // ASCII
    
    for (int i = 0; texto[i] != '\0'; i++) {
        frequencia[(int)texto[i]]++;
    }
    
    printf("Caracteres que aparecem mais de uma vez:\n");
    for (int i = 0; i < 128; i++) {
        if (frequencia[i] > 1 && isprint(i)) {
            printf("'%c': %d vezes\n", (char)i, frequencia[i]);
        }
    }
    
    return 0;
} 