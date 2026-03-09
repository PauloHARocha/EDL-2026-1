#include<stdlib.h>
#include"pilha.h"

struct pilha {
    int dados[MAX];
    int topo;
};

Pilha criar_pilha(){
    Pilha p = malloc(sizeof(struct pilha));
    if(p != NULL)
        p->topo = 0;
    return p;
}

int push(Pilha p, int valor){
    if(p->topo < MAX && p != NULL){
        p->dados[p->topo] = valor;
        p->topo++;
        return 0;
    }else
        return 1;
}

int peek(Pilha p, int* valor){
    if (p->topo == 0 || p == NULL)
        return 1;
    else
        *valor = p->dados[p->topo - 1];
        return 0;
}

int pop(Pilha p){
    if (p->topo == 0 || p == NULL)
        return 1;
    else
        p->topo--;
    return 0;
}

int tamanho_pilha(Pilha p){
    if(p == NULL)
        return 0;
    return p->topo;
}

void destruir_pilha(Pilha p){
    if(p != NULL)
        free(p);
}