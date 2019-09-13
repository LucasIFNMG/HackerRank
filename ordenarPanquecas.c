#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Problema Adaptado de https://www.ime.usp.br/~cef/IImaratona/prova-junior/node13.html

/* Ordenar uma Pilha de panquecas, usando somente uma espátula, ou seja, só é possível colocá-la embaixo de uma pilha de panquecas e virá-las de cabeça pra baixo ,
invertendo a ordem.

Os números representam os diâmetros das panquecas

Exemplo: (Flip 5) | (Flip 4)
    2   =>  5     | 3   =>  4
    5   =>  2     | 9   =>  8
    3   =>  5     | 8   =>  9
    1   =>  6     | 4   =>  3

A pilha de panquecas deve ficar em ordem decrescente, ou seja, ter a Maior por baixo e a Menor por cima.
Exemplo:
    8   =>  2
    4   =>  4
    6   =>  5
    7   =>  6
    5   =>  7
    2   =>  8
*/
void flipPanquecas(int panquecas[] , int tamanhoPilha, int maiorPanquecaPilha, int indiceMaior)
{
    int i,j;
    //Se a maior estiver no topo, flipa tudo
    printf("FLIP. MAIOR = %d",maiorPanquecaPilha);
    if(panquecas[0] == maiorPanquecaPilha)
    {
        for(i = 0; i < tamanhoPilha; )
        {
            for(j = ( (tamanhoPilha - 1) - i ) ; j >= 0 ; )
                {
                    int aux = panquecas[i];
                    panquecas[i] = panquecas[j];
                    panquecas[j] = aux;
                    j--;
                    i++;
                    break;
                }

        printf("\n--------\n");   
            for(int k = 0 ; k < tamanhoPilha; k++)
                printf("%d\n",panquecas[k]);

       if (i > j)
            break;
            
        }       
    }
    //Se não, flipa a pilha de cima, a partir dela somente
    else
    {
        for(i = 0; i <= indiceMaior; )
        {
            for(j = indiceMaior - i; j >= 0 ; )
                {
                    int aux = panquecas[i];
                    panquecas[i] = panquecas[j];
                    panquecas[j] = aux;

                    j--;
                    i++;

                    break;
                }
            if (i > j)
            {
                printf("BREAK! i = %d , j = %d",i,j);
                break;
            }
        }
        
    }

}

void ordenaPanquecas (int panquecas[] , int tamanhoPilha)
{
    int cont = 0, maiorPanquecaPilha = 0, indiceMaior = 0;

    for(int i = 0; i < tamanhoPilha; i++)
        if(panquecas[i] >= maiorPanquecaPilha)
        {
            maiorPanquecaPilha = panquecas[i];
            indiceMaior = i;
        }

    // Verificar se a Pilha está 'ordenada'. Se não estiver, flipar
    for(int i=1; i < tamanhoPilha; i++)
        for(int j=0; j < tamanhoPilha-1; j++)
            if(panquecas[j] > panquecas[j+1])
            {
                flipPanquecas(panquecas, tamanhoPilha, maiorPanquecaPilha, indiceMaior);
                if(panquecas[tamanhoPilha-1] == maiorPanquecaPilha)
                    ordenaPanquecas(panquecas, tamanhoPilha - 1);
            }

}

int main()
{
    srand(time(NULL));
    int tamanhoPilha = 15;
    int panquecas[tamanhoPilha];
    
    for(int i=0;i < tamanhoPilha; i++)
        panquecas[i] = rand()%10;

    ordenaPanquecas(panquecas, tamanhoPilha);

    printf("Panquecas Ordenadas\n");

    for(int i = 0; i < tamanhoPilha; i++)
        printf("%d\n", panquecas[i]);

}
