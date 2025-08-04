# Aula 16: Estruturas (struct)

## Objetivos da Aula
- Compreender o conceito de estruturas (struct) em C
- Aprender a declarar e definir estruturas
- Entender como acessar membros de estruturas
- Dominar arrays de estruturas
- Aplicar estruturas em situações práticas

## Teoria

### O que são Estruturas?
Estruturas (struct) são tipos de dados compostos que permitem agrupar variáveis de tipos diferentes sob um único nome. Elas são fundamentais para:
- Organizar dados relacionados
- Criar tipos de dados personalizados
- Representar entidades complexas
- Melhorar a legibilidade do código

### Declaração de Estruturas

#### Sintaxe Básica
```c
struct nome_estrutura {
    tipo1 membro1;
    tipo2 membro2;
    tipo3 membro3;
    // ... mais membros
};
```

#### Exemplo de Estrutura
```c
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
    char genero;
};
```

### Definição de Variáveis de Estrutura

#### 1. Definição Separada
```c
struct Pessoa pessoa1;
struct Pessoa pessoa2;
```

#### 2. Definição com Inicialização
```c
struct Pessoa pessoa1 = {"João", 25, 1.75, 'M'};
```

#### 3. Definição de Array de Estruturas
```c
struct Pessoa turma[30];
```

### Acesso aos Membros

#### Operador Ponto (.)
```c
struct Pessoa pessoa;
pessoa.idade = 25;
pessoa.altura = 1.75;
strcpy(pessoa.nome, "Maria");
```

#### Inicialização de Membros
```c
struct Pessoa pessoa = {
    .nome = "Ana",
    .idade = 30,
    .altura = 1.65,
    .genero = 'F'
};
```

### Estruturas Aninhadas

#### Estrutura dentro de Estrutura
```c
struct Endereco {
    char rua[100];
    char cidade[50];
    int numero;
};

struct Pessoa {
    char nome[50];
    int idade;
    struct Endereco endereco;
};
```

#### Acesso a Membros Aninhados
```c
struct Pessoa pessoa;
strcpy(pessoa.endereco.cidade, "São Paulo");
pessoa.endereco.numero = 123;
```

### Ponteiros para Estruturas

#### Declaração de Ponteiros
```c
struct Pessoa *ptr_pessoa;
```

#### Acesso via Ponteiro
```c
struct Pessoa pessoa;
struct Pessoa *ptr = &pessoa;

// Usando operador seta (->)
ptr->idade = 25;
ptr->altura = 1.75;

// Equivalente a:
(*ptr).idade = 25;
(*ptr).altura = 1.75;
```

### Arrays de Estruturas

#### Declaração e Inicialização
```c
struct Pessoa turma[] = {
    {"João", 20, 1.75, 'M'},
    {"Maria", 22, 1.65, 'F'},
    {"Pedro", 21, 1.80, 'M'}
};
```

#### Acesso a Elementos
```c
printf("Nome: %s\n", turma[0].nome);
turma[1].idade = 23;
```

### Estruturas como Parâmetros de Funções

#### Passagem por Valor
```c
void imprimir_pessoa(struct Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
}
```

#### Passagem por Referência
```c
void modificar_pessoa(struct Pessoa *p) {
    p->idade++;
    p->altura += 0.01;
}
```

### Typedef com Estruturas

#### Criação de Alias
```c
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

// Uso
Pessoa pessoa1;
Pessoa *ptr_pessoa;
```

### Estruturas com Ponteiros

#### Estruturas que Contêm Ponteiros
```c
struct Aluno {
    char *nome;
    int *notas;
    int num_notas;
};
```

#### Alocação Dinâmica
```c
struct Aluno *aluno = malloc(sizeof(struct Aluno));
aluno->nome = malloc(50);
aluno->notas = malloc(10 * sizeof(int));
```

### Estruturas Union

#### Definição de Union
```c
union Valor {
    int inteiro;
    float real;
    char texto[20];
};
```

#### Uso de Union
```c
union Valor valor;
valor.inteiro = 42;
printf("Inteiro: %d\n", valor.inteiro);
valor.real = 3.14;
printf("Real: %.2f\n", valor.real);
```

### Estruturas com Funções

#### Estruturas que Contêm Ponteiros para Funções
```c
typedef int (*Operacao)(int, int);

struct Calculadora {
    char nome[20];
    Operacao operacao;
};

int soma(int a, int b) { return a + b; }
int multiplicacao(int a, int b) { return a * b; }
```

### Estruturas Auto-Referenciadas

#### Lista Encadeada
```c
struct No {
    int dado;
    struct No *proximo;
};
```

#### Árvore Binária
```c
struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};
```

### Estruturas com Bit Fields

#### Campos de Bits
```c
struct Configuracao {
    unsigned int ligado : 1;
    unsigned int modo : 2;
    unsigned int nivel : 4;
};
```

### Estruturas com Padding

#### Alinhamento de Memória
```c
struct Exemplo {
    char a;     // 1 byte
    int b;      // 4 bytes (pode ter padding)
    char c;     // 1 byte
};
```

## Exemplos Práticos

### Exemplo 1: Estruturas Básicas
Demonstra declaração, inicialização e acesso a membros de estruturas.

### Exemplo 2: Arrays de Estruturas
Mostra como trabalhar com arrays de estruturas e operações em lote.

### Exemplo 3: Estruturas com Ponteiros
Ilustra o uso de ponteiros com estruturas e alocação dinâmica.

## Exercícios

### Exercício 1: Sistema de Cadastro
Crie um sistema de cadastro usando estruturas para armazenar informações de pessoas.

### Exercício 2: Biblioteca de Livros
Implemente um sistema de biblioteca usando estruturas para gerenciar livros.

### Exercício 3: Agenda de Contatos
Crie uma agenda de contatos usando estruturas e arrays de estruturas.

## Conceitos Importantes

### Vantagens das Estruturas
1. **Organização**: Agrupa dados relacionados
2. **Legibilidade**: Código mais claro e organizado
3. **Reutilização**: Estruturas podem ser reutilizadas
4. **Flexibilidade**: Permite criar tipos complexos

### Cuidados com Estruturas
1. **Tamanho**: Estruturas podem ser grandes
2. **Passagem**: Preferir passagem por referência para estruturas grandes
3. **Inicialização**: Sempre inicializar estruturas
4. **Alinhamento**: Considerar alinhamento de memória

### Boas Práticas
1. Usar nomes descritivos para estruturas e membros
2. Agrupar membros relacionados
3. Considerar o tamanho da estrutura
4. Usar typedef para simplificar declarações
5. Documentar o propósito de cada estrutura

## Próximos Passos
Na próxima aula, aprenderemos sobre:
- Arquivos em C
- Operações de leitura e escrita
- Manipulação de arquivos
- Aplicações práticas

## Resumo
- Estruturas agrupam dados relacionados
- Operador ponto (.) acessa membros
- Operador seta (->) acessa membros via ponteiro
- Arrays de estruturas permitem coleções
- Estruturas podem ser aninhadas
- Typedef simplifica declarações 