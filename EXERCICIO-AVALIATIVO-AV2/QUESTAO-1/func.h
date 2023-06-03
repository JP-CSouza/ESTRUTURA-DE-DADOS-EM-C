//FUNC.H

//imprimir o vetor
void imprimirVetor(int vetor[], int tam) {
    printf("Vetor Ordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função Bubble Sort
void bubbleSort(int vetor[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos de posição
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função Insertion Sort
void insertionSort(int vetor[], int tam) {
    int i, chave, j;
    for (i = 1; i < tam; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}
