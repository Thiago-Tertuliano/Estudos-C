#include <stdio.h>
#include <string.h>

// Estrutura básica para pessoa
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
    struct Endereco endereco;
};

// Estrutura para produto
struct Produto {
    char nome[100];
    float preco;
    int quantidade;
    char categoria[30];
};

// Estrutura para data
struct Data {
    int dia;
    int mes;
    int ano;
};

// Estrutura para horário
struct Horario {
    int hora;
    int minuto;
    int segundo;
};

// Estrutura para compromisso
struct Compromisso {
    char descricao[200];
    struct Data data;
    struct Horario horario;
    int prioridade;
};

int main() {
    printf("=== Estruturas Básicas ===\n\n");
    
    // 1. Declaração e inicialização básica
    printf("1. Estrutura Básica:\n");
    struct Pessoa pessoa1 = {"João Silva", 25, 1.75, 'M'};
    printf("   Nome: %s\n", pessoa1.nome);
    printf("   Idade: %d\n", pessoa1.idade);
    printf("   Altura: %.2f\n", pessoa1.altura);
    printf("   Gênero: %c\n", pessoa1.genero);
    printf("\n");
    
    // 2. Acesso e modificação de membros
    printf("2. Modificação de Membros:\n");
    struct Pessoa pessoa2;
    strcpy(pessoa2.nome, "Maria Santos");
    pessoa2.idade = 30;
    pessoa2.altura = 1.65;
    pessoa2.genero = 'F';
    
    printf("   Nome: %s\n", pessoa2.nome);
    printf("   Idade: %d\n", pessoa2.idade);
    printf("   Altura: %.2f\n", pessoa2.altura);
    printf("   Gênero: %c\n", pessoa2.genero);
    printf("\n");
    
    // 3. Inicialização com designadores
    printf("3. Inicialização com Designadores:\n");
    struct Pessoa pessoa3 = {
        .nome = "Pedro Costa",
        .idade = 28,
        .altura = 1.80,
        .genero = 'M'
    };
    
    printf("   Nome: %s\n", pessoa3.nome);
    printf("   Idade: %d\n", pessoa3.idade);
    printf("   Altura: %.2f\n", pessoa3.altura);
    printf("   Gênero: %c\n", pessoa3.genero);
    printf("\n");
    
    // 4. Estrutura aninhada
    printf("4. Estrutura Aninhada:\n");
    struct PessoaCompleta pessoa_completa = {
        .nome = "Ana Oliveira",
        .idade = 35,
        .altura = 1.70,
        .genero = 'F',
        .endereco = {
            .rua = "Rua das Flores",
            .cidade = "São Paulo",
            .estado = "SP",
            .numero = 123,
            .cep = "01234-567"
        }
    };
    
    printf("   Nome: %s\n", pessoa_completa.nome);
    printf("   Idade: %d\n", pessoa_completa.idade);
    printf("   Endereço: %s, %d - %s, %s - %s\n", 
           pessoa_completa.endereco.rua,
           pessoa_completa.endereco.numero,
           pessoa_completa.endereco.cidade,
           pessoa_completa.endereco.estado,
           pessoa_completa.endereco.cep);
    printf("\n");
    
    // 5. Array de estruturas
    printf("5. Array de Estruturas:\n");
    struct Produto produtos[3] = {
        {"Notebook", 2500.00, 5, "Eletrônicos"},
        {"Livro C", 45.50, 10, "Livros"},
        {"Mouse", 25.00, 20, "Periféricos"}
    };
    
    for (int i = 0; i < 3; i++) {
        printf("   Produto %d:\n", i + 1);
        printf("     Nome: %s\n", produtos[i].nome);
        printf("     Preço: R$ %.2f\n", produtos[i].preco);
        printf("     Quantidade: %d\n", produtos[i].quantidade);
        printf("     Categoria: %s\n", produtos[i].categoria);
        printf("\n");
    }
    
    // 6. Estruturas com datas e horários
    printf("6. Estruturas com Datas e Horários:\n");
    struct Compromisso compromisso = {
        .descricao = "Reunião de projeto",
        .data = {15, 12, 2024},
        .horario = {14, 30, 0},
        .prioridade = 1
    };
    
    printf("   Descrição: %s\n", compromisso.descricao);
    printf("   Data: %02d/%02d/%d\n", 
           compromisso.data.dia, 
           compromisso.data.mes, 
           compromisso.data.ano);
    printf("   Horário: %02d:%02d:%02d\n", 
           compromisso.horario.hora, 
           compromisso.horario.minuto, 
           compromisso.horario.segundo);
    printf("   Prioridade: %d\n", compromisso.prioridade);
    printf("\n");
    
    // 7. Comparação de estruturas
    printf("7. Comparação de Estruturas:\n");
    struct Pessoa pessoa4 = {"Carlos", 25, 1.75, 'M'};
    struct Pessoa pessoa5 = {"Carlos", 25, 1.75, 'M'};
    
    // Comparação manual (não é possível comparar estruturas diretamente)
    int sao_iguais = (strcmp(pessoa4.nome, pessoa5.nome) == 0 &&
                     pessoa4.idade == pessoa5.idade &&
                     pessoa4.altura == pessoa5.altura &&
                     pessoa4.genero == pessoa5.genero);
    
    printf("   Pessoa 4: %s, %d anos\n", pessoa4.nome, pessoa4.idade);
    printf("   Pessoa 5: %s, %d anos\n", pessoa5.nome, pessoa5.idade);
    printf("   São iguais? %s\n", sao_iguais ? "Sim" : "Não");
    printf("\n");
    
    // 8. Cálculos com estruturas
    printf("8. Cálculos com Estruturas:\n");
    struct Produto produto1 = {"Produto A", 100.00, 5, "Categoria 1"};
    struct Produto produto2 = {"Produto B", 50.00, 10, "Categoria 2"};
    
    float valor_total1 = produto1.preco * produto1.quantidade;
    float valor_total2 = produto2.preco * produto2.quantidade;
    float valor_total_geral = valor_total1 + valor_total2;
    
    printf("   %s: R$ %.2f x %d = R$ %.2f\n", 
           produto1.nome, produto1.preco, produto1.quantidade, valor_total1);
    printf("   %s: R$ %.2f x %d = R$ %.2f\n", 
           produto2.nome, produto2.preco, produto2.quantidade, valor_total2);
    printf("   Valor total: R$ %.2f\n", valor_total_geral);
    printf("\n");
    
    // 9. Estruturas como parâmetros (simulação)
    printf("9. Estruturas como Parâmetros:\n");
    struct Pessoa pessoas[] = {pessoa1, pessoa2, pessoa3, pessoa4};
    int num_pessoas = 4;
    
    printf("   Lista de pessoas:\n");
    for (int i = 0; i < num_pessoas; i++) {
        printf("     %d. %s (%d anos)\n", 
               i + 1, pessoas[i].nome, pessoas[i].idade);
    }
    printf("\n");
    
    // 10. Demonstração de tamanho de estruturas
    printf("10. Tamanho das Estruturas:\n");
    printf("   Tamanho de struct Pessoa: %zu bytes\n", sizeof(struct Pessoa));
    printf("   Tamanho de struct Endereco: %zu bytes\n", sizeof(struct Endereco));
    printf("   Tamanho de struct PessoaCompleta: %zu bytes\n", sizeof(struct PessoaCompleta));
    printf("   Tamanho de struct Produto: %zu bytes\n", sizeof(struct Produto));
    printf("   Tamanho de struct Compromisso: %zu bytes\n", sizeof(struct Compromisso));
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 