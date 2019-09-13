/* https://www.ime.usp.br/~cef/IImaratona/prova-junior/node1.html#SECTION00010000000000000000

Problema 1: Pirâmide

Os segredos das pirâmides vêm instigando cientistas e místicos há séculos, dando asas à imaginação das pessoas. Uma dessas curiosidades são os chamados números piramidais. 

Dizemos que um número inteiro é piramidal se for igual à soma de 3 números primos consecutivos. 

Assim, por exemplo, o numero 15 é piramidal, pois 15 = 3 + 5 + 7 .
O número 10 tambem é piramidal, já que 10 = 2 + 3+ 5 . 
O número 23 é piramidal, pois 23 = 5 + 7 + 11 .

Neste programa você receberá uma sequência de numeros inteiros maiores que 0, terminada por um zero, e deverá verificar se cada um dos números da sequência é ou não piramidal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

//Primo: Só é Divisível por 1 e por Ele mesmo (1 não é primo, deve ter no mínimo 2 divisores)
int ehPrimo(int n)
{
    int cont = 0;
    if(n<=1)
        return 0;

    if(n >=2)
    {
        for(int i = 2; i <= n/2; i++)
        {
            if(n % i == 0 )
            {
                cont++;
                return 0;
            }
            
        }

        if(cont == 0 )
            return 1;
    }
}

int ehPiramidal(int n)
{
    int trinca[] = {0,0,0};
    int cont = 0, soma = 0;
    int k = 0;

    for(int i=2; i <= n/2; i++)
    {
        if(ehPrimo(i) == 1)
        {
            //Se a trinca estiver completa, substituir o menor número pelo novo. No caso, o menor é o do primeiro índice.
            if(cont == 3)
            {
                trinca[0] = i;

                //Manter a trinca ordenada, na qual Sempre o menor número estará no índice 0
                for(int i=1; i < 3; i++)
                    for(int j=0; j < 3-1; j++)
                     if(trinca[j] > trinca[j+1])
                     {
                        int aux = trinca[j];
                        trinca[j] = trinca[j+1];
                        trinca[j+1] = aux;
                     }
            }
            else
            {
                trinca[cont] = i;
                cont++;
            }
        }
        //Quando preencher a trinca de nºs primos, verificar se a soma deles resulta no nº passado como parâmetro
        if(cont == 3)
        {
            soma = 0;
            k = 0;
            for(k = 0; k < cont; k++)
                soma += trinca[k];
           
            
            if( soma == n )
                return 1;
            
        }

    }
    return 0;

}

int main()
{
    setlocale(LC_ALL,"");

    int n = 0;

    do
    {
        printf("Insira um nº(Negativo para Encerrar):\n");
        scanf(" %d", &n);

        int verificaPiramide = ehPiramidal(n);

        if(verificaPiramide == 1)
            printf("\n%d É PIRAMIDAL!\n",n);
        else
        {
            printf("\n%d não é piramidal.\n",n);
        }
    }while(n>=0);

    return 0;

}