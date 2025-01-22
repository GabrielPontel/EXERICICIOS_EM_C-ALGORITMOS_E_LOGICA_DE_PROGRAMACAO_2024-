#include <stdio.h>
#define TF 1000

//Programa de manipulacao de vetor e laco para realizar a nota fiscal apartir dos dados inseridos pelo o usuario

void main()
{
    int quant[TF],
        tl=0,
        i,
        quanttotal=0;

    float valor[TF],
          valorproduto[TF],
          soma = 0,
          X;

    printf("Qual o preco do produto 1 :\n");
    scanf("%f", &valor[0]);
    X = valor[0];
    while( X>0 )
    {
        printf("Qual a quantidade comprada do produto %d ?\n", tl+1);
        scanf("%d", &quant[tl]);
        tl++;
        printf("Qual o preco do produto:\n");
        scanf("%f", &valor[tl]);
        X=valor[tl];
    }

    for(i=0; i<tl; i++)
    {
        valorproduto[i] = valor[i] * quant[i];
    }

    for(i=0; i<tl; i++)
    {
        quanttotal+=quant[i];
        soma+= valorproduto[i];
    }
    printf("\n\n---Ticket Fiscal---\n\n");
    for(i=0; i<tl; i++)
    {
        printf("Numero sequencial = %d \nPreco = R$ %.2f \nQuantidade = %d \nTotal do item = %.2f \n\n",i+1 ,valor[i] ,quant[i] ,valorproduto[i]);
    }
    printf("O valor total da compra e de : R$ %.2f\n", soma);
    printf("A quantidade total da compra e de : %d\n", quanttotal);

}
