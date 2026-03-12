typedef struct fila* Fila; // 8 bytes

Fila criar_fila();
int inserir(Fila f, int valor);
int remover(Fila f);
int acessar(Fila f, int* valor);
int tamanho(Fila f);
void destruir(Fila f);