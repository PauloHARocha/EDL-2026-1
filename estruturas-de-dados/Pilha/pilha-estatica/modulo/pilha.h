#define MAX 3
typedef struct pilha* Pilha;

Pilha criar_pilha();
int push(Pilha p, int valor);
int peek(Pilha p, int* valor);
int pop(Pilha p);
int tamanho_pilha(Pilha p);
void destruir_pilha(Pilha p);