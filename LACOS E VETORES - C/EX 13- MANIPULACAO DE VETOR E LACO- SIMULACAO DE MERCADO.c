#include <stdio.h>
#define TF 20

//Programa de manipulacao de dois vetores no qual simula um estoque de mercado simples...

void main()
{

    int quant[TF], cod[TF], i, tl,elemento,repeticao,codescolhido,pos,inserido,retirado,cont;
    char opcao,continuar;

    tl=0;
    printf("SE NAO QUISER ADICIONAR MAIS PRODUTOS DIGITE NO CODIGO O NUMERO 0\n");
    do
    {
        printf("Insira o codigo do produto %d:\n",tl+1);
        scanf("%d", &cod[tl]);
    }
    while(cod[tl]<0);

    if(cod[tl]!=0)
    {
        while(cod[tl]>0 && tl<TF)
        {
            do
            {
                printf("Insira o total de itens do produto %d:\n", tl+1);
                scanf("%d", &quant[tl]);
            }
            while(quant[tl]<0);

            tl++;
            if(tl<TF)
                do
                {
                    printf("Insira o codigo do produto %d:\n",tl+1);
                    scanf("%d", &cod[tl]);
                    elemento = cod[tl];
                    repeticao = 0;
                    for(i=0; i<tl; i++)
                    {
                        if(elemento == cod[i])
                            repeticao++;
                    }
                }
                while(cod[tl]<0 || repeticao>0);
        }
        do
        {
            do
            {
                printf("Escolha o produto a ser executado e insira seu codigo:\n\n");
                for(i=0; i<tl; i++)
                {
                    printf("%d\n", cod[i]);
                }
                scanf("%d", &codescolhido);
                repeticao=0;
                for(i=0; i<tl; i++)
                {
                    if(codescolhido == cod[i])
                    {
                        pos = i;
                        repeticao++;
                    }
                }


            }
            while(repeticao == 0);

            do
            {
                printf("Os itens serao\n Inseridos (I)\n Retirados (R)\n");
                scanf(" %c", &opcao);
                if(opcao == 'I' || opcao == 'R')
                {
                    if(opcao=='I')
                    {
                        do
                        {
                            printf("Digite quantos itens serao inseridos:\n");
                            scanf("%d", &inserido);
                        }
                        while(inserido<=0);
                        quant[pos] = quant[pos] + inserido;

                    }
                    else
                    {
                        if(quant[pos]>0)
                        {
                            do
                            {
                                printf("Digite quantos itens serao retirados:\nLembrando que a apenas %d produtos no estoque\n", quant[pos]);
                                scanf("%d", &retirado);
                                if(retirado>quant[pos])
                                    printf("Nao contem essa quantidade no estoque\n");
                            }
                            while(retirado<=0 || retirado>quant[pos]);
                            quant[pos] = quant[pos] - retirado;
                        }
                        else
                        {
                            printf("Nao tem como retirar itens, pois a 0 itens\n");
                        }
                    }
                }
            }
            while(opcao!='I' && opcao!='R');
            cont=0;
            do
            {
                printf("Deseja continuar inserindo e retirando itens??\n (S) SIM\n (N) NAO\n");
                scanf(" %c", &continuar);
                if(continuar == 'N')
                    cont++;
            }
            while(continuar!='S' && continuar!='N');
        }
        while(cont==0);
        cont=0;
        printf("Os codigos de produtos que contem no maximo 9 itens:\n");
        for(i=0; i<tl; i++)
        {
            if(quant[i]<=20)
            {
                if(quant[i]<10)
                {
                    printf("cod = %d\n", cod[i]);
                }
                else
                {
                    cont++;
                }
            }
        }
        printf("O numero de produtos que apresentam estoque entre 10 e 20: %d\n", cont);

        for(i=0; i<tl; i++)
        {
            printf("O produto de cod:%d\nApresenta %d itens\n\n", cod[i], quant[i]);

        }
    }
}

