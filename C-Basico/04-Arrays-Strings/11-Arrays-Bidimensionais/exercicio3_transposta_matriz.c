#include <stdio.h>

int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int transposta[3][3];
    
    printf("=== Transposta de Matriz ===\n\n");
    
    // Exibindo matriz original
    printf("Matriz original 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Calculando a transposta
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
    
    // Exibindo matriz transposta
    printf("Matriz transposta 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", transposta[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Demonstração do processo
    printf("=== Demonstração do Processo ===\n");
    printf("Elementos que foram trocados:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) { // Apenas elementos fora da diagonal
                printf("matriz[%d][%d] = %d -> transposta[%d][%d] = %d\n", 
                       i, j, matriz[i][j], j, i, transposta[j][i]);
            }
        }
    }
    
    // Comparação lado a lado
    printf("\n=== Comparação Lado a Lado ===\n");
    printf("Original    |    Transposta\n");
    printf("--------    |    ----------\n");
    for (int i = 0; i < 3; i++) {
        // Linha da matriz original
        for (int j = 0; j < 3; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("    |    ");
        
        // Linha da matriz transposta
        for (int j = 0; j < 3; j++) {
            printf("%2d ", transposta[i][j]);
        }
        printf("\n");
    }
    
    // Verificação da propriedade da transposta
    printf("\n=== Verificação da Propriedade ===\n");
    printf("A transposta da transposta deve ser igual à matriz original:\n");
    
    int transposta_da_transposta[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposta_da_transposta[j][i] = transposta[i][j];
        }
    }
    
    printf("Transposta da transposta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", transposta_da_transposta[i][j]);
        }
        printf("\n");
    }
    
    // Verificação se é igual à original
    int sao_iguais = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (transposta_da_transposta[i][j] != matriz[i][j]) {
                sao_iguais = 0;
                break;
            }
        }
    }
    
    if (sao_iguais) {
        printf("\n✓ Verificação correta: A transposta da transposta é igual à matriz original!\n");
    } else {
        printf("\n✗ Erro na verificação!\n");
    }
    
    return 0;
} 