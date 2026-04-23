# Gabarito: Prova 1ºGQ (1ª Chamada)

## Questão 1

### a) Pilha  

`[10, 30, 50]`  

(topo = 50)

### b) Fila  

`[50, 60, 70]`  

(início = 50)


## Questão 2

```c

#define MAX 10

struct fila {

    char dados[MAX];

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

int enfileira(Fila f, char valor){

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

int consulta_inicio(Fila f, char* valor){

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

W

```


## Questão 3

`90`


## Questão 4

```c

int remove_valor(Lista li, int valor){

    if(li == NULL || li->inicio == NULL)

        return 0;

    Elem *ant = NULL;

    Elem *no = li->inicio;

    while(no != NULL && no->dado != valor){

        ant = no;

        no = no->prox;

    }

    if(no == NULL)

        return 0;

    if(ant == NULL)

        li->inicio = no->prox;

    else

        ant->prox = no->prox;

    free(no);

    return 1;

}

int remove_valor(Lista li, int valor){

    if(li == NULL || li->inicio == NULL)

        return 0;

    Elem *no = li->inicio;

    if(no->dado == valor){

        li->inicio = no->prox;

        free(no);

        return 1;

    }

    while(no->prox != NULL){

        if(no->prox->dado == valor){

            Elem *removido = no->prox;

            no->prox = removido->prox;

            free(removido);

            return 1;

        }

        no = no->prox;

    }

    return 0;

}

```


## Questão 5

```c

int qtd_pares(Pilha p){

    if(p == NULL)

        return 0;

    Pilha aux = cria_pilha();

    int x, qtd = 0;

    while(tamanho(p) > 0){

        peek(p, &x);

        pop(p);

        if(x % 2 == 0)

            qtd++;

        push(aux, x);

    }

    while(tamanho(aux) > 0){

        peek(aux, &x);

        pop(aux);

        push(p, x);

    }

    return qtd;

}

```