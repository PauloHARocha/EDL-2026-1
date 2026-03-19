#include<stdio.h>
#include"fila.h"

void remover_negativos(Fila f) {
    Fila aux = criar_fila();
    int valor;
    int n = tamanho(f);
    for(int i=0; i< n;i++){
        acessar(f, &valor);
        remover(f);
        if(valor > 0){
            inserir(f, valor);
        }
    }
}

int main(){
    Fila f = criar_fila();
    inserir(f, 50); // enqueue
    inserir(f, -20);
    inserir(f, -30);
    inserir(f, 20);
    int valor = 0;
    while(tamanho(f)){
        acessar(f, &valor);
        printf("[%d] ", valor);
        remover(f);
    }
    printf("\n");
    inserir(f, 50); // enqueue
    inserir(f, -20);
    inserir(f, -30);
    inserir(f, 20);

    remover_negativos(f);

    while(tamanho(f)){
        acessar(f, &valor);
        printf("[%d] ", valor);
        remover(f);
    }

    printf("\n");
    destruir(f);
    return 0;
}