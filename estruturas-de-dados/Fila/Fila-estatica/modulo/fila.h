typedef struct fila* Fila; // 8 bytes

Fila criar_fila();
int inserir(Fila f, int valor); //enqueue ou enfileirar
int remover(Fila f); // dequeue ou desenfileirar
int acessar(Fila f, int* valor); // peek
int tamanho(Fila f);
void destruir(Fila f);