# Aula 15: Ponteiros e Funções

## Objetivos da Aula
- Compreender a passagem de parâmetros por referência usando ponteiros
- Aprender a usar ponteiros como parâmetros de funções
- Entender ponteiros para funções
- Dominar o uso de ponteiros para retornar múltiplos valores
- Aplicar ponteiros e funções em situações práticas

## Teoria

### Passagem de Parâmetros por Referência

#### Por Valor vs Por Referência
- **Por Valor**: Uma cópia do valor é passada para a função
- **Por Referência**: O endereço da variável é passado, permitindo modificação

#### Sintaxe de Passagem por Referência
```c
// Declaração da função
void modificar_valor(int *ptr);

// Chamada da função
int numero = 42;
modificar_valor(&numero);
```

### Funções com Parâmetros Ponteiros

#### 1. Funções que Modificam Valores
```c
void incrementar(int *ptr) {
    (*ptr)++;  // Modifica o valor original
}

int main() {
    int valor = 10;
    incrementar(&valor);
    printf("Valor: %d\n", valor);  // Imprime 11
}
```

#### 2. Funções que Retornam Múltiplos Valores
```c
void calcular_estatisticas(int array[], int tamanho, 
                          int *min, int *max, float *media) {
    *min = array[0];
    *max = array[0];
    *media = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (array[i] < *min) *min = array[i];
        if (array[i] > *max) *max = array[i];
        *media += array[i];
    }
    *media /= tamanho;
}
```

#### 3. Funções que Validam Dados
```c
int validar_entrada(int *valor, int min, int max) {
    if (*valor < min || *valor > max) {
        *valor = (min + max) / 2;  // Valor padrão
        return 0;  // Inválido
    }
    return 1;  // Válido
}
```

### Ponteiros para Funções

#### Declaração de Ponteiros para Funções
```c
// Tipo da função
int (*ptr_funcao)(int, int);

// Exemplos de funções
int soma(int a, int b) { return a + b; }
int multiplicacao(int a, int b) { return a * b; }

// Atribuição
ptr_funcao = soma;
ptr_funcao = multiplicacao;
```

#### Uso de Ponteiros para Funções
```c
int executar_operacao(int (*operacao)(int, int), int a, int b) {
    return operacao(a, b);
}

int main() {
    int resultado = executar_operacao(soma, 5, 3);
    printf("Resultado: %d\n", resultado);
}
```

### Arrays de Ponteiros para Funções
```c
int (*operacoes[])(int, int) = {soma, multiplicacao, subtracao};

// Uso
int resultado = operacoes[0](10, 5);  // Soma
int resultado2 = operacoes[1](10, 5); // Multiplicação
```

### Ponteiros como Retorno de Funções

#### Retornando Ponteiros
```c
int* encontrar_maior(int *array, int tamanho) {
    int *maior = &array[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > *maior) {
            maior = &array[i];
        }
    }
    return maior;
}
```

#### Ponteiros para Arrays
```c
int* criar_array(int tamanho) {
    int *array = malloc(tamanho * sizeof(int));
    // Inicializar array
    return array;
}
```

### Ponteiros Constantes em Funções

#### Ponteiros para Constantes
```c
void imprimir_array(const int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
        // array[i] = 0;  // ERRO: não pode modificar
    }
}
```

#### Ponteiros Constantes
```c
void processar_dados(int *const array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] *= 2;  // Pode modificar valores
        // array = NULL;  // ERRO: não pode modificar ponteiro
    }
}
```

### Ponteiros Void em Funções

#### Funções Genéricas
```c
void* buscar_elemento(void *array, int tamanho, int posicao, size_t tamanho_elemento) {
    return (char*)array + (posicao * tamanho_elemento);
}

// Uso
int numeros[] = {1, 2, 3, 4, 5};
int *elemento = buscar_elemento(numeros, 5, 2, sizeof(int));
```

### Ponteiros para Ponteiros em Funções

#### Alocação Dinâmica
```c
int alocar_array(int **ptr_array, int tamanho) {
    *ptr_array = malloc(tamanho * sizeof(int));
    if (*ptr_array == NULL) {
        return 0;  // Falha
    }
    return 1;  // Sucesso
}

// Uso
int *array;
if (alocar_array(&array, 10)) {
    // Usar array
    free(array);
}
```

### Callbacks com Ponteiros para Funções

#### Função de Comparação
```c
int comparar_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void ordenar_array(int *array, int tamanho, 
                  int (*comparar)(const void*, const void*)) {
    // Implementação do algoritmo de ordenação
    // usando a função de comparação
}
```

### Ponteiros para Estruturas

#### Passagem de Estruturas por Referência
```c
typedef struct {
    int x, y;
} Ponto;

void mover_ponto(Ponto *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

void imprimir_ponto(const Ponto *p) {
    printf("(%d, %d)\n", p->x, p->y);
}
```

### Ponteiros e Arrays em Funções

#### Arrays como Ponteiros
```c
void processar_array(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] *= 2;
    }
}

// Equivalente a:
void processar_array(int array[], int tamanho) {
    // Mesma implementação
}
```

### Ponteiros para Strings em Funções

#### Manipulação de Strings
```c
void inverter_string(char *str) {
    char *inicio = str;
    char *fim = str;
    
    while (*fim) fim++;
    fim--;
    
    while (inicio < fim) {
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}
```

## Exemplos Práticos

### Exemplo 1: Passagem por Referência
Demonstra como usar ponteiros para modificar valores em funções.

### Exemplo 2: Ponteiros para Funções
Mostra como usar ponteiros para funções como parâmetros.

### Exemplo 3: Retorno de Múltiplos Valores
Ilustra como retornar múltiplos valores usando ponteiros.

## Exercícios

### Exercício 1: Calculadora com Ponteiros para Funções
Crie um programa que use ponteiros para funções em uma calculadora.

### Exercício 2: Sistema de Validação
Implemente um sistema de validação usando ponteiros e funções.

### Exercício 3: Biblioteca de Funções
Crie uma biblioteca de funções matemáticas usando ponteiros.

## Conceitos Importantes

### Vantagens da Passagem por Referência
1. **Eficiência**: Evita cópia de dados grandes
2. **Modificação**: Permite alterar valores originais
3. **Múltiplos Retornos**: Uma função pode retornar vários valores
4. **Flexibilidade**: Ponteiros para funções permitem callbacks

### Cuidados com Ponteiros em Funções
1. **Verificação de NULL**: Sempre verificar ponteiros antes de usar
2. **Escopo**: Ponteiros locais não devem ser retornados
3. **Const**: Usar const quando apropriado
4. **Documentação**: Documentar o comportamento dos ponteiros

### Boas Práticas
1. Usar const para parâmetros que não devem ser modificados
2. Verificar ponteiros NULL no início das funções
3. Documentar se a função modifica os parâmetros
4. Usar nomes descritivos para ponteiros para funções
5. Preferir passagem por referência para estruturas grandes

## Próximos Passos
Na próxima aula, aprenderemos sobre:
- Estruturas (struct)
- Arrays de estruturas
- Ponteiros para estruturas
- Aplicações práticas

## Resumo
- Ponteiros permitem passagem por referência
- Funções podem retornar múltiplos valores via ponteiros
- Ponteiros para funções permitem callbacks
- Const protege dados de modificação acidental
- Ponteiros void permitem funções genéricas 