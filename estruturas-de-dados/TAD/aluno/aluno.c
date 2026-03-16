#include"aluno.h"
#include<stdlib.h>

struct aluno{
    int mat;
    float media;
};

Aluno criar_aluno(int mat, float media){
    Aluno a = malloc(sizeof(struct aluno));

    if(a != NULL){
        a->mat = mat;
        a->media = media;
    }
    return a;
}
int acessar_mat(Aluno a){
    return a->mat;
}
float acessar_media(Aluno a){
    return a->media;
}
void destruir(Aluno a){
    if(a != NULL)
        free(a);
}