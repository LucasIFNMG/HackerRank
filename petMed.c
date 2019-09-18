/*Fonte: Maratona de Programação do X Simpósio de Informática do IFNMG - Januária

Um animal ficará em uma clínica por x dias, sendo definido x rações DIFERENTES, uma para cada dia.
Entradas:
1ª) Nº de Dias (x)
2ª) 0 ou 1 se a 1ª ração foi aplicada, 0 ou 1 para a 2ª, assim por diante

Restrições: deve ser aplicada exatamente 1 ração por dia;
            Nunca repetir a mesma ração ao longo de todos os dias.

Saída:
'i' se a programação for inválida ou 'v'  se for válida
*/
//@author LucasIFNMG

#include <stdio.h>

int main()
{
    int x, ok = 0;
    char saida = 'v';
    int racaoDada;

    scanf(" %d",&x);
    int DiaRacao[x][x];

    //Percorrendo a Matriz, analisando os dias
    for(int dia = 0; dia < x; dia++)
    {
        racaoDada = 0;
        ok = 0;
        for(int racao = 0; racao < x; racao++ )
        {
            scanf(" %d",&DiaRacao[dia][racao]);
            if(DiaRacao[dia][racao] == 1)
            {
                if(racaoDada == 1) //Mais de uma ração no mesmo dia
                    saida = 'i';
                else
                    racaoDada = 1;
            }

        }
        if(racaoDada == 0)
            saida = 'i';
    }

    if( saida == 'v')
    {
        //Percorrendo a Matriz, analisando as rações
        for(int racao = 0; racao < x; racao++)
         {
            racaoDada = 0;
            for(int dia = 0; dia < x; dia++ )
            {
                if(DiaRacao[racao][dia] == 1)
                {
                    if(racaoDada == 1)
                        saida = 'i';
                    else
                        racaoDada = 1;

                }

            }

         }
         if(racaoDada == 0)
            saida = 'i';
    }
    printf("%c ",saida);

}
