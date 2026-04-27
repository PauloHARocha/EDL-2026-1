#include<stdlib.h>
#include<stdio.h>

typedef struct elemento{
    int valor;
    struct elemento* prox;
} Elem;

typedef struct lista{
    Elem* final;
    int qtd;
}* Lista;

Lista criar_lista(){
    Lista li = malloc(sizeof(struct lista));
    if(li != NULL){
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

int inserir_inicio(Lista li, int valor){
    Elem* no = malloc(sizeof(Elem));
    if(no != NULL){
        no->valor = valor;
        if(li->final == NULL){
            no->prox = no;
            li->final = no;
        }else{
            no->prox = li->final->prox;
            li->final->prox = no;
        }
        li->qtd++;
        return 0;
    }
    return 1;
}


int inserir_final(Lista li, int valor){
    if(li == NULL)
        return 1;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL)
        return 1;
    no->valor = valor;
    if(li->final == NULL){
        li->final = no;
        no->prox = no;
    }else{
        no->prox = li->final->prox;
        li->final->prox = no;
        li->final = no;
    }
    li->qtd++;
    return 0;    
}

int remover_inicio(Lista li){
}

int remover_final(Lista li){
}

int acessar_inicio(Lista li, int* valor){
}

int acessar_final(Lista li, int* valor){
}

void destruir(Lista li){
}

int tamanho_lista(Lista li){
}

int main(){
    Lista li = criar_lista();
    inserir_inicio(li, 20);
    inserir_inicio(li, 30);
    inserir_inicio(li, 40);
    int valor;
    acessar_inicio(li, &valor);
    printf("O valor do inicio é: %d\n", valor);

    printf("Tamanho da lista: %d\n", lista_quantidade(li));

    destruir(li);
    return 0;
}