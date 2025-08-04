# Aula 6: Estruturas de Repetição

## 🎯 Objetivos da Aula

- Entender os conceitos de loops e iterações
- Aprender a usar a estrutura `for`
- Conhecer as estruturas `while` e `do-while`
- Compreender controle de fluxo (break e continue)
- Aplicar estruturas de repetição em problemas práticos

## 📚 Teoria

### O que são Estruturas de Repetição?

Estruturas de repetição (loops) permitem executar um bloco de código múltiplas vezes, baseado em uma condição. São fundamentais para automatizar tarefas repetitivas.

### Estrutura for

A estrutura `for` é ideal quando você sabe quantas vezes o loop deve executar.

#### Sintaxe Básica

```c
for (inicialização; condição; incremento) {
    // código a ser executado
}
```

**Componentes:**
- **Inicialização**: Executada uma vez no início
- **Condição**: Verificada antes de cada iteração
- **Incremento**: Executado após cada iteração

#### Exemplos de for

```c
// Contagem de 1 a 10
for (int i = 1; i <= 10; i++) {
    printf("%d ", i);
}

// Contagem regressiva
for (int i = 10; i >= 1; i--) {
    printf("%d ", i);
}

// Incremento de 2 em 2
for (int i = 0; i <= 20; i += 2) {
    printf("%d ", i);
}
```

### Estrutura while

A estrutura `while` executa enquanto uma condição for verdadeira.

#### Sintaxe

```c
while (condição) {
    // código a ser executado
}
```

#### Exemplo

```c
int contador = 1;
while (contador <= 10) {
    printf("%d ", contador);
    contador++;
}
```

### Estrutura do-while

A estrutura `do-while` executa pelo menos uma vez, depois verifica a condição.

#### Sintaxe

```c
do {
    // código a ser executado
} while (condição);
```

#### Exemplo

```c
int numero;
do {
    printf("Digite um número positivo: ");
    scanf("%d", &numero);
} while (numero <= 0);
```

### Controle de Fluxo

#### break

O `break` interrompe a execução do loop e sai dele.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break;  // Sai do loop quando i == 5
    }
    printf("%d ", i);
}
```

#### continue

O `continue` pula para a próxima iteração do loop.

```c
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
        continue;  // Pula números pares
    }
    printf("%d ", i);  // Só imprime ímpares
}
```

## 💻 Exemplos Práticos

### Exemplo 1: Tabuada

```c
#include <stdio.h>

int main() {
    int numero;
    
    printf("Digite um número para ver sua tabuada: ");
    scanf("%d", &numero);
    
    printf("\n=== TABUADA DO %d ===\n", numero);
    
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
    
    return 0;
}
```

### Exemplo 2: Soma de Números

```c
#include <stdio.h>

int main() {
    int n, soma = 0;
    
    printf("Quantos números você quer somar? ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int numero;
        printf("Digite o %dº número: ", i);
        scanf("%d", &numero);
        soma += numero;
    }
    
    printf("A soma dos %d números é: %d\n", n, soma);
    
    return 0;
}
```

### Exemplo 3: Verificação de Número Primo

```c
#include <stdio.h>

int main() {
    int numero, eh_primo = 1;
    
    printf("Digite um número para verificar se é primo: ");
    scanf("%d", &numero);
    
    if (numero <= 1) {
        eh_primo = 0;
    } else {
        for (int i = 2; i * i <= numero; i++) {
            if (numero % i == 0) {
                eh_primo = 0;
                break;
            }
        }
    }
    
    if (eh_primo) {
        printf("%d é um número primo.\n", numero);
    } else {
        printf("%d não é um número primo.\n", numero);
    }
    
    return 0;
}
```

## 🎯 Exercícios

### Exercício 1: Calculadora de Fatorial
Crie um programa que:
- Solicite um número inteiro positivo
- Calcule o fatorial usando loop
- Exiba o resultado
- Valide se o número é positivo

### Exercício 2: Série de Fibonacci
Crie um programa que:
- Solicite quantos termos da série Fibonacci mostrar
- Gere a série usando loop
- Exiba os termos formatados
- Calcule a soma dos termos

### Exercício 3: Verificador de Números Perfeitos
Crie um programa que:
- Solicite um número
- Verifique se é um número perfeito (soma dos divisores = número)
- Liste todos os divisores
- Use break para otimizar o loop

## 📝 Conceitos Importantes

### Loops Aninhados

```c
// Tabuada completa
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        printf("%d x %d = %d\n", i, j, i * j);
    }
    printf("\n");
}
```

### Loops Infinitos

```c
// Loop infinito com break
while (1) {
    printf("Digite 0 para sair: ");
    int valor;
    scanf("%d", &valor);
    
    if (valor == 0) {
        break;
    }
    
    printf("Você digitou: %d\n", valor);
}
```

### Otimização de Loops

```c
// Busca otimizada
int encontrou = 0;
for (int i = 0; i < n; i++) {
    if (array[i] == valor_procurado) {
        encontrou = 1;
        break;  // Sai assim que encontra
    }
}
```

### Contadores e Acumuladores

```c
int soma = 0;      // Acumulador
int contador = 0;  // Contador

for (int i = 1; i <= 100; i++) {
    if (i % 2 == 0) {
        soma += i;      // Acumula valores
        contador++;     // Conta quantos
    }
}

printf("Soma dos pares: %d\n", soma);
printf("Quantidade de pares: %d\n", contador);
```

## ⚠️ Erros Comuns

1. **Loop infinito**: Condição nunca se torna falsa
2. **Off-by-one**: Loop executa uma vez a mais ou a menos
3. **Variável não inicializada**: Usar variável sem valor inicial
4. **Condição incorreta**: Loop não executa ou executa demais

## 🎓 Resumo da Aula

- ✅ Entendemos os conceitos de loops e iterações
- ✅ Aprendemos a usar `for`, `while` e `do-while`
- ✅ Conhecemos `break` e `continue`
- ✅ Vimos loops aninhados e otimizações
- ✅ Aplicamos estruturas de repetição em problemas práticos

**Próxima aula**: Funções Básicas 