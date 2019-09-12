#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int somaVetor(int vetor[], int n)
{
   int soma = 0;

   for(int i = 0; i < n; i++)
        soma += vetor[i];

    return soma;

}


int main()
{
    int vetor[] = {1,2,3};
    
    int n = sizeof(vetor)/sizeof(int);

    int somaElementos = somaVetor(vetor, n);

    printf("Soma dos Elementos = %d",somaElementos);

    return 0;
}