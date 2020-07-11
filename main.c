#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
	int chave;
	struct cel *esq;
	struct cel *dir;
} no;


no* criarNo(int valor)
{
	no *novo;
	novo = malloc (sizeof (no));
	novo->chave = valor;
	novo->esq = novo->dir = NULL;
	return novo;
}

void erd(no *a)
{
	if(a != NULL)
	{
		erd(a->esq);
		printf("%d \n", a->chave);
		erd(a->dir);
	}
}

int altura (no *r)
{
	if(r == NULL) return -1;
	else
	{
		int he = altura(r->esq);
		int hd = altura(r->dir);
		if(he < hd) return hd + 1;
		else return he + 1;
	}
}

no * buscar (no *r, int valor)
{
	if (r == NULL || r->chave == valor) return r;
	if (r->chave > valor)return buscar (r->esq, valor);
	else return buscar (r->dir, valor);
}

no * inserir(no * root, no * novo)
{
	if(root == NULL) return novo;

	if(novo->chave < root->chave) root->esq = inserir(root->esq, novo);
	else if(novo->chave > root->chave) root->dir = inserir(root->dir, novo);

	return root;
}

no * remover (no *r)
{
	no *current, *before;
	if (r->esq == NULL)
	{
		before = r->dir;
		free (r);
		return before;
	}
	current = r;
	before = r->esq;
	while (before->dir != NULL)
	{
		current = before;
		before = before->dir;
	}
	if (current != r)
	{
		current->dir = before->esq;
		before->esq = r->esq;
	}
	before->dir = r->dir;
	free (r);
	return before;
}

int main()
{
	no *arvore = criarNo(5);
	inserir(arvore, criarNo(3));
	inserir(arvore, criarNo(4));
	inserir(arvore, criarNo(2));
	inserir(arvore, criarNo(8));
	inserir(arvore, criarNo(7));
	inserir(arvore, criarNo(6));
	inserir(arvore, criarNo(9));

/* 
		5
	   /  \
      3     8
	/  \   / \
   2    4 7	  9 
*/
	printf("Raiz:%d ",arvore->chave);
	arvore= remover(arvore);
	printf("Raiz:%d ",arvore->chave);
	arvore= remover(arvore);
	printf("Raiz:%d ",arvore->chave);
	arvore= remover(arvore);
	printf("Raiz:%d ",arvore->chave);
	arvore= remover(arvore);
	printf("Raiz:%d ",arvore->chave);
	arvore= remover(arvore);
	printf("Raiz:%d ",arvore->chave);
	arvore= remover(arvore);
	printf("Raiz:%d ",arvore->chave);


}
