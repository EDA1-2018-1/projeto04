
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

//-----------------------------------------------------
/* Declarção de Funções*/
Lista *insere_inicio(Lista*,Aviao*);
Lista *insere_fim(Lista*,Aviao*);
Lista *retira_inicio(Lista*);
Lista *retira_fim(Lista*);

void fila_insere_inicio(Fila*);
void fila_insere_fim(Fila*);
Aviao fila_retira_inicio(Fila*);
Aviao fila_retira_fim(Fila*);

int numeroDecolagem();
//-----------------------------------------------------
typedef struct aviao {
  int id;
  char tipo;
  int combustivel;
} Aviao;

typedef struct lista {
  Aviao aviao;
  struct lista* ant;
  struct lista* prox;
} Lista;

typedef struct fila {
  Lista* ini;
  Lista* fim;
} Fila;

int main(int argc, char const *argv[]) {

  char codVoos[64][6] =  {"VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009",
													"AZ1008", "AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880",
													"AL0012", "TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002",
													"AZ1002", "AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403",
													"AZ1001", "LN7003", "AZ1004", "TG1504", "AZ1005", "TG1502", "GL7601",
													"TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390", "VV3392",
													"GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920", "AZ1065",
													"LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510",
													"TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609", "KL5610",
													"KL5611"};

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
Lista *insere_inicio (Lista* ini, Aviao *i) { //Auxiliar
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   novo->aviao = *i;
   novo->prox = ini;
   novo->ant = NULL;
   if (ini != NULL){
     ini->ant = novo;
   }
   return novo;
}
//--------------------------------------------------------
Lista *insere_fim (Lista* fim, Aviao *i) { //Auxiliar
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   novo->aviao = *i;
   novo->prox = NULL;
   novo->ant = fim;
   if (fim != NULL){
      fim->prox = novo;
   }
   return novo;
}
//--------------------------------------------------------
Lista *retira_inicio (Lista* ini) { //Auxiliar
   Lista* p = ini->prox;
   if (p != NULL){
     p->ant = NULL;
   }
   free(ini);
   return p;
}
//--------------------------------------------------------
Lista *retira_fim (Lista* fim) { //Auxiliar
   Lista* p = fim->ant;
   if (p != NULL){
     p->prox = NULL;
   }
   free(fim);
   return p;
}
//-------------------------------------------------------
void fila_insere_inicio (Fila* f) {
	 Aviao *i = (Aviao*)calloc(1,sizeof(Aviao));
   f->ini = insere_inicio(f->ini,i);
   if (f->fim==NULL){
     f->fim = f->ini;
   }
}
//-------------------------------------------------------
void fila_insere_fim (Fila* f) {
	 Aviao *i = (Aviao*)calloc(1,sizeof(Aviao));
   f->fim = insere_fim(f->fim,i);
   if (f->ini==NULL){
      f->ini = f->fim;
   }
}
//-------------------------------------------------------
Aviao fila_retira_inicio (Fila* f) {
   Aviao v;
   if (f->ini == NULL) {
      printf("Fila vazia.\n");
      exit(1);         /* aborta programa */
   }
   v = f->ini->aviao;
   f->ini = retira_inicio(f->ini);
   if (f->ini == NULL){
      f->fim = NULL;
   }
   return v;
}
//-------------------------------------------------------
Aviao fila_retira_fim (Fila* f) {
   Aviao v;
   if (f->ini == NULL) {
      printf("Fila vazia.\n");
      exit(1);
   }
   v = f->fim->aviao;
   f->fim = retira_fim(f->fim);
   if (f->fim == NULL){
     f->ini = NULL;
   }
   return v;
}
//-------------------------------------------------------
int numeroDecolagem(){
  srand(time(NULL));
  return 10+(rand() % (22)) + 1;
}
//-------------------------------------------------------
//-------------------------------------------------------
