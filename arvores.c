#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int dado;
    struct no *esquerda;
    struct no *direita;
} no;

typedef struct no arvore;


arvore* insere_item(arvore *a, int dado){
    if(a == NULL){
        a = (arvore*)malloc(sizeof(no));
        a->dado = dado;
        a->esquerda = a->direita = NULL;
    }
    else if(dado < a->dado){
        a->esquerda = insere_item(a->esquerda, dado);
    }
    else if(dado > a->dado){
        a->direita = insere_item(a->direita, dado);
    }
    return a;
}

arvore* retira_item(arvore *r, int dado){
    if (r == NULL){
        return NULL;
    }else if (r->dado > dado){
        r->esquerda = retira_item(r->esquerda, dado);
    }else if (r->dado < dado){
        r->direita = retira_item(r->direita, dado);
    }else {
            if (r->esquerda == NULL && r->direita == NULL) {
                free (r);
                r = NULL;
            }
            else if (r->esquerda == NULL) {
                arvore *aux = r;
                r = r->direita;
                free (aux);
            }
            else if (r->direita == NULL) {
                arvore *aux = r;
                r = r->esquerda;
                free (aux);
            }
            else {
                arvore *aux2 = r->esquerda;
                while(aux2->direita != NULL){
                    aux2 = aux2->direita;
                }
                r->dado = aux2->dado;
                aux2->dado = dado;
                r->esquerda = retira_item(r->esquerda, dado);
            }
        }
 return r;
}

int esta_na_arvore(arvore *a, int nbuscar){
    if(a->direita == NULL && a->esquerda == NULL){
        return 0;
    }
    else if(nbuscar > a->dado){
        esta_na_arvore(a->direita, nbuscar);
        if(nbuscar == a->dado){
            return 1;
        }
    }
    else if(nbuscar < a->dado){
        esta_na_arvore(a->esquerda, nbuscar);
        if(nbuscar == a->dado){
            return 1;
        }
    }
}

void imprime(arvore *a){
    if(a->direita == NULL && a->esquerda == NULL){
        printf("(C%d()())", a->dado);
    }
    else{
        printf("(");
        printf("C%d", a->dado);
        if(a->esquerda != NULL){
            imprime(a->esquerda);
        }
        else{
            printf("()");
        }
        if(a->direita !=NULL){
            imprime(a->direita);
        }
        else{
            printf("()");
        }
        printf(")");
    }
}

int main(){
    arvore *a;
    int nbuscar, nraizes, i, dado, numero;
    scanf("%d", &nraizes);
    for(i=0; i<nraizes; i++){
        scanf("%d", &numero);
        insere_item(a, numero);
    }
    scanf("%d", &nbuscar);
    if(esta_na_arvore(a, nbuscar) == 1){
        retira_item(a, nbuscar);
    }
    if(esta_na_arvore(a, nbuscar) == 0){
        insere_item(a, nbuscar);
    }
    imprime(a);
    return 0;
}