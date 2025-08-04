#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para arquivo
struct Arquivo {
    char nome[100];
    char conteudo[1000];
    int tamanho;
    char tipo[20];
};

// Função para criar novo arquivo
void criar_arquivo(const char *nome, const char *conteudo) {
    FILE *arquivo = fopen(nome, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo '%s'!\n", nome);
        return;
    }
    
    fprintf(arquivo, "%s", conteudo);
    fclose(arquivo);
    printf("Arquivo '%s' criado com sucesso!\n", nome);
}

// Função para ler arquivo
void ler_arquivo(const char *nome) {
    FILE *arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo '%s'!\n", nome);
        return;
    }
    
    char linha[100];
    printf("Conteúdo do arquivo '%s':\n", nome);
    printf("----------------------------------------\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    printf("----------------------------------------\n");
    
    fclose(arquivo);
}

// Função para anexar conteúdo ao arquivo
void anexar_arquivo(const char *nome, const char *conteudo) {
    FILE *arquivo = fopen(nome, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo '%s'!\n", nome);
        return;
    }
    
    fprintf(arquivo, "\n%s", conteudo);
    fclose(arquivo);
    printf("Conteúdo anexado ao arquivo '%s'!\n", nome);
}

// Função para copiar arquivo
void copiar_arquivo(const char *origem, const char *destino) {
    FILE *arq_origem = fopen(origem, "r");
    if (arq_origem == NULL) {
        printf("Erro ao abrir arquivo de origem '%s'!\n", origem);
        return;
    }
    
    FILE *arq_destino = fopen(destino, "w");
    if (arq_destino == NULL) {
        printf("Erro ao criar arquivo de destino '%s'!\n", destino);
        fclose(arq_origem);
        return;
    }
    
    char caractere;
    while ((caractere = fgetc(arq_origem)) != EOF) {
        fputc(caractere, arq_destino);
    }
    
    fclose(arq_origem);
    fclose(arq_destino);
    printf("Arquivo '%s' copiado para '%s' com sucesso!\n", origem, destino);
}

// Função para contar linhas do arquivo
int contar_linhas(const char *nome) {
    FILE *arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo '%s'!\n", nome);
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

// Função para buscar texto no arquivo
void buscar_texto(const char *nome, const char *texto_busca) {
    FILE *arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo '%s'!\n", nome);
        return;
    }
    
    char linha[100];
    int numero_linha = 1;
    int encontrado = 0;
    
    printf("Buscando '%s' no arquivo '%s':\n", texto_busca, nome);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, texto_busca) != NULL) {
            printf("Linha %d: %s", numero_linha, linha);
            encontrado = 1;
        }
        numero_linha++;
    }
    
    if (!encontrado) {
        printf("Texto '%s' não encontrado no arquivo.\n", texto_busca);
    }
    
    fclose(arquivo);
}

// Função para obter informações do arquivo
void info_arquivo(const char *nome) {
    FILE *arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo '%s'!\n", nome);
        return;
    }
    
    // Contar caracteres e linhas
    int caracteres = 0;
    int linhas = 0;
    char caractere;
    
    while ((caractere = fgetc(arquivo)) != EOF) {
        caracteres++;
        if (caractere == '\n') {
            linhas++;
        }
    }
    
    fclose(arquivo);
    
    printf("Informações do arquivo '%s':\n", nome);
    printf("- Caracteres: %d\n", caracteres);
    printf("- Linhas: %d\n", linhas);
    printf("- Tamanho aproximado: %.2f KB\n", (float)caracteres / 1024);
}

// Função para listar arquivos de texto
void listar_arquivos_texto() {
    printf("Arquivos de texto disponíveis:\n");
    printf("1. exemplo.txt\n");
    printf("2. dados.txt\n");
    printf("3. notas.txt\n");
    printf("4. agenda.txt\n");
}

int main() {
    int opcao;
    char nome_arquivo[100];
    char conteudo[1000];
    char texto_busca[100];
    
    printf("=== SISTEMA DE ARQUIVOS SIMPLES ===\n\n");
    
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Criar arquivo\n");
        printf("2. Ler arquivo\n");
        printf("3. Anexar conteúdo\n");
        printf("4. Copiar arquivo\n");
        printf("5. Contar linhas\n");
        printf("6. Buscar texto\n");
        printf("7. Informações do arquivo\n");
        printf("8. Listar arquivos\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer
        
        switch (opcao) {
            case 1:
                printf("Nome do arquivo: ");
                scanf("%s", nome_arquivo);
                getchar();
                printf("Conteúdo: ");
                fgets(conteudo, sizeof(conteudo), stdin);
                conteudo[strcspn(conteudo, "\n")] = 0; // Remover \n
                criar_arquivo(nome_arquivo, conteudo);
                break;
                
            case 2:
                printf("Nome do arquivo: ");
                scanf("%s", nome_arquivo);
                ler_arquivo(nome_arquivo);
                break;
                
            case 3:
                printf("Nome do arquivo: ");
                scanf("%s", nome_arquivo);
                getchar();
                printf("Conteúdo para anexar: ");
                fgets(conteudo, sizeof(conteudo), stdin);
                conteudo[strcspn(conteudo, "\n")] = 0;
                anexar_arquivo(nome_arquivo, conteudo);
                break;
                
            case 4:
                printf("Arquivo de origem: ");
                scanf("%s", nome_arquivo);
                printf("Arquivo de destino: ");
                scanf("%s", conteudo);
                copiar_arquivo(nome_arquivo, conteudo);
                break;
                
            case 5:
                printf("Nome do arquivo: ");
                scanf("%s", nome_arquivo);
                int linhas = contar_linhas(nome_arquivo);
                if (linhas >= 0) {
                    printf("O arquivo '%s' tem %d linhas.\n", nome_arquivo, linhas);
                }
                break;
                
            case 6:
                printf("Nome do arquivo: ");
                scanf("%s", nome_arquivo);
                printf("Texto para buscar: ");
                scanf("%s", texto_busca);
                buscar_texto(nome_arquivo, texto_busca);
                break;
                
            case 7:
                printf("Nome do arquivo: ");
                scanf("%s", nome_arquivo);
                info_arquivo(nome_arquivo);
                break;
                
            case 8:
                listar_arquivos_texto();
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