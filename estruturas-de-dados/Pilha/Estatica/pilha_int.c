#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct pilha {
    int dados[MAX];
    int topo;
} *Pilha;

Pilha criar_pilha(){
    Pilha p = malloc(sizeof(struct pilha));
    if(p != NULL)
        p->topo = 0;
    return p;
}

int push(Pilha p, int matricula){
    if(p->topo < MAX && p != NULL){
        p->dados[p->topo] = matricula;
        p->topo++;
        return 0;
    }else
        return 1;
}

int peek(Pilha p, int* matricula){
    if (p->topo == 0 || p == NULL)
        return 1;
    else
        *matricula = p->dados[p->topo - 1];
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

int main(){
    Pilha p = criar_pilha();
    int matricula;

    for(int i = 0; i < MAX; i++){
        printf("Insira a matricula aluno %d: ", i+1);
        scanf("%d", &matricula);

        if(push(p, matricula)){
            printf("Erro, valor nao inserido\n");
        }else{
            printf("Valor inserido: %d\n", matricula);
        }
        printf("Quantidade de elementos: %d\n", tamanho_pilha(p));
    }
   
    for(int i = 0; i < MAX; i++){
        printf("Elemento da pilha posicao %d: %d\n", i, p->dados[i]);
    }
    
    while(tamanho_pilha(p)){
        if(peek(p, &matricula))
            printf("Erro de acesso\n");
        else
            printf("Matricula aluno %d: %d \n", 
                tamanho_pilha(p), matricula); 
        pop(p);
    }

    destruir_pilha(p);
    return 0;
}