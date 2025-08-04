#include <stdio.h>
#include <string.h>

// Estrutura para aluno
struct Aluno {
    char nome[50];
    int matricula;
    float notas[4];
    float media;
    char status[20];
};

// Estrutura para funcionário
struct Funcionario {
    char nome[50];
    char cargo[30];
    float salario;
    int departamento;
    char data_admissao[11];
};

// Estrutura para livro
struct Livro {
    char titulo[100];
    char autor[50];
    char isbn[20];
    int ano_publicacao;
    float preco;
    int quantidade_estoque;
};

// Estrutura para conta bancária
struct ContaBancaria {
    int numero;
    char titular[50];
    float saldo;
    char tipo[20];
    char data_abertura[11];
};

// Estrutura para produto
struct Produto {
    char codigo[20];
    char nome[100];
    float preco;
    int quantidade;
    char categoria[30];
    char fornecedor[50];
};

// Função para calcular média do aluno
void calcular_media_aluno(struct Aluno *aluno) {
    float soma = 0;
    for (int i = 0; i < 4; i++) {
        soma += aluno->notas[i];
    }
    aluno->media = soma / 4.0;
    
    if (aluno->media >= 7.0) {
        strcpy(aluno->status, "Aprovado");
    } else if (aluno->media >= 5.0) {
        strcpy(aluno->status, "Recuperação");
    } else {
        strcpy(aluno->status, "Reprovado");
    }
}

// Função para imprimir dados do aluno
void imprimir_aluno(struct Aluno aluno) {
    printf("   Nome: %s\n", aluno.nome);
    printf("   Matrícula: %d\n", aluno.matricula);
    printf("   Notas: %.1f, %.1f, %.1f, %.1f\n", 
           aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.notas[3]);
    printf("   Média: %.2f\n", aluno.media);
    printf("   Status: %s\n", aluno.status);
}

// Função para buscar aluno por matrícula
struct Aluno* buscar_aluno(struct Aluno *turma, int num_alunos, int matricula) {
    for (int i = 0; i < num_alunos; i++) {
        if (turma[i].matricula == matricula) {
            return &turma[i];
        }
    }
    return NULL;
}

// Função para calcular estatísticas da turma
void estatisticas_turma(struct Aluno *turma, int num_alunos, 
                        float *media_geral, int *aprovados, int *reprovados) {
    float soma_medias = 0;
    *aprovados = 0;
    *reprovados = 0;
    
    for (int i = 0; i < num_alunos; i++) {
        soma_medias += turma[i].media;
        if (strcmp(turma[i].status, "Aprovado") == 0) {
            (*aprovados)++;
        } else if (strcmp(turma[i].status, "Reprovado") == 0) {
            (*reprovados)++;
        }
    }
    
    *media_geral = soma_medias / num_alunos;
}

// Função para ordenar alunos por média
void ordenar_alunos_por_media(struct Aluno *turma, int num_alunos) {
    for (int i = 0; i < num_alunos - 1; i++) {
        for (int j = 0; j < num_alunos - i - 1; j++) {
            if (turma[j].media < turma[j + 1].media) {
                struct Aluno temp = turma[j];
                turma[j] = turma[j + 1];
                turma[j + 1] = temp;
            }
        }
    }
}

// Função para calcular folha de pagamento
float calcular_folha_pagamento(struct Funcionario *funcionarios, int num_funcionarios) {
    float total = 0;
    for (int i = 0; i < num_funcionarios; i++) {
        total += funcionarios[i].salario;
    }
    return total;
}

// Função para buscar funcionários por departamento
void funcionarios_por_departamento(struct Funcionario *funcionarios, int num_funcionarios, 
                                 int departamento) {
    printf("   Funcionários do departamento %d:\n", departamento);
    for (int i = 0; i < num_funcionarios; i++) {
        if (funcionarios[i].departamento == departamento) {
            printf("     %s - %s - R$ %.2f\n", 
                   funcionarios[i].nome, 
                   funcionarios[i].cargo, 
                   funcionarios[i].salario);
        }
    }
}

// Função para calcular valor total do estoque
float calcular_valor_estoque(struct Produto *produtos, int num_produtos) {
    float valor_total = 0;
    for (int i = 0; i < num_produtos; i++) {
        valor_total += produtos[i].preco * produtos[i].quantidade;
    }
    return valor_total;
}

int main() {
    printf("=== Arrays de Estruturas ===\n\n");
    
    // 1. Array de alunos
    printf("1. Sistema de Alunos:\n");
    struct Aluno turma[5] = {
        {"João Silva", 1001, {8.5, 7.0, 9.0, 8.0}, 0, ""},
        {"Maria Santos", 1002, {6.0, 5.5, 7.0, 6.5}, 0, ""},
        {"Pedro Costa", 1003, {9.5, 9.0, 8.5, 9.0}, 0, ""},
        {"Ana Oliveira", 1004, {4.0, 5.0, 3.5, 4.5}, 0, ""},
        {"Carlos Lima", 1005, {7.5, 8.0, 7.0, 8.5}, 0, ""}
    };
    
    // Calcular médias e status
    for (int i = 0; i < 5; i++) {
        calcular_media_aluno(&turma[i]);
    }
    
    printf("   Lista de alunos:\n");
    for (int i = 0; i < 5; i++) {
        printf("   Aluno %d:\n", i + 1);
        imprimir_aluno(turma[i]);
        printf("\n");
    }
    
    // 2. Busca de aluno
    printf("2. Busca de Aluno:\n");
    int matricula_busca = 1003;
    struct Aluno *aluno_encontrado = buscar_aluno(turma, 5, matricula_busca);
    
    if (aluno_encontrado != NULL) {
        printf("   Aluno encontrado:\n");
        imprimir_aluno(*aluno_encontrado);
    } else {
        printf("   Aluno não encontrado!\n");
    }
    printf("\n");
    
    // 3. Estatísticas da turma
    printf("3. Estatísticas da Turma:\n");
    float media_geral;
    int aprovados, reprovados;
    estatisticas_turma(turma, 5, &media_geral, &aprovados, &reprovados);
    
    printf("   Média geral: %.2f\n", media_geral);
    printf("   Aprovados: %d\n", aprovados);
    printf("   Reprovados: %d\n", reprovados);
    printf("   Em recuperação: %d\n", 5 - aprovados - reprovados);
    printf("\n");
    
    // 4. Ordenação por média
    printf("4. Alunos Ordenados por Média:\n");
    ordenar_alunos_por_media(turma, 5);
    
    for (int i = 0; i < 5; i++) {
        printf("   %d. %s - Média: %.2f\n", 
               i + 1, turma[i].nome, turma[i].media);
    }
    printf("\n");
    
    // 5. Array de funcionários
    printf("5. Sistema de Funcionários:\n");
    struct Funcionario funcionarios[4] = {
        {"Ana Silva", "Desenvolvedor", 5000.00, 1, "15/03/2023"},
        {"João Santos", "Analista", 4500.00, 2, "20/01/2023"},
        {"Maria Costa", "Desenvolvedor", 5200.00, 1, "10/05/2023"},
        {"Pedro Lima", "Gerente", 8000.00, 3, "05/02/2023"}
    };
    
    printf("   Lista de funcionários:\n");
    for (int i = 0; i < 4; i++) {
        printf("   %d. %s - %s - R$ %.2f - Depto: %d\n", 
               i + 1, funcionarios[i].nome, funcionarios[i].cargo, 
               funcionarios[i].salario, funcionarios[i].departamento);
    }
    
    float folha_pagamento = calcular_folha_pagamento(funcionarios, 4);
    printf("   Folha de pagamento total: R$ %.2f\n", folha_pagamento);
    printf("\n");
    
    // 6. Funcionários por departamento
    printf("6. Funcionários por Departamento:\n");
    funcionarios_por_departamento(funcionarios, 4, 1);
    printf("\n");
    
    // 7. Array de livros
    printf("7. Biblioteca de Livros:\n");
    struct Livro livros[3] = {
        {"A Linguagem C", "Brian Kernighan", "978-0131103627", 1988, 45.50, 10},
        {"C Programming", "Dennis Ritchie", "978-0131101630", 1978, 35.00, 5},
        {"Modern C", "Jens Gustedt", "978-1617295812", 2019, 60.00, 8}
    };
    
    printf("   Catálogo de livros:\n");
    for (int i = 0; i < 3; i++) {
        printf("   %d. %s - %s (%d) - R$ %.2f - Estoque: %d\n", 
               i + 1, livros[i].titulo, livros[i].autor, 
               livros[i].ano_publicacao, livros[i].preco, livros[i].quantidade_estoque);
    }
    printf("\n");
    
    // 8. Array de contas bancárias
    printf("8. Sistema Bancário:\n");
    struct ContaBancaria contas[3] = {
        {1001, "João Silva", 5000.00, "Corrente", "15/01/2023"},
        {1002, "Maria Santos", 3200.50, "Poupança", "20/02/2023"},
        {1003, "Pedro Costa", 15000.00, "Corrente", "10/03/2023"}
    };
    
    printf("   Contas bancárias:\n");
    for (int i = 0; i < 3; i++) {
        printf("   Conta %d: %s - R$ %.2f (%s)\n", 
               contas[i].numero, contas[i].titular, 
               contas[i].saldo, contas[i].tipo);
    }
    printf("\n");
    
    // 9. Array de produtos
    printf("9. Sistema de Produtos:\n");
    struct Produto produtos[4] = {
        {"P001", "Notebook Dell", 3500.00, 5, "Eletrônicos", "Dell Inc"},
        {"P002", "Mouse Wireless", 25.00, 50, "Periféricos", "Logitech"},
        {"P003", "Teclado Mecânico", 200.00, 15, "Periféricos", "Corsair"},
        {"P004", "Monitor 24\"", 800.00, 8, "Eletrônicos", "Samsung"}
    };
    
    printf("   Produtos em estoque:\n");
    for (int i = 0; i < 4; i++) {
        printf("   %s - %s - R$ %.2f - Qtd: %d - %s\n", 
               produtos[i].codigo, produtos[i].nome, produtos[i].preco, 
               produtos[i].quantidade, produtos[i].categoria);
    }
    
    float valor_estoque = calcular_valor_estoque(produtos, 4);
    printf("   Valor total do estoque: R$ %.2f\n", valor_estoque);
    printf("\n");
    
    // 10. Operações com arrays de estruturas
    printf("10. Operações Avançadas:\n");
    
    // Encontrar produto mais caro
    struct Produto *produto_mais_caro = &produtos[0];
    for (int i = 1; i < 4; i++) {
        if (produtos[i].preco > produto_mais_caro->preco) {
            produto_mais_caro = &produtos[i];
        }
    }
    printf("   Produto mais caro: %s - R$ %.2f\n", 
           produto_mais_caro->nome, produto_mais_caro->preco);
    
    // Encontrar aluno com maior média
    struct Aluno *melhor_aluno = &turma[0];
    for (int i = 1; i < 5; i++) {
        if (turma[i].media > melhor_aluno->media) {
            melhor_aluno = &turma[i];
        }
    }
    printf("   Melhor aluno: %s - Média: %.2f\n", 
           melhor_aluno->nome, melhor_aluno->media);
    
    // Contar funcionários por departamento
    int dept1 = 0, dept2 = 0, dept3 = 0;
    for (int i = 0; i < 4; i++) {
        switch (funcionarios[i].departamento) {
            case 1: dept1++; break;
            case 2: dept2++; break;
            case 3: dept3++; break;
        }
    }
    printf("   Funcionários por departamento: Depto 1: %d, Depto 2: %d, Depto 3: %d\n", 
           dept1, dept2, dept3);
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 