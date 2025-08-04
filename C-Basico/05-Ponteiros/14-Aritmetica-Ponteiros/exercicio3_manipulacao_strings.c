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
    *destino = '\0';
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

// Função para contar consoantes usando ponteiros
int contar_consoantes(char *ptr) {
    int contador = 0;
    while (*ptr != '\0') {
        char c = tolower(*ptr);
        if (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            contador++;
        }
        ptr++;
    }
    return contador;
}

// Função para contar espaços usando ponteiros
int contar_espacos(char *ptr) {
    int contador = 0;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            contador++;
        }
        ptr++;
    }
    return contador;
}

// Função para contar dígitos usando ponteiros
int contar_digitos(char *ptr) {
    int contador = 0;
    while (*ptr != '\0') {
        if (*ptr >= '0' && *ptr <= '9') {
            contador++;
        }
        ptr++;
    }
    return contador;
}

// Função para remover espaços usando ponteiros
void remover_espacos(char *ptr) {
    char *destino = ptr;
    
    while (*ptr != '\0') {
        if (*ptr != ' ') {
            *destino = *ptr;
            destino++;
        }
        ptr++;
    }
    *destino = '\0';
}

// Função para substituir caractere usando ponteiros
void substituir_caractere(char *ptr, char antigo, char novo) {
    while (*ptr != '\0') {
        if (*ptr == antigo) {
            *ptr = novo;
        }
        ptr++;
    }
}

// Função para verificar palíndromo usando ponteiros
int verificar_palindromo(char *ptr) {
    char *inicio = ptr;
    char *fim = ptr;
    
    // Encontrar o final da string
    while (*fim != '\0') {
        fim++;
    }
    fim--;
    
    // Verificar palíndromo
    while (inicio < fim) {
        if (tolower(*inicio) != tolower(*fim)) {
            return 0;  // Não é palíndromo
        }
        inicio++;
        fim--;
    }
    return 1;  // É palíndromo
}

int main() {
    printf("=== Manipulação de Strings com Ponteiros ===\n\n");
    
    // Declaração de strings
    char str1[] = "Hello World";
    char str2[] = "Programming";
    char str3[100] = "";
    char str4[100] = "";
    char str5[] = "Racecar";
    char str6[] = "A man a plan a canal Panama";
    
    printf("1. Strings originais:\n");
    printf("   str1: %s\n", str1);
    printf("   str2: %s\n", str2);
    printf("   str5: %s\n", str5);
    printf("   str6: %s\n", str6);
    printf("\n");
    
    printf("2. Contagem de caracteres:\n");
    printf("   str1 tem %d caracteres\n", contar_caracteres(str1));
    printf("   str2 tem %d caracteres\n", contar_caracteres(str2));
    printf("\n");
    
    printf("3. Cópia de string:\n");
    printf("   str3 antes: '%s'\n", str3);
    copiar_string(str1, str3);
    printf("   str3 depois de copiar str1: '%s'\n", str3);
    printf("\n");
    
    printf("4. Concatenação de strings:\n");
    printf("   str4 antes: '%s'\n", str4);
    copiar_string(str1, str4);
    printf("   str4 depois de copiar str1: '%s'\n", str4);
    
    concatenar_strings(str4, str2);
    printf("   str4 depois de concatenar str2: '%s'\n", str4);
    printf("\n");
    
    printf("5. Conversão de case:\n");
    char str_case[] = "Hello World Programming";
    printf("   String original: %s\n", str_case);
    
    converter_maiusculas(str_case);
    printf("   String em maiúsculas: %s\n", str_case);
    
    converter_minusculas(str_case);
    printf("   String em minúsculas: %s\n", str_case);
    printf("\n");
    
    printf("6. Contagem de tipos de caracteres:\n");
    char str_analise[] = "Hello World 123 Programming!";
    printf("   String: %s\n", str_analise);
    printf("   Vogais: %d\n", contar_vogais(str_analise));
    printf("   Consoantes: %d\n", contar_consoantes(str_analise));
    printf("   Espaços: %d\n", contar_espacos(str_analise));
    printf("   Dígitos: %d\n", contar_digitos(str_analise));
    printf("\n");
    
    printf("7. Inversão de string:\n");
    char str_inverter[] = "Hello";
    printf("   String original: %s\n", str_inverter);
    
    inverter_string(str_inverter);
    printf("   String invertida: %s\n", str_inverter);
    printf("\n");
    
    printf("8. Verificação de palíndromo:\n");
    printf("   '%s' é palíndromo? %s\n", str5, verificar_palindromo(str5) ? "Sim" : "Não");
    printf("   '%s' é palíndromo? %s\n", str6, verificar_palindromo(str6) ? "Sim" : "Não");
    printf("\n");
    
    printf("9. Remoção de espaços:\n");
    char str_espacos[] = "  Hello   World  ";
    printf("   String original: '%s'\n", str_espacos);
    
    remover_espacos(str_espacos);
    printf("   String sem espaços: '%s'\n", str_espacos);
    printf("\n");
    
    printf("10. Substituição de caracteres:\n");
    char str_subst[] = "Hello World";
    printf("   String original: %s\n", str_subst);
    
    substituir_caractere(str_subst, 'o', '0');
    printf("   String após substituir 'o' por '0': %s\n", str_subst);
    
    substituir_caractere(str_subst, 'l', '1');
    printf("   String após substituir 'l' por '1': %s\n", str_subst);
    printf("\n");
    
    printf("11. Navegação caractere por caractere:\n");
    char str_nav[] = "Programming";
    char *ptr_nav = str_nav;
    
    printf("   Navegando por '%s':\n", str_nav);
    int posicao = 0;
    while (*ptr_nav != '\0') {
        printf("   Posição %d: '%c' (ASCII: %d)\n", posicao, *ptr_nav, *ptr_nav);
        ptr_nav++;
        posicao++;
    }
    printf("\n");
    
    printf("12. Busca de caracteres:\n");
    char str_busca[] = "Hello World Programming";
    char caractere_busca = 'o';
    char *ptr_busca = str_busca;
    
    printf("   String: %s\n", str_busca);
    printf("   Procurando por '%c':\n", caractere_busca);
    
    posicao = 0;
    int encontrados = 0;
    while (*ptr_busca != '\0') {
        if (*ptr_busca == caractere_busca) {
            printf("   Encontrado na posição %d\n", posicao);
            encontrados++;
        }
        ptr_busca++;
        posicao++;
    }
    printf("   Total encontrado: %d\n", encontrados);
    printf("\n");
    
    printf("13. Demonstração de ponteiros para ponteiros:\n");
    char *strings[] = {"Hello", "World", "Programming", "C"};
    char **ptr_strings = strings;
    
    printf("   Array de strings:\n");
    for (int i = 0; i < 4; i++) {
        printf("   [%d]: %s (comprimento: %d)\n", i, *ptr_strings, contar_caracteres(*ptr_strings));
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
    
    printf("16. Estatísticas de strings:\n");
    char str_stats[] = "Programming in C is fun! 123";
    printf("   String: %s\n", str_stats);
    printf("   Comprimento: %d\n", contar_caracteres(str_stats));
    printf("   Vogais: %d\n", contar_vogais(str_stats));
    printf("   Consoantes: %d\n", contar_consoantes(str_stats));
    printf("   Espaços: %d\n", contar_espacos(str_stats));
    printf("   Dígitos: %d\n", contar_digitos(str_stats));
    printf("   Outros: %d\n", contar_caracteres(str_stats) - contar_vogais(str_stats) - 
                              contar_consoantes(str_stats) - contar_espacos(str_stats) - 
                              contar_digitos(str_stats));
    printf("\n");
    
    printf("=== Fim da Manipulação ===\n");
    
    return 0;
} 