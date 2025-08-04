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

// Função para escrever texto em arquivo
void escrever_texto(const char *nome_arquivo, const char *texto) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita!\n");
        return;
    }
    
    fprintf(arquivo, "%s\n", texto);
    fclose(arquivo);
    printf("Texto escrito no arquivo '%s'\n", nome_arquivo);
}

// Função para ler texto de arquivo
void ler_texto(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para leitura!\n");
        return;
    }
    
    char linha[100];
    printf("Conteúdo do arquivo '%s':\n", nome_arquivo);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    
    fclose(arquivo);
}

// Função para anexar texto ao arquivo
void anexar_texto(const char *nome_arquivo, const char *texto) {
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para anexar!\n");
        return;
    }
    
    fprintf(arquivo, "%s\n", texto);
    fclose(arquivo);
    printf("Texto anexado ao arquivo '%s'\n", nome_arquivo);
}

// Função para escrever dados formatados
void escrever_dados_formatados(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    fprintf(arquivo, "=== Dados Formatados ===\n");
    fprintf(arquivo, "Nome: João Silva\n");
    fprintf(arquivo, "Idade: %d\n", 25);
    fprintf(arquivo, "Altura: %.2f\n", 1.75);
    fprintf(arquivo, "Salário: R$ %.2f\n", 2500.50);
    fprintf(arquivo, "Data: %02d/%02d/%d\n", 15, 12, 2024);
    
    fclose(arquivo);
    printf("Dados formatados escritos no arquivo '%s'\n", nome_arquivo);
}

// Função para ler dados formatados
void ler_dados_formatados(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    char linha[100];
    printf("Dados lidos do arquivo '%s':\n", nome_arquivo);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    
    fclose(arquivo);
}

// Função para escrever estrutura em arquivo binário
void escrever_estrutura_binaria(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo binário!\n");
        return;
    }
    
    struct Pessoa pessoas[] = {
        {"João Silva", 25, 1.75, 'M'},
        {"Maria Santos", 30, 1.65, 'F'},
        {"Pedro Costa", 28, 1.80, 'M'},
        {"Ana Oliveira", 35, 1.70, 'F'}
    };
    
    int num_pessoas = 4;
    fwrite(&num_pessoas, sizeof(int), 1, arquivo);
    fwrite(pessoas, sizeof(struct Pessoa), num_pessoas, arquivo);
    
    fclose(arquivo);
    printf("Estruturas escritas no arquivo binário '%s'\n", nome_arquivo);
}

// Função para ler estrutura de arquivo binário
void ler_estrutura_binaria(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo binário!\n");
        return;
    }
    
    int num_pessoas;
    fread(&num_pessoas, sizeof(int), 1, arquivo);
    
    struct Pessoa *pessoas = malloc(num_pessoas * sizeof(struct Pessoa));
    fread(pessoas, sizeof(struct Pessoa), num_pessoas, arquivo);
    
    printf("Pessoas lidas do arquivo binário '%s':\n", nome_arquivo);
    for (int i = 0; i < num_pessoas; i++) {
        printf("  %d. %s - %d anos - %.2f m - %c\n", 
               i + 1, pessoas[i].nome, pessoas[i].idade, 
               pessoas[i].altura, pessoas[i].genero);
    }
    
    free(pessoas);
    fclose(arquivo);
}

// Função para copiar arquivo
void copiar_arquivo(const char *origem, const char *destino) {
    FILE *arq_origem = fopen(origem, "r");
    FILE *arq_destino = fopen(destino, "w");
    
    if (arq_origem == NULL || arq_destino == NULL) {
        printf("Erro ao abrir arquivos para cópia!\n");
        if (arq_origem != NULL) fclose(arq_origem);
        if (arq_destino != NULL) fclose(arq_destino);
        return;
    }
    
    char caractere;
    while ((caractere = fgetc(arq_origem)) != EOF) {
        fputc(caractere, arq_destino);
    }
    
    fclose(arq_origem);
    fclose(arq_destino);
    printf("Arquivo '%s' copiado para '%s'\n", origem, destino);
}

// Função para contar linhas de arquivo
int contar_linhas(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return -1;
    }
    
    int linhas = 0;
    char caractere;
    
    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            linhas++;
        }
    }
    
    fclose(arquivo);
    return linhas;
}

// Função para buscar texto em arquivo
void buscar_texto(const char *nome_arquivo, const char *texto_busca) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    char linha[100];
    int linha_num = 1;
    int encontrado = 0;
    
    printf("Buscando '%s' no arquivo '%s':\n", texto_busca, nome_arquivo);
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, texto_busca) != NULL) {
            printf("  Linha %d: %s", linha_num, linha);
            encontrado = 1;
        }
        linha_num++;
    }
    
    if (!encontrado) {
        printf("  Texto não encontrado!\n");
    }
    
    fclose(arquivo);
}

// Função para mostrar informações do arquivo
void info_arquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    // Contar caracteres
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    
    // Contar linhas
    rewind(arquivo);
    int linhas = 0;
    char caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') linhas++;
    }
    
    fclose(arquivo);
    
    printf("Informações do arquivo '%s':\n", nome_arquivo);
    printf("  Tamanho: %ld bytes\n", tamanho);
    printf("  Linhas: %d\n", linhas);
}

int main() {
    printf("=== Operações Básicas com Arquivos ===\n\n");
    
    // 1. Escrita e leitura de texto simples
    printf("1. Escrita e Leitura de Texto:\n");
    escrever_texto("exemplo.txt", "Olá, mundo! Este é um arquivo de exemplo.");
    ler_texto("exemplo.txt");
    printf("\n");
    
    // 2. Anexar texto
    printf("2. Anexar Texto:\n");
    anexar_texto("exemplo.txt", "Esta linha foi anexada ao arquivo.");
    ler_texto("exemplo.txt");
    printf("\n");
    
    // 3. Dados formatados
    printf("3. Dados Formatados:\n");
    escrever_dados_formatados("dados.txt");
    ler_dados_formatados("dados.txt");
    printf("\n");
    
    // 4. Estruturas em arquivo binário
    printf("4. Estruturas em Arquivo Binário:\n");
    escrever_estrutura_binaria("pessoas.bin");
    ler_estrutura_binaria("pessoas.bin");
    printf("\n");
    
    // 5. Cópia de arquivo
    printf("5. Cópia de Arquivo:\n");
    copiar_arquivo("dados.txt", "dados_copia.txt");
    printf("Verificando cópia:\n");
    ler_texto("dados_copia.txt");
    printf("\n");
    
    // 6. Contagem de linhas
    printf("6. Contagem de Linhas:\n");
    int num_linhas = contar_linhas("dados.txt");
    printf("Arquivo 'dados.txt' tem %d linhas\n", num_linhas);
    printf("\n");
    
    // 7. Busca de texto
    printf("7. Busca de Texto:\n");
    buscar_texto("dados.txt", "João");
    printf("\n");
    
    // 8. Informações do arquivo
    printf("8. Informações do Arquivo:\n");
    info_arquivo("dados.txt");
    printf("\n");
    
    // 9. Demonstração de diferentes modos
    printf("9. Diferentes Modos de Abertura:\n");
    
    // Modo "w" - sobrescreve
    FILE *arq1 = fopen("teste.txt", "w");
    if (arq1 != NULL) {
        fprintf(arq1, "Primeira linha\n");
        fclose(arq1);
    }
    
    // Modo "a" - anexa
    FILE *arq2 = fopen("teste.txt", "a");
    if (arq2 != NULL) {
        fprintf(arq2, "Segunda linha\n");
        fclose(arq2);
    }
    
    printf("Arquivo criado com diferentes modos:\n");
    ler_texto("teste.txt");
    printf("\n");
    
    // 10. Verificação de erros
    printf("10. Verificação de Erros:\n");
    
    // Tentar abrir arquivo inexistente
    FILE *arq_inexistente = fopen("arquivo_inexistente.txt", "r");
    if (arq_inexistente == NULL) {
        printf("Erro esperado: arquivo inexistente não pode ser aberto\n");
    } else {
        fclose(arq_inexistente);
    }
    
    // Verificar operações de escrita
    FILE *arq_teste = fopen("teste_erro.txt", "w");
    if (arq_teste != NULL) {
        if (fprintf(arq_teste, "Teste de escrita\n") < 0) {
            printf("Erro na escrita!\n");
        } else {
            printf("Escrita bem-sucedida\n");
        }
        fclose(arq_teste);
    }
    printf("\n");
    
    printf("=== Fim do Exemplo ===\n");
    
    return 0;
} 