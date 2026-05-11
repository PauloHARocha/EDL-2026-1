#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}Elem; 

typedef struct fila {
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
}*Fila;

Fila criar_fila(){
    Fila f = malloc(sizeof(struct fila));
    if(f != NULL){
        f->inicio = NULL;
        f->final = NULL;
        f->qtd = 0;
    }
    return f;
}

int enqueue(Fila f, int dado){
    if(f == NULL) return 1;

    Elem *no = malloc(sizeof(Elem));
    no->valor = dado;
    no->prox = NULL;

    if(f->final == NULL){
        f->inicio = no;
    }else{
        f->final->prox = no;
    }
    f->final = no;
    f->qtd++;
    return 0;
}

int dequeue(Fila f){
    if(f == NULL || f->qtd == 0) return 1;

    Elem *aux = f->inicio;
    f->inicio = aux->prox; // f->inicio->prox
    if(f->inicio == NULL)
        f->final = NULL;

    free(aux);
    f->qtd--;
    return 0;
}
