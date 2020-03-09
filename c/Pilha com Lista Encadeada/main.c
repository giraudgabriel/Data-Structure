#include <stdio.h>
#include "pilha.h"

int main()
{
	Pilha* p;
	
	p = criar_pilha();
	
	push(p, 1);
	push(p, 2);
	push(p, 3);	
	push(p, 4);
	
	printf("TOPO: %.2f \n", topo(p));
	pop(p);
	printf("TOPO: %.2f \n", topo(p));
	pop(p);
	printf("TOPO: %.2f \n", topo(p));
	pop(p);
	printf("TOPO: %.2f \n", topo(p));
	pop(p);
	printf("TOPO: %.2f \n", topo(p));
	pop(p);
	
	
	return 0;
}