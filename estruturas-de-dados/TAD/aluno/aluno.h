// Dados
typedef struct aluno* Aluno;

// Operacoes
Aluno criar_aluno(int mat, float media);
int acessar_mat(Aluno a);
float acessar_media(Aluno a);
void destruir(Aluno a);