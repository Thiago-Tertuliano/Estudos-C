#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para endereço
struct Endereco {
    char rua[100];
    char bairro[50];
    char cidade[50];
    char estado[3];
    int numero;
    char cep[10];
    char complemento[50];
};

// Estrutura para contato
struct Contato {
    char telefone[15];
    char email[100];
    char celular[15];
};

// Estrutura para pessoa
struct Pessoa {
    char nome[100];
    char cpf[15];
    int idade;
    char genero;
    float altura;
    float peso;
    struct Endereco endereco;
    struct Contato contato;
    char profissao[50];
    float salario;
    char estado_civil[20];
    char data_nascimento[11];
};

// Estrutura para cadastro
struct Cadastro {
    struct Pessoa *pessoas;
    int num_pessoas;
    int capacidade;
};

// Função para criar cadastro
struct Cadastro* criar_cadastro(int capacidade_inicial) {
    struct Cadastro *cadastro = malloc(sizeof(struct Cadastro));
    if (cadastro != NULL) {
        cadastro->pessoas = malloc(capacidade_inicial * sizeof(struct Pessoa));
        if (cadastro->pessoas != NULL) {
            cadastro->num_pessoas = 0;
            cadastro->capacidade = capacidade_inicial;
        } else {
            free(cadastro);
            cadastro = NULL;
        }
    }
    return cadastro;
}

// Função para expandir cadastro
int expandir_cadastro(struct Cadastro *cadastro) {
    if (cadastro == NULL) return 0;
    
    int nova_capacidade = cadastro->capacidade * 2;
    struct Pessoa *novo_array = realloc(cadastro->pessoas, nova_capacidade * sizeof(struct Pessoa));
    
    if (novo_array != NULL) {
        cadastro->pessoas = novo_array;
        cadastro->capacidade = nova_capacidade;
        return 1;
    }
    return 0;
}

// Função para adicionar pessoa
int adicionar_pessoa(struct Cadastro *cadastro, struct Pessoa pessoa) {
    if (cadastro == NULL) return 0;
    
    if (cadastro->num_pessoas >= cadastro->capacidade) {
        if (!expandir_cadastro(cadastro)) {
            return 0;
        }
    }
    
    cadastro->pessoas[cadastro->num_pessoas] = pessoa;
    cadastro->num_pessoas++;
    return 1;
}

// Função para buscar pessoa por CPF
struct Pessoa* buscar_por_cpf(struct Cadastro *cadastro, const char *cpf) {
    if (cadastro == NULL) return NULL;
    
    for (int i = 0; i < cadastro->num_pessoas; i++) {
        if (strcmp(cadastro->pessoas[i].cpf, cpf) == 0) {
            return &cadastro->pessoas[i];
        }
    }
    return NULL;
}

// Função para buscar pessoa por nome
struct Pessoa* buscar_por_nome(struct Cadastro *cadastro, const char *nome) {
    if (cadastro == NULL) return NULL;
    
    for (int i = 0; i < cadastro->num_pessoas; i++) {
        if (strstr(cadastro->pessoas[i].nome, nome) != NULL) {
            return &cadastro->pessoas[i];
        }
    }
    return NULL;
}

// Função para remover pessoa
int remover_pessoa(struct Cadastro *cadastro, const char *cpf) {
    if (cadastro == NULL) return 0;
    
    for (int i = 0; i < cadastro->num_pessoas; i++) {
        if (strcmp(cadastro->pessoas[i].cpf, cpf) == 0) {
            // Mover elementos para preencher o espaço
            for (int j = i; j < cadastro->num_pessoas - 1; j++) {
                cadastro->pessoas[j] = cadastro->pessoas[j + 1];
            }
            cadastro->num_pessoas--;
            return 1;
        }
    }
    return 0;
}

// Função para imprimir pessoa
void imprimir_pessoa(struct Pessoa *pessoa) {
    if (pessoa == NULL) return;
    
    printf("\n=== Dados da Pessoa ===\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("CPF: %s\n", pessoa->cpf);
    printf("Idade: %d anos\n", pessoa->idade);
    printf("Gênero: %c\n", pessoa->genero);
    printf("Altura: %.2f m\n", pessoa->altura);
    printf("Peso: %.1f kg\n", pessoa->peso);
    printf("Profissão: %s\n", pessoa->profissao);
    printf("Salário: R$ %.2f\n", pessoa->salario);
    printf("Estado Civil: %s\n", pessoa->estado_civil);
    printf("Data de Nascimento: %s\n", pessoa->data_nascimento);
    
    printf("\n=== Endereço ===\n");
    printf("Rua: %s, %d\n", pessoa->endereco.rua, pessoa->endereco.numero);
    printf("Bairro: %s\n", pessoa->endereco.bairro);
    printf("Cidade: %s - %s\n", pessoa->endereco.cidade, pessoa->endereco.estado);
    printf("CEP: %s\n", pessoa->endereco.cep);
    if (strlen(pessoa->endereco.complemento) > 0) {
        printf("Complemento: %s\n", pessoa->endereco.complemento);
    }
    
    printf("\n=== Contato ===\n");
    printf("Telefone: %s\n", pessoa->contato.telefone);
    printf("Celular: %s\n", pessoa->contato.celular);
    printf("Email: %s\n", pessoa->contato.email);
}

// Função para listar todas as pessoas
void listar_pessoas(struct Cadastro *cadastro) {
    if (cadastro == NULL || cadastro->num_pessoas == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }
    
    printf("\n=== Lista de Pessoas Cadastradas ===\n");
    for (int i = 0; i < cadastro->num_pessoas; i++) {
        printf("%d. %s - CPF: %s - Idade: %d\n", 
               i + 1, cadastro->pessoas[i].nome, 
               cadastro->pessoas[i].cpf, cadastro->pessoas[i].idade);
    }
}

// Função para calcular estatísticas
void estatisticas_cadastro(struct Cadastro *cadastro) {
    if (cadastro == NULL || cadastro->num_pessoas == 0) {
        printf("Nenhuma pessoa cadastrada para calcular estatísticas.\n");
        return;
    }
    
    float media_idade = 0, media_altura = 0, media_peso = 0, media_salario = 0;
    int homens = 0, mulheres = 0;
    float maior_salario = cadastro->pessoas[0].salario;
    float menor_salario = cadastro->pessoas[0].salario;
    
    for (int i = 0; i < cadastro->num_pessoas; i++) {
        media_idade += cadastro->pessoas[i].idade;
        media_altura += cadastro->pessoas[i].altura;
        media_peso += cadastro->pessoas[i].peso;
        media_salario += cadastro->pessoas[i].salario;
        
        if (cadastro->pessoas[i].genero == 'M') homens++;
        else mulheres++;
        
        if (cadastro->pessoas[i].salario > maior_salario) {
            maior_salario = cadastro->pessoas[i].salario;
        }
        if (cadastro->pessoas[i].salario < menor_salario) {
            menor_salario = cadastro->pessoas[i].salario;
        }
    }
    
    media_idade /= cadastro->num_pessoas;
    media_altura /= cadastro->num_pessoas;
    media_peso /= cadastro->num_pessoas;
    media_salario /= cadastro->num_pessoas;
    
    printf("\n=== Estatísticas do Cadastro ===\n");
    printf("Total de pessoas: %d\n", cadastro->num_pessoas);
    printf("Homens: %d (%.1f%%)\n", homens, (float)homens/cadastro->num_pessoas*100);
    printf("Mulheres: %d (%.1f%%)\n", mulheres, (float)mulheres/cadastro->num_pessoas*100);
    printf("Média de idade: %.1f anos\n", media_idade);
    printf("Média de altura: %.2f m\n", media_altura);
    printf("Média de peso: %.1f kg\n", media_peso);
    printf("Média de salário: R$ %.2f\n", media_salario);
    printf("Maior salário: R$ %.2f\n", maior_salario);
    printf("Menor salário: R$ %.2f\n", menor_salario);
}

// Função para ler dados da pessoa
struct Pessoa ler_dados_pessoa() {
    struct Pessoa pessoa;
    
    printf("\n=== Cadastro de Nova Pessoa ===\n");
    
    printf("Nome completo: ");
    scanf(" %[^\n]", pessoa.nome);
    
    printf("CPF: ");
    scanf(" %s", pessoa.cpf);
    
    printf("Idade: ");
    scanf("%d", &pessoa.idade);
    
    printf("Gênero (M/F): ");
    scanf(" %c", &pessoa.genero);
    
    printf("Altura (em metros): ");
    scanf("%f", &pessoa.altura);
    
    printf("Peso (em kg): ");
    scanf("%f", &pessoa.peso);
    
    printf("Profissão: ");
    scanf(" %[^\n]", pessoa.profissao);
    
    printf("Salário: ");
    scanf("%f", &pessoa.salario);
    
    printf("Estado civil: ");
    scanf(" %[^\n]", pessoa.estado_civil);
    
    printf("Data de nascimento (DD/MM/AAAA): ");
    scanf(" %s", pessoa.data_nascimento);
    
    printf("\n=== Endereço ===\n");
    printf("Rua: ");
    scanf(" %[^\n]", pessoa.endereco.rua);
    
    printf("Número: ");
    scanf("%d", &pessoa.endereco.numero);
    
    printf("Bairro: ");
    scanf(" %[^\n]", pessoa.endereco.bairro);
    
    printf("Cidade: ");
    scanf(" %[^\n]", pessoa.endereco.cidade);
    
    printf("Estado (sigla): ");
    scanf(" %s", pessoa.endereco.estado);
    
    printf("CEP: ");
    scanf(" %s", pessoa.endereco.cep);
    
    printf("Complemento (opcional): ");
    scanf(" %[^\n]", pessoa.endereco.complemento);
    
    printf("\n=== Contato ===\n");
    printf("Telefone: ");
    scanf(" %s", pessoa.contato.telefone);
    
    printf("Celular: ");
    scanf(" %s", pessoa.contato.celular);
    
    printf("Email: ");
    scanf(" %s", pessoa.contato.email);
    
    return pessoa;
}

// Função para liberar cadastro
void liberar_cadastro(struct Cadastro *cadastro) {
    if (cadastro != NULL) {
        if (cadastro->pessoas != NULL) {
            free(cadastro->pessoas);
        }
        free(cadastro);
    }
}

int main() {
    printf("=== Sistema de Cadastro ===\n\n");
    
    struct Cadastro *cadastro = criar_cadastro(10);
    if (cadastro == NULL) {
        printf("Erro ao criar cadastro!\n");
        return 1;
    }
    
    int opcao;
    char cpf_busca[15], nome_busca[100];
    
    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Cadastrar nova pessoa\n");
        printf("2. Buscar por CPF\n");
        printf("3. Buscar por nome\n");
        printf("4. Listar todas as pessoas\n");
        printf("5. Remover pessoa\n");
        printf("6. Estatísticas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                struct Pessoa nova_pessoa = ler_dados_pessoa();
                if (adicionar_pessoa(cadastro, nova_pessoa)) {
                    printf("\nPessoa cadastrada com sucesso!\n");
                } else {
                    printf("\nErro ao cadastrar pessoa!\n");
                }
                break;
            }
            
            case 2: {
                printf("Digite o CPF para busca: ");
                scanf(" %s", cpf_busca);
                
                struct Pessoa *pessoa = buscar_por_cpf(cadastro, cpf_busca);
                if (pessoa != NULL) {
                    imprimir_pessoa(pessoa);
                } else {
                    printf("Pessoa não encontrada!\n");
                }
                break;
            }
            
            case 3: {
                printf("Digite o nome para busca: ");
                scanf(" %[^\n]", nome_busca);
                
                struct Pessoa *pessoa = buscar_por_nome(cadastro, nome_busca);
                if (pessoa != NULL) {
                    imprimir_pessoa(pessoa);
                } else {
                    printf("Pessoa não encontrada!\n");
                }
                break;
            }
            
            case 4: {
                listar_pessoas(cadastro);
                break;
            }
            
            case 5: {
                printf("Digite o CPF da pessoa a ser removida: ");
                scanf(" %s", cpf_busca);
                
                if (remover_pessoa(cadastro, cpf_busca)) {
                    printf("Pessoa removida com sucesso!\n");
                } else {
                    printf("Pessoa não encontrada!\n");
                }
                break;
            }
            
            case 6: {
                estatisticas_cadastro(cadastro);
                break;
            }
            
            case 0:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
                break;
        }
        
    } while (opcao != 0);
    
    liberar_cadastro(cadastro);
    printf("=== Fim do Programa ===\n");
    
    return 0;
} 