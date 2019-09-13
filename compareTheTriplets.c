/* https://www.hackerrank.com/challenges/compare-the-triplets/problem
Alice ganha pontos, distribuídos em 3 parâmetros: a = (alice0], alice1], alice2]). O mesmo para Bob:  b = (b[0], b[1], b[2])

Se alicez] > b[z], Alice ganha 1 ponto
Se alicez] < b[z], Bob ganha 1 ponto
Se alicez] = b[z], Nenhum dos dois ganha ponto

Dado um vetor para cada pessoa, descobrir o total de pontos que eles ganharam.

Ex: a = [1,2,3]
    b = [3,2,1]

    Alice terá 1 ponto, Bob também
    Retorno será [1,1].

Problema: Dados 2 trincas de valores inteiros, retornar um vetor com 2 valores, representando a pontuação de Alice e Bob
*/

#include <stdio.h>
int main()
{
    int alice[3];
    int b[3];
    int i = 0;

    printf("Informe os 3 valores para Alice:\n");
    for(i=0; i<=2;i++)
        scanf(" %d",&alice[i]);

    printf("Informe os 3 valores para Bob:\n");
    for(i=0; i<=2;i++)
        scanf(" %d",&b[i]);

    int pontosAlice = 0, pontosBob = 0;

    for(i = 0;  i <=2 ;  i++ )
    {
        if ( alice[i] > b[i] )
            pontosAlice++;

        if ( alice[i] < b[i] )
            pontosBob++;
    }

    int vetorPontuacao[] = {pontosAlice, pontosBob};

    printf("%d %d", vetorPontuacao[0], vetorPontuacao[1]);


}