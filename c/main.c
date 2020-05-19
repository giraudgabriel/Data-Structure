#include <stdio.h>
#include <stdlib.h>
#define t 4

void select_sort(int n, int v[])
{
	int i, j, menor;

	for(i = 0; i < (n - 1); i++)
	{
		menor = i;
		for(j = i + 1; j < n; j++)
			if(v[j] < v[menor]) menor = j;
		troca(i, menor, v);
	}
}

void troca(int i, int menor, int v[])
{
	int aux = v[i];
	v[i] = v[menor];
	v[menor] = aux;
}

int main()
{
	int vetor[t] = { 2, 4 , 1 , 3};

	int i, aux, j, menor;


	for(i = 0; i < t; i++)
		printf("%d \n", vetor[i]);

	select_sort(t, vetor);

	for(i = 0; i < t; i++)
		printf("\n%d", vetor[i]);

	return 0;
}
