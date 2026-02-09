#include<stdio.h>
#include"quadrado.h"

int main(){

    Quadrado q;
    q.l = 0;

    printf("Insira o lado do quadrado: ");
    scanf("%f", &q.l);
    
    printf("Quadrado com area %.2f e perimetro %.2f\n", calculo_area(q), calculo_perimetro(q));

    return 0;
}