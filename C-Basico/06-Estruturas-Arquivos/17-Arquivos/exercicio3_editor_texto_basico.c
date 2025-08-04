#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 1000
#define MAX_COLUNAS 100

// Estrutura para linha de texto
struct Linha {
    char conteudo[MAX_COLUNAS];
    int numero;
};

// Estrutura para documento
struct Documento {
    struct Linha linhas[MAX_LINHAS];
    int total_linhas;
    char nome[100];
    int modificado;
};

// Função para inicializar documento
void inicializar_documento(struct Documento *doc, const char *nome) {
    doc->total_linhas = 0;
    strcpy(doc->nome, nome);
    doc->modificado = 0;
}

// Função para adicionar linha ao documento
void adicionar_linha(struct Documento *doc, const char *conteudo) {
    if (doc->total_linhas < MAX_LINHAS) {
        strcpy(doc->linhas[doc->total_linhas].conteudo, conteudo);
        doc->linhas[doc->total_linhas].numero = doc->total_linhas + 1;
        doc->total_linhas++;
        doc->modificado = 1;
    } else {
        printf("Erro: Documento cheio!\n");
    }
}

// Função para inserir linha em posição específica
void inserir_linha(struct Documento *doc, int posicao, const char *conteudo) {
    if (posicao < 0 || posicao > doc->total_linhas) {
        printf("Posição inválida!\n");
        return;
    }
    
    if (doc->total_linhas >= MAX_LINHAS) {
        printf("Erro: Documento cheio!\n");
        return;
    }
    
    // Mover linhas para abrir espaço
    for (int i = doc->total_linhas; i > posicao; i--) {
        doc->linhas[i] = doc->linhas[i-1];
        doc->linhas[i].numero = i + 1;
    }
    
    // Inserir nova linha
    strcpy(doc->linhas[posicao].conteudo, conteudo);
    doc->linhas[posicao].numero = posicao + 1;
    doc->total_linhas++;
    doc->modificado = 1;
}

// Função para remover linha
void remover_linha(struct Documento *doc, int posicao) {
    if (posicao < 0 || posicao >= doc->total_linhas) {
        printf("Posição inválida!\n");
        return;
    }
    
    // Mover linhas para preencher espaço
    for (int i = posicao; i < doc->total_linhas - 1; i++) {
        doc->linhas[i] = doc->linhas[i+1];
        doc->linhas[i].numero = i + 1;
    }
    
    doc->total_linhas--;
    doc->modificado = 1;
}

// Função para editar linha
void editar_linha(struct Documento *doc, int posicao, const char *novo_conteudo) {
    if (posicao < 0 || posicao >= doc->total_linhas) {
        printf("Posição inválida!\n");
        return;
    }
    
    strcpy(doc->linhas[posicao].conteudo, novo_conteudo);
    doc->modificado = 1;
}

// Função para exibir documento
void exibir_documento(struct Documento *doc) {
    printf("\n=== DOCUMENTO: %s ===\n", doc->nome);
    printf("Total de linhas: %d\n", doc->total_linhas);
    printf("Status: %s\n", doc->modificado ? "Modificado" : "Salvo");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < doc->total_linhas; i++) {
        printf("%3d: %s\n", doc->linhas[i].numero, doc->linhas[i].conteudo);
    }
    
    if (doc->total_linhas == 0) {
        printf("(Documento vazio)\n");
    }
    printf("----------------------------------------\n");
}

// Função para salvar documento em arquivo
void salvar_documento(struct Documento *doc, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo '%s'!\n", nome_arquivo);
        return;
    }
    
    for (int i = 0; i < doc->total_linhas; i++) {
        fprintf(arquivo, "%s\n", doc->linhas[i].conteudo);
    }
    
    fclose(arquivo);
    doc->modificado = 0;
    printf("Documento salvo em '%s'\n", nome_arquivo);
}

// Função para carregar documento de arquivo
void carregar_documento(struct Documento *doc, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo '%s'!\n", nome_arquivo);
        return;
    }
    
    // Limpar documento atual
    doc->total_linhas = 0;
    strcpy(doc->nome, nome_arquivo);
    doc->modificado = 0;
    
    char linha[MAX_COLUNAS];
    while (fgets(linha, sizeof(linha), arquivo) != NULL && doc->total_linhas < MAX_LINHAS) {
        // Remover \n do final
        linha[strcspn(linha, "\n")] = 0;
        adicionar_linha(doc, linha);
    }
    
    fclose(arquivo);
    printf("Documento carregado de '%s'\n", nome_arquivo);
}

// Função para buscar texto no documento
void buscar_texto(struct Documento *doc, const char *texto_busca) {
    printf("Buscando '%s' no documento:\n", texto_busca);
    int encontrado = 0;
    
    for (int i = 0; i < doc->total_linhas; i++) {
        if (strstr(doc->linhas[i].conteudo, texto_busca) != NULL) {
            printf("Linha %d: %s\n", doc->linhas[i].numero, doc->linhas[i].conteudo);
            encontrado = 1;
        }
    }
    
    if (!encontrado) {
        printf("Texto não encontrado no documento.\n");
    }
}

// Função para substituir texto
void substituir_texto(struct Documento *doc, const char *texto_antigo, const char *texto_novo) {
    int substituicoes = 0;
    
    for (int i = 0; i < doc->total_linhas; i++) {
        char *pos = strstr(doc->linhas[i].conteudo, texto_antigo);
        if (pos != NULL) {
            // Substituição simples (primeira ocorrência por linha)
            char temp[MAX_COLUNAS];
            strcpy(temp, doc->linhas[i].conteudo);
            
            int pos_inicio = pos - doc->linhas[i].conteudo;
            int len_antigo = strlen(texto_antigo);
            int len_novo = strlen(texto_novo);
            
            // Construir nova string
            char nova_linha[MAX_COLUNAS] = "";
            strncpy(nova_linha, doc->linhas[i].conteudo, pos_inicio);
            nova_linha[pos_inicio] = '\0';
            strcat(nova_linha, texto_novo);
            strcat(nova_linha, pos + len_antigo);
            
            strcpy(doc->linhas[i].conteudo, nova_linha);
            substituicoes++;
        }
    }
    
    if (substituicoes > 0) {
        doc->modificado = 1;
        printf("%d substituições realizadas.\n", substituicoes);
    } else {
        printf("Texto não encontrado para substituição.\n");
    }
}

// Função para contar palavras
int contar_palavras(const char *texto) {
    int palavras = 0;
    int dentro_palavra = 0;
    
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == ' ' || texto[i] == '\t' || texto[i] == '\n') {
            dentro_palavra = 0;
        } else if (!dentro_palavra) {
            dentro_palavra = 1;
            palavras++;
        }
    }
    
    return palavras;
}

// Função para estatísticas do documento
void estatisticas_documento(struct Documento *doc) {
    int total_caracteres = 0;
    int total_palavras = 0;
    int linhas_vazias = 0;
    
    for (int i = 0; i < doc->total_linhas; i++) {
        total_caracteres += strlen(doc->linhas[i].conteudo);
        total_palavras += contar_palavras(doc->linhas[i].conteudo);
        
        if (strlen(doc->linhas[i].conteudo) == 0) {
            linhas_vazias++;
        }
    }
    
    printf("=== ESTATÍSTICAS DO DOCUMENTO ===\n");
    printf("Total de linhas: %d\n", doc->total_linhas);
    printf("Linhas vazias: %d\n", linhas_vazias);
    printf("Total de caracteres: %d\n", total_caracteres);
    printf("Total de palavras: %d\n", total_palavras);
    printf("Média de caracteres por linha: %.1f\n", 
           doc->total_linhas > 0 ? (float)total_caracteres / doc->total_linhas : 0);
    printf("Média de palavras por linha: %.1f\n", 
           doc->total_linhas > 0 ? (float)total_palavras / doc->total_linhas : 0);
}

// Função para ordenar linhas alfabeticamente
void ordenar_linhas(struct Documento *doc) {
    for (int i = 0; i < doc->total_linhas - 1; i++) {
        for (int j = i + 1; j < doc->total_linhas; j++) {
            if (strcmp(doc->linhas[i].conteudo, doc->linhas[j].conteudo) > 0) {
                // Trocar linhas
                struct Linha temp = doc->linhas[i];
                doc->linhas[i] = doc->linhas[j];
                doc->linhas[j] = temp;
                
                // Atualizar números das linhas
                doc->linhas[i].numero = i + 1;
                doc->linhas[j].numero = j + 1;
            }
        }
    }
    doc->modificado = 1;
    printf("Linhas ordenadas alfabeticamente.\n");
}

// Função para mostrar menu
void mostrar_menu() {
    printf("\n=== EDITOR DE TEXTO BÁSICO ===\n");
    printf("1. Adicionar linha\n");
    printf("2. Inserir linha em posição\n");
    printf("3. Editar linha\n");
    printf("4. Remover linha\n");
    printf("5. Exibir documento\n");
    printf("6. Salvar documento\n");
    printf("7. Carregar documento\n");
    printf("8. Buscar texto\n");
    printf("9. Substituir texto\n");
    printf("10. Estatísticas\n");
    printf("11. Ordenar linhas\n");
    printf("0. Sair\n");
    printf("Opção: ");
}

int main() {
    struct Documento doc;
    inicializar_documento(&doc, "Novo Documento");
    
    int opcao;
    char entrada[1000];
    int posicao;
    char texto_busca[100];
    char texto_novo[100];
    char nome_arquivo[100];
    
    do {
        mostrar_menu();
        scanf("%d", &opcao);
        getchar(); // Limpar buffer
        
        switch (opcao) {
            case 1:
                printf("Digite o conteúdo da linha: ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;
                adicionar_linha(&doc, entrada);
                break;
                
            case 2:
                printf("Posição para inserir (0-%d): ", doc.total_linhas);
                scanf("%d", &posicao);
                getchar();
                printf("Digite o conteúdo da linha: ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;
                inserir_linha(&doc, posicao, entrada);
                break;
                
            case 3:
                printf("Número da linha para editar (1-%d): ", doc.total_linhas);
                scanf("%d", &posicao);
                getchar();
                printf("Novo conteúdo: ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;
                editar_linha(&doc, posicao - 1, entrada);
                break;
                
            case 4:
                printf("Número da linha para remover (1-%d): ", doc.total_linhas);
                scanf("%d", &posicao);
                remover_linha(&doc, posicao - 1);
                break;
                
            case 5:
                exibir_documento(&doc);
                break;
                
            case 6:
                printf("Nome do arquivo para salvar: ");
                scanf("%s", nome_arquivo);
                salvar_documento(&doc, nome_arquivo);
                break;
                
            case 7:
                printf("Nome do arquivo para carregar: ");
                scanf("%s", nome_arquivo);
                carregar_documento(&doc, nome_arquivo);
                break;
                
            case 8:
                printf("Texto para buscar: ");
                scanf("%s", texto_busca);
                buscar_texto(&doc, texto_busca);
                break;
                
            case 9:
                printf("Texto para substituir: ");
                scanf("%s", texto_busca);
                printf("Novo texto: ");
                scanf("%s", texto_novo);
                substituir_texto(&doc, texto_busca, texto_novo);
                break;
                
            case 10:
                estatisticas_documento(&doc);
                break;
                
            case 11:
                ordenar_linhas(&doc);
                break;
                
            case 0:
                if (doc.modificado) {
                    printf("Documento modificado! Deseja salvar? (s/n): ");
                    char resposta;
                    scanf("%c", &resposta);
                    if (resposta == 's' || resposta == 'S') {
                        printf("Nome do arquivo para salvar: ");
                        scanf("%s", nome_arquivo);
                        salvar_documento(&doc, nome_arquivo);
                    }
                }
                printf("Saindo do editor...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
        
    } while (opcao != 0);
    
    return 0;
} 