#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
   int conteudo;
   struct reg *prox;
} celula;

int main(int argc, char const *argv[])
{
    celula *le;
    le = malloc (sizeof (celula));
    le->prox = NULL;
    insere(5, le);
    insere(6, le);
    insere(7, le);
    ordernarCrescente(le);
    imprime(le);
    return 0;
}


void imprime(celula *le){
    if(le != NULL){
        printf("%d \n",*le->prox);
        imprime(le->prox);
    }
}

void insere (int x, celula *p)
{
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->conteudo = x;
   nova->prox = p->prox;
   p->prox = nova;
}

void ordernarCrescente(celula *p){
    if(p != NULL){
        celula *ant = p->prox;
        celula *pos = p->prox->prox;

        if(ant->conteudo > pos->conteudo){
            ant = pos;
            pos = p->prox;
        }
        ordernarCrescente(p->prox);
    }
}

void ordernarDecrescente(celula *p){
    if(p != NULL){
        celula *ant = p->prox;
        celula *pos = p->prox->prox;

        if(ant->conteudo < pos->conteudo){
            ant = pos;
            pos = p->prox;
        }
        ordernarDecrescente(p->prox);
    }
}

void buscarERemover(int x, celula *le){
    if(le != NULL){
        if(le->conteudo == x) {
            celula *removida = le;
            le = removida->prox;
            free(removida);
        }
        else buscarERemover(x,le->prox);
    }
    else printf("\n Valor não encontrado!");
}


void remover(int valor, celula *p)
{
    if(p == NULL){
        return NULL;
    }
    celula *ant = NULL;
    celula *aux = p;
    while(aux != NULL)
    {
        if(valor == aux->conteudo) break;
        ant = aux;
        aux = aux->prox;
    }
    if(ant == NULL){
        p = p->prox;
        printf("\n %d Removido com sucesso!\n\n",valor);
        free(aux);
    }
    else if(aux != NULL){
        ant = aux->prox;
        printf("\n\t%d removido com sucesso!\n\n",valor);
        free(aux);
    }
}
