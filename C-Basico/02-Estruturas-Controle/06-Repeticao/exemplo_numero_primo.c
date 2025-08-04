#include <stdio.h>

int main() {
    int numero, eh_primo = 1;
    
    printf("Digite um número para verificar se é primo: ");
    scanf("%d", &numero);
    
    if (numero <= 1) {
        eh_primo = 0;
    } else {
        for (int i = 2; i * i <= numero; i++) {
            if (numero % i == 0) {
                eh_primo = 0;
                break;
            }
        }
    }
    
    if (eh_primo) {
        printf("%d é um número primo.\n", numero);
    } else {
        printf("%d não é um número primo.\n", numero);
    }
    
    return 0;
} 