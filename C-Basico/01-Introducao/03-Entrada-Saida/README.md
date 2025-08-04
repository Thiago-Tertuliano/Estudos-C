# Aula 3: Entrada e Saída Básica

## 🎯 Objetivos da Aula

- Entender as funções de entrada e saída em C
- Aprender a usar `printf()` para saída formatada
- Conhecer a função `scanf()` para entrada de dados
- Compreender especificadores de formato
- Aplicar entrada e saída em programas práticos

## 📚 Teoria

### Funções de Saída

#### printf() - Saída Formatada

A função `printf()` é a principal função de saída em C. Ela permite imprimir texto formatado na tela.

**Sintaxe básica:**
```c
printf("texto a ser exibido");
printf("formato", variáveis);
```

**Especificadores de formato:**
| Tipo | Especificador | Descrição |
|------|---------------|-----------|
| `int` | `%d` | Números inteiros |
| `float` | `%f` | Números decimais |
| `double` | `%lf` | Números decimais duplos |
| `char` | `%c` | Caracteres |
| `char[]` | `%s` | Strings |
| `unsigned int` | `%u` | Inteiros sem sinal |
| `hexadecimal` | `%x` | Números em hexadecimal |
| `octal` | `%o` | Números em octal |

#### Exemplos de printf()

```c
int idade = 25;
float altura = 1.75;
char nome[50] = "João";

// Saída simples
printf("Olá, mundo!\n");

// Saída com variável
printf("Idade: %d anos\n", idade);

// Saída com múltiplas variáveis
printf("Nome: %s, Idade: %d, Altura: %.2f\n", nome, idade, altura);

// Formatação de números
printf("Número com 2 casas decimais: %.2f\n", altura);
printf("Número com 3 casas decimais: %.3f\n", altura);
```

### Funções de Entrada

#### scanf() - Entrada Formatada

A função `scanf()` permite ler dados do teclado e armazená-los em variáveis.

**Sintaxe básica:**
```c
scanf("formato", &variável);
```

**Importante:** Sempre use `&` antes da variável (exceto para arrays).

#### Exemplos de scanf()

```c
int idade;
float altura;
char nome[50];

// Lendo um inteiro
printf("Digite sua idade: ");
scanf("%d", &idade);

// Lendo um float
printf("Digite sua altura: ");
scanf("%f", &altura);

// Lendo uma string
printf("Digite seu nome: ");
scanf("%s", nome);  // Sem & para strings

// Lendo múltiplos valores
printf("Digite idade e altura: ");
scanf("%d %f", &idade, &altura);
```

### Caracteres Especiais

| Caractere | Descrição |
|-----------|-----------|
| `\n` | Nova linha |
| `\t` | Tabulação |
| `\r` | Retorno de carro |
| `\\` | Barra invertida |
| `\"` | Aspas duplas |
| `\'` | Aspas simples |

## 💻 Exemplos Práticos

### Exemplo 1: Programa de Cadastro Simples

```c
#include <stdio.h>

int main() {
    char nome[100];
    int idade;
    float altura;
    
    printf("=== CADASTRO DE PESSOA ===\n");
    
    printf("Digite seu nome: ");
    scanf("%s", nome);
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);
    
    printf("\n=== DADOS CADASTRADOS ===\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);
    
    return 0;
}
```

### Exemplo 2: Calculadora Interativa

```c
#include <stdio.h>

int main() {
    float num1, num2;
    char operacao;
    
    printf("=== CALCULADORA ===\n");
    
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);
    
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    
    printf("\nResultado: ");
    
    switch(operacao) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            if(num2 != 0)
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            else
                printf("Erro: Divisão por zero!\n");
            break;
        default:
            printf("Operação inválida!\n");
    }
    
    return 0;
}
```

## 🎯 Exercícios

### Exercício 1: Calculadora de IMC
Crie um programa que:
- Solicite peso e altura do usuário
- Calcule o IMC (IMC = peso / altura²)
- Exiba o resultado formatado
- Classifique o IMC (abaixo do peso, normal, sobrepeso, etc.)

### Exercício 2: Conversor de Moedas
Crie um programa que:
- Solicite um valor em reais
- Calcule o equivalente em dólares (cotação fixa)
- Calcule o equivalente em euros (cotação fixa)
- Exiba os três valores formatados

### Exercício 3: Calculadora de Juros
Crie um programa que:
- Solicite capital inicial, taxa de juros e tempo
- Calcule juros simples (J = C * i * t)
- Calcule montante final (M = C + J)
- Exiba os resultados detalhados

## 📝 Conceitos Importantes

### Buffer de Entrada

O `scanf()` pode ter problemas com o buffer de entrada. Para resolver:

```c
// Problema: scanf pode "pular" entradas
char nome[50];
int idade;

printf("Digite seu nome: ");
scanf("%s", nome);
printf("Digite sua idade: ");
scanf("%d", &idade);  // Pode pular esta entrada

// Solução: Limpar o buffer
printf("Digite seu nome: ");
scanf("%s", nome);
getchar();  // Limpa o buffer
printf("Digite sua idade: ");
scanf("%d", &idade);
```

### Formatação Avançada

```c
int numero = 42;
float valor = 123.456;

// Formatação de números
printf("Número com 5 espaços: %5d\n", numero);
printf("Número com zeros à esquerda: %05d\n", numero);
printf("Valor com 2 casas decimais: %.2f\n", valor);
printf("Valor com 10 espaços: %10.2f\n", valor);
```

### Validação de Entrada

```c
int idade;
printf("Digite sua idade: ");
if(scanf("%d", &idade) != 1) {
    printf("Erro: Entrada inválida!\n");
    return 1;
}
```

## ⚠️ Erros Comuns

1. **Esquecer `&` no scanf**: Erro de compilação ou comportamento inesperado
2. **Não verificar retorno do scanf**: Pode ignorar erros de entrada
3. **Buffer de entrada**: scanf pode "pular" entradas
4. **Formato incorreto**: Especificador não corresponde ao tipo da variável

## 🎓 Resumo da Aula

- ✅ Entendemos as funções printf() e scanf()
- ✅ Aprendemos especificadores de formato
- ✅ Vimos como fazer entrada e saída formatada
- ✅ Criamos programas interativos
- ✅ Compreendemos problemas comuns e soluções

**Próxima aula**: Operadores Aritméticos 