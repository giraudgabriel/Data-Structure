#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
	Lista* lista;

	lista = criar_lista();

	if(vazia(lista))
		printf("Lista vazia!\n");
	else
		printf("Lista nao vazia!\n");

	lista = inserir_lista(lista, 10);
	lista = inserir_lista(lista, 20);
	imprimir_lista(lista);
	
	if(vazia(lista))
		printf("Lista vazia!\n");
	else
		printf("Lista nao vazia!\n");
	
	Lista* found = buscar(lista, 10);
	found = buscar(lista, 20);
	
	if(comparar(lista, lista) == 1)
		printf("Iguais!");
	
	return 0;
}
