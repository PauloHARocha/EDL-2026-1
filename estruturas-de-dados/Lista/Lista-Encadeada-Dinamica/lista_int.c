#include<stdlib.h>
#include<stdio.h>

typedef struct elemento{
    int valor;
    struct elemento* prox;
} Elem;

typedef struct lista{
    Elem* inicio;
} Lista;

Lista* criar_lista(){
    Lista *li = malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
    }
    return li;
}

int inserir_inicio(Lista* li, int valor){
    Elem* no = malloc(sizeof(Elem));
    if(no != NULL){
        no->valor = valor;
        no->prox = li->inicio;
        li->inicio = no;
        return 0;
    }
    return 1;
}

int remover_inicio(Lista* li){
    if(li->inicio == NULL){
        return 1;
    }
    Elem* no = li->inicio;
    li->inicio = no->prox;
    free(no);
    return 0;
}

int acessar_inicio(Lista *li, int* valor){
    if(li == NULL){
        return 1;
    }
    *valor = li->inicio->valor;
    return 0;
}

void destruir(Lista *li){
    if(li != NULL){
        Elem* no = li->inicio;
        while(no != NULL){
            Elem *prox = no->prox;
            free(no);
            no = prox;
        }
        free(li);
    }
}

int main(){
    Lista* li = criar_lista();
    inserir_inicio(li, 20);
    inserir_inicio(li, 30);
    inserir_inicio(li, 40);
    int valor;
    acessar_inicio(li, &valor);
    printf("O valor do inicio é: %d\n", valor);

    remover_inicio(li);
    acessar_inicio(li, &valor);
    printf("O valor do inicio é: %d\n", valor);

    destruir(li);
    return 0;
}