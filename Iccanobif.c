//https://www.urionlinejudge.com.br/judge/pt/problems/view/2807

#include <stdio.h>

int main()
{
    int N, i;
   
    // 1<= N <= 40
    scanf(" %d", &N);

    int iccanobif[40] = { 0 };

    iccanobif[0] = 1;
    iccanobif[1] = 1;
    for(i = 2; i< N; i++)
        iccanobif[i] = iccanobif[i-1] + iccanobif[i-2];

    for(i = N-1; i>=1; --i)
        printf("%d ",iccanobif[i]);
    
    printf("%d\n",iccanobif[i]);

}
