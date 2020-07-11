#include <stdio.h>
#include <stdlib.h>


void insertion_sort (int n, int v[])
{
	int i, j, key;
	for(j = 1; j < n; j++)
	{
		key = v[j];
		
		for(i = j -1; i >= 0 && v[i] > key; i--)
			v[i + 1] = v[i];
		
		v[i + 1] = key;
	}

}
int main()
{	
	// complexidade = O(n²) -> pior caso -> array totalmente desordenado -> ex: [5,4,3,2,1...]
	
	
	// j = 1
	// [5 , 4 , 3 , 2, 1] 
	//key = 4, i = 1 -1
	// 4 < 5 i--
	// [4 , 5 , 3 , 2, 1] -> j = 2
	
	// key = 3 , i = 2 -1
	// 3 < 5 i--
	// 3 < 4 i--
	// [3, 4, 5, 2, 1]  -> j=  3
	
	//key = 2, i = 3 -1
	// 2 < 5 i--
	// 2 < 4 i--
	// 2 < 3 i--
	// [2, 3, 4, 5, 1]  -> j = 4
	
	// key = 1, i = 4 -1
	// 1 < 5 i--
	// 1 < 4 i--
	// 1 < 3 i--
	// 1 < 2 i--
	// [1 , 2, 3 , 4 , 5]  -> j = 5
	
	// end loop
	
	int vetor[5] = {5, 4, 3, 2, 1};
	insertion_sort(5, vetor);

	int i = 0;
	while(i < 5)
	{
		printf("%d \t", vetor[i]);
		i++;
	}
	return 0;
}
