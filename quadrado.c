#include<stdlib.h>
#include"quadrado.h"

struct Quadrado{
    float l;
};

Quadrado cria_quadrado(float l){
    if(l < 0 )
        l *= -1;
    
    Quadrado q = malloc(sizeof(struct Quadrado));
    if(q != NULL){
        q->l = l;
    }
    return q;
}

void destruir_quadrado(Quadrado q){
    free(q);
}

float acessa_lado(Quadrado q){
    return q->l;
}

float calculo_area(Quadrado q){
    return q->l * q->l;
}

float calculo_perimetro(Quadrado q){
    return 4 * q->l;
}