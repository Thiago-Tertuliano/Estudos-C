#ifndef RELATORIO_H
#define RELATORIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

// Funções de relatórios e estatísticas
void livros_mais_emprestados(const char *arquivo_emprestimos, const char *arquivo_livros);
void usuarios_mais_ativos(const char *arquivo_emprestimos, const char *arquivo_usuarios);
void relatorio_atrasos(const char *arquivo_emprestimos, const char *arquivo_livros, const char *arquivo_usuarios);
void estatisticas_gerais(const char *arquivo_livros, const char *arquivo_usuarios, const char *arquivo_emprestimos);
void inventario_completo(const char *arquivo_livros);
void relatorio_financeiro(const char *arquivo_emprestimos);
void exportar_relatorio(const char *conteudo, const char *nome_arquivo);
void menu_relatorios(const char *arquivo_livros, const char *arquivo_usuarios, const char *arquivo_emprestimos);

#endif 