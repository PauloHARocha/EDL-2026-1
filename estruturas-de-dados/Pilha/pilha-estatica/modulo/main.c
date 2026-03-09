#include<stdio.h>
#include"pilha.h"

struct pilha {
    int dados[MAX];
    int topo;
};

Pilha copiar_pilha_2(Pilha p){

    Pilha p_copia = criar_pilha();

    for(int i = 0; i<10; i++){
        p_copia->dados[i] = p->dados[i];
    }

    return p_copia;
}

Pilha copiar_pilha(Pilha p){
    // peek pra acessar o topo
    // push pra inserir na nova
    Pilha p_copia = criar_pilha();
    Pilha p_aux = criar_pilha();

    int valor;
    while(tamanho_pilha(p)){
        peek(p, &valor);
        push(p_aux, valor);
        pop(p);
    }

    while(tamanho_pilha(p_aux)){
        peek(p_aux, &valor);
        push(p, valor);
        push(p_copia, valor);
        pop(p_aux);
    }

    destruir_pilha(p_aux);

    return p_copia;


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
    
    Pilha p_copia = copiar_pilha(p);
    
    printf("Pilha original p\n");
    while(tamanho_pilha(p)){
        if(peek(p, &matricula))
            printf("Erro de acesso\n");
        else
            printf("Matricula aluno %d: %d \n", 
                tamanho_pilha(p), matricula); 
        pop(p);
    }

    printf("Pilha copia p_copia\n");
    while(tamanho_pilha(p_copia)){
        if(peek(p_copia, &matricula))
            printf("Erro de acesso\n");
        else
            printf("Matricula aluno %d: %d \n", 
                tamanho_pilha(p_copia), matricula); 
        pop(p_copia);
    }

    destruir_pilha(p);
    destruir_pilha(p_copia);
    return 0;
}