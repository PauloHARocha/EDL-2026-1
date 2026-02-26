#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct lista {
    int dados[MAX];
    int qtd;
} *Lista;

Lista criar_lista(){
    Lista l = malloc(sizeof(struct lista));
    if(l != NULL)
        l->qtd = 0;
    return l;
}

int inserir_final(Lista l, int matricula){
    if(l->qtd < MAX){
        l->dados[l->qtd] = matricula;
        l->qtd++;
        return 0;
    }else
        return 1;
}

int acessar_final(Lista l, int* matricula){
    if (l->qtd == 0)
        return 1;
    else
        *matricula = l->dados[l->qtd - 1];
        return 0;
}

int remover_final(Lista l){
    if (l->qtd == 0)
        return 1;
    else
        l->qtd--;
    return 0;
}

int tamanho_lista(Lista l){
    if(l == NULL)
        return 0;
    return l->qtd;
}

void destruir_lista(Lista l){
    if(l != NULL)
        free(l);
}

int main(){
    Lista l = criar_lista();
    int matricula;

    for(int i = 0; i < MAX; i++){
        printf("Insira a matricula aluno %d: ", i+1);
        scanf("%d", &matricula);

        if(inserir_final(l, matricula)){
            printf("Erro, valor nao inserido\n");
        }else{
            printf("Valor %d inserido\n", matricula);
        }
        printf("Quantidade de elementos: %d\n", tamanho_lista(l));
    }
   
    for(int i = 0; i < tamanho_lista(l); i++){
        if(acessar_final(l, &matricula))
            printf("Erro de acesso\n");
        else
            printf("Matricula aluno %d: %d \n", i+1, matricula);    
    }

    destruir_lista(l);
    return 0;
}