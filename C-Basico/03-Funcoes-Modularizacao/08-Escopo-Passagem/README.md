# Aula 8: Escopo e Passagem de Parâmetros

## Objetivos da Aula
- Compreender o conceito de escopo de variáveis
- Aprender sobre variáveis locais e globais
- Entender passagem por valor vs passagem por referência
- Praticar o uso de ponteiros em funções

## Teoria

### Escopo de Variáveis
O escopo define onde uma variável pode ser acessada no código.

#### Variáveis Locais
- Declaradas dentro de uma função
- Só podem ser acessadas dentro da função
- São destruídas quando a função termina

#### Variáveis Globais
- Declaradas fora de qualquer função
- Podem ser acessadas por qualquer função
- Existem durante toda a execução do programa

### Passagem de Parâmetros

#### Passagem por Valor
- Uma cópia do valor é passada para a função
- Modificações na função não afetam a variável original
- Usado para tipos simples (int, float, char)

#### Passagem por Referência
- O endereço da variável é passado para a função
- Modificações na função afetam a variável original
- Usado com ponteiros

### Ponteiros Básicos
- Ponteiros armazenam endereços de memória
- Operador `&`: obtém o endereço de uma variável
- Operador `*`: acessa o valor no endereço

## Exemplos Práticos

### Exemplo 1: Variáveis Locais vs Globais
```c
#include <stdio.h>

// Variável global
int contador_global = 0;

void funcao1() {
    // Variável local
    int contador_local = 10;
    contador_global++;
    printf("Função 1 - Local: %d, Global: %d\n", contador_local, contador_global);
}

void funcao2() {
    // Variável local com mesmo nome
    int contador_local = 20;
    contador_global++;
    printf("Função 2 - Local: %d, Global: %d\n", contador_local, contador_global);
}

int main() {
    printf("Início - Global: %d\n", contador_global);
    funcao1();
    funcao2();
    printf("Fim - Global: %d\n", contador_global);
    return 0;
}
```

### Exemplo 2: Passagem por Valor
```c
#include <stdio.h>

void incrementar_por_valor(int x) {
    x = x + 1;
    printf("Dentro da função: %d\n", x);
}

int main() {
    int numero = 5;
    printf("Antes da função: %d\n", numero);
    incrementar_por_valor(numero);
    printf("Depois da função: %d\n", numero);
    return 0;
}
```

### Exemplo 3: Passagem por Referência
```c
#include <stdio.h>

void incrementar_por_referencia(int *x) {
    *x = *x + 1;
    printf("Dentro da função: %d\n", *x);
}

int main() {
    int numero = 5;
    printf("Antes da função: %d\n", numero);
    incrementar_por_referencia(&numero);
    printf("Depois da função: %d\n", numero);
    return 0;
}
```

## Exercícios

### Exercício 1: Troca de Valores
Crie uma função que troque os valores de duas variáveis.

**Requisitos:**
- Use passagem por referência
- A função deve trocar os valores das variáveis
- Teste com diferentes valores

### Exercício 2: Calculadora com Referência
Crie funções que calculem soma, subtração, multiplicação e divisão usando passagem por referência.

**Requisitos:**
- Cada função deve receber dois números e um ponteiro para o resultado
- A função deve armazenar o resultado no ponteiro
- Teste todas as operações

### Exercício 3: Validador de Dados
Crie uma função que valide se um número está em um intervalo específico.

**Requisitos:**
- Função deve receber o número, valor mínimo e máximo
- Deve retornar 1 se válido, 0 se inválido
- Use passagem por valor para os parâmetros

## Dicas Importantes
- Variáveis locais têm prioridade sobre globais
- Use passagem por valor quando não precisa modificar a variável original
- Use passagem por referência quando precisa modificar a variável original
- Sempre verifique se ponteiros são válidos antes de usar

## Próximos Passos
Na próxima aula, aprenderemos sobre funções recursivas e modularização de código. 