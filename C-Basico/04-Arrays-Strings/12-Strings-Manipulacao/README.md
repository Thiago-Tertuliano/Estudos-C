# Aula 12: Strings e Manipulação

## Objetivos da Aula
- Compreender o conceito de strings em C
- Aprender a declarar e inicializar strings
- Entender funções de manipulação de strings
- Praticar operações com strings

## Teoria

### O que são Strings?
Strings são arrays de caracteres terminados pelo caractere nulo (`\0`). Em C, não existe um tipo string nativo.

### Declaração de Strings
```c
char string[tamanho];
char nome[] = "João";
char texto[50] = "Olá mundo";
```

### Características das Strings
- **Terminação**: Sempre terminam com `\0`
- **Índice**: Começa em 0
- **Tamanho**: Inclui o caractere nulo
- **Biblioteca**: `<string.h>` para funções

### Funções Importantes da Biblioteca string.h
- `strlen()`: Comprimento da string
- `strcpy()`: Copiar string
- `strcat()`: Concatenar strings
- `strcmp()`: Comparar strings
- `strchr()`: Buscar caractere
- `strstr()`: Buscar substring

## Exemplos Práticos

### Exemplo 1: Strings Básicas
```c
#include <stdio.h>
#include <string.h>

int main() {
    char nome[50] = "João Silva";
    char cidade[] = "São Paulo";
    char profissao[30];
    
    printf("Nome: %s\n", nome);
    printf("Cidade: %s\n", cidade);
    printf("Tamanho do nome: %lu\n", strlen(nome));
    
    strcpy(profissao, "Programador");
    printf("Profissão: %s\n", profissao);
    
    return 0;
}
```

### Exemplo 2: Entrada e Saída de Strings
```c
#include <stdio.h>
#include <string.h>

int main() {
    char nome[50], sobrenome[50], nome_completo[100];
    
    printf("Digite seu nome: ");
    scanf(" %[^\n]", nome);
    
    printf("Digite seu sobrenome: ");
    scanf(" %[^\n]", sobrenome);
    
    strcpy(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome);
    
    printf("Nome completo: %s\n", nome_completo);
    printf("Tamanho: %lu caracteres\n", strlen(nome_completo));
    
    return 0;
}
```

### Exemplo 3: Manipulação de Strings
```c
#include <stdio.h>
#include <string.h>

int main() {
    char texto[100] = "Programação em C é muito interessante";
    char palavra[20];
    char *posicao;
    
    printf("Texto original: %s\n", texto);
    printf("Tamanho: %lu\n", strlen(texto));
    
    // Buscar palavra
    posicao = strstr(texto, "C");
    if (posicao != NULL) {
        printf("'C' encontrado na posição: %ld\n", posicao - texto);
    }
    
    // Copiar parte da string
    strncpy(palavra, texto, 11);
    palavra[11] = '\0';
    printf("Primeira palavra: %s\n", palavra);
    
    // Comparar strings
    if (strcmp(palavra, "Programação") == 0) {
        printf("Palavra correta!\n");
    }
    
    return 0;
}
```

## Exercícios

### Exercício 1: Verificador de Palíndromo
Crie um programa que verifique se uma string é um palíndromo.

**Requisitos:**
- Leia uma string do usuário
- Verifique se é palíndromo (lê igual de trás para frente)
- Ignore espaços e diferenças de maiúscula/minúscula

### Exercício 2: Contador de Caracteres
Crie um programa que conte caracteres em uma string.

**Requisitos:**
- Leia uma string do usuário
- Conte vogais, consoantes, espaços e outros caracteres
- Exiba estatísticas detalhadas

### Exercício 3: Inversor de String
Crie um programa que inverta uma string.

**Requisitos:**
- Leia uma string do usuário
- Inverta a string
- Exiba a string original e a invertida

## Dicas Importantes
- Sempre reserve espaço para o caractere nulo (`\0`)
- Use `scanf(" %[^\n]", string)` para ler strings com espaços
- Verifique sempre se há espaço suficiente antes de concatenar
- Use funções da biblioteca `string.h` quando possível

## Próximos Passos
Na próxima aula, aprenderemos sobre ponteiros, iniciando o Módulo 5. 