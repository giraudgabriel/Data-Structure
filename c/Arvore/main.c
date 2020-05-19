#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
	int conteudo;
	struct reg *esq;
	struct reg *dir;
} no;


void inserir(int v, no** arv)
{
	no *novo = NULL;
	if(!(*arv))
	{
		novo = (no*)malloc(sizeof(no));
		novo->esq = novo->dir = NULL;
		novo->conteudo = v;
		*arv = novo;
		return;
	}

	if(v < (*arv)->conteudo) inserir(v, &(*arv)->esq);
	else if(v > (*arv)->conteudo) inserir(v, &(*arv)->dir);

}


no* buscar (no* arv, int k)
{
	if (arv == NULL || arv->conteudo == k)
		return arv;
	if (arv->conteudo > k)
		return buscar (arv->esq, k);
	else
		return buscar (arv->dir, k);
}

void erd(no* arv)
{
	if(arv != NULL)
	{
		erd(arv->esq);
		printf("%d \n", arv->conteudo);
		erd(arv->dir);
	}
}

void red(no* arv)
{
	if(arv != NULL)
	{
		printf("%d \n", arv->conteudo);
		erd(arv->esq);
		erd(arv->dir);
	}
}


int main()
{
	no *arv = NULL;
	inserir(5, &arv);
	inserir(4, &arv);
	inserir(6, &arv);
	red(arv);
	return 0;
}
