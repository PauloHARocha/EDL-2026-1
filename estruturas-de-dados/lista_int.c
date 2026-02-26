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

int inserir(Lista l, int matricula, int pos){
    if(pos < MAX){
        l->dados[pos] = matricula;
        l->qtd++;
        return 0;
    }else
        return 1;
}

int acessar(Lista l, int pos, int* matricula){
    if (pos >= MAX || pos < 0)
        return 1;
    else
        *matricula = l->dados[pos];
        return 0;
}

int main(){
    Lista l = criar_lista();
    int matricula;

    for(int i = 0; i < MAX; i++){
        printf("Insira a matricula aluno %d: ", i+1);
        scanf("%d", &matricula);

        if(inserir(l, matricula, i)){
            printf("Erro, valor nao inserido\n");
        }else{
            printf("Valor %d inserido\n", matricula);
        }
        printf("Quantidade de elementos: %d\n", l->qtd);
    }
   
    for(int i = 0; i < l->qtd; i++){
        if(acessar(l, i, &matricula))
            printf("Erro de acesso\n");
        else
            printf("Matricula aluno %d: %d \n", i+1, matricula);    
    }


    return 0;
}