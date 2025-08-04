# Aula 4: Operadores Aritméticos

## 🎯 Objetivos da Aula

- Entender os operadores aritméticos básicos
- Conhecer operadores de atribuição
- Aprender sobre precedência de operadores
- Compreender operadores de incremento e decremento
- Aplicar operadores em cálculos práticos

## 📚 Teoria

### Operadores Aritméticos Básicos

Os operadores aritméticos são símbolos que realizam operações matemáticas entre valores.

| Operador | Nome | Exemplo | Resultado |
|----------|------|---------|-----------|
| `+` | Adição | `5 + 3` | `8` |
| `-` | Subtração | `10 - 4` | `6` |
| `*` | Multiplicação | `6 * 7` | `42` |
| `/` | Divisão | `15 / 3` | `5` |
| `%` | Módulo (resto) | `17 % 5` | `2` |

### Operadores de Atribuição

Permitem atribuir valores a variáveis e realizar operações simultaneamente.

| Operador | Exemplo | Equivale a |
|----------|---------|------------|
| `=` | `a = 5` | `a = 5` |
| `+=` | `a += 3` | `a = a + 3` |
| `-=` | `a -= 2` | `a = a - 2` |
| `*=` | `a *= 4` | `a = a * 4` |
| `/=` | `a /= 2` | `a = a / 2` |
| `%=` | `a %= 3` | `a = a % 3` |

### Operadores de Incremento e Decremento

Permitem aumentar ou diminuir o valor de uma variável em 1.

| Operador | Nome | Exemplo | Resultado |
|----------|------|---------|-----------|
| `++` | Incremento | `a++` | `a = a + 1` |
| `--` | Decremento | `a--` | `a = a - 1` |

**Diferença entre pré e pós incremento:**
```c
int a = 5;
int b;

// Pós-incremento: primeiro usa o valor, depois incrementa
b = a++;  // b = 5, a = 6

// Pré-incremento: primeiro incrementa, depois usa o valor
b = ++a;  // b = 7, a = 7
```

### Precedência de Operadores

A ordem em que as operações são executadas segue regras de precedência:

1. **Parênteses** `()` - Maior precedência
2. **Multiplicação, Divisão, Módulo** `*`, `/`, `%`
3. **Adição, Subtração** `+`, `-`
4. **Atribuição** `=`, `+=`, `-=`, etc.

**Exemplo:**
```c
int resultado = 2 + 3 * 4;  // resultado = 14 (não 20)
int resultado2 = (2 + 3) * 4;  // resultado2 = 20
```

## 💻 Exemplos Práticos

### Exemplo 1: Operadores Básicos

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    float resultado;
    
    printf("=== OPERADORES ARITMÉTICOS ===\n");
    printf("a = %d, b = %d\n\n", a, b);
    
    // Operações básicas
    printf("Adição: %d + %d = %d\n", a, b, a + b);
    printf("Subtração: %d - %d = %d\n", a, b, a - b);
    printf("Multiplicação: %d * %d = %d\n", a, b, a * b);
    printf("Divisão: %d / %d = %d\n", a, b, a / b);
    printf("Módulo: %d %% %d = %d\n", a, b, a % b);
    
    // Divisão com float
    resultado = (float)a / b;
    printf("Divisão real: %d / %d = %.2f\n", a, b, resultado);
    
    return 0;
}
```

### Exemplo 2: Operadores de Atribuição

```c
#include <stdio.h>

int main() {
    int numero = 10;
    
    printf("=== OPERADORES DE ATRIBUIÇÃO ===\n");
    printf("Valor inicial: %d\n\n", numero);
    
    // Operadores de atribuição
    numero += 5;
    printf("Após += 5: %d\n", numero);
    
    numero -= 3;
    printf("Após -= 3: %d\n", numero);
    
    numero *= 2;
    printf("Após *= 2: %d\n", numero);
    
    numero /= 4;
    printf("Após /= 4: %d\n", numero);
    
    numero %= 3;
    printf("Após %%= 3: %d\n", numero);
    
    return 0;
}
```

### Exemplo 3: Incremento e Decremento

```c
#include <stdio.h>

int main() {
    int a = 5, b;
    
    printf("=== INCREMENTO E DECREMENTO ===\n");
    printf("Valor inicial de a: %d\n\n", a);
    
    // Pós-incremento
    b = a++;
    printf("b = a++: b = %d, a = %d\n", b, a);
    
    // Pré-incremento
    b = ++a;
    printf("b = ++a: b = %d, a = %d\n", b, a);
    
    // Pós-decremento
    b = a--;
    printf("b = a--: b = %d, a = %d\n", b, a);
    
    // Pré-decremento
    b = --a;
    printf("b = --a: b = %d, a = %d\n", b, a);
    
    return 0;
}
```

## 🎯 Exercícios

### Exercício 1: Calculadora Avançada
Crie um programa que:
- Solicite dois números
- Realize todas as operações aritméticas básicas
- Calcule potência (use multiplicação)
- Calcule raiz quadrada (aproximação)
- Exiba todos os resultados formatados

### Exercício 2: Conversor de Unidades
Crie um programa que:
- Solicite uma temperatura em Celsius
- Calcule Fahrenheit e Kelvin
- Solicite uma distância em metros
- Calcule em centímetros, quilômetros e milhas
- Use operadores de atribuição

### Exercício 3: Calculadora de Média
Crie um programa que:
- Solicite 4 notas de um aluno
- Calcule a média aritmética
- Calcule a média ponderada (pesos: 2, 3, 3, 2)
- Exiba ambas as médias

## 📝 Conceitos Importantes

### Divisão Inteira vs Divisão Real

```c
int a = 10, b = 3;
float resultado;

// Divisão inteira
printf("Divisão inteira: %d / %d = %d\n", a, b, a / b);

// Divisão real (com cast)
resultado = (float)a / b;
printf("Divisão real: %d / %d = %.2f\n", a, b, resultado);
```

### Operador Módulo (%)

O operador módulo retorna o resto da divisão inteira:

```c
int numero = 17;
int divisor = 5;
int resto = numero % divisor;  // resto = 2

// Aplicações comuns
int par_ou_impar = numero % 2;  // 0 = par, 1 = ímpar
int ultimo_digito = numero % 10;  // Último dígito
```

### Precedência e Associatividade

```c
int resultado = 2 + 3 * 4 - 1;  // resultado = 13
// Ordem: 3 * 4 = 12, 2 + 12 = 14, 14 - 1 = 13

int resultado2 = (2 + 3) * (4 - 1);  // resultado2 = 15
// Ordem: 2 + 3 = 5, 4 - 1 = 3, 5 * 3 = 15
```

## ⚠️ Erros Comuns

1. **Divisão por zero**: Causa erro em tempo de execução
2. **Divisão inteira**: Pode não dar o resultado esperado
3. **Precedência**: Não usar parênteses quando necessário
4. **Overflow**: Resultado maior que o tipo pode armazenar

## 🎓 Resumo da Aula

- ✅ Entendemos os operadores aritméticos básicos
- ✅ Aprendemos operadores de atribuição
- ✅ Conhecemos incremento e decremento
- ✅ Compreendemos precedência de operadores
- ✅ Vimos aplicações práticas dos operadores

**Próxima aula**: Estruturas Condicionais 