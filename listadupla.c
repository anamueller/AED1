#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celula{
    char dado;
    struct celula *prox, *ant;
} celula;

typedef struct {
    celula *comeco;
    celula *fim;    
} lista;

void inicia_lista (lista *l) {
    l->comeco = NULL;
    l->fim = NULL;
}

void insere_lista(lista *l, char dado, int tamanho, int posicao){
    celula *ptr = (celula*)malloc(sizeof(celula));
    celula *novo;
    int i;
    novo->dado = dado;
    ptr = l->comeco;
    if(l->comeco == NULL){
        l->comeco = novo;
        ptr->prox = NULL;
        ptr->ant = NULL;
    }
    else{
        for(i = 1; i<posicao; i++){ //achar a celula que está no posição desejada
            ptr = ptr->prox; //indo toda vez para o próximo
        }
        novo->prox = ptr;
        novo->ant = ptr->ant;
        ptr->ant->prox = novo;
        ptr->ant = novo;
    }
}

char lista_retira(lista *l, int posicao, int tamanho){
    celula *ptr, *auxiliar;
    char aux;
    int i;
    ptr = l->comeco;
    if(l->comeco == NULL){
        printf("ERRO");
    }
    for(i = 1; i<posicao; i++){ //achar a celula que está no posição desejada
        ptr = ptr->prox; //indo toda vez para o próximo
    }
    auxiliar = ptr->prox;
    auxiliar->ant = ptr->ant;
    ptr->ant->prox = auxiliar;
    aux = ptr->dado;
    free(ptr);
    return aux;
}


int main(){
    char entrada[50000];
    lista *l = (lista*)malloc(sizeof(lista));
    int cursor, i, tamanho = 0;
    inicia_lista(l);
    scanf("%s", entrada);
    cursor = 1;
    for ( i==0; entrada[i] != '\n'; i++){
        if (64 < entrada[i] && entrada[i] < 123){
            insere_lista(l, entrada[i], tamanho, cursor);
        }
        switch(entrada[i]){
            case ' ':
                insere_lista(l, entrada[i], tamanho, cursor);
                break;
            case '<':
                cursor = cursor - 1;
                break;
            case '>':
                cursor = cursor + 1;
                break;
            case '[':
                cursor = 1;
                break;
            case ']':
                cursor = tamanho;
                break;
            case '-':
                lista_retira(l, cursor, tamanho);
                break;

        }
    }
    for(i==0; i<=tamanho; i++){
        printf("%s", &entrada[i]);
    }
    return 0;
}