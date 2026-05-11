#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}Elem; 

typedef struct pilha {
    struct elemento *topo;
    int qtd;
}*Pilha;

Pilha criar_pilha(){
    Pilha p = malloc(sizeof(struct pilha));
    if(p != NULL){
        p->topo = NULL;
        p->qtd = 0;
    }
    return p;
}

int push(Pilha p, int valor) {
    if (p == NULL) return 1;
    Elem *no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    if (p->qtd == 0) {
        no->prox = NULL;
    } else {
        no->prox = p->topo;
    }
    p->topo = no;
    p->qtd++;
    return 0;
}

int pop(Pilha p){
    Elem* aux = p->topo;

    if(p->topo != NULL){
        p->topo = p->topo->prox;
    }
    else{
        return 1;
    }

    p->qtd--;

    free(aux);

    return 0;
}

int peek(Pilha p, int *valor){
    if(p == NULL || p->topo == NULL){
        return 1;
    }
    *valor = p->topo->valor;
    return 0;
}

int size(Pilha p){

    if(p ==NULL){
        return 0;
    }
    return p->qtd;
}

void destruir(Pilha p){

    if(p != NULL){
        Elem * aux;

    while(p->topo != NULL){
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
        Elem *aux;
        }
    free(p);
    }
}

int menor_valor_pilha(Pilha p, int *menor_valor){ // Usando as operacoes
    if (p == NULL || size(p) == 0) return 1;
    Pilha aux = criar_pilha();
    peek(p, menor_valor);
    int menor_aux;
    while (size(p) > 0){
        peek(p, &menor_aux);
        if(menor_aux < *menor_valor) *menor_valor = menor_aux;
        pop(p);
        push(aux, menor_aux);
    }
    while(size(aux) > 0){
        peek(aux, &menor_aux);
        push(p, menor_aux);
        pop(aux);
    }
    destruir(aux);

    return 0;
}

int main(){

    return 0;
}

