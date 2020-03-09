#include <stdio.h>
#include "fila.h"
int main()
{
	Fila* f = criar_fila();
	
	inserir(f, 1);
	inserir(f, 2);
	inserir(f, 3);
	
	imprimir(f);
	
	remover(f);
	
	imprimir(f);
	
	inserir(f, 4);
	
	imprimir(f);
	
	return 0;
}