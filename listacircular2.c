#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula *ptr;

typedef struct celula {
    char dado;
    ptr Prox;
} celula;

typedef struct {
  ptr fim;
  int tamanho;
} lista;

void lista_inicia(lista *l){
  l->fim = (ptr) malloc(sizeof(celula));
  l->fim->Prox = l->fim;
  l->tamanho = 0;
}

int lista_vazia(lista *l){
  return (l->fim->Prox == l->fim);
}

int lista_tamanho(lista *l){
  return (l->tamanho);
}

int lista_insere(lista *l, ptr p, char x){
  ptr ant, novo;
  ant = l->fim->Prox;
  while ((ant != l->fim) && (ant->Prox != p)){
    ant = ant->Prox;
  }
  if (ant->Prox != p){
    return 0;
  }
  novo = (ptr) malloc(sizeof(celula));
  novo->dado = x;
  novo->Prox = ant->Prox;
  ant->Prox = novo;
  if(ant == l->fim){
    l->fim = novo;
  }
  l->tamanho++;
  return 1;
}

int lista_retira(lista *l, ptr p, char *pX){
  ptr ant, pAux;
  if (lista_vazia(l)){
    return 0;
  }
   ant = l->fim->Prox;
  while ((ant != l->fim) && (ant->Prox != p)){
    ant = ant->Prox;
  }    
  if (ant->Prox != p){
    return 0;
  }
  pAux = ant->Prox;
  ant->Prox = pAux->Prox;
  if (pAux == l->fim){
    l->fim = ant;
  }
  *pX = pAux->dado;
  free(pAux);
  l->tamanho--;
  return 1;
}

ptr lista_retorna(lista *l, int p){
  ptr pApontador;
  int indice;
  indice = 0;
  pApontador = l->fim->Prox->Prox;
  while ((pApontador != l->fim->Prox) && (indice != p)){
    pApontador = pApontador->Prox;
    indice++;
  }
  return pApontador;
}

void lista_imprime(lista *l) {
  ptr p;
  for(p = l->fim->Prox->Prox; p != l->fim->Prox; p = p->Prox){
    printf("%c", p->dado);
  }
}

int main () {
  int cursor, i, tamanho;
  char entrada[50000];
  lista lista;
  lista_inicia(&lista);
  scanf("%[^\n]s", entrada);
  tamanho = strlen(entrada);
  cursor = 0;
  char aux;
  for(i = 0; i < tamanho; i++) {
    switch(entrada[i]) {
      case '[':
        cursor = 0;
        break;
      case ']':
        cursor = lista.tamanho;
        break;
      case '-':
        if(cursor > 0) {
          cursor--;
          lista_retira(&lista, lista_retorna(&lista, cursor), &aux);
        }
        break;
      case '<':
        if(cursor > 0) {
          cursor--;
        }
        break;
      case '>':
        if(cursor < lista.tamanho) {
          cursor++;
        }
        break;
      default:
        lista_insere(&lista, lista_retorna(&lista, cursor), entrada[i]);
        cursor++;
        break;
    }
  }
  while(!lista_vazia(&lista)) {
    lista_retira(&lista, lista_retorna(&lista, 0), &aux);
    printf("%c", aux);
  }
  return 0;
}