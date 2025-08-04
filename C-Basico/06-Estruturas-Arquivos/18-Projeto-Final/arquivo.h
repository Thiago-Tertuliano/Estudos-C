#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Funções de manipulação de arquivos
void criar_arquivo_se_nao_existe(const char *nome_arquivo);
void backup_dados(const char *arquivo_origem, const char *arquivo_backup);
void restaurar_backup(const char *arquivo_backup, const char *arquivo_destino);
void log_operacao(const char *operacao, const char *detalhes);
void limpar_arquivo(const char *nome_arquivo);
int contar_registros(const char *nome_arquivo, size_t tamanho_registro);
void verificar_integridade_arquivo(const char *nome_arquivo, size_t tamanho_registro);
void compactar_arquivo(const char *nome_arquivo, size_t tamanho_registro);

#endif 