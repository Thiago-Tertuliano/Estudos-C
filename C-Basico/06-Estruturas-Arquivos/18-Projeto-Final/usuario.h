#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para usuário
struct Usuario {
    int id;
    char nome[100];
    char email[100];
    char telefone[20];
    char endereco[200];
    char tipo[20]; // "estudante", "professor", "funcionario"
    int max_emprestimos;
    int emprestimos_ativos;
    char status[20];
};

// Funções de gestão de usuários
void cadastrar_usuario(const char *arquivo);
void buscar_usuario(const char *arquivo);
void atualizar_usuario(const char *arquivo);
void remover_usuario(const char *arquivo);
void listar_usuarios(const char *arquivo);
void historico_emprestimos(const char *arquivo_usuarios, const char *arquivo_emprestimos);
struct Usuario* buscar_usuario_por_id(const char *arquivo, int id);
int validar_email(const char *email);
void atualizar_emprestimos_ativos(const char *arquivo, int id, int delta);
void menu_usuarios(const char *arquivo);

#endif 