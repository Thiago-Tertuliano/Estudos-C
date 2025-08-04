#ifndef LIVRO_H
#define LIVRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para livro
struct Livro {
    int id;
    char titulo[100];
    char autor[100];
    char editora[100];
    char categoria[50];
    int ano_publicacao;
    int quantidade_total;
    int quantidade_disponivel;
    char isbn[20];
    char status[20];
};

// Funções de gestão de livros
void cadastrar_livro(const char *arquivo);
void buscar_livro(const char *arquivo);
void atualizar_livro(const char *arquivo);
void remover_livro(const char *arquivo);
void listar_livros(const char *arquivo);
void relatorio_estoque(const char *arquivo);
struct Livro* buscar_livro_por_id(const char *arquivo, int id);
int validar_isbn(const char *isbn);
void menu_livros(const char *arquivo);

#endif 