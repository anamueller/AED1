void insere_lista_meio(lista *l, char dado, int tamanho, int posicao){
    celula *atual, *anterior,*novo; 
    atual = l->comeco; //apontando para o primeiro item da lista
    anterior = NULL; //apontando para nada por enquanto
    if(posicao>tamanho){
        printf("ERRO");
    }
    for(int i = 1; i<posicao; i++){ //achar a celula que está no posição desejada
        anterior = atual; //mexendo pra apontar ao anterior
        atual = atual->prox; //indo toda vez para o próximo
    }
    anterior->prox = novo;
    novo->prox = atual;
    novo->dado = dado;
}


void insere_lista(lista *l, char dado, int tamanho, int posicao){
    celula *ptr, *novo;
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
            i++;
        }
        novo->prox = ptr;
        novo->ant = ptr->ant;
        ptr->ant->prox = novo;
        ptr->ant = novo;
    }
}

    if (posicao == 1){ //começo da lista quando aperta [ (igual pilha, topo = final) 
        ptr->dado = dado;
        ptr->prox = l->comeco;
        l->comeco = ptr;
        aux = l->fim->prox;
        aux = ptr;
    }
    if(posicao == tamanho){ //fim da lista quando aperta ] (igual fila, adiciona no final)
        ptr->dado = dado;
        ptr->prox = NULL;
        if(l->comeco == NULL){ //quando a fila esta vazia
            l->comeco = ptr;
        }
        else{
            aux = l->fim->prox;
            aux = ptr;
        }
        l->fim = ptr;
        ptr->prox = l->comeco;
    }
    if(posicao != 1 && posicao != tamanho){
        celula *atual, *anterior,*novo;
        int i; 
        atual = l->comeco; //apontando para o primeiro item da lista
        anterior = NULL; //apontando para nada por enquanto
        for(i = 1; i<posicao; i++){ //achar a celula que está no posição desejada
            anterior = atual; //mexendo pra apontar ao anterior
            atual = atual->prox; //indo toda vez para o próximo
        }
        anterior->prox = novo;
        novo->prox = atual;
        novo->dado = dado;
    }
        if(posicao>tamanho){
        printf("ERRO");
        }