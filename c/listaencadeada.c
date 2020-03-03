#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
   int conteudo;
   struct reg *prox;
} celula;

int main()
{    
    celula *lstCabeca;
    lstCabeca = malloc(sizeof(celula));
    lstCabeca->prox = NULL;
    inserirComCabeca(1,lstCabeca);
    inserirComCabeca(2,lstCabeca);
    int array[] = {3,4,5};
    inserirArray(array,lstCabeca, 3);
    imprimirComCabeca(lstCabeca);

// Sem cabeca
    celula *lstSemCabeca;
    lstSemCabeca = NULL;
    inserirSemCabeca(&lstSemCabeca, 5);
    inserirSemCabeca(&lstSemCabeca, 6);
    imprimeSemCabeca(lstSemCabeca);
    pop(&lstSemCabeca);
    printf("Depois do pop: \n");
    imprimeSemCabeca(lstSemCabeca);
    return 0; 
}

void pop(celula **lst)
{
    celula* p = *lst;
    *lst = p->prox;
    free(p);
}

void imprimeSemCabeca(celula *lst){
    celula *p;
    for (p = lst; p != NULL; p = p->prox) 
        printf ("%d\n", p->conteudo);
}

void imprimirComCabeca(celula *le){
    if(le != NULL){
        printf("%d \n",*le->prox);
        imprimirComCabeca(le->prox);
    }
}

void inserirComCabeca(int valor, celula *le){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->prox = le->prox;
    le->prox = nova;
}

void inserirSemCabeca(celula** lst, int valor)
{
    celula* nova = malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->prox = *lst;
    *lst = nova;
}

void inserirArray(int valores[], celula *lst, int quantidade){
    for (int i = 0; i < quantidade; i++)
        inserir(valores[i], lst);
}


void remover (celula *p) {
    celula *toRemove;
    toRemove = p->prox;
    p->prox = toRemove->prox;
    free(toRemove);
}


celula* buscar (int valor, celula *lst)
{
   if (lst->prox == NULL) 
      return NULL;
   if (lst->prox->conteudo == valor) 
      return lst->prox;
   return buscar (valor, lst->prox);
}


