#include <stdio.h>
#include <string.h>

int main() {
    printf("=== Strings Básicas ===\n\n");
    
    // Declaração e inicialização de strings
    char nome[50] = "João Silva";
    char cidade[] = "São Paulo";
    char profissao[30];
    char texto[100] = "Programação em C é muito interessante";
    
    // Exibindo strings
    printf("Nome: %s\n", nome);
    printf("Cidade: %s\n", cidade);
    printf("Texto: %s\n", texto);
    
    // Informações sobre as strings
    printf("\n=== Informações ===\n");
    printf("Tamanho do nome: %lu caracteres\n", strlen(nome));
    printf("Tamanho da cidade: %lu caracteres\n", strlen(cidade));
    printf("Tamanho do texto: %lu caracteres\n", strlen(texto));
    
    // Copiando strings
    printf("\n=== Copiando Strings ===\n");
    strcpy(profissao, "Programador");
    printf("Profissão: %s\n", profissao);
    
    // Concatenando strings
    printf("\n=== Concatenando Strings ===\n");
    char nome_completo[100];
    strcpy(nome_completo, nome);
    strcat(nome_completo, " - ");
    strcat(nome_completo, profissao);
    printf("Nome completo: %s\n", nome_completo);
    
    // Comparando strings
    printf("\n=== Comparando Strings ===\n");
    char palavra1[] = "C";
    char palavra2[] = "c";
    
    if (strcmp(palavra1, palavra2) == 0) {
        printf("'%s' e '%s' são iguais\n", palavra1, palavra2);
    } else {
        printf("'%s' e '%s' são diferentes\n", palavra1, palavra2);
    }
    
    // Buscando em strings
    printf("\n=== Buscando em Strings ===\n");
    char *posicao = strstr(texto, "C");
    if (posicao != NULL) {
        printf("'C' encontrado na posição: %ld\n", posicao - texto);
    } else {
        printf("'C' não encontrado\n");
    }
    
    // Buscando caractere
    char *pos_vogal = strchr(nome, 'a');
    if (pos_vogal != NULL) {
        printf("Primeira 'a' em '%s' na posição: %ld\n", nome, pos_vogal - nome);
    }
    
    return 0;
} 