# Aula 1: O que é C e Primeiro Programa

## 🎯 Objetivos da Aula

- Entender o que é a linguagem C
- Conhecer a história e características da linguagem
- Escrever e executar o primeiro programa "Hello World"
- Compreender a estrutura básica de um programa C

## 📚 Teoria

### O que é a Linguagem C?

A linguagem C foi desenvolvida por Dennis Ritchie na Bell Labs em 1972. É uma linguagem de programação de propósito geral que combina características de linguagens de alto e baixo nível.

**Características principais:**
- **Portabilidade**: Código pode ser compilado em diferentes plataformas
- **Eficiência**: Gera código executável rápido e eficiente
- **Flexibilidade**: Permite programação de baixo nível quando necessário
- **Simplicidade**: Sintaxe clara e direta
- **Base para outras linguagens**: C++ e C# são baseados em C

### Por que aprender C?

1. **Fundamentos sólidos**: Muitos conceitos de programação foram estabelecidos em C
2. **Sistemas operacionais**: Linux, Windows e macOS têm partes escritas em C
3. **Microcontroladores**: Muito usado em programação embarcada
4. **Algoritmos**: Ideal para aprender estruturas de dados e algoritmos
5. **Performance**: Ainda muito usado quando performance é crítica

### Estrutura Básica de um Programa C

```c
#include <stdio.h>    // Inclusão de biblioteca
#include <stdlib.h>   // Outras bibliotecas necessárias

int main() {          // Função principal
    // Código do programa aqui
    return 0;         // Retorno da função main
}
```

**Componentes essenciais:**
- `#include`: Inclui bibliotecas necessárias
- `main()`: Função principal, ponto de entrada do programa
- `return 0`: Indica que o programa terminou com sucesso

## 💻 Exemplo Prático: Hello World

### Código Completo

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    printf("Bem-vindo ao curso de C!\n");
    return 0;
}
```

### Explicação do Código

1. `#include <stdio.h>`: Inclui a biblioteca padrão de entrada/saída
2. `int main()`: Define a função principal que retorna um inteiro
3. `printf()`: Função para imprimir texto na tela
4. `\n`: Caractere de nova linha
5. `return 0`: Retorna 0 indicando sucesso

## 🎯 Exercícios

### Exercício 1: Seu Primeiro Programa
Crie um programa que imprima seu nome e idade na tela.

**Dicas:**
- Use múltiplas chamadas de `printf()`
- Inclua informações pessoais fictícias

### Exercício 2: Informações Acadêmicas
Escreva um programa que mostre:
- Seu nome
- Seu curso
- Sua universidade
- Uma mensagem motivacional

### Exercício 3: Calculadora Simples
Crie um programa que declare duas variáveis com valores fixos e imprima:
- A soma
- A subtração
- A multiplicação
- A divisão

## 📝 Conceitos Importantes

### Comentários
```c
// Comentário de uma linha

/*
  Comentário
  de múltiplas
  linhas
*/
```

### Pontos e Vírgulas
- Cada instrução deve terminar com `;`
- O ponto e vírgula é obrigatório

### Chaves `{}`
- Delimitam blocos de código
- São obrigatórias para funções e estruturas de controle

## 🔧 Como Compilar e Executar

### No Windows (usando GCC):
```bash
gcc programa.c -o programa.exe
programa.exe
```

### No Linux/Mac:
```bash
gcc programa.c -o programa
./programa
```

## ⚠️ Erros Comuns

1. **Esquecer `#include <stdio.h>`**: Erro de compilação
2. **Faltar ponto e vírgula**: Erro de sintaxe
3. **Esquecer `return 0`**: Programa pode não funcionar corretamente
4. **Erro de digitação**: C é case-sensitive

## 🎓 Resumo da Aula

- ✅ Entendemos o que é a linguagem C
- ✅ Vimos a estrutura básica de um programa
- ✅ Criamos nosso primeiro programa "Hello World"
- ✅ Aprendemos a compilar e executar código C
- ✅ Conhecemos erros comuns e como evitá-los

**Próxima aula**: Variáveis e Tipos de Dados 