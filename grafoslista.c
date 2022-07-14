#include <stdio.h>
#include <stdlib.h>

//Algumas TADs foram formulados com o auxílio do monitor (Bruno)

typedef struct {
    int valor;
    struct lista *prox;
}lista;

void inicia(lista *listas[], int n){
    int i = 0;
    for(i=0; i<n; i++){
        listas[i] = NULL;
    }
}

void insere(lista *l, int n){
    lista *aux = l;
    while(aux->prox !=NULL){
        aux = aux->prox;
    }
    lista *novo = (lista *)malloc(sizeof(lista));
    novo->valor = n;
    novo->prox = NULL;
    aux->prox = novo;
}


int imprime (lista *l, int num){
    lista *aux = l->prox;
    int contador=0;
    while(aux!=NULL){
        contador++;
        aux=aux->prox;
    }
    aux = l->prox;
    printf("%d ", contador);
    while(aux!=NULL){  
        printf("%d ", aux->valor);
        aux=aux->prox;
    }
    printf("\n");
    return contador;
}

int main(){

    lista *listas;
    int N,D,i,dependente=0;
    int n1,n2;
    scanf("%d %d", &N, &D);
    int dependentes[100];
    for(i=0; i<100; i++){
        dependentes[i] = 0;
    }
    listas = (lista*)malloc(N*sizeof(lista));
    inicia(listas, N);
    for(i=0;i<D;i++){
        scanf("%d %d", &n1, &n2);
        dependente = dependentes[n2];
        dependentes[n2] = dependente + 1;
        insere(&listas[n1-1],n2);
    }
    for(i=0; i<N;i++){
        printf("%d ", i+1);
        printf("%d ", dependentes[i+1]);
        imprime(&listas[i], i+1);
    }

    return 0;
}