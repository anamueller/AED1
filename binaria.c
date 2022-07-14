#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int Chave;
} TItem;
 
typedef struct SnoA *Tarvorebin;
 
typedef struct SnoA {
    Tarvorebin Left, Right;
    TItem Item;
} Tno;
 
Tno* inicia(){
    return NULL;
}
 
Tno* cria (TItem x, Tarvorebin Left, Tarvorebin Right){
 
    Tno *no = (Tarvorebin) malloc(sizeof(Tno));
    no->Item = x;
    no->Left = Left;
    no->Right = Right;
 
    return no;
}
 
typedef Tarvorebin TABB;
 
TABB pesquisa(TABB Raiz, int x){
    TABB *no;
    no = &Raiz;
 
    while ((no != NULL) && (x != (*no)->Item.Chave)){
        if (x < (*no)->Item.Chave){
            no =& (*no)->Left;
        } else if (x > (*no)->Item.Chave){
            no =& (*no)->Right;
        }
    }
    return *no;
}
 
int insere (TABB *pno, TItem x){
    if (*pno == NULL){
        *pno = cria(x, inicia(), inicia());
        return 1;
    } else if (x.Chave < (*pno)->Item.Chave){
        return insere(&(*pno)->Left, x);
    } else if (x.Chave > (*pno)->Item.Chave){
        return insere(&(*pno)->Right, x);
    } else {
        return 0;
    }
}
 
void antes (TABB *q, TABB *t){
    if((*t)->Right != NULL){
        antes(q, &(*t)->Right);
    } else {
        (*q)->Item = (*t)->Item;
        *q = *t;
        *t = (*t)->Left;
    }
}
 
void prox(TABB *q, TABB *t){
    if((*t)->Left != NULL){
        prox(q, &(*t)->Left);
    } else {
        (*q)->Item = (*t)->Item;
        *q = *t;
        *t = (*t)->Right;
    }
}
 
int retira(TABB *pRaiz, int x){
    TABB *p, u;
    p = pRaiz;
 
    while ((*p != NULL) && (x != (*p)->Item.Chave)) {
        if (x < (*p)->Item.Chave){
            p = &(*p)->Left;
        } else if (x > (*p)->Item.Chave){
            p = &(*p)->Right;
        }
    }
 
    if (*p != NULL) {
        u = *p;
 
        if (u->Left == NULL){
            *p = u->Right;
        } else if (u->Right == NULL){
            *p = u->Left;
        } else {
            prox(&u, &u->Right);
        }
        free(u);
        return 1;
    }
    return 0;
}
 
void imprimi(TABB *no) {
  printf("(");
  printf("C%d", (*no)->Item.Chave);
  if((*no)->Left != NULL)
      imprimi(&(*no)->Left);
  else
      printf("()");
  if((*no)->Right != NULL)
      imprimi(&(*no)->Right);
  else
      printf("()");
  printf(")");
}
 
 
int main() {
    int nraizes, i, numero, nbuscar;
    TABB arv;
    arv = inicia();
    scanf("%d", &nraizes);
    int x;
    TItem item;
    for(i = 0; i < nraizes; i++) {
        scanf("%d", &numero);
        item.Chave = numero;
        insere(&arv, item);
    }
    scanf("%d", &nbuscar);
    x = nbuscar;
    item.Chave = x;
    if(retira(&arv, x) == 0)
       insere(&arv, item);
    imprimi(&arv);
return 0;
}