# Gabarito: Prova 1ºGQ (2ª Chamada)


## Questão 1

### a) Pilha  

`[5, 15, 65]`  

(topo = 65)

### b) Fila  

`[55, 65, 75]`  

(início = 55)


## Questão 2

```c

#define MAX 10

struct fila {

    float dados[MAX];

    int inicio, final, qtd;

};

typedef struct fila* Fila; 

Fila criar_fila(){

    Fila f = malloc(sizeof(struct fila));

    if(f != NULL){

        f->inicio = 0;

        f->final = 0;

        f->qtd = 0;

    }

    return f;

}

int enfileira(Fila f, float valor){

    if(f->qtd < MAX && f != NULL){

        f->dados[f->final] = valor;

        f->final = (f->final + 1) % MAX;

        f->qtd++;

        return 0;

    }else{

        return 1;

    }

}

int desenfileira(Fila f){

    if(f->qtd == 0 || f == NULL){

        return 1;

    }else{

        f->inicio = (f->inicio + 1) % MAX;

        f->qtd--;

        return 0;

    }

}

int consulta_inicio(Fila f, float* valor){

    if(f->qtd == 0 || f == NULL){

        return 1;

    }else{

        *valor = f->dados[f->inicio];

        return 0;

    }

}

```

**Saída:**

```c

3.5

```


## Questão 3

`27`


## Questão 4

```c

int insere_posicao(Lista li, int pos, int valor){

    if(li == NULL || pos < 0)

        return 0;

    Elem *novo = malloc(sizeof(Elem));

    if(novo == NULL)

        return 0;

    novo->dado = valor;

    if(pos == 0){

        novo->prox = li->inicio;

        li->inicio = novo;

        return 1;

    }

    Elem *ant = li->inicio;

    int i = 0;

    while(ant != NULL && i < pos - 1){

        ant = ant->prox;

        i++;

    }

    if(ant == NULL){

        free(novo);

        return 0;

    }

    novo->prox = ant->prox;

    ant->prox = novo;

    return 1;

}

```


## Questão 5

```c

int maior_valor(Pilha p, int *maior){

    if(p == NULL || tamanho(p) == 0)

        return 0;

    Pilha aux = cria_pilha();

    int x;

    peek(p, &x);

    *maior = x;

    while(tamanho(p) > 0){

        peek(p, &x);

        pop(p);

        if(x > *maior)

            *maior = x;

        push(aux, x);

    }

    while(tamanho(aux) > 0){

        peek(aux, &x);

        pop(aux);

        push(p, x);

    }

    return 1;

}

```