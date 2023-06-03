struct NodePilha{
  int item;
struct NodePilha *prox;
};
typedef struct NodePilha nodeP;

int vazia(nodeP *PILHA){
    if(PILHA -> prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

//Funcao EMPILHAR (PUSH) ----------------------------------
void PUSH(nodeP *PILHA, int tam){
  nodeP *novo = (nodeP*) malloc(sizeof(nodeP));
  novo -> prox = NULL;

  printf("Novo item: ");
  scanf("%d", &novo -> item);

  if(vazia(PILHA)){
    PILHA -> prox = novo;
  }else{
    nodeP *tmp = PILHA -> prox;
    while(tmp -> prox != NULL){
      tmp = tmp -> prox;
    }
    tmp -> prox = novo;
  }
  tam++;
}

//Funcao DESEMPILHAR--------------------------------

void POP( nodeP *PILHA,int tam){
    if(PILHA -> prox == NULL){
        printf("\nA Pilha ja está vazia! \n\n");
        return;
    }else{
        nodeP *ultimo = PILHA -> prox;
        nodeP *penultimo = PILHA;
        
    while(ultimo -> prox !=NULL){
        penultimo = ultimo;
        ultimo = ultimo -> prox;
    }
    free(ultimo);
    penultimo -> prox = NULL;
    tam--;
    
    printf("\nÚltimo item da pilha foi removido com sucesso!\n\n");
    }
}

//Funcao IMPRIMIR ----------------------------------
void IMPRIMIR(nodeP *PILHA, int tam){
  if(vazia(PILHA)){
    printf("PILHA VAZIA!!\n\n");
  return;
  }
  nodeP *tmp;
  tmp = PILHA -> prox;
  printf("\nPILHA: ");
  while(tmp != NULL){
    printf("%3d", tmp -> item);
    tmp = tmp -> prox;
    tam++;
  }
printf("\nQuantidade itens PILHA: %d",tam);
printf("\n");

}
// LIMPAR PILHA -------------------------------------
void LIMPARPILHA(nodeP *PILHA){
    if(vazia(PILHA)){
        
        printf("\nA Pilha ja está vazia! \n\n");
        return ;
        
    }else{
        while(!vazia(PILHA)){
            nodeP *ultimo = PILHA -> prox;
            nodeP *penultimo = PILHA;
            
            while(ultimo -> prox !=NULL){
                penultimo = ultimo;
                ultimo = ultimo -> prox;
            }
            free(ultimo);
            penultimo -> prox = NULL;
        }
        printf("\n\n A Pilha foi limpa com sucesso!\n\n");
    }
}
//  IMPRIMIR TOPO -----------------------------------
  
void TOPOPILHA(nodeP *PILHA){
    if(vazia(PILHA)){
        
        printf("\nA Pilha ja está vazia! \n\n");
        return ;
        
    }else{
        
        nodeP *tmp = PILHA -> prox;
        
        printf("\nTopo da pilha é:");
        while (tmp->prox != NULL){
            tmp = tmp -> prox;
        }   
    printf("%3d",tmp -> item);
    printf("\n\n");
    }
}


