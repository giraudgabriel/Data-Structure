#include <stdio.h> 
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} celula;

void Empilha (int y, celula *p) {
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->valor = y;
    nova->prox = p->prox;
    p->prox = nova;
}

int Desempilha (celula *p) {
    int x; 
    celula *toRemove;
    toRemove = p->prox;
    x = toRemove->valor;
    p->prox = toRemove->prox;
    free (toRemove);
    return x;
}

void Listar(celula *pilha) {
	celula *aux = pilha->prox;

    while (aux != NULL)
    {
        printf("%d", aux->valor);
        aux = aux->prox;
    }
}


int main(int argc, char const *argv[])
{

    celula *p = malloc(sizeof(celula));
    p->prox = NULL;

    Empilha(1, p);
    Empilha(2, p);
    Empilha(3, p);
    
    Listar(p);
    
    printf("\nO valor retirado foi %d", Desempilha(p));
    printf("\nO valor retirado foi %d", Desempilha(p));
    printf("\nO valor retirado foi %d", Desempilha(p));
  
    return 0;
}

