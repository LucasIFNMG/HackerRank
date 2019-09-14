//https://www.urionlinejudge.com.br/judge/pt/problems/view/2807

#include <stdio.h>

#define TAMANHO 40
int iccanobif[TAMANHO];

void icc()
{
    iccanobif[0] = 1;
    iccanobif[1] = 1;
    for(int i = 2; i<= TAMANHO; i++)
        iccanobif[i] = iccanobif[i-1] + iccanobif[i-2];
}


int main()
{
    int N;
    icc();
    // 1<= N <= 40
    scanf(" %d", &N);

    for(int i = N-1; i>=0; i--)
    {
        printf("%d",iccanobif[i]);
        if(i!=0)
            printf(" ");
    }

}