
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
    
    int tam, opcao;
    
    //tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int* vetor = (int*)malloc(tam * sizeof(int));

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }


    printf("╭─────────────────────╮\n");
    printf("│SISTEMA DE ORDENAÇÃO │\n");
    printf("├─────────────────────┤\n");
    printf("│Selecione uma opção: │\n");
    printf("│                     │\n");
    printf("│ [1] - bubbleSort    │\n");
    printf("│ [2] - Insertion Sort│\n");
    printf("│                     │\n");
    printf("╰─────────────────────╯\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            bubbleSort(vetor, tam);
            imprimirVetor(vetor, tam);
            break;
        case 2:
            insertionSort(vetor, tam);
            imprimirVetor(vetor, tam);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }

    free(vetor);

    return 0;
}
