#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int forca_inicial;
	int forca_confronto;
	int indice;
} competidor;

typedef struct celula{
    competidor dado; //conteúdo da fila
    struct celula *prox; //ponteiro da fila que aponta pro próximo item da fila
} celula;

typedef struct {
    celula *frente; //apontador que aponta para frente da fila
    celula *tras; //apontador que aponta para frente da fila
} fila;

void inicia_fila(fila *f){
    f->frente = NULL; 
    f->tras = NULL;
}

void fila_insere(competidor dado, fila *f){
    celula *ptr = (celula*)malloc(sizeof(celula)); //alocando memória e criando o ponteiro tipo celula
    if (ptr == NULL){ //se o ponteiro não contém nada, não tem nada para adicionar
        printf("ERRO");
    }
    else{
        ptr->dado = dado; //atribuindo o valor do dado ao ponteiro criado
        ptr->prox = NULL; //o endereço do prox passa a ser o fim da fila 
        if(f->frente == NULL){ //quando a fila esta vazia
            f->frente = ptr;
        }
        else{
            f->tras->prox = ptr;
        }
        f->tras = ptr;
    }
}

competidor fila_retira(fila *f){
    celula *ptr = f->frente;
    competidor aux;
    if(f->tras == NULL){
        printf("ERRO");
    }
    else {
        f->frente = ptr->prox;
        ptr->prox = NULL;
        aux = ptr->dado;
        free(ptr);
        if(f->frente == NULL){
            f->tras = NULL;
        }
        
    }
    return aux;
}

int main(){
 int i, k, N, pi, count;
    scanf("%d %d", &N, &k);
    count = pow(2, N);
	fila *f = (fila*)malloc(sizeof(fila));
	competidor C1, C2, x;
	inicia_fila(f);
    for (i=0; i < count; i++){
        scanf("%d", &pi);
		x.forca_inicial = pi;
		x.forca_confronto = pi;
		x.indice = i + 1;
		fila_insere(x, f);
    }

	while (f->tras != f->frente){
		C1 = fila_retira(f);
		C2 = fila_retira(f);
		if (C1.forca_confronto > C2.forca_confronto || C1.forca_confronto == C2.forca_confronto){
			x.forca_confronto = (C1.forca_confronto - C2.forca_confronto) + k;	
			if(x.forca_confronto > C1.forca_inicial){
				x.forca_confronto = C1.forca_inicial;
			}
			x.indice = C1.indice;
			x.forca_inicial = C1.forca_inicial;
			fila_insere(x, f);
		}
		else{
			x.forca_confronto = (C2.forca_confronto - C1.forca_confronto) + k;
			if(x.forca_confronto  > C2.forca_inicial){
				x.forca_confronto = C2.forca_inicial;
			}
			x.indice = C2.indice;
			x.forca_inicial =C2.forca_inicial;
			fila_insere(x, f);
		}
	}

	competidor ganhador;
	ganhador = f->frente->dado;
	printf("%d", ganhador.indice);
    return 0;
}