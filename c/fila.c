#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    int valor;
    struct reg *prox;
} celula;

typedef struct{
    celula *inicio;
    celula *fim;
} fila;

int main(int argc, char const *argv[])
{
    fila* f = malloc(sizeof(fila));
    f->inicio = f->fim = NULL;

    inserir(f, 1);
    inserir(f, 2);
    inserir(f, 3);
    inserir(f, 4);
    inserir(f, 5);

    printf("Removi: %d \n",remover(f));
    printf("Removi: %d \n",remover(f));

    imprimir(f);

    return 0;
}

celula* inserirFim(celula *fim, int valor){
    celula *nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->prox = NULL;
    if(fim != NULL) fim->prox = nova;
    return nova;
}

celula* removeInicio(celula *inicio){
    celula *p = inicio->prox;
    free(inicio);
    return p;
}

void inserir(fila *f, int valor)
{
    f->fim = inserirFim(f->fim, valor);
    if(f->inicio == NULL) f->inicio = f->fim;
}

int remover(fila *f)
{
    int y;
    if(vazia(f)){
        printf("Fila vazia! \n");
        exit(1);
    }
    y = f->inicio->valor;
    f->inicio = removeInicio(f->inicio);
    if(f->inicio == NULL) f->fim = NULL;
    return y;
}

void imprimir(fila* f){
    celula* c;
    for (c = f->inicio ; c!= NULL; c = c->prox)
        printf("%d \n", c->valor);    
}

int vazia(fila* f)
{
    return (f->inicio == NULL);
}

void liberar(fila* f){
    if(f->inicio != NULL){
        celula *t = f->inicio->prox;
        free(f->inicio);
        f->inicio = t;
        liberar(f);
    }
    free(f);
}
