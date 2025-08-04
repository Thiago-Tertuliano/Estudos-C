# Aula 9: Funções Recursivas

## Objetivos da Aula
- Compreender o conceito de recursividade
- Aprender a criar funções recursivas
- Entender casos base e casos recursivos
- Praticar algoritmos recursivos clássicos

## Teoria

### O que é Recursividade?
Recursividade é quando uma função chama a si mesma. É uma técnica poderosa para resolver problemas que podem ser divididos em subproblemas menores.

### Estrutura de uma Função Recursiva
```c
tipo_retorno funcao_recursiva(parametros) {
    // Caso base (condição de parada)
    if (condicao_base) {
        return valor_base;
    }
    
    // Caso recursivo
    return operacao_com_funcao_recursiva(parametros_modificados);
}
```

### Componentes Essenciais
1. **Caso Base**: Condição que para a recursão
2. **Caso Recursivo**: Chamada da função com parâmetros modificados
3. **Convergência**: Garantia de que a recursão chega ao caso base

### Vantagens e Desvantagens
**Vantagens:**
- Código mais limpo e elegante
- Solução natural para problemas recursivos
- Facilita a compreensão de algoritmos

**Desvantagens:**
- Pode consumir muita memória (stack)
- Pode ser mais lenta que versões iterativas
- Risco de stack overflow

## Exemplos Práticos

### Exemplo 1: Fatorial Recursivo
```c
#include <stdio.h>

int fatorial_recursivo(int n) {
    // Caso base
    if (n <= 1) {
        return 1;
    }
    
    // Caso recursivo
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int n = 5;
    printf("Fatorial de %d = %d\n", n, fatorial_recursivo(n));
    return 0;
}
```

### Exemplo 2: Série de Fibonacci
```c
#include <stdio.h>

int fibonacci(int n) {
    // Casos base
    if (n <= 1) {
        return n;
    }
    
    // Caso recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10;
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}
```

### Exemplo 3: Soma de Array
```c
#include <stdio.h>

int soma_array(int arr[], int n) {
    // Caso base
    if (n <= 0) {
        return 0;
    }
    
    // Caso recursivo
    return arr[n - 1] + soma_array(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("Soma do array = %d\n", soma_array(arr, n));
    return 0;
}
```

## Exercícios

### Exercício 1: Potência Recursiva
Crie uma função recursiva que calcule a potência de um número.

**Requisitos:**
- Use a fórmula: base^expoente = base * base^(expoente-1)
- Caso base: expoente = 0 retorna 1
- Teste com diferentes valores

### Exercício 2: Máximo Divisor Comum (MDC)
Crie uma função recursiva que calcule o MDC usando o algoritmo de Euclides.

**Requisitos:**
- Use a fórmula: MDC(a,b) = MDC(b, a%b)
- Caso base: b = 0 retorna a
- Teste com diferentes pares de números

### Exercício 3: Inversão de String
Crie uma função recursiva que inverta uma string.

**Requisitos:**
- Use passagem por referência para modificar a string
- Caso base: string vazia ou um caractere
- Teste com diferentes strings

## Dicas Importantes
- Sempre defina claramente o caso base
- Garanta que a recursão converge para o caso base
- Considere usar versões iterativas para problemas complexos
- Monitore o uso de memória em recursões profundas

## Próximos Passos
Na próxima aula, aprenderemos sobre arrays e strings, iniciando o Módulo 4. 