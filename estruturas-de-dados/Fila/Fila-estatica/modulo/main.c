#include<stdio.h>
#include"fila.h"

int main(){
    Fila f = criar_fila();
    inserir(f, 10);
    inserir(f, 20);
    inserir(f, 30);
    int valor;    
    remover(f);
    inserir(f, 50);
    remover(f);
    inserir(f, 60);
    inserir(f, 70);
    acessar(f, &valor);
    printf("Inicio da fila: %d\n", valor);
    destruir(f);
    return 0;
}