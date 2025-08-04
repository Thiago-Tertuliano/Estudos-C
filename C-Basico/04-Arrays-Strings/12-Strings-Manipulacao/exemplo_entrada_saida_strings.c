#include <stdio.h>
#include <string.h>

int main() {
    char nome[50], sobrenome[50], email[100];
    char nome_completo[100], perfil[200];
    
    printf("=== Entrada e Saída de Strings ===\n\n");
    
    // Entrada de dados
    printf("Digite seu nome: ");
    scanf(" %[^\n]", nome);
    
    printf("Digite seu sobrenome: ");
    scanf(" %[^\n]", sobrenome);
    
    printf("Digite seu email: ");
    scanf(" %[^\n]", email);
    
    // Processamento das strings
    strcpy(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome);
    
    strcpy(perfil, "Nome: ");
    strcat(perfil, nome_completo);
    strcat(perfil, "\nEmail: ");
    strcat(perfil, email);
    
    // Saída dos dados
    printf("\n=== Dados Coletados ===\n");
    printf("Nome completo: %s\n", nome_completo);
    printf("Email: %s\n", email);
    printf("Tamanho do nome: %lu caracteres\n", strlen(nome_completo));
    printf("Tamanho do email: %lu caracteres\n", strlen(email));
    
    // Perfil completo
    printf("\n=== Perfil Completo ===\n");
    printf("%s\n", perfil);
    
    // Análise das strings
    printf("\n=== Análise das Strings ===\n");
    
    // Verificar se email contém @
    if (strchr(email, '@') != NULL) {
        printf("✓ Email válido (contém @)\n");
    } else {
        printf("✗ Email inválido (não contém @)\n");
    }
    
    // Verificar se nome contém espaços
    if (strchr(nome, ' ') != NULL) {
        printf("✓ Nome contém espaços\n");
    } else {
        printf("✗ Nome não contém espaços\n");
    }
    
    // Comparar tamanhos
    if (strlen(nome) > strlen(sobrenome)) {
        printf("Nome é maior que sobrenome\n");
    } else if (strlen(nome) < strlen(sobrenome)) {
        printf("Sobrenome é maior que nome\n");
    } else {
        printf("Nome e sobrenome têm o mesmo tamanho\n");
    }
    
    // Primeira letra de cada string
    printf("\nPrimeira letra do nome: %c\n", nome[0]);
    printf("Primeira letra do sobrenome: %c\n", sobrenome[0]);
    printf("Primeira letra do email: %c\n", email[0]);
    
    return 0;
} 