#include <stdio.h>
#include <stdlib.h>
int main()
{
	int vetor[7] = {4, 1, 9 , 2, 5, 18, 3};

	int aux, i, j, k, n = 7;
	int h = n / 2;

	while(h > 0)
	{
		i = h;
		while(i < n)
		{
			aux = vetor[i];
			j = i;
			while(j >= h && aux < vetor[j - h])
			{
				vetor[j] = vetor[j - h];
				j = j - h;
			}
			vetor[j] = aux;
			i = i + 1;
		}
	
		h = h / 2;
	}
	

	
	
	printf("h = %d \t", h); 
		for(k = 0; k < n; k++)
			printf("%d ", vetor[k]);
		printf("\n");

	

	return 0;
}
