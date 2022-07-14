#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *comeco;
    celula *fim;    
    int tamanho;
} lista;

void inicia_lista (lista *l) {
    l->comeco = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}

void insere_lista (lista *l, char dado, int posicao){
    celula *ptr = (celula*)malloc(sizeof(celula));
    celula *atual, *anterior;
    int i;
    ptr->dado = dado;
    if(posicao>l->tamanho){
        printf("ERRO");
    }
    if(l->comeco == NULL){
        l->comeco = ptr;
        l->fim = ptr;
        ptr->prox = NULL;
    }
    else{ //adicionado em qualquer posição
        ptr = l->comeco;
        for(i = 1; i<posicao; i++){ //achar a celula que está no posição desejada
            anterior = atual; //mexendo pra apontar ao anterior
            atual = atual->prox; //indo toda vez para o próximo
        }
        if(posicao != l->tamanho){
            anterior->prox = ptr;
            ptr->prox = atual;
        }
        else{ //adicionando no final da lista
            anterior->prox = ptr;
            ptr->prox = l->comeco;
        }
    }
    l->tamanho++;
}
    
void lista_retira(lista *l, int posicao){
    celula *atual, *anterior;
    int i;
    atual = l->comeco;
    if(posicao>0){
        printf("ERRO: Posição inesxistente");
    }
    for(i = 1; i<posicao; i++){ //achar a celula que está no posição desejada
        anterior = atual; //mexendo pra apontar ao anterior
        atual = atual->prox; //indo toda vez para o próximo
    }
    anterior->prox = atual->prox;
    free(atual);
    l->tamanho--;   
}

int main(){
    char entrada[50000], auxiliar;
    lista *l = (lista*)malloc(sizeof(lista));
    int cursor, i = 0;
    inicia_lista(l);
    cursor = 0;
    while(auxiliar != '\n'){
        scanf("%c", &auxiliar);
        entrada[i] = auxiliar;
        i++;
    }
    for(i=0; i < strlen(entrada); i++)
        if (64 < entrada[i] && entrada[i] < 123){
        insere_lista(l, entrada[i], cursor);
        cursor++;
        break;
        }
        switch(entrada[i]){
            case '<':
                cursor--;
                break;
            case '>':
                cursor++;
                break;
            case '[':
                cursor = 1;
                break;
            case ']':
                cursor = l->tamanho;
                break;
            case '-':
                cursor--;
                lista_retira(l, cursor);
                break;
            default:
                insere_lista(l, entrada[i], cursor);
                cursor++;
                break;
            }
    celula *atual;
    atual = l->comeco;
    for(i = 1; i<l->tamanho; i++){ 
        printf("%c", atual->dado);
        atual = atual->prox;
    }
    return 0;
}