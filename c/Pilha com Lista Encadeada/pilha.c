#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#define N 50

struct lista
{
	float info;
	struct lista* prox;
};

struct pilha
{
	Lista* prim;
};

Pilha* criar_pilha()
{
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void push(Pilha* p, float v)
{
	Lista* n = (Lista*)malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->prim;
	p->prim = n;
}

float pop(Pilha* p)
{
	Lista* t;
	float v;

	if(vazia(p))
	{
		printf("Pilha vazia!");
		exit(1);
	}
	t = p->prim;
	v = t->info;
	p->prim = t->prox;
	free(t);
	return v;
}

int vazia(Pilha* p)
{
	return(p->prim == NULL);
}

void liberar(Pilha* p)
{
	if(p->prim != NULL)
	{
		Lista* t = p->prim;
		p->prim = t->prox;
		free(t);
		liberar(p);
	}
	free(p);
}

float topo(Pilha *p)
{
	if(vazia(p))
	{
		printf("A lista esta vazia! \n");
		exit(1);
	}
	return p->prim->info;
}