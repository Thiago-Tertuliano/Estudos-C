#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "usuario.h"

// Estrutura para empréstimo
struct Emprestimo {
    int id;
    int livro_id;
    int usuario_id;
    char data_emprestimo[20];
    char data_devolucao_prevista[20];
    char data_devolucao_real[20];
    float multa;
    char status[20]; // "ativo", "devolvido", "atrasado"
};

// Funções de gestão de empréstimos
void realizar_emprestimo(const char *arquivo_emprestimos, const char *arquivo_livros, const char *arquivo_usuarios);
void processar_devolucao(const char *arquivo_emprestimos, const char *arquivo_livros, const char *arquivo_usuarios);
void renovar_emprestimo(const char *arquivo_emprestimos);
void listar_emprestimos_ativos(const char *arquivo_emprestimos, const char *arquivo_livros, const char *arquivo_usuarios);
void verificar_atrasos(const char *arquivo_emprestimos);
void aplicar_multas(const char *arquivo_emprestimos);
struct Emprestimo* buscar_emprestimo_por_id(const char *arquivo, int id);
float calcular_multa(const char *data_devolucao_prevista, const char *data_devolucao_real);
void atualizar_status_emprestimo(const char *arquivo, int id, const char *novo_status);
void menu_emprestimos(const char *arquivo_emprestimos, const char *arquivo_livros, const char *arquivo_usuarios);

#endif 