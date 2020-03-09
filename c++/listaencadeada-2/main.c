#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    int valor;
    struct reg *prox;
} celula;

int main()
{
    celula* lst;
    lst = NULL;

    inserirSemCabeca(lst,1);
    inserirSemCabeca(lst,2);

   for(celula *aux = lst; lst != NULL; aux = aux->prox)
        printf("%d \n",aux->valor);

    printf("Hello world!\n");
    return 0;
}

void inserirSemCabeca(celula* lst, int valor){
    if(lst == NULL){
        lst->valor = valor;
        lst->prox = NULL;
    }else{
        celula* nova = malloc(sizeof(celula));
        nova->valor = valor;
        nova->prox = lst;
        lst = nova;
        free(nova);
    }
}


