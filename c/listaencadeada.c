#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
   int conteudo;
   struct reg *prox;
} celula;

int main()
{
    celula *lstSemCabeca;
    lstSemCabeca = NULL;
    
    celula *lstCabeca;
    lstCabeca = malloc(sizeof(celula));
    lstCabeca->prox = NULL;

    inserir(1,lstCabeca);
    inserir(2,lstCabeca);
    inserir(3,lstCabeca);
    inserir(4,lstCabeca);

    int array[] = { 5,6,7,8,9,10,11,12 };
    inserirArray(array,lstCabeca,8);

    imprimirComCabeca(lstCabeca);

    return 0; 
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

void inserir(int valor, celula *le){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->prox = le->prox;
    le->prox = nova;
}

void inserirArray(int valores[], celula *lst, int quantidade){
    for (int i = 0; i < quantidade; i++)
        inserir(valores[i], lst);
}

celula* buscar (int valor, celula *lst)
{
   if (lst->prox == NULL) 
      return NULL;
   if (lst->prox->conteudo == valor) 
      return lst->prox;
   return buscar (valor, lst->prox);
}

void remover (celula *p)
{
   celula *morta;
   morta = p->prox;
   p->prox = morta->prox;
   free (morta);
}

void buscarERemover(int valor, celula *lst){
    celula *aRemover = buscar(valor, lst);
    if(aRemover != NULL) remover(aRemover);
    else printf("\n \t Valor não encontrado! \t \n");
}


