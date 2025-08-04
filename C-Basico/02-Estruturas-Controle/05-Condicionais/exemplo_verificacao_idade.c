#include <stdio.h>

int main() {
    int idade;
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    if (idade < 0) {
        printf("Idade inválida!\n");
    } else if (idade < 18) {
        printf("Você é menor de idade.\n");
    } else if (idade < 65) {
        printf("Você é adulto.\n");
    } else {
        printf("Você é idoso.\n");
    }
    
    return 0;
} 