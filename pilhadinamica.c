#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct NO{
    float dado; //conteúdo da pilha
    struct NO *prox; //vetor da pilha que aponta pro próximo item da pilha
} NO; 

typedef struct pilha{
    NO *topo; //apontador que aponta para o topo da pilha
} pilha;

void inicia_pilha(pilha *p){
    p->topo = NULL; //criando uma pilha com nenhum inteiro por isso o topo aponta para null ou seja nada
}

void pilha_empilha(float dado, pilha *p){
    NO *ptr = (NO*) malloc(sizeof(NO)); //alocando memória e criando o ponteiro tipo celula
    if (ptr == NULL){ //se o ponteiro não contém nada, não tem nada para adicionar
        printf("ERRO");
    }
    else{
        ptr->dado = dado; //atribuindo o valor do dado ao ponteiro criado que ajuda a adicionar a nossa pilha
        ptr->prox = p->topo; //o endereço do prox passa a ser o topo(pois o item aidcionado aponta para o item anterior a ele) 
        p->topo = ptr; //topo é aonde o ponteiro auxiliar está apontando, o novo dado
    }
}

float pilha_desempilha(pilha *p){
    NO* ptr = p->topo; //o ponteiro auxiliar aponta para o atual topo(item que será retirado)
    float dado;
    if(ptr == NULL){ //se aponta para o topo e é null sigifica que está sem itens na pilha
        printf("Pilha vazia");
    }
    else{
        p->topo = ptr->prox; //topo passa a apontar para o item anterior ao topo (que será o novo topo)
        ptr->prox = NULL; //o item que será retirado aponta para nada
        dado = ptr->dado; //salvando o dado que será deletado da pilha
        free(ptr); //deletando o dado e deixando o ponteiro auxiliar livre
        return dado; //retornando o dado que foi deletado
    }
}

int main(){
    char entrada[49];
    pilha *pi = (pilha*)malloc(sizeof(pilha));
    inicia_pilha(pi);
    scanf("%s", entrada);
    int i;
    float y;
    for (i == 0; i<=strlen(entrada); i++){
        if( 64 < entrada[i] && entrada[i] < 123){
            scanf("%f", &y);
            pilha_empilha(y, pi);
        }
        else{
            float num1, num2;
            float conta;
            switch (entrada[i]){
                case '+':
                    num1 = pilha_desempilha(pi);
                    num2 = pilha_desempilha(pi);
                    conta = num2+num1;
                    pilha_empilha(conta, pi);
                    break;
                case '-':
                    num1 = pilha_desempilha(pi);
                    num2 = pilha_desempilha(pi);
                    conta = num2-num1;
                    pilha_empilha(conta, pi);
                    break;
                case '*':
                    num1 = pilha_desempilha(pi);
                    num2 = pilha_desempilha(pi);
                    conta = num2*num1;
                    pilha_empilha(conta, pi);
                    break;
                case '/':
                    num1 = pilha_desempilha(pi);
                    num2 = pilha_desempilha(pi);
                    conta = num2/num1;
                    pilha_empilha(conta, pi);
                    break;
            }
        }
    }
    float final;
    final = pilha_desempilha(pi);
    printf("%f", final);
    return 0;
}