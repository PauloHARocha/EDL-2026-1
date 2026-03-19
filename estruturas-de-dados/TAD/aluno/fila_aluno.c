#include<stdlib.h>
#include<stdio.h>
#include"aluno.h"
#define MAX 5

// Dados
struct fila {
    Aluno dados[MAX];
    int inicio, final, qtd;
};

typedef struct fila* Fila; // 8 bytes

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

int inserir(Fila f, Aluno a){
    if(f->qtd < MAX && f != NULL){
        f->dados[f->final] = a;
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

int acessar(Fila f, Aluno* a){
    if(f->qtd == 0 || f == NULL){
        return 1;
    }else{
        *a = f->dados[f->inicio];
        return 0;
    }
}

int tamanho(Fila f){
    if(f == NULL){
        return 0;
    }
    return f->qtd;
}

void destruir_fila(Fila f){
    if(f != NULL)
        free(f);
}

int main(){
    Fila f = criar_fila();
    Aluno a1 = criar_aluno(123, 6.0);
    Aluno a2 = criar_aluno(124, 6.5);
    Aluno a3 = criar_aluno(125, 7.8);
    Aluno aux;

    inserir(f, a1);
    inserir(f, a2);
    inserir(f, a3);

    acessar(f, &aux);
    remover(f);
    destruir(aux);

    
    printf("Segundo aluno  mat: %d | media: %.2f\n", 
        acessar_mat(aux), 
        acessar_media(aux));
    
    
    destruir(a2);
    destruir(a3);

    destruir_fila(f);
    return 0;
}