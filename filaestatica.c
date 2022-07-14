#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxtam 32768

typedef struct {
	int forca_inicial;
	int forca_confronto;
	int indice;
} competidor;

typedef struct {
	competidor itens[maxtam];
	int frente;
	int tras;
} fila;

void fila_inicia(fila *f, competidor x){
	f->frente = 0;
	f->tras = 0;
	x.indice = 0;
	x.forca_inicial = 0;
}

int fila_vazia (fila *f) {
	if (f->frente == f->tras){
		return 1;
	}
	if (f->frente != f->tras){
		return 0;
	}
}

int insere_fila(fila *f, competidor x){
	f->itens[f->tras] = x;
	f->tras = f->tras + 1;
	return 1;
}

competidor retira_fila(fila *f){ //usando método físico
	int i;
	competidor aux;
	if (fila_vazia(f) == 1){
		printf("ERRO: fila vazia");
	}
	else{
		aux = f->itens[0];
		for(i = 0; i<f->tras; i++){
			f->itens[i] = f->itens[i+1];
		}
	}
	f->tras = f->tras--;
	return aux;
}

int main(){
    int i, k, N, pi, count;
    scanf("%d %d", &N, &k);
    count = pow(2, N);
	fila *f = (fila*)malloc(sizeof(fila));
	competidor C1, C2, x;
	fila_inicia(f, x);
    for (i=0; i < count; i++){
        scanf("%d", &pi);
		x.forca_inicial = pi;
		x.forca_confronto = pi;
		x.indice = i + 1;
		insere_fila(f, x);
    }

	while (f->tras != 1){
		C1 = retira_fila(f);
		C2 = retira_fila(f);
		if (C1.forca_confronto > C2.forca_confronto || C1.forca_confronto == C2.forca_confronto){
			x.forca_confronto = (C1.forca_confronto - C2.forca_confronto) + k;	
			if(x.forca_confronto > C1.forca_inicial){
				x.forca_confronto = C1.forca_inicial;
			}
			x.indice = C1.indice;
			x.forca_inicial = C1.forca_inicial;
			insere_fila(f, x);
		}
		else{
			x.forca_confronto = (C2.forca_confronto - C1.forca_confronto) + k;
			if(x.forca_confronto  > C2.forca_inicial){
				x.forca_confronto = C2.forca_inicial;
			}
			x.indice = C2.indice;
			x.forca_inicial =C2.forca_inicial;
			insere_fila(f, x);
		}
	}

	competidor ganhador;
	ganhador = f->itens[0];
	printf("%d", ganhador.indice);
    return 0;
}