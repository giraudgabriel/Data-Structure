#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
   int         conteudo;
   struct reg *prox;
} celula;

int main(int argc, char const *argv[])
{
    celula a;
    celula *lst;

    // lst = &a;
    // lst->conteudo = 0;

    // printf("%d",lst->conteudo);

    // lst->conteudo++;

    // printf("%d",lst->conteudo);

    lst = malloc(sizeof(celula));
    lst->conteudo = 15;

    printf("%d",lst->conteudo);

    lst->prox = &a;

    free(lst);

    return 0;
}
