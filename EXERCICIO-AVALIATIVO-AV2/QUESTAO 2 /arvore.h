//------------------------------------------------------------------
typedef struct no{
  int chave;
  struct no *esquerda, *direita;
}No;

typedef struct{
  No *raiz;
  int tam;
}ArvB;


// INSERIR ---------------------------------------------------

No* inserir(No* raiz, int valor){
  if(raiz == NULL){
    No *novo = (No*)malloc (sizeof(No));
    novo -> chave = valor;
    novo -> esquerda = NULL;
    novo -> direita = NULL;
    return novo;
  }else{
    if(valor < raiz -> chave)
      raiz -> esquerda = inserir(raiz -> esquerda, valor); 
    if(valor > raiz -> chave)
      raiz -> direita = inserir(raiz -> direita, valor);
    return raiz;
  }
}

//REMOVER -------------------------------------------

No* remover(No *raiz, int item){
  if(raiz == NULL){
    printf("Valor nao encontrado...\n");
    return NULL;
  }else{
    if(raiz -> chave == item){
      if(raiz -> esquerda == NULL && raiz -> direita == NULL){
        free(raiz);
        return NULL;  
      }
      else{
        if(raiz -> esquerda == NULL || raiz -> direita == NULL){
            No *temp;
            
          if(raiz -> esquerda != NULL){
            temp = raiz -> esquerda;
            free(raiz);
            return temp;
            
          }else{
            temp = raiz -> direita;
            free(raiz);
            return temp;
            
          }
          }else{
            No *temp = raiz -> esquerda;
          
            while(temp -> direita != NULL)
                temp = temp -> direita;
                
              raiz -> chave = temp -> chave;
              temp -> chave = item;
              raiz -> esquerda = remover(raiz -> esquerda, item);
          
          return raiz;
        }
      }
    }else{
        if(item < raiz -> chave){
            raiz -> esquerda = remover (raiz -> esquerda, item);
            return raiz;
        }else{
            raiz -> direita = remover(raiz -> direita, item);
            return raiz;
        }
    }
  }
}

// IMPRIMIR ------------------------------------------------

void imprime(No *raiz){
  if(raiz != NULL){
    imprime(raiz -> esquerda);
    
    printf("%d ",raiz -> chave);
    
    imprime(raiz -> direita);
  }
}

// INSERIR --------------------------------------

No* input(No* raiz){
    int num;
  int tamanho;    
    
  printf("Digite numero: ");
  scanf("%d", &num);
  
  raiz = inserir(raiz, num);
  
  return raiz;
}

//BUSCAR -------------------------------------

void buscar(No* raiz, int valor) {
  if (raiz == NULL) {
    printf("\n");
    printf("\nValor não encontrado na árvore.\n");
    } else{
      
        if (raiz->chave == valor) {
        printf("\n");
        printf("\nValor encontrado na árvore.\n");
        
        } else if (valor < raiz->chave) {
        buscar(raiz->esquerda, valor);
        
        }else {
        buscar(raiz->direita, valor);
        }
    }
}

//IMPRIMIR DIREIRA P/ ESQUERDA -----------------------------------------

void imprimirDireitaEsquerda(No* raiz){
   if(raiz != NULL){
    imprimirDireitaEsquerda(raiz -> direita);
    
    printf("%d ",raiz -> chave);
    
    imprimirDireitaEsquerda(raiz -> esquerda);
  }
    
}

// ENCONTRAR MAIOR NUMERO -------------------------------

int encontrarMaiorNumero(No* raiz) {
  if (raiz == NULL) {
    printf("Árvore vazia. Não há elementos.\n");
    return 0;
  

        }else if (raiz->direita != NULL) {
          return encontrarMaiorNumero(raiz->direita);
          
        }else{
          printf("Maior elemento da árvore: %d\n", raiz->chave);
          return raiz->chave;
    }
}
