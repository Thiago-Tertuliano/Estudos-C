# Aula 2: Variáveis e Tipos de Dados

## 🎯 Objetivos da Aula

- Entender o conceito de variáveis
- Conhecer os tipos de dados básicos em C
- Aprender a declarar e inicializar variáveis
- Compreender o escopo e tempo de vida das variáveis

## 📚 Teoria

### O que são Variáveis?

Uma variável é um espaço na memória do computador que armazena dados que podem ser modificados durante a execução do programa. É como uma "caixa" onde guardamos informações.

**Características das variáveis:**
- **Nome**: Identificador único para acessar a variável
- **Tipo**: Define que tipo de dado pode armazenar
- **Valor**: O conteúdo atual da variável
- **Endereço**: Localização na memória

### Tipos de Dados Básicos em C

#### 1. Tipos Inteiros

| Tipo | Tamanho | Intervalo | Descrição |
|------|---------|-----------|-----------|
| `char` | 1 byte | -128 a 127 | Caracteres e inteiros pequenos |
| `short` | 2 bytes | -32.768 a 32.767 | Inteiros curtos |
| `int` | 4 bytes | -2.147.483.648 a 2.147.483.647 | Inteiros padrão |
| `long` | 4-8 bytes | -2.147.483.648 a 2.147.483.647 | Inteiros longos |
| `long long` | 8 bytes | -9.223.372.036.854.775.808 a 9.223.372.036.854.775.807 | Inteiros muito longos |

#### 2. Tipos de Ponto Flutuante

| Tipo | Tamanho | Precisão | Descrição |
|------|---------|----------|-----------|
| `float` | 4 bytes | 6-7 dígitos | Números decimais simples |
| `double` | 8 bytes | 15-16 dígitos | Números decimais duplos |
| `long double` | 10-16 bytes | 19-20 dígitos | Números decimais muito precisos |

#### 3. Tipos Especiais

| Tipo | Descrição |
|------|-----------|
| `void` | Tipo vazio (sem valor) |
| `_Bool` | Tipo booleano (C99) |

### Declaração de Variáveis

```c
// Sintaxe básica
tipo nome_da_variavel;

// Exemplos
int idade;
float altura;
char letra;
double salario;
```

### Inicialização de Variáveis

```c
// Declaração e inicialização
int idade = 25;
float altura = 1.75;
char letra = 'A';
double salario = 2500.50;

// Declaração múltipla
int a, b, c;
int x = 10, y = 20, z = 30;
```

### Modificadores de Tipo

```c
// signed (com sinal) - padrão
signed int numero = -10;

// unsigned (sem sinal) - apenas positivos
unsigned int contador = 100;

// const (constante) - não pode ser alterada
const float PI = 3.14159;
```

## 💻 Exemplos Práticos

### Exemplo 1: Variáveis Básicas

```c
#include <stdio.h>

int main() {
    // Declaração de variáveis
    int idade = 25;
    float altura = 1.75;
    char nome[50] = "João";
    double salario = 3500.75;
    
    // Exibindo os valores
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);
    printf("Salário: R$ %.2f\n", salario);
    
    return 0;
}
```

### Exemplo 2: Operações com Variáveis

```c
#include <stdio.h>

int main() {
    int a = 10, b = 5;
    float resultado;
    
    // Operações matemáticas
    resultado = a + b;
    printf("Soma: %d + %d = %.2f\n", a, b, resultado);
    
    resultado = a - b;
    printf("Subtração: %d - %d = %.2f\n", a, b, resultado);
    
    resultado = a * b;
    printf("Multiplicação: %d * %d = %.2f\n", a, b, resultado);
    
    resultado = (float)a / b;  // Cast para float
    printf("Divisão: %d / %d = %.2f\n", a, b, resultado);
    
    return 0;
}
```

## 🎯 Exercícios

### Exercício 1: Cadastro de Aluno
Crie um programa que declare variáveis para:
- Nome do aluno
- Idade
- Altura
- Peso
- Nota média

Exiba todas as informações formatadas.

### Exercício 2: Conversão de Temperatura
Crie um programa que:
- Declare uma variável para temperatura em Celsius
- Calcule a temperatura em Fahrenheit (F = C * 9/5 + 32)
- Calcule a temperatura em Kelvin (K = C + 273.15)
- Exiba os três valores

### Exercício 3: Calculadora de Área
Crie um programa que:
- Declare variáveis para base e altura de um retângulo
- Calcule a área (A = base * altura)
- Calcule o perímetro (P = 2 * (base + altura))
- Exiba os resultados

## 📝 Conceitos Importantes

### Nomenclatura de Variáveis

**Regras:**
- Pode conter letras, números e underscore (_)
- Deve começar com letra ou underscore
- É case-sensitive (maiúsculas ≠ minúsculas)
- Não pode usar palavras reservadas

**Boas práticas:**
```c
// ✅ Nomes descritivos
int idade_aluno;
float altura_pessoa;
char nome_completo[100];

// ❌ Evitar nomes confusos
int a, b, c;
int x1, x2, x3;
```

### Especificadores de Formato

| Tipo | Especificador | Exemplo |
|------|---------------|---------|
| `int` | `%d` | `printf("%d", idade);` |
| `float` | `%f` | `printf("%.2f", altura);` |
| `double` | `%lf` | `printf("%.2lf", salario);` |
| `char` | `%c` | `printf("%c", letra);` |
| `char[]` | `%s` | `printf("%s", nome);` |

### Cast (Conversão de Tipos)

```c
int a = 10, b = 3;
float resultado;

// Sem cast - divisão inteira
resultado = a / b;  // resultado = 3.0

// Com cast - divisão real
resultado = (float)a / b;  // resultado = 3.33...
```

## ⚠️ Erros Comuns

1. **Não inicializar variáveis**: Pode conter lixo de memória
2. **Usar tipo errado**: Perda de precisão ou overflow
3. **Esquecer ponto e vírgula**: Erro de sintaxe
4. **Nome de variável inválido**: Erro de compilação

## 🎓 Resumo da Aula

- ✅ Entendemos o conceito de variáveis
- ✅ Conhecemos os tipos de dados básicos
- ✅ Aprendemos a declarar e inicializar variáveis
- ✅ Vimos operações matemáticas com variáveis
- ✅ Compreendemos conversão de tipos

**Próxima aula**: Entrada e Saída Básica 