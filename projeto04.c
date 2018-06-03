#include <stdio.h>
#include <stdlib.h>

#define UnTempo 5

//-----------------------------------------------------
/* Declarção de Funções*/
Fila* cria_Fila();
int insere_Fila(Fila* fi, Lista li);
int remove_Fila(Fila* fi);
void libera_Fila(fi);

//-----------------------------------------------------
typedef struct lista {
  int id;
  char tipo;
  int combustivel;
  struct lista* prox;
} Lista;

typedef struct fila {
  Lista* ini;
  Lista* fim;
} Fila;

int main(int argc, char const *argv[]) {

  // printf("Aeroporto Internacional de Brasília\n", );
  // printf("Hora inicial: %d\n", ??,);
  // printf("Fila de Pedidos: %s\n", ??,);
  // printf("Número de Voos: %d\n",??,);
  // printf("Número de aproximações: %d\n",??,);
  // printf("Número de Decolagens: %d\n",??,);

  return 0;
}

//-----------------------------------------------------
/*Funções*/

Fila* cria_Fila(){
  Fila* fi = (Fila*) malloc(sizeof(Fila));
  if(fi != NULL){
    fi->fim = NULL;
    fi->ini = NULL;
  }
  return fi;
}
//-------------------------------------------------------
void libera_Fila(Fila* fi){ // DELETAR A FILA (NÃO SEI SE É NECESSÁRIO)
  if (fi != NULL){
    Lista* no;
    while (fi->ini != NULL) {
      no = fi->ini;
      fi->ini = fi->ini->prox;
      free(fi);
    }
  }
}
//-------------------------------------------------------
int insere_Fila(Fila* fi, Lista li){ //Função para inserir no fim
  if(fi --NULL) return 0;
  Lista* li = (li*) malloc(sizeof(Lista));

  if(li == NULL) return 0;
  li->info = li;
  li->prox = NULL;

  if(fi->fim == NULL){
    fi->ini = li;
  }
  else{
    fi->fim->prox = li;
  }
  return 1;
}
//--------------------------------------------------------
int remove_Fila(Fila* fi){
  if(fi == NULL) return 0;
  if(fi->ini == NULL){
    return 0;
  }
  Lista *li = fi->inicio;
  fi->ini = fi->ini->prox;

  if(fi->ini == NULL){
    fi->fim = NULL;
  }
  free(li);
  return 1;
}
