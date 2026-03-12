#include<stdlib.h>
#define MAX 5
#include"fila.h"

// Dados
struct fila {
    int dados[MAX];
    int inicio, final, qtd;
};

// Operaçoes

Fila criar_fila(){
    Fila f = malloc(sizeof(struct fila));
    if(f != NULL){
        f->inicio = 0;
        f->final = 0;
        f->qtd = 0;
    }
    return f;
}

int inserir(Fila f, int valor){
    if(f->qtd < MAX && f != NULL){
        f->dados[f->final] = valor;
        f->final = (f->final + 1) % MAX;
        f->qtd++;
        return 0;
    }else{
        return 1;
    }
}

int remover(Fila f){
    if(f->qtd == 0 || f == NULL){
        return 1;
    }else{
        f->inicio = (f->inicio + 1) % MAX;
        f->qtd--;
        return 0;
    }
}

int acessar(Fila f, int* valor){
    if(f->qtd == 0 || f == NULL){
        return 1;
    }else{
        *valor = f->dados[f->inicio];
        return 0;
    }
}

int tamanho(Fila f){
    if(f == NULL){
        return 0;
    }
    return f->qtd;
}

void destruir(Fila f){
    if(f != NULL)
        free(f);
}
