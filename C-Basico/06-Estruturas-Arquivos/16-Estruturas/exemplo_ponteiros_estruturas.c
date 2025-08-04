#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
    char genero;
};

// Estrutura para endereço
struct Endereco {
    char rua[100];
    char cidade[50];
    char estado[3];
    int numero;
    char cep[10];
};

// Estrutura aninhada
struct PessoaCompleta {
    char nome[50];
    int idade;
    float altura;
    char genero;
    struct Endereco *endereco;
};

// Estrutura para nó de lista encadeada
struct No {
    int dado;
    struct No *proximo;
};

// Estrutura para árvore binária
struct NoArvore {
    int valor;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
};

// Estrutura para aluno com ponteiros
struct Aluno {
    char *nome;
    int matricula;
    float *notas;
    int num_notas;
    float media;
};

// Função para criar pessoa dinamicamente
struct Pessoa* criar_pessoa(const char *nome, int idade, float altura, char genero) {
    struct Pessoa *pessoa = malloc(sizeof(struct Pessoa));
    if (pessoa != NULL) {
        strcpy(pessoa->nome, nome);
        pessoa->idade = idade;
        pessoa->altura = altura;
        pessoa->genero = genero;
    }
    return pessoa;
}

// Função para criar endereço dinamicamente
struct Endereco* criar_endereco(const char *rua, const char *cidade, 
                                const char *estado, int numero, const char *cep) {
    struct Endereco *endereco = malloc(sizeof(struct Endereco));
    if (endereco != NULL) {
        strcpy(endereco->rua, rua);
        strcpy(endereco->cidade, cidade);
        strcpy(endereco->estado, estado);
        endereco->numero = numero;
        strcpy(endereco->cep, cep);
    }
    return endereco;
}

// Função para imprimir pessoa
void imprimir_pessoa(struct Pessoa *pessoa) {
    if (pessoa != NULL) {
        printf("   Nome: %s\n", pessoa->nome);
        printf("   Idade: %d\n", pessoa->idade);
        printf("   Altura: %.2f\n", pessoa->altura);
        printf("   Gênero: %c\n", pessoa->genero);
    }
}

// Função para imprimir endereço
void imprimir_endereco(struct Endereco *endereco) {
    if (endereco != NULL) {
        printf("   Rua: %s, %d\n", endereco->rua, endereco->numero);
        printf("   Cidade: %s - %s\n", endereco->cidade, endereco->estado);
        printf("   CEP: %s\n", endereco->cep);
    }
}

// Função para modificar pessoa
void modificar_pessoa(struct Pessoa *pessoa, int nova_idade, float nova_altura) {
    if (pessoa != NULL) {
        pessoa->idade = nova_idade;
        pessoa->altura = nova_altura;
    }
}

// Função para criar nó de lista encadeada
struct No* criar_no(int dado) {
    struct No *no = malloc(sizeof(struct No));
    if (no != NULL) {
        no->dado = dado;
        no->proximo = NULL;
    }
    return no;
}

// Função para inserir no início da lista
void inserir_inicio(struct No **inicio, int dado) {
    struct No *novo = criar_no(dado);
    if (novo != NULL) {
        novo->proximo = *inicio;
        *inicio = novo;
    }
}

// Função para imprimir lista
void imprimir_lista(struct No *inicio) {
    struct No *atual = inicio;
    printf("   Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para criar nó de árvore
struct NoArvore* criar_no_arvore(int valor) {
    struct NoArvore *no = malloc(sizeof(struct NoArvore));
    if (no != NULL) {
        no->valor = valor;
        no->esquerda = NULL;
        no->direita = NULL;
    }
    return no;
}

// Função para inserir na árvore
struct NoArvore* inserir_arvore(struct NoArvore *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no_arvore(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_arvore(raiz->direita, valor);
    }
    
    return raiz;
}

// Função para imprimir árvore (in-order)
void imprimir_arvore(struct NoArvore *raiz) {
    if (raiz != NULL) {
        imprimir_arvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_arvore(raiz->direita);
    }
}

// Função para criar aluno dinamicamente
struct Aluno* criar_aluno(const char *nome, int matricula, int num_notas) {
    struct Aluno *aluno = malloc(sizeof(struct Aluno));
    if (aluno != NULL) {
        aluno->nome = malloc(strlen(nome) + 1);
        aluno->notas = malloc(num_notas * sizeof(float));
        
        if (aluno->nome != NULL && aluno->notas != NULL) {
            strcpy(aluno->nome, nome);
            aluno->matricula = matricula;
            aluno->num_notas = num_notas;
            aluno->media = 0.0;
        } else {
            // Liberar memória se falhar
            if (aluno->nome != NULL) free(aluno->nome);
            if (aluno->notas != NULL) free(aluno->notas);
            free(aluno);
            aluno = NULL;
        }
    }
    return aluno;
}

// Função para calcular média do aluno
void calcular_media_aluno(struct Aluno *aluno) {
    if (aluno != NULL && aluno->notas != NULL) {
        float soma = 0;
        for (int i = 0; i < aluno->num_notas; i++) {
            soma += aluno->notas[i];
        }
        aluno->media = soma / aluno->num_notas;
    }
}

// Função para imprimir aluno
void imprimir_aluno(struct Aluno *aluno) {
    if (aluno != NULL) {
        printf("   Nome: %s\n", aluno->nome);
        printf("   Matrícula: %d\n", aluno->matricula);
        printf("   Notas: ");
        for (int i = 0; i < aluno->num_notas; i++) {
            printf("%.1f ", aluno->notas[i]);
        }
        printf("\n   Média: %.2f\n", aluno->media);
    }
}

// Função para liberar memória do aluno
void liberar_aluno(struct Aluno *aluno) {
    if (aluno != NULL) {
        if (aluno->nome != NULL) free(aluno->nome);
        if (aluno->notas != NULL) free(aluno->notas);
        free(aluno);
    }
}

// Função para liberar memória da lista
void liberar_lista(struct No *inicio) {
    struct No *atual = inicio;
    while (atual != NULL) {
        struct No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

// Função para liberar memória da árvore
void liberar_arvore(struct NoArvore *raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    printf("=== Ponteiros com Estruturas ===\n\n");
    
    // 1. Ponteiros para estruturas básicas
    printf("1. Ponteiros para Estruturas Básicas:\n");
    struct Pessoa *ptr_pessoa = criar_pessoa("João Silva", 25, 1.75, 'M');
    
    if (ptr_pessoa != NULL) {
        printf("   Pessoa criada dinamicamente:\n");
        imprimir_pessoa(ptr_pessoa);
        
        printf("   Modificando pessoa...\n");
        modificar_pessoa(ptr_pessoa, 26, 1.76);
        imprimir_pessoa(ptr_pessoa);
        
        free(ptr_pessoa);
    }
    printf("\n");
    
    // 2. Estruturas aninhadas com ponteiros
    printf("2. Estruturas Aninhadas com Ponteiros:\n");
    struct PessoaCompleta pessoa_completa = {
        .nome = "Maria Santos",
        .idade = 30,
        .altura = 1.65,
        .genero = 'F',
        .endereco = NULL
    };
    
    pessoa_completa.endereco = criar_endereco("Rua das Flores", "São Paulo", "SP", 123, "01234-567");
    
    printf("   Pessoa completa:\n");
    printf("   Nome: %s\n", pessoa_completa.nome);
    printf("   Idade: %d\n", pessoa_completa.idade);
    imprimir_endereco(pessoa_completa.endereco);
    
    if (pessoa_completa.endereco != NULL) {
        free(pessoa_completa.endereco);
    }
    printf("\n");
    
    // 3. Lista encadeada
    printf("3. Lista Encadeada:\n");
    struct No *lista = NULL;
    
    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 20);
    inserir_inicio(&lista, 30);
    inserir_inicio(&lista, 40);
    
    imprimir_lista(lista);
    
    // Buscar elemento na lista
    struct No *atual = lista;
    int busca = 20;
    int encontrado = 0;
    
    while (atual != NULL && !encontrado) {
        if (atual->dado == busca) {
            encontrado = 1;
        }
        atual = atual->proximo;
    }
    
    printf("   Elemento %d encontrado? %s\n", busca, encontrado ? "Sim" : "Não");
    printf("\n");
    
    // 4. Árvore binária
    printf("4. Árvore Binária:\n");
    struct NoArvore *raiz = NULL;
    
    raiz = inserir_arvore(raiz, 50);
    raiz = inserir_arvore(raiz, 30);
    raiz = inserir_arvore(raiz, 70);
    raiz = inserir_arvore(raiz, 20);
    raiz = inserir_arvore(raiz, 40);
    raiz = inserir_arvore(raiz, 60);
    raiz = inserir_arvore(raiz, 80);
    
    printf("   Árvore (in-order): ");
    imprimir_arvore(raiz);
    printf("\n\n");
    
    // 5. Alunos com alocação dinâmica
    printf("5. Alunos com Alocação Dinâmica:\n");
    struct Aluno *aluno1 = criar_aluno("Ana Silva", 1001, 4);
    struct Aluno *aluno2 = criar_aluno("Carlos Santos", 1002, 3);
    
    if (aluno1 != NULL && aluno2 != NULL) {
        // Definir notas
        aluno1->notas[0] = 8.5;
        aluno1->notas[1] = 7.0;
        aluno1->notas[2] = 9.0;
        aluno1->notas[3] = 8.0;
        
        aluno2->notas[0] = 6.5;
        aluno2->notas[1] = 7.5;
        aluno2->notas[2] = 8.0;
        
        calcular_media_aluno(aluno1);
        calcular_media_aluno(aluno2);
        
        printf("   Aluno 1:\n");
        imprimir_aluno(aluno1);
        printf("\n   Aluno 2:\n");
        imprimir_aluno(aluno2);
        
        liberar_aluno(aluno1);
        liberar_aluno(aluno2);
    }
    printf("\n");
    
    // 6. Array de ponteiros para estruturas
    printf("6. Array de Ponteiros para Estruturas:\n");
    struct Pessoa *pessoas[3];
    
    pessoas[0] = criar_pessoa("João", 25, 1.75, 'M');
    pessoas[1] = criar_pessoa("Maria", 30, 1.65, 'F');
    pessoas[2] = criar_pessoa("Pedro", 28, 1.80, 'M');
    
    printf("   Lista de pessoas:\n");
    for (int i = 0; i < 3; i++) {
        if (pessoas[i] != NULL) {
            printf("   %d. %s (%d anos)\n", i + 1, pessoas[i]->nome, pessoas[i]->idade);
        }
    }
    
    // Liberar memória
    for (int i = 0; i < 3; i++) {
        if (pessoas[i] != NULL) {
            free(pessoas[i]);
        }
    }
    printf("\n");
    
    // 7. Ponteiros para ponteiros
    printf("7. Ponteiros para Ponteiros:\n");
    struct Pessoa **ptr_ptr_pessoa = malloc(sizeof(struct Pessoa*));
    if (ptr_ptr_pessoa != NULL) {
        *ptr_ptr_pessoa = criar_pessoa("Ana", 35, 1.70, 'F');
        
        if (*ptr_ptr_pessoa != NULL) {
            printf("   Pessoa via ponteiro para ponteiro:\n");
            imprimir_pessoa(*ptr_ptr_pessoa);
            
            free(*ptr_ptr_pessoa);
        }
        free(ptr_ptr_pessoa);
    }
    printf("\n");
    
    // 8. Estruturas com ponteiros para funções
    printf("8. Estruturas com Ponteiros para Funções:\n");
    typedef void (*FuncaoImpressao)(struct Pessoa*);
    
    struct {
        char nome[20];
        FuncaoImpressao imprimir;
    } operacao = {"Imprimir", imprimir_pessoa};
    
    struct Pessoa *pessoa_teste = criar_pessoa("Teste", 25, 1.75, 'M');
    if (pessoa_teste != NULL) {
        printf("   Executando função via estrutura:\n");
        operacao.imprimir(pessoa_teste);
        free(pessoa_teste);
    }
    printf("\n");
    
    // 9. Comparação de ponteiros
    printf("9. Comparação de Ponteiros:\n");
    struct Pessoa *p1 = criar_pessoa("João", 25, 1.75, 'M');
    struct Pessoa *p2 = criar_pessoa("João", 25, 1.75, 'M');
    struct Pessoa *p3 = p1;  // Mesmo endereço
    
    printf("   p1 == p2? %s\n", (p1 == p2) ? "Sim" : "Não");
    printf("   p1 == p3? %s\n", (p1 == p3) ? "Sim" : "Não");
    
    if (p1 != NULL) free(p1);
    if (p2 != NULL) free(p2);
    printf("\n");
    
    // 10. Demonstração de vazamento de memória
    printf("10. Gerenciamento de Memória:\n");
    printf("   Liberando memória das estruturas...\n");
    
    liberar_lista(lista);
    liberar_arvore(raiz);
    
    printf("   Memória liberada com sucesso!\n");
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 