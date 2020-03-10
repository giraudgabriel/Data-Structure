#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *V, int N)
{
    int i, j, menor, troca;
    for(i = 0; i< N-1; i++)
    {
        menor = i;
        for(j = i + 1; j < N; j++)
        {
            if(V[j] < V[menor])
                menor = j;
        }
        if(i != menor)
        {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

int main()
{
    int v[] = {23,24,1,4,2,5,10};
    selectionSort(v, 7);
    int i;
    for(i = 0; i < 7; i++)
        printf("%d \t",v[i]);
}
