# Aula 7: Funções Básicas

## Objetivos da Aula
- Compreender o conceito de funções em C
- Aprender a declarar e definir funções
- Entender parâmetros e valores de retorno
- Praticar a criação de funções simples

## Teoria

### O que são Funções?
Funções são blocos de código reutilizáveis que executam uma tarefa específica. Elas ajudam a organizar o código, evitar repetição e facilitar a manutenção.

### Estrutura Básica de uma Função
```c
tipo_retorno nome_funcao(tipo_parametro1 parametro1, tipo_parametro2 parametro2) {
    // Corpo da função
    // Instruções
    return valor_retorno;
}
```

### Componentes de uma Função
1. **Tipo de Retorno**: Define o tipo de dado que a função retorna
2. **Nome da Função**: Identificador único para a função
3. **Parâmetros**: Dados que a função recebe (opcional)
4. **Corpo da Função**: Código que será executado
5. **Return**: Retorna um valor (exceto para funções void)

### Tipos de Funções
- **Funções com retorno**: Retornam um valor específico
- **Funções void**: Não retornam valor (apenas executam ações)

### Declaração vs Definição
- **Declaração (Protótipo)**: Informa ao compilador sobre a existência da função
- **Definição**: Implementa o código da função

## Exemplos Práticos

### Exemplo 1: Função Simples sem Parâmetros
```c
#include <stdio.h>

// Declaração da função
void saudacao();

int main() {
    printf("Iniciando programa...\n");
    saudacao(); // Chamada da função
    printf("Programa finalizado.\n");
    return 0;
}

// Definição da função
void saudacao() {
    printf("Olá! Bem-vindo ao curso de C!\n");
    printf("Estamos aprendendo sobre funções.\n");
}
```

### Exemplo 2: Função com Parâmetros e Retorno
```c
#include <stdio.h>

// Declaração da função
int soma(int a, int b);

int main() {
    int num1 = 10, num2 = 20;
    int resultado = soma(num1, num2);
    printf("A soma de %d + %d = %d\n", num1, num2, resultado);
    return 0;
}

// Definição da função
int soma(int a, int b) {
    return a + b;
}
```

### Exemplo 3: Função com Múltiplos Parâmetros
```c
#include <stdio.h>

// Declaração da função
float media(float a, float b, float c);

int main() {
    float nota1 = 8.5, nota2 = 7.0, nota3 = 9.2;
    float media_final = media(nota1, nota2, nota3);
    printf("Média das notas: %.2f\n", media_final);
    return 0;
}

// Definição da função
float media(float a, float b, float c) {
    return (a + b + c) / 3.0;
}
```

## Exercícios

### Exercício 1: Calculadora de Área
Crie uma função que calcule a área de um retângulo.

**Requisitos:**
- Função deve receber base e altura como parâmetros
- Deve retornar a área calculada
- Teste com diferentes valores

### Exercício 2: Verificador de Paridade
Crie uma função que verifique se um número é par ou ímpar.

**Requisitos:**
- Função deve receber um número inteiro
- Deve retornar 1 se par, 0 se ímpar
- Teste com vários números

### Exercício 3: Calculadora de Potência
Crie uma função que calcule a potência de um número.

**Requisitos:**
- Função deve receber base e expoente
- Deve retornar o resultado da potênciação
- Teste com diferentes valores

## Dicas Importantes
- Sempre declare as funções antes de usá-las
- Use nomes descritivos para as funções
- Mantenha as funções com responsabilidade única
- Teste suas funções com diferentes valores

## Próximos Passos
Na próxima aula, aprenderemos sobre escopo de variáveis e passagem de parâmetros por valor e referência. 