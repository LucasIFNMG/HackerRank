/* https://www.urionlinejudge.com.br/judge/pt/problems/view/2846
Timelimit: 1
A sequência de Fibonacci é uma das sequências mais famosas do mundo. Os termos de Fibonacci são sempre iguais à soma dos dois termos anteriores a eles na sequência, e os dois primeiros termos são 1. Ou seja:

1 , 1, 2, 3, 5, 8, 13, 21, 34 ...

Porém, não estamos interessados em achar os termos da sequência de Fibonacci, mas sim os termos da sequência de Fibonot!

A sequência de Fibonot é composta pelos números que não pertencem à sequência de Fibonacci. Mais especificamente, os números inteiros positivos não-nulos. Em ordem crescente!

Eis os primeiros termos de Fibonot:

4, 6, 7, 9, 10, 11, 12, 14, 15 ...

Sua tarefa é achar o K-ésimo número de Fibonot.
1 <= K <= 100.000
*/
#include <stdio.h>

#define TAMANHO 200000

int fibonacci[TAMANHO];
int fibonot[TAMANHO];

void fib()
{
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    //Sequência Fibonacci
    for(int i = 2; i <= TAMANHO; i++ )
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

    //Verifica se o iterador i = fibonacci[i]. Se for, incrementa indFA (índice de Fibonacci). 
    //Se não, acrescenta i ao vetor fibonot[indFO] (índice Fibonot)
    for(int indFA = 1, indFO = 1, i = 1; i<= TAMANHO; i++)
    {
        if(fibonacci[indFA] != i)
            fibonot[indFO++] = i;
        
        else
            indFA++;
    }
}

int main()
{
    int k, n , cont = 0;

    fib();

    printf("Insira N (nº de vezes que será rodado o código: ");
    scanf(" %d", &n);

    do
    {
        printf("Insira K (K-ésimo número na Seq. Fibonot: ");
        scanf(" %d", &k);
        printf("%d\n", fibonot[k]);
        cont++;
    } while ( cont != n);

}