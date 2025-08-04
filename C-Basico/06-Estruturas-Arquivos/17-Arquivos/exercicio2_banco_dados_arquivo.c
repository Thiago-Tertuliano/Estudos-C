#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para cliente
struct Cliente {
    int id;
    char nome[100];
    char email[100];
    char telefone[20];
    float saldo;
    char status[20];
};

// Estrutura para transação
struct Transacao {
    int id;
    int cliente_id;
    char tipo[20]; // "deposito", "saque", "transferencia"
    float valor;
    char data[20];
    char descricao[200];
};

// Função para adicionar cliente
void adicionar_cliente(const char *arquivo) {
    FILE *arq = fopen(arquivo, "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de clientes!\n");
        return;
    }
    
    struct Cliente cliente;
    
    printf("=== ADICIONAR CLIENTE ===\n");
    printf("ID: ");
    scanf("%d", &cliente.id);
    getchar();
    
    printf("Nome: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = 0;
    
    printf("Email: ");
    fgets(cliente.email, sizeof(cliente.email), stdin);
    cliente.email[strcspn(cliente.email, "\n")] = 0;
    
    printf("Telefone: ");
    fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
    cliente.telefone[strcspn(cliente.telefone, "\n")] = 0;
    
    printf("Saldo inicial: ");
    scanf("%f", &cliente.saldo);
    getchar();
    
    strcpy(cliente.status, "ativo");
    
    fwrite(&cliente, sizeof(struct Cliente), 1, arq);
    fclose(arq);
    
    printf("Cliente adicionado com sucesso!\n");
}

// Função para listar todos os clientes
void listar_clientes(const char *arquivo) {
    FILE *arq = fopen(arquivo, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de clientes!\n");
        return;
    }
    
    struct Cliente cliente;
    int contador = 0;
    
    printf("=== LISTA DE CLIENTES ===\n");
    printf("%-5s %-30s %-25s %-15s %-10s %-10s\n", 
           "ID", "Nome", "Email", "Telefone", "Saldo", "Status");
    printf("--------------------------------------------------------------------------------\n");
    
    while (fread(&cliente, sizeof(struct Cliente), 1, arq) == 1) {
        printf("%-5d %-30s %-25s %-15s %-10.2f %-10s\n",
               cliente.id, cliente.nome, cliente.email, 
               cliente.telefone, cliente.saldo, cliente.status);
        contador++;
    }
    
    printf("--------------------------------------------------------------------------------\n");
    printf("Total de clientes: %d\n", contador);
    
    fclose(arq);
}

// Função para buscar cliente por ID
struct Cliente* buscar_cliente(const char *arquivo, int id) {
    FILE *arq = fopen(arquivo, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de clientes!\n");
        return NULL;
    }
    
    struct Cliente *cliente = malloc(sizeof(struct Cliente));
    
    while (fread(cliente, sizeof(struct Cliente), 1, arq) == 1) {
        if (cliente->id == id) {
            fclose(arq);
            return cliente;
        }
    }
    
    fclose(arq);
    free(cliente);
    return NULL;
}

// Função para atualizar saldo do cliente
void atualizar_saldo(const char *arquivo, int id, float novo_saldo) {
    FILE *arq = fopen(arquivo, "rb+");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de clientes!\n");
        return;
    }
    
    struct Cliente cliente;
    long posicao;
    
    while (fread(&cliente, sizeof(struct Cliente), 1, arq) == 1) {
        if (cliente.id == id) {
            posicao = ftell(arq) - sizeof(struct Cliente);
            fseek(arq, posicao, SEEK_SET);
            
            cliente.saldo = novo_saldo;
            fwrite(&cliente, sizeof(struct Cliente), 1, arq);
            
            fclose(arq);
            printf("Saldo atualizado com sucesso!\n");
            return;
        }
    }
    
    fclose(arq);
    printf("Cliente não encontrado!\n");
}

// Função para registrar transação
void registrar_transacao(const char *arquivo_transacoes, int cliente_id, 
                        const char *tipo, float valor, const char *descricao) {
    FILE *arq = fopen(arquivo_transacoes, "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de transações!\n");
        return;
    }
    
    struct Transacao transacao;
    static int proximo_id = 1;
    
    transacao.id = proximo_id++;
    transacao.cliente_id = cliente_id;
    strcpy(transacao.tipo, tipo);
    transacao.valor = valor;
    strcpy(transacao.descricao, descricao);
    
    // Data atual (simplificada)
    strcpy(transacao.data, "2024-12-15");
    
    fwrite(&transacao, sizeof(struct Transacao), 1, arq);
    fclose(arq);
    
    printf("Transação registrada com sucesso!\n");
}

// Função para realizar depósito
void realizar_deposito(const char *arquivo_clientes, const char *arquivo_transacoes) {
    int id;
    float valor;
    
    printf("ID do cliente: ");
    scanf("%d", &id);
    printf("Valor do depósito: ");
    scanf("%f", &valor);
    
    struct Cliente *cliente = buscar_cliente(arquivo_clientes, id);
    if (cliente == NULL) {
        printf("Cliente não encontrado!\n");
        return;
    }
    
    float novo_saldo = cliente->saldo + valor;
    atualizar_saldo(arquivo_clientes, id, novo_saldo);
    
    char descricao[200];
    sprintf(descricao, "Depósito de R$ %.2f", valor);
    registrar_transacao(arquivo_transacoes, id, "deposito", valor, descricao);
    
    free(cliente);
}

// Função para realizar saque
void realizar_saque(const char *arquivo_clientes, const char *arquivo_transacoes) {
    int id;
    float valor;
    
    printf("ID do cliente: ");
    scanf("%d", &id);
    printf("Valor do saque: ");
    scanf("%f", &valor);
    
    struct Cliente *cliente = buscar_cliente(arquivo_clientes, id);
    if (cliente == NULL) {
        printf("Cliente não encontrado!\n");
        return;
    }
    
    if (cliente->saldo < valor) {
        printf("Saldo insuficiente!\n");
        free(cliente);
        return;
    }
    
    float novo_saldo = cliente->saldo - valor;
    atualizar_saldo(arquivo_clientes, id, novo_saldo);
    
    char descricao[200];
    sprintf(descricao, "Saque de R$ %.2f", valor);
    registrar_transacao(arquivo_transacoes, id, "saque", valor, descricao);
    
    free(cliente);
}

// Função para listar transações de um cliente
void listar_transacoes_cliente(const char *arquivo_transacoes, int cliente_id) {
    FILE *arq = fopen(arquivo_transacoes, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de transações!\n");
        return;
    }
    
    struct Transacao transacao;
    int encontrado = 0;
    
    printf("=== TRANSAÇÕES DO CLIENTE %d ===\n", cliente_id);
    printf("%-5s %-15s %-10s %-20s %-50s\n", 
           "ID", "Tipo", "Valor", "Data", "Descrição");
    printf("--------------------------------------------------------------------------------\n");
    
    while (fread(&transacao, sizeof(struct Transacao), 1, arq) == 1) {
        if (transacao.cliente_id == cliente_id) {
            printf("%-5d %-15s %-10.2f %-20s %-50s\n",
                   transacao.id, transacao.tipo, transacao.valor, 
                   transacao.data, transacao.descricao);
            encontrado = 1;
        }
    }
    
    if (!encontrado) {
        printf("Nenhuma transação encontrada para este cliente.\n");
    }
    
    printf("--------------------------------------------------------------------------------\n");
    fclose(arq);
}

// Função para gerar relatório de saldos
void gerar_relatorio_saldos(const char *arquivo_clientes) {
    FILE *arq = fopen(arquivo_clientes, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de clientes!\n");
        return;
    }
    
    struct Cliente cliente;
    float total_saldos = 0;
    int total_clientes = 0;
    float maior_saldo = 0;
    float menor_saldo = 999999;
    
    printf("=== RELATÓRIO DE SALDOS ===\n");
    
    while (fread(&cliente, sizeof(struct Cliente), 1, arq) == 1) {
        total_saldos += cliente.saldo;
        total_clientes++;
        
        if (cliente.saldo > maior_saldo) {
            maior_saldo = cliente.saldo;
        }
        if (cliente.saldo < menor_saldo) {
            menor_saldo = cliente.saldo;
        }
    }
    
    printf("Total de clientes: %d\n", total_clientes);
    printf("Soma total dos saldos: R$ %.2f\n", total_saldos);
    printf("Média dos saldos: R$ %.2f\n", total_saldos / total_clientes);
    printf("Maior saldo: R$ %.2f\n", maior_saldo);
    printf("Menor saldo: R$ %.2f\n", menor_saldo);
    
    fclose(arq);
}

int main() {
    const char *arquivo_clientes = "clientes.dat";
    const char *arquivo_transacoes = "transacoes.dat";
    int opcao;
    
    printf("=== SISTEMA DE BANCO DE DADOS EM ARQUIVO ===\n\n");
    
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Adicionar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Realizar depósito\n");
        printf("4. Realizar saque\n");
        printf("5. Listar transações de cliente\n");
        printf("6. Gerar relatório de saldos\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                adicionar_cliente(arquivo_clientes);
                break;
                
            case 2:
                listar_clientes(arquivo_clientes);
                break;
                
            case 3:
                realizar_deposito(arquivo_clientes, arquivo_transacoes);
                break;
                
            case 4:
                realizar_saque(arquivo_clientes, arquivo_transacoes);
                break;
                
            case 5:
                printf("ID do cliente: ");
                int id;
                scanf("%d", &id);
                listar_transacoes_cliente(arquivo_transacoes, id);
                break;
                
            case 6:
                gerar_relatorio_saldos(arquivo_clientes);
                break;
                
            case 0:
                printf("Saindo do sistema...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
        
    } while (opcao != 0);
    
    return 0;
} 