# Aula 5: Estruturas Condicionais

## 🎯 Objetivos da Aula

- Entender os operadores relacionais e lógicos
- Aprender a usar a estrutura `if-else`
- Conhecer a estrutura `switch-case`
- Compreender operadores ternários
- Aplicar estruturas condicionais em problemas práticos

## 📚 Teoria

### Operadores Relacionais

Os operadores relacionais comparam valores e retornam verdadeiro (1) ou falso (0).

| Operador | Nome | Exemplo | Resultado |
|----------|------|---------|-----------|
| `==` | Igual a | `5 == 5` | `1` (verdadeiro) |
| `!=` | Diferente de | `5 != 3` | `1` (verdadeiro) |
| `<` | Menor que | `3 < 5` | `1` (verdadeiro) |
| `>` | Maior que | `5 > 3` | `1` (verdadeiro) |
| `<=` | Menor ou igual | `5 <= 5` | `1` (verdadeiro) |
| `>=` | Maior ou igual | `5 >= 3` | `1` (verdadeiro) |

### Operadores Lógicos

Os operadores lógicos combinam condições booleanas.

| Operador | Nome | Exemplo | Resultado |
|----------|------|---------|-----------|
| `&&` | E (AND) | `(5 > 3) && (2 < 4)` | `1` (verdadeiro) |
| `\|\|` | OU (OR) | `(5 > 3) \|\| (2 > 4)` | `1` (verdadeiro) |
| `!` | NÃO (NOT) | `!(5 > 3)` | `0` (falso) |

### Estrutura if-else

A estrutura `if-else` permite executar código condicionalmente.

#### Sintaxe Básica

```c
if (condição) {
    // código executado se a condição for verdadeira
}
```

#### Sintaxe com else

```c
if (condição) {
    // código executado se a condição for verdadeira
} else {
    // código executado se a condição for falsa
}
```

#### Sintaxe com else if

```c
if (condição1) {
    // código executado se condição1 for verdadeira
} else if (condição2) {
    // código executado se condição2 for verdadeira
} else {
    // código executado se nenhuma condição for verdadeira
}
```

### Estrutura switch-case

A estrutura `switch-case` é útil para múltiplas condições baseadas em um valor.

```c
switch (variável) {
    case valor1:
        // código executado se variável == valor1
        break;
    case valor2:
        // código executado se variável == valor2
        break;
    default:
        // código executado se nenhum case for verdadeiro
        break;
}
```

### Operador Ternário

O operador ternário é uma forma abreviada de `if-else`.

```c
resultado = (condição) ? valor_se_verdadeiro : valor_se_falso;
```

## 💻 Exemplos Práticos

### Exemplo 1: Verificação de Idade

```c
#include <stdio.h>

int main() {
    int idade;
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    if (idade < 0) {
        printf("Idade inválida!\n");
    } else if (idade < 18) {
        printf("Você é menor de idade.\n");
    } else if (idade < 65) {
        printf("Você é adulto.\n");
    } else {
        printf("Você é idoso.\n");
    }
    
    return 0;
}
```

### Exemplo 2: Calculadora com Switch

```c
#include <stdio.h>

int main() {
    float num1, num2, resultado;
    char operacao;
    
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);
    
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    
    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("Erro: Divisão por zero!\n");
            }
            break;
        default:
            printf("Operação inválida!\n");
    }
    
    return 0;
}
```

### Exemplo 3: Operador Ternário

```c
#include <stdio.h>

int main() {
    int numero;
    
    printf("Digite um número: ");
    scanf("%d", &numero);
    
    // Usando operador ternário
    char* resultado = (numero % 2 == 0) ? "par" : "ímpar";
    printf("O número %d é %s.\n", numero, resultado);
    
    // Outro exemplo
    int maior = (numero > 10) ? numero : 10;
    printf("O maior valor entre %d e 10 é: %d\n", numero, maior);
    
    return 0;
}
```

## 🎯 Exercícios

### Exercício 1: Sistema de Notas
Crie um programa que:
- Solicite uma nota de 0 a 10
- Classifique a nota (A: 9-10, B: 7-8, C: 5-6, D: 0-4)
- Use estrutura `if-else` aninhada
- Valide se a nota está no intervalo correto

### Exercício 2: Calculadora de Desconto
Crie um programa que:
- Solicite o valor de uma compra
- Calcule desconto baseado no valor:
  - 10% para compras até R$ 100
  - 15% para compras até R$ 500
  - 20% para compras acima de R$ 500
- Exiba o valor original, desconto e valor final

### Exercício 3: Verificador de Triângulo
Crie um programa que:
- Solicite os três lados de um triângulo
- Verifique se é um triângulo válido
- Classifique o triângulo (equilátero, isósceles, escaleno)
- Use operadores lógicos para as verificações

## 📝 Conceitos Importantes

### Precedência de Operadores

1. **Parênteses** `()`
2. **Operadores unários** `!`, `++`, `--`
3. **Multiplicação, Divisão, Módulo** `*`, `/`, `%`
4. **Adição, Subtração** `+`, `-`
5. **Operadores relacionais** `<`, `<=`, `>`, `>=`
6. **Operadores de igualdade** `==`, `!=`
7. **Operadores lógicos** `&&`, `||`
8. **Operador ternário** `? :`
9. **Atribuição** `=`

### Curto-circuito

Os operadores `&&` e `||` usam curto-circuito:

```c
// Se a primeira condição for falsa, a segunda não é avaliada
if (a == 0 && b / a > 5) {
    // Nunca executado se a == 0
}

// Se a primeira condição for verdadeira, a segunda não é avaliada
if (a > 0 || b / a > 5) {
    // Nunca executado se a > 0
}
```

### Estruturas Condicionais Aninhadas

```c
if (idade >= 18) {
    if (idade >= 65) {
        printf("Idoso\n");
    } else {
        printf("Adulto\n");
    }
} else {
    if (idade >= 12) {
        printf("Adolescente\n");
    } else {
        printf("Criança\n");
    }
}
```

## ⚠️ Erros Comuns

1. **Usar `=` em vez de `==`**: `if (a = 5)` atribui 5 a a
2. **Esquecer `break` no switch**: Executa o próximo case
3. **Condições complexas**: Usar parênteses para clareza
4. **Operadores lógicos**: `&&` não é `&`, `||` não é `|`

## 🎓 Resumo da Aula

- ✅ Entendemos operadores relacionais e lógicos
- ✅ Aprendemos a usar `if-else` e `switch-case`
- ✅ Conhecemos o operador ternário
- ✅ Vimos precedência de operadores
- ✅ Aplicamos estruturas condicionais em problemas práticos

**Próxima aula**: Estruturas de Repetição 