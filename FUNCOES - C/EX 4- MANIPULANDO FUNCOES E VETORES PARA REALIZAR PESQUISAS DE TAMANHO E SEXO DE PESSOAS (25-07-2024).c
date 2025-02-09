#include <stdio.h>
/*
O IFSP realizou uma pesquisa entre os habitantes de Presidente Epit�cio e coletados os dados de altura e sexo (M =
masculino, F = feminino) das pessoas. Fa�a um programa que leia dados de N pessoas, sendo que a pesquisa se es
tende a no m�ximo 100 pessoas e informe:
a) a maior e a menor alturas encontradas;
b) a m�dia de altura das mulheres;
c) a m�dia de altura da popula��o;
d) o percentual de homens na popula��o.
*/

//Funcao para realizar a leitura dos vetores de altura e sexo
int ler_vetor(char v[], float c[])
{
    int tl=0;
    do
    {
        printf("Caso queira sair digite 'X'. \nDiigite 'M' para masculino e 'F' para feminino\nDigite o sexo do usuario %d:", tl+1);
        scanf(" %c", &v[tl]);
        if(v[tl]!='F'&&v[tl]!='M'&&v[tl]!='X')
        {
            printf("Digite novamente...\n");
        }
    }
    while(v[tl]!='F'&&v[tl]!='M'&&v[tl]!='X');

    while(v[tl]!='X'&&tl<100)
    {
        do
        {
            printf("Digite a altura do usuario %d:", tl+1);
            scanf("%f", &c[tl]);
        }
        while(c[tl]<0);

        tl++;
        do
        {
            printf("Caso queira sair digite 'X'. Digite o sexo do usuario %d:", tl+1);
            scanf(" %c", &v[tl]);
            if(v[tl]!='F'&&v[tl]!='M'&&v[tl]!='X')
            {
                printf("Digite novamente...\n");
            }
        }
        while(v[tl]!='F'&&v[tl]!='M'&&v[tl]!='X');
    }
    return tl;
}

//Funcao que calcula a media da altura das mulheres
float cont_F(char v[], int tl, float c[])
{
    int i, f=0;
    float cont=0, media;
    for(i=0; i<tl; i++)
    {
        if(v[i]=='F')
        {
            cont+=c[i];
            f++;
        }

    }
    media=(float)cont/f;
    return media;
}

//Funcao que calcula a media da altura das pessoas
float cont_A(float c[], int tl)
{
    int i;
    float cont, media;
    for(i=0; i<tl; i++)
    {
        cont+=c[i];
    }
    media=(float)cont/tl;
    return media;
}

//Funcao para encontrar a maior pessoa
float enc_maior(float c[], int tl)
{
    int i;
    float maior=0;
    for(i=0; i<tl; i++)
    {
        if(c[i]>maior)
            maior=c[i];
    }
    return maior;
}

//Funcao para encontrar a menor pessoa
float enc_menor(float c[], int tl)
{
    int i;
    float menor=c[0];
    for(i=1; i<tl; i++)
    {
        if(c[i]<menor)
            menor=c[i];
    }
    return menor;
}

//funcao para calcular o percentual de homens no vetor
float cont_M(char v[], int tl)
{
    int i, cont=0;
    float perc;
    for(i=0; i<tl; i++)
    {
        if(v[i]=='M')
            cont++;
    }
    perc=((float)cont/tl)*100;
    return perc;
}

void main()
{
    int tl;
    float altura[100];
    char sexo[100];

    tl=ler_vetor(sexo, altura);
    printf("A maior altura:%.2f\n", enc_maior(altura, tl));
    printf("A menor altura e:%.2f\n", enc_menor(altura, tl));
    printf("A media de altura das mulheres:%.2f\n", cont_F(sexo, tl, altura));
    printf("A media de altura da populacao e:%.2f\n", cont_A(altura, tl));
    printf("O percentual de homens e:%.2f%%%\n", cont_M(sexo, tl));
}
