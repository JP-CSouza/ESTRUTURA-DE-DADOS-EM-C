struct NodeFila{
    int conteudo;
    struct NodeFila *prox;
};
typedef struct NodeFila nodeF;

int EMPTY(nodeF *FILA){
    if(FILA->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

//EMPILHAR FILA - PILHA -----------------------------------------

nodeF* ENQUEUE(nodeF *FILA,int tam){
    nodeF *novo=(nodeF*)malloc(sizeof(nodeF));
    novo->prox = NULL;
    
    printf("Novo item da Fila: ");
    scanf("%d",&novo->conteudo);
    
    if(EMPTY(FILA)){
        FILA->prox = novo;
    }
    else{
        nodeF *tmp = FILA ->prox;
        while(tmp->prox !=NULL){
            tmp = tmp->prox;
        }
        tmp->prox =novo;
    }
  tam++;
  return novo;
}

//------------------------------------

void DEQUEUE(nodeF *FILA,int tam){
    if(FILA->prox == NULL){
        printf("Fila esta vazia \n");
        return;
    }else{
        nodeF *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        free(tmp);
    }
  printf("Item removido com sucesso da fila!");
}

//IMPRIMIR FILA ----------------------------------

void IMPRIMEFILA(nodeF *FILA, int tam){
    if(EMPTY(FILA)){
        printf("\nA Fila está vazia!\n\n");
        return ;
    }
    nodeF *tmp = FILA -> prox;
    
    printf("\n Fila: ");
    
    while (tmp != NULL){
        printf("%3d ",tmp -> conteudo);
        tmp = tmp ->prox;
        tam++;
    }
  printf("\nTamanho da fila é de: %d",tam);
  printf("\n\n");
}

//IMPRIMIR MAIOR DA FILA --------------------------

void IMPRIMEMAIOR(nodeF *FILA){
     if (EMPTY(FILA)) {
        printf("A Fila está vazia!\n");
        return;
    }else{
        
       int maior = INT_MIN;
        
        nodeF *tmp = FILA->prox;
        while (tmp != NULL) {
            if (tmp -> conteudo > maior) {
                maior = tmp -> conteudo;
            }
            tmp = tmp->prox;
        }
    
    printf("\n\nMaior elemento da Fila: %d\n", maior);
    }   
    
}

// IMPRIMIR MENOR ----------------------------------- 

void IMPRIMEMENOR(nodeF *FILA){
     if (EMPTY(FILA)) {
        printf("A Fila está vazia!\n");
        return;
    }else{
        
       int menor = INT_MAX;
        
        nodeF *tmp = FILA->prox;
        while (tmp != NULL) {
            if (tmp -> conteudo < menor) {
                menor = tmp -> conteudo;
            }
            tmp = tmp->prox;
        }
    
    printf("\n\nMenor elemento da Fila: %d\n", menor);
    }   
    
}

//LIMPAR FILA ---------------------------------------- 

void LIMPARFILA(nodeF *FILA){
    if(EMPTY(FILA)){
        
        printf("\nA Fila ja está vazia! \n\n");
        return ;
        
    }else{
        while(!EMPTY(FILA)){
            nodeF *ultimo = FILA -> prox;
            nodeF *penultimo = FILA;
            
            while(ultimo -> prox !=NULL){
                penultimo = ultimo;
                ultimo = ultimo -> prox;
            }
            free(ultimo);
            penultimo -> prox = NULL;
        }
        printf("\n\n A Fila foi limpa com sucesso!\n\n");
    }
}
