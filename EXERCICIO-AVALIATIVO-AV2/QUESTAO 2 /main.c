#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "pilha.h"
#include "fila.h"
#include "arvore.h"



int main() {
  int opcao,opcaoPilha,opcaoFila,opcaoArv;
  int buscarElemento, removerElemento;
  int maiorNum;

  //------------------Alocando pilha "malocando pilha" ------------------
  nodeP *PILHA = (nodeP*) malloc(sizeof(nodeP));
  PILHA -> prox = NULL;
  int tam = 0;
  //------------------Alocando fila "malocando fila" --------------------
  nodeF *FILA = (nodeF*)malloc(sizeof(nodeF));
  FILA ->prox = NULL; 
  //------------------Alocando arvore "malocando arvore" 
    ArvB arvore;
    arvore.raiz = NULL;
    No *raiz = NULL;



  //usando o DO WHILE para que ele execute pelo menos uma função/ mas tem como fazer só com o while.
    do {
      
      printf("\n\n");
      printf("╭────────────────────────╮\n");
      printf("│  SISTEMA DE ORDENAÇÃO  │\n");
      printf("├────────────────────────┤\n");
      printf("│  Selecione uma opção:  │\n");
      printf("│                        │\n");
      printf("│ [1] - Executar Pilha   │\n");
      printf("│ [2] - Executar Fila    │\n");
      printf("│ [3] - Executar Árvore  │\n");
      printf("│ [0] - Fechar o programa│\n");
      printf("╰────────────────────────╯\n");

      printf("Digite o número da opção: ");
      scanf("%d", &opcao);

        switch (opcao) {
            case 1:
              do{ 
                printf("\n\n");
                printf("╭──────────────────────────╮\n");
                printf("│          PILHA           │\n");
                printf("├──────────────────────────┤\n");
                printf("│  Selecione uma opção:    │\n");
                printf("│                          │\n");
                printf("│ [1] - Empilhar Pilha     │\n");
                printf("│ [2] - Desempilhar Pilha  │\n");
                printf("│ [3] - Imprimir Pilha     │\n");
                printf("│ [4] - Limpar Pilha       │\n");
                printf("│ [5] - Imprimir Topo Pilha│\n");
                printf("│ [0] - SAIR               │\n");
                printf("╰──────────────────────────╯\n");
            
                printf("Digite o número da opção: ");
                scanf("%d", &opcaoPilha);
                printf("\nVoce escolheu Pilha\n");
  
                switch (opcaoPilha){
                  case 1:
                    PUSH(PILHA,tam); 
                  break;
  
                  case 2:
                    printf("\nDESEMPILHANDO...\n");
                    POP(PILHA,tam);
                  break;
  
                  case 3:
                    printf("\nIMPRIMINDO...\n");
                    IMPRIMIR(PILHA,tam);
                    break;
  
                  case 4:
                    printf("\nLIMPANDO PILHA...\n");
                    LIMPARPILHA(PILHA);
                    break;
  
                  case 5:    
                    printf("\nIMPRIMINDO TOP DA PILHA...\n");
                    TOPOPILHA(PILHA);
                    break;
                  
                  default:
                    printf("\n--> OPÇÃO INVALIDA!! <--\n");
                    printf("\nTente novamente\n");
                    break;
                }
              }while(opcaoPilha != 0 );
              break;
            case 2:
              do{
                printf("\n\n");
                printf("╭──────────────────────────────╮\n");
                printf("│              FILA            │\n");
                printf("├──────────────────────────────┤\n");
                printf("│    Selecione uma opção:      │\n");
                printf("│                              │\n");
                printf("│ [1] - Enfilheirar fila       │\n");
                printf("│ [2] - Desenfileirar fila     │\n");
                printf("│ [3] - Maior elemento da fila │\n");
                printf("│ [4] - Menor elemento da fila │\n");
                printf("│ [5] - Imprimir fila          │\n");
                printf("│ [6] - Limpar fila            │\n");
                printf("│ [0] - SAIR                   │\n");
                printf("╰──────────────────────────────╯\n");
            
                printf("Digite o número da opção: ");
                scanf("%d", &opcaoFila);
                printf("\nVoce escolheu Fila\n");
  
                switch (opcaoFila){
                  case 1:
                  ENQUEUE(FILA,tam);
                  break;
                  
                  case 2:
                  DEQUEUE(FILA, tam);
                  break;
                  
                  case 3:
                  IMPRIMEMAIOR(FILA);
                  break;
                  
                  case 4:
                  IMPRIMEMENOR(FILA);
                  break;
                  
                  case 5:
                  IMPRIMEFILA(FILA,tam);
                  break;

                  case 6:
                    LIMPARFILA(FILA);
                    break;
                  
                  case 0:
                    break;
                  
                  default:
                    printf("\n--> OPÇÃO INVALIDA!! <--\n");
                    printf("\nTente novamente\n");
                    break;

                }
              }while(opcaoFila !=0);
                break;
          
            case 3:
              do{
                printf("\n\n");
                printf("╭───────────────────────────────╮\n");
                printf("│            ARVORE             │\n");
                printf("├───────────────────────────────┤\n");
                printf("│    Selecione uma opção:       │\n");
                printf("│                               │\n");
                printf("│ [1] - Inserir um elemento     │\n");
                printf("│ [2] - Imprima a arvore        │\n");
                printf("│ [3] - Imprima a arvore        │\n");
                printf("│         decrescente           │\n");
                printf("│ [4] - Imprimir maior elemento │\n");
                printf("│ [5] - Buscar elemento         │\n");
                printf("│ [6] - Deletar um elemento     │\n");
                printf("│ [0] - SAIR                    │\n");
                printf("╰───────────────────────────────╯\n");
            
                printf("Digite o número da opção: ");
                scanf("%d", &opcaoArv);
                printf("\nVoce escolheu ARVORE!\n");
  
                switch (opcaoArv){
                  case 1:                
                    raiz = input(raiz);
                    break;
                  case 2:
                    printf("\n\nÁrvore: ");
                    imprime(raiz);
                    printf("\n");
                    break;
                  case 3:
                    printf("\n\nÁrvore Da direita para esquerda: ");  
                    imprimirDireitaEsquerda(raiz);
                    printf("\n");
                    break;
                  case 4: 
                    maiorNum = encontrarMaiorNumero(raiz);
                    printf("\n");
                    break;
                  case 5:
                    printf("Digite o valor a ser buscado: ");
                    scanf("%d", &buscarElemento);
                    buscar(raiz, buscarElemento);
                    printf("\n");
                    break;
                  case 6:
                    printf("\n\nDigite o valor a ser removido: ");
                    scanf("%d", &removerElemento);
                    raiz = remover(raiz, removerElemento);
                    break;
                  case 0:
                    break;
                }
              }while(opcaoArv !=0);
              break;
            case 0:
                printf("\nFECHANDO O PROGRAMA...\n");
                break;
            default:
                printf("\n--> OPÇÃO INVALIDA!! <--\n");
                printf("\nTente novamente\n");
                break;
        }
          
        printf("\n");
    }while (opcao != 0);

    printf("Programa encerrado.\n");

    return 0;
}
