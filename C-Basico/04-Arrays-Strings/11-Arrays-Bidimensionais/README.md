# Aula 11: Arrays Bidimensionais (Matrizes)

## Objetivos da Aula
- Compreender o conceito de matrizes em C
- Aprender a declarar e inicializar matrizes
- Entender acesso a elementos usando dois índices
- Praticar operações com matrizes

## Teoria

### O que são Matrizes?
Matrizes são arrays com duas dimensões, organizados em linhas e colunas. São úteis para representar dados tabulares.

### Declaração de Matrizes
```c
tipo nome_matriz[linhas][colunas];
```

### Características das Matrizes
- **Linhas**: Primeira dimensão
- **Colunas**: Segunda dimensão
- **Índices**: [linha][coluna] (ambos começam em 0)
- **Memória**: Armazenadas linha por linha

### Inicialização de Matrizes
```c
// Inicialização completa
int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

// Inicialização parcial
int valores[3][3] = {{1, 2}, {3, 4}}; // Resto é zero

// Inicialização automática
int dados[][3] = {{1, 2, 3}, {4, 5, 6}}; // Linhas = 2
```

### Acesso a Elementos
```c
matriz[linha][coluna] // Acessa elemento na posição [linha][coluna]
```

## Exemplos Práticos

### Exemplo 1: Matriz Básica
```c
#include <stdio.h>

int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    printf("Matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

### Exemplo 2: Entrada e Saída de Matriz
```c
#include <stdio.h>

int main() {
    int matriz[3][3];
    
    // Entrada de dados
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Saída da matriz
    printf("\nMatriz digitada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

### Exemplo 3: Operações com Matrizes
```c
#include <stdio.h>

int main() {
    int matriz[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int soma = 0, maximo = matriz[0][0], minimo = matriz[0][0];
    
    printf("Matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Cálculo de estatísticas
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            soma += matriz[i][j];
            if (matriz[i][j] > maximo) maximo = matriz[i][j];
            if (matriz[i][j] < minimo) minimo = matriz[i][j];
        }
    }
    
    printf("\nEstatísticas:\n");
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", (float)soma / 16);
    printf("Máximo: %d\n", maximo);
    printf("Mínimo: %d\n", minimo);
    
    return 0;
}
```

## Exercícios

### Exercício 1: Calculadora de Matriz
Crie um programa que calcule estatísticas de uma matriz.

**Requisitos:**
- Leia uma matriz 3x3 do usuário
- Calcule soma, média, máximo e mínimo
- Exiba a matriz e os resultados

### Exercício 2: Diagonal Principal
Crie um programa que trabalhe com a diagonal principal de uma matriz.

**Requisitos:**
- Matriz 4x4 predefinida
- Calcule a soma da diagonal principal
- Exiba a diagonal e o resultado

### Exercício 3: Transposta de Matriz
Crie um programa que calcule a transposta de uma matriz.

**Requisitos:**
- Matriz 3x3 predefinida
- Calcule e exiba a matriz transposta
- Compare matriz original e transposta

## Dicas Importantes
- Use loops aninhados para percorrer matrizes
- Primeiro índice = linha, segundo índice = coluna
- Matrizes são passadas por referência para funções
- Verifique sempre os limites das dimensões

## Próximos Passos
Na próxima aula, aprenderemos sobre strings e manipulação de texto. 