#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para imprimir string usando ponteiros
void imprimir_string(char *ptr) {
    printf("   String: ");
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
}

// Função para contar caracteres usando ponteiros
int contar_caracteres(char *ptr) {
    int contador = 0;
    while (*ptr != '\0') {
        contador++;
        ptr++;
    }
    return contador;
}

// Função para copiar string usando ponteiros
void copiar_string(char *origem, char *destino) {
    while (*origem != '\0') {
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0';  // Terminador nulo
}

// Função para concatenar strings usando ponteiros
void concatenar_strings(char *destino, char *origem) {
    // Encontrar o final da string destino
    while (*destino != '\0') {
        destino++;
    }
    
    // Copiar a string origem
    while (*origem != '\0') {
        *destino = *origem;
        destino++;
        origem++;
    }
    *destino = '\0';
}

// Função para comparar strings usando ponteiros
int comparar_strings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// Função para inverter string usando ponteiros
void inverter_string(char *ptr) {
    char *inicio = ptr;
    char *fim = ptr;
    
    // Encontrar o final da string
    while (*fim != '\0') {
        fim++;
    }
    fim--;  // Voltar para o último caractere (não o '\0')
    
    // Inverter
    while (inicio < fim) {
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

// Função para converter para maiúsculas usando ponteiros
void converter_maiusculas(char *ptr) {
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

// Função para converter para minúsculas usando ponteiros
void converter_minusculas(char *ptr) {
    while (*ptr != '\0') {
        *ptr = tolower(*ptr);
        ptr++;
    }
}

// Função para contar vogais usando ponteiros
int contar_vogais(char *ptr) {
    int contador = 0;
    while (*ptr != '\0') {
        char c = tolower(*ptr);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
        ptr++;
    }
    return contador;
}

int main() {
    printf("=== Operações com Strings usando Ponteiros ===\n\n");
    
    // Declaração de strings
    char str1[] = "Hello World";
    char str2[] = "Programming";
    char str3[50] = "";
    char str4[50] = "";
    
    // Ponteiros para as strings
    char *ptr1 = str1;
    char *ptr2 = str2;
    char *ptr3 = str3;
    char *ptr4 = str4;
    
    printf("1. Strings originais:\n");
    printf("   str1: %s\n", str1);
    printf("   str2: %s\n", str2);
    printf("\n");
    
    printf("2. Navegação caractere por caractere:\n");
    printf("   str1 usando ponteiros: ");
    while (*ptr1 != '\0') {
        printf("%c ", *ptr1);
        ptr1++;
    }
    printf("\n");
    
    printf("   str2 usando ponteiros: ");
    while (*ptr2 != '\0') {
        printf("%c ", *ptr2);
        ptr2++;
    }
    printf("\n\n");
    
    printf("3. Contagem de caracteres:\n");
    ptr1 = str1;
    ptr2 = str2;
    
    printf("   str1 tem %d caracteres\n", contar_caracteres(ptr1));
    printf("   str2 tem %d caracteres\n", contar_caracteres(ptr2));
    printf("\n");
    
    printf("4. Cópia de string:\n");
    printf("   str3 antes: '%s'\n", str3);
    copiar_string(str1, ptr3);
    printf("   str3 depois de copiar str1: '%s'\n", str3);
    printf("\n");
    
    printf("5. Concatenação de strings:\n");
    printf("   str4 antes: '%s'\n", str4);
    copiar_string(str1, ptr4);
    printf("   str4 depois de copiar str1: '%s'\n", str4);
    
    concatenar_strings(ptr4, str2);
    printf("   str4 depois de concatenar str2: '%s'\n", str4);
    printf("\n");
    
    printf("6. Comparação de strings:\n");
    char str_a[] = "abc";
    char str_b[] = "abc";
    char str_c[] = "abd";
    
    printf("   Comparando 'abc' com 'abc': %d\n", comparar_strings(str_a, str_b));
    printf("   Comparando 'abc' com 'abd': %d\n", comparar_strings(str_a, str_c));
    printf("   Comparando 'abd' com 'abc': %d\n", comparar_strings(str_c, str_a));
    printf("\n");
    
    printf("7. Inversão de string:\n");
    char str_inverter[] = "Hello";
    printf("   String original: %s\n", str_inverter);
    
    inverter_string(str_inverter);
    printf("   String invertida: %s\n", str_inverter);
    printf("\n");
    
    printf("8. Conversão de case:\n");
    char str_case[] = "Hello World";
    printf("   String original: %s\n", str_case);
    
    converter_maiusculas(str_case);
    printf("   String em maiúsculas: %s\n", str_case);
    
    converter_minusculas(str_case);
    printf("   String em minúsculas: %s\n", str_case);
    printf("\n");
    
    printf("9. Contagem de vogais:\n");
    char str_vogais[] = "Programming in C";
    printf("   String: %s\n", str_vogais);
    printf("   Número de vogais: %d\n", contar_vogais(str_vogais));
    printf("\n");
    
    printf("10. Busca de caractere:\n");
    char str_busca[] = "Hello World";
    char caractere_busca = 'o';
    char *ptr_busca = str_busca;
    
    printf("   String: %s\n", str_busca);
    printf("   Procurando por '%c':\n", caractere_busca);
    
    int posicao = 0;
    while (*ptr_busca != '\0') {
        if (*ptr_busca == caractere_busca) {
            printf("   Encontrado na posição %d\n", posicao);
        }
        ptr_busca++;
        posicao++;
    }
    printf("\n");
    
    printf("11. Substituição de caracteres:\n");
    char str_subst[] = "Hello World";
    printf("   String original: %s\n", str_subst);
    
    char *ptr_subst = str_subst;
    while (*ptr_subst != '\0') {
        if (*ptr_subst == 'o') {
            *ptr_subst = '0';
        }
        ptr_subst++;
    }
    printf("   String após substituir 'o' por '0': %s\n", str_subst);
    printf("\n");
    
    printf("12. Análise de endereços de caracteres:\n");
    char str_analise[] = "ABC";
    char *ptr_analise = str_analise;
    
    printf("   Análise de '%s':\n", str_analise);
    for (int i = 0; i < 4; i++) {  // Incluindo '\0'
        printf("   Posição %d: endereço %p, valor '%c' (ASCII: %d)\n", 
               i, (void*)ptr_analise, *ptr_analise, *ptr_analise);
        ptr_analise++;
    }
    printf("\n");
    
    printf("13. Demonstração de ponteiros para ponteiros com strings:\n");
    char *strings[] = {"Hello", "World", "Programming", "C"};
    char **ptr_strings = strings;
    
    printf("   Array de strings:\n");
    for (int i = 0; i < 4; i++) {
        printf("   %s\n", *ptr_strings);
        ptr_strings++;
    }
    printf("\n");
    
    printf("14. Operações com strings constantes:\n");
    const char *str_const = "Constant String";
    printf("   String constante: %s\n", str_const);
    printf("   Endereço: %p\n", (void*)str_const);
    printf("   Comprimento: %d\n", contar_caracteres((char*)str_const));
    printf("\n");
    
    printf("15. Comparação de endereços de strings:\n");
    char str_comp1[] = "Hello";
    char str_comp2[] = "Hello";
    char *ptr_comp1 = str_comp1;
    char *ptr_comp2 = str_comp2;
    
    printf("   str_comp1: %s (endereço: %p)\n", str_comp1, (void*)ptr_comp1);
    printf("   str_comp2: %s (endereço: %p)\n", str_comp2, (void*)ptr_comp2);
    printf("   ptr_comp1 < ptr_comp2? %s\n", (ptr_comp1 < ptr_comp2) ? "Sim" : "Não");
    printf("   ptr_comp1 == ptr_comp2? %s\n", (ptr_comp1 == ptr_comp2) ? "Sim" : "Não");
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 