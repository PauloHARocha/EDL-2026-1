#include"aluno.h"
#include<stdio.h>

int main(){
    Aluno a1 = criar_aluno(123, 6);

    printf("Aluno a1 matricula: %d | media: %.2f\n", acessar_mat(a1), acessar_media(a1));

    destruir(a1);

    return 0;
}