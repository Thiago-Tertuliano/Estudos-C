# Aula 14: Aritmética de Ponteiros

## Objetivos da Aula
- Compreender os conceitos de aritmética de ponteiros
- Aprender a realizar operações matemáticas com ponteiros
- Entender a relação entre ponteiros e arrays
- Dominar o uso de ponteiros para navegar em estruturas de dados
- Aplicar aritmética de ponteiros em situações práticas

## Teoria

### O que é Aritmética de Ponteiros?
Aritmética de ponteiros permite realizar operações matemáticas com endereços de memória. Diferente da aritmética normal, ela trabalha com unidades baseadas no tamanho do tipo apontado.

### Operações Básicas de Aritmética de Ponteiros

#### 1. Incremento e Decremento
```c
int array[5] = {1, 2, 3, 4, 5};
int *ptr = array;

ptr++;    // Avança para o próximo elemento
ptr--;    // Volta para o elemento anterior
```

#### 2. Adição e Subtração de Inteiros
```c
int *ptr = array;
ptr = ptr + 2;    // Avança 2 posições
ptr = ptr - 1;    // Volta 1 posição
```

#### 3. Diferença entre Ponteiros
```c
int *ptr1 = &array[0];
int *ptr2 = &array[3];
int diferenca = ptr2 - ptr1;  // Resultado: 3
```

### Relação entre Ponteiros e Arrays

#### Arrays como Ponteiros
```c
int array[5] = {10, 20, 30, 40, 50};
int *ptr = array;  // ptr aponta para o primeiro elemento

// Estas expressões são equivalentes:
array[0] = 100;
*ptr = 100;
```

#### Acesso a Elementos via Ponteiros
```c
int array[5] = {10, 20, 30, 40, 50};
int *ptr = array;

// Diferentes formas de acessar elementos:
printf("%d\n", array[2]);     // Notação de array
printf("%d\n", *(ptr + 2));   // Notação de ponteiro
printf("%d\n", ptr[2]);       // Ponteiro como array
```

### Operações de Aritmética de Ponteiros

#### 1. Incremento (`++`)
```c
int *ptr = array;
ptr++;  // Avança para o próximo elemento
```

#### 2. Decremento (`--`)
```c
int *ptr = &array[3];
ptr--;  // Volta para o elemento anterior
```

#### 3. Adição (`+`)
```c
int *ptr = array;
ptr = ptr + 3;  // Avança 3 posições
```

#### 4. Subtração (`-`)
```c
int *ptr = &array[4];
ptr = ptr - 2;  // Volta 2 posições
```

#### 5. Diferença entre Ponteiros
```c
int *ptr1 = array;
int *ptr2 = &array[3];
int posicoes = ptr2 - ptr1;  // Número de posições entre eles
```

### Tamanho dos Tipos e Aritmética

A aritmética de ponteiros considera o tamanho do tipo apontado:

```c
int array[5] = {1, 2, 3, 4, 5};
int *ptr_int = array;
char *ptr_char = (char*)array;

ptr_int++;  // Avança 4 bytes (tamanho de int)
ptr_char++; // Avança 1 byte (tamanho de char)
```

### Comparações de Ponteiros

#### 1. Igualdade (`==`, `!=`)
```c
int *ptr1 = array;
int *ptr2 = &array[2];

if (ptr1 == ptr2) {
    printf("Apontam para o mesmo endereço\n");
}
```

#### 2. Relacionais (`<`, `>`, `<=`, `>=`)
```c
if (ptr1 < ptr2) {
    printf("ptr1 vem antes de ptr2 na memória\n");
}
```

### Ponteiros e Strings

#### Navegação em Strings
```c
char str[] = "Hello";
char *ptr = str;

while (*ptr != '\0') {
    printf("%c", *ptr);
    ptr++;
}
```

#### Comparação de Strings
```c
char *str1 = "Hello";
char *str2 = "World";

if (str1 < str2) {
    printf("str1 vem antes de str2 na memória\n");
}
```

### Ponteiros para Ponteiros

#### Aritmética com Ponteiros para Ponteiros
```c
int **ptr_ptr = &ptr;
ptr_ptr++;  // Avança para o próximo ponteiro
```

### Cuidados com Aritmética de Ponteiros

#### 1. Limites de Arrays
```c
int array[5] = {1, 2, 3, 4, 5};
int *ptr = array;

// PERIGOSO - Acesso fora dos limites:
ptr = ptr + 10;  // Pode causar comportamento indefinido
```

#### 2. Ponteiros para Diferentes Arrays
```c
int array1[5] = {1, 2, 3, 4, 5};
int array2[5] = {6, 7, 8, 9, 10};

int *ptr1 = array1;
int *ptr2 = array2;

// PERIGOSO - Diferença entre arrays diferentes:
int diff = ptr2 - ptr1;  // Comportamento indefinido
```

#### 3. Ponteiros NULL
```c
int *ptr = NULL;
ptr++;  // Comportamento indefinido
```

### Aplicações Práticas

#### 1. Navegação em Arrays
```c
int array[10] = {0};
int *ptr = array;

// Preencher array
for (int i = 0; i < 10; i++) {
    *ptr = i * 2;
    ptr++;
}
```

#### 2. Busca em Arrays
```c
int array[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
int *ptr = array;
int valor = 7;

while (ptr < array + 10) {
    if (*ptr == valor) {
        printf("Encontrado na posição %ld\n", ptr - array);
        break;
    }
    ptr++;
}
```

#### 3. Cópia de Arrays
```c
int origem[5] = {1, 2, 3, 4, 5};
int destino[5];
int *ptr_origem = origem;
int *ptr_destino = destino;

for (int i = 0; i < 5; i++) {
    *ptr_destino = *ptr_origem;
    ptr_origem++;
    ptr_destino++;
}
```

## Exemplos Práticos

### Exemplo 1: Aritmética Básica
Demonstra operações básicas de aritmética de ponteiros.

### Exemplo 2: Navegação em Arrays
Mostra como usar ponteiros para navegar e manipular arrays.

### Exemplo 3: Operações com Strings
Ilustra o uso de aritmética de ponteiros com strings.

## Exercícios

### Exercício 1: Calculadora de Ponteiros
Crie um programa que demonstre todas as operações de aritmética de ponteiros.

### Exercício 2: Busca em Array
Implemente uma função de busca em array usando aritmética de ponteiros.

### Exercício 3: Manipulação de Strings
Crie um programa que manipule strings usando aritmética de ponteiros.

## Conceitos Importantes

### Vantagens da Aritmética de Ponteiros
1. **Eficiência**: Operações diretas com endereços
2. **Flexibilidade**: Navegação dinâmica em estruturas
3. **Controle**: Acesso preciso à memória
4. **Performance**: Menos overhead que índices

### Cuidados Especiais
1. **Limites**: Sempre verificar limites de arrays
2. **Tipos**: Usar ponteiros do tipo correto
3. **NULL**: Verificar ponteiros antes de usar
4. **Arrays**: Não misturar ponteiros de arrays diferentes

### Boas Práticas
1. Sempre verificar limites antes de acessar
2. Usar nomes descritivos para ponteiros
3. Documentar o propósito de cada operação
4. Testar com diferentes tamanhos de dados
5. Evitar aritmética com ponteiros NULL

## Próximos Passos
Na próxima aula, aprenderemos sobre:
- Ponteiros e funções
- Passagem de parâmetros por referência
- Ponteiros para funções
- Aplicações avançadas

## Resumo
- Aritmética de ponteiros trabalha com endereços de memória
- Operações consideram o tamanho do tipo apontado
- Arrays e ponteiros têm relação estreita
- Cuidado especial com limites e tipos
- Ferramenta poderosa para navegação em estruturas 