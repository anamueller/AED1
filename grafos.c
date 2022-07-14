#include <stdio.h>
#include <stdlib.h>
#define maxvertices 100

typedef struct {
    int adj[maxvertices][maxvertices];
    int nvertices;
    int narestas;
} grafo;

void inicia_matriz(grafo *g){
    int i;
    for(i=0; i<maxvertices; i++){
        g->adj[i][i] = 0;
    }
}

void insere_aresta(grafo *g, int comeco, int fim){
    g->adj[comeco][fim] = 1;
}

int retorna_dependentes(grafo *g, int linha, int N){
    int aux = 0, i;
    for(i=1; i<=N; i++){
        if(g->adj[linha][i] == 0){
            aux = aux;
        }
        else{
            aux++;
        }
    }
    return aux;
}

int imprimi_dependencias(grafo *g, int coluna, int N){
    int aux = 0, i;
    for(i=1; i<=N; i++){
        if(g->adj[i][coluna] == 0){
            aux = aux;
        }
        else{
            aux++;
        }
    }
    printf("%d", aux);
    for(i=1; i<=N; i++){
        if(g->adj[i][coluna] == 1){
            printf(" %d", i);
        }
    }
    printf("\n");
    return aux;
}

int main(){
    int i, pacotes, relacoes, comeco, fim, dependente;
    grafo *g = (grafo*)malloc(sizeof(grafo));
    inicia_matriz(g);
    scanf("%d %d", &pacotes, &relacoes);
    for(i = 1; i<=relacoes; i++){
        scanf("%d %d", &fim, &comeco);
        insere_aresta(g, comeco, fim);
    }
    for(i=1; i<=pacotes; i++){
        dependente = retorna_dependentes(g, i, pacotes);
        printf("%d %d ", i, dependente);
        imprimi_dependencias(g, i, pacotes);
    }
    return 0; 
}