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

void destruir(){

}

void menor_valor_pilha(){ // Usando as operacoes

}

int main(){

    return 0;
}

