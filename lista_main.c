#include<stdio.h>
#include"quadrado.h"
#define TAM 5

int main(){
    Quadrado lista[TAM];
    float lado;

    for(int i = 0; i < TAM; i++){
        printf("Insira lado quadrado %d: \n", i+1);
        scanf("%f", &lado);

        lista[i] = cria_quadrado(lado);
    }

    for(int i = 0; i < TAM; i++){
        printf("Area quadrado %d: %.2f \n", i+1, calculo_area(lista[i]));
    }

    return 0;
}