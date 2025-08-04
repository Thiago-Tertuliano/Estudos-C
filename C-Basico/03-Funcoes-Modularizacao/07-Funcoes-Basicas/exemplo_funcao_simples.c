#include <stdio.h>

// Declaração da função (protótipo)
void saudacao();
void menu_opcoes();

int main() {
    printf("=== Programa de Demonstração de Funções ===\n\n");
    
    // Chamada da função saudacao
    saudacao();
    
    printf("\n--- Menu de Opções ---\n");
    menu_opcoes();
    
    printf("\nPrograma finalizado com sucesso!\n");
    return 0;
}

// Definição da função saudacao
void saudacao() {
    printf("Olá! Bem-vindo ao curso de C!\n");
    printf("Estamos aprendendo sobre funções básicas.\n");
    printf("As funções ajudam a organizar nosso código.\n");
}

// Definição da função menu_opcoes
void menu_opcoes() {
    printf("1. Aprender funções\n");
    printf("2. Praticar exercícios\n");
    printf("3. Revisar conceitos\n");
    printf("4. Sair\n");
    printf("Escolha uma opção acima.\n");
} 