#include<stdio.h>
#include"quadrado.h"
#define TAM 5

int main(){
    Quadrado lista[TAM];
    float lado;

    for(int i = 0; i < 2; i++){
        printf("Insira lado quadrado %d: ", i+1);
        scanf("%f", &lado);

        lista[i] = cria_quadrado(lado);
    }

    int imenor_area = 0;
    int imaior_perimetro = 0;
    
    for(int i = 1; i < TAM; i++){
        if(calculo_area(lista[imenor_area]) > calculo_area(lista[i])) 
            imenor_area = i;
        if(calculo_perimetro(lista[imaior_perimetro]) < calculo_perimetro(lista[i])) 
            imaior_perimetro = i;

        printf("Area quadrado %d: %.2f \n", i+1, calculo_area(lista[i]));
        printf("Perimetro quadrado %d: %.2f \n", i+1, calculo_perimetro(lista[i]));
    }
    
    printf("Menor área quadrado %d: %.2f \n", imenor_area + 1, calculo_area(lista[imenor_area]));
    printf("Perimetro quadrado %d: %.2f \n", imaior_perimetro + 1, calculo_perimetro(lista[imaior_perimetro]));

    for(int i = 0; i < TAM; i++)
        destruir_quadrado(lista[i]);

    return 0;
}