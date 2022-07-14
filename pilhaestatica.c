#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float itens_pilha[500]; //vetor que serão armazenados os itens da pilha
    int topo;
} pilha;

int pilha_inicia(pilha *p){
    p->topo = 0;
    return 1;
}

int pilha_vazia(pilha *p){
    if (p->topo == 0){
        return 1; //true, pilha está vazia
    }
    else {
        return 0; //false, pilha não está vazia
    }
}

int pilha_cheia(pilha *p){
    if (p->topo == 500){
        return 1; //true, pilha está cheia
    }
    else{
        return 0;  //false, pilha não está cheia
    }
}

int pilha_insere(pilha *p, float x){
    if (pilha_cheia(p) == 1){
        printf("ERRO: Pilha cheia");
        return 0; //false, não conseguiu colocar o item
    }
    else {
        p->topo++;
        p->itens_pilha[p->topo] = x;
        return 1; //true, conseguiu colocar o item
    }
}

float pilha_desempilha(pilha *p){
    float aux;
    if (pilha_vazia(p) == 1){
        printf("ERRO: Pilha vazia");
        return 0; //false, não conseguiu remover o item
    }
    else{
        aux = p->itens_pilha[p->topo];
        p->topo--;
        return aux; //true, conseguiu remover o item
    }
}

int tamanho_pilha(pilha *p){
    return (p->topo);
}

int main(){
    char entrada[49];
    pilha *p = (pilha*)malloc(sizeof(pilha));
    pilha_inicia(p);
    scanf("%s", entrada);
    int i;
    float y;
    for (i == 0; i<=strlen(entrada); i++){
        if( 64 < entrada[i] && entrada[i] < 123){
            scanf("%f", &y);
            pilha_insere(p, y);
        }
        else{
            float num1, num2;
            float conta;
            switch (entrada[i]){
                case '+':
                    num1 = pilha_desempilha(p);
                    num2 = pilha_desempilha(p);
                    conta = num2+num1;
                    pilha_insere(p, conta);
                    break;
                case '-':
                    num1 = pilha_desempilha(p);
                    num2 = pilha_desempilha(p);
                    conta = num2-num1;
                    pilha_insere(p, conta);
                    break;
                case '*':
                    num1 = pilha_desempilha(p);
                    num2 = pilha_desempilha(p);
                    conta = num2*num1;
                    pilha_insere(p, conta);
                    break;
                case '/':
                    num1 = pilha_desempilha(p);
                    num2 = pilha_desempilha(p);
                    conta = num2/num1;
                    pilha_insere(p, conta);
                    break;
            }
        }
    }
    float final;
    final = p->itens_pilha[p->topo];
    printf("%f", final);
    return 0;
}