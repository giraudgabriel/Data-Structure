#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
	int info;
	struct lista* prox;
};


Lista* criar_lista()
{
	return NULL;
}

Lista* inserir_lista(Lista* l, int i)
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprimir_lista(Lista* l)
{
	Lista* p;
	for(p = l; p != NULL; p = p->prox)
		printf("%d \n", p->info);
}


int vazia(Lista* l)
{
	return (l == NULL);
}

Lista* buscar(Lista* l, int v)
{
	if(l->info == v)
		return l;
	else if(l != NULL)
		buscar(l->prox, v);
	return NULL;
}

Lista* remover(Lista* l, int v)
{
	Lista *ant = NULL;
	Lista* p = l;

	while(p != NULL && p->info != v)
	{
		ant = p;
		p = p->prox;
	}

	if(p == NULL)
		return l;

	if(ant == NULL)
	{
		// remove do inicio da lista
		l = p->prox;
	}

	else
	{
		// remove do meio da lista
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

int comparar(Lista* l1, Lista*l2)
{
	Lista* p1 = l1;
	Lista* p2 = l2;
	
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->info != p2->info)
			return 0;
		p1 = p1->prox;
		p2 = p2->prox;
	}	
	return 1;
}


