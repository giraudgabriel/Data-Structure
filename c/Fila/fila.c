#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct lista
{
	float info;
	struct lista* prox;
};

struct fila
{
	Lista* ini;
	Lista* fim;
};

Fila* criar_fila()
{
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

void inserir(Fila* f, float v)
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = NULL;
	if(f->fim != NULL)
		f->fim->prox = novo;
	else
		f->ini = novo;
	f-> fim = novo;
}

float remover(Fila* f)
{
	Lista *t;
	float v;

	if(vazia(f))
	{
		printf("Fila vazia \n");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini == NULL)
		f->fim = NULL;
	free(t);
	return v;
}

int vazia(Fila* f)
{
	return (f->ini == NULL);
}

void liberar(Fila* f)
{
	
	if(f->ini != NULL)
	{
	   Lista* toRemove = f->ini;
	   f->ini = toRemove->prox;
	   free(toRemove);
	   liberar(f);		
	}
	free(f);
}

void imprimir(Fila* f)
{
	printf("\n");
	Lista* aux = f->ini;
	while(aux != NULL)
	{
		printf("%.2f \t",aux->info);
		aux = aux->prox;
	}
}
