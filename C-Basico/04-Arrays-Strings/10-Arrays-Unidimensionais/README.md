# Aula 10: Arrays Unidimensionais

## Objetivos da Aula
- Compreender o conceito de arrays em C
- Aprender a declarar e inicializar arrays
- Entender acesso a elementos e índices
- Praticar operações básicas com arrays

## Teoria

### O que são Arrays?
Arrays são estruturas de dados que armazenam múltiplos valores do mesmo tipo em uma sequência contígua de memória.

### Declaração de Arrays
```c
tipo nome_array[tamanho];
```

### Características dos Arrays
- **Índice**: Posição do elemento (começa em 0)
- **Tamanho**: Número fixo de elementos
- **Tipo**: Todos os elementos devem ser do mesmo tipo
- **Memória**: Elementos armazenados sequencialmente

### Inicialização de Arrays
```c
// Inicialização com valores
int numeros[5] = {1, 2, 3, 4, 5};

// Inicialização parcial
int valores[5] = {1, 2, 3}; // Resto é zero

// Inicialização automática de tamanho
int dados[] = {10, 20, 30, 40}; // Tamanho = 4
```

### Acesso a Elementos
```c
array[indice] // Acessa elemento na posição índice
```

## Exemplos Práticos

### Exemplo 1: Array Básico
```c
#include <stdio.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    
    printf("Elementos do array:\n");
    for (int i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }
    
    return 0;
}
```

### Exemplo 2: Entrada e Saída de Arrays
```c
#include <stdio.h>

int main() {
    int notas[5];
    
    // Entrada de dados
    printf("Digite 5 notas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%d", &notas[i]);
    }
    
    // Saída dos dados
    printf("\nNotas digitadas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nota %d: %d\n", i + 1, notas[i]);
    }
    
    return 0;
}
```

### Exemplo 3: Operações com Arrays
```c
#include <stdio.h>

int main() {
    int valores[6] = {15, 8, 22, 3, 17, 9};
    int soma = 0, maximo = valores[0], minimo = valores[0];
    
    // Cálculo de soma, máximo e mínimo
    for (int i = 0; i < 6; i++) {
        soma += valores[i];
        if (valores[i] > maximo) maximo = valores[i];
        if (valores[i] < minimo) minimo = valores[i];
    }
    
    printf("Array: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");
    printf("Soma: %d\n", soma);
    printf("Máximo: %d\n", maximo);
    printf("Mínimo: %d\n", minimo);
    printf("Média: %.2f\n", (float)soma / 6);
    
    return 0;
}
```

## Exercícios

### Exercício 1: Calculadora de Estatísticas
Crie um programa que calcule estatísticas de um array de números.

**Requisitos:**
- Leia 10 números do usuário
- Calcule soma, média, máximo e mínimo
- Exiba os resultados

### Exercício 2: Busca em Array
Crie um programa que busque um elemento em um array.

**Requisitos:**
- Array com valores predefinidos
- Busca por valor digitado pelo usuário
- Informe se encontrou e em qual posição

### Exercício 3: Inversão de Array
Crie um programa que inverta a ordem dos elementos de um array.

**Requisitos:**
- Array com valores predefinidos
- Inverta a ordem dos elementos
- Exiba o array original e o invertido

## Dicas Importantes
- Sempre verifique os limites do array para evitar overflow
- Use loops para percorrer arrays
- Arrays são passados por referência para funções
- O tamanho do array deve ser conhecido em tempo de compilação

## Próximos Passos
Na próxima aula, aprenderemos sobre arrays bidimensionais (matrizes). 