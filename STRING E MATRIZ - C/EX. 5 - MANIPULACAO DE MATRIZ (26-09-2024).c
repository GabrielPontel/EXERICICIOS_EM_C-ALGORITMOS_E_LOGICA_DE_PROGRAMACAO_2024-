#include <stdio.h>
#define TF 10

/*
Fazer um programa em linguagem C utilizando funções capaz de ler uma matriz de inteiros com
tamanho máximo de 10 por 10 e seja capaz de:
a. Calcular a soma de cada uma das linhas;
b. Calcular a soma de cada uma das colunas;
c. Apresentar o número da linha com a maior soma dos elementos;
d. Determinar a linha do maior elemento;
e. Determinar a coluna do maior elemento;
f.
Determinar a posição do menor elemento;
*/

//Funcao para ler a matriz
void ler_matriz(int mat[TF][TF])
{
    int i,j;
    for(i=0;i<TF;i++)
        for(j=0;j<TF;j++)
        {
            printf("MATRIZ[%d][%d] = ",i,j);
            scanf("%d", &mat[i][j]);
        }
}

//Funcao que soma o valor de uma coluna
int somar_coluna(int mat[TF][TF], int pos)
{
    int i,somar=0;
    for(i=0; i<TF; i++)
    {
        somar+=mat[i][pos];
    }
    return somar;
}

//Funcao que soma o valor de uma linha
int somar_linha(int vet[TF])
{
    int i,somar=0;
    for(i=0;i<TF;i++)
        somar+=vet[i];
    return somar;
}

//Funcao pra apresentar a soma das linhas
void apresentar_soma_linhas(int mat[TF][TF])
{
    int i;
    for(i=0;i<TF;i++)
    {
        printf("A soma da linha %d = %d\n",i, somar_linha(mat[i]));
    }
}

//Funcao pra apresentar a soma das colunas
void apresentar_soma_colunas(int mat[TF][TF])
{
    int i;
    for(i=0;i<TF;i++)
    {
        printf("A soma da coluna %d = %d\n",i, somar_coluna(mat,i));
    }
}

//Funcao para encontrar qual linha apresentar maior somatoria de elementos
int achar_Maior(int mat[TF][TF])
{
    int i=0;
    int maior;
    maior = somar_linha(mat[i]);
    for(i=1;i<TF;i++)
    {
        if(maior<somar_linha(mat[i]))
        {
            maior = somar_linha(mat[i]);
        }
    }
    return maior;
}

//Funcao para achar a linha do maior elemento
int achar_linha(int mat[TF][TF])
{
    int i,j,elem,linha;
    elem = mat[0][0];
    linha = 0;
    for(i=0;i<TF;i++)
        for(j=0;j<TF;j++)
        {
            if(elem<mat[i][j])
            {
                elem=mat[i][j];
                linha = i;
            }
        }
    return linha;
}

//Funcao para achar a coluna do maior elemento
int achar_coluna(int mat[TF][TF])
{
    int i,j,elem,coluna;
    elem = mat[0][0];
    coluna = 0;
    for(i=0;i<TF;i++)
        for(j=0;j<TF;j++)
        {
            if(elem<mat[i][j])
            {
                elem=mat[i][j];
                coluna = j;
            }
        }
    return coluna;
}

//Funcao apara encontra a posicao do menor elemento
int achar_menor(int mat[TF][TF], int *coluna)
{
     int i,j,elem,linha;

    elem = mat[0][0];
    *coluna = 0;
    linha = 0;
    for(i=0;i<TF;i++)
        for(j=0;j<TF;j++)
        {
            if(elem>mat[i][j])
            {
                elem=mat[i][j];
                linha = i;
                *coluna = j;
            }
        }
    return linha;
}

void main()
{
    int mat[TF][TF],col;

    ler_matriz(mat);
    apresentar_soma_linhas(mat);
    apresentar_soma_colunas(mat);
    printf("\nA soma linha com a maior soma = %d\n", achar_Maior(mat));
    printf("\nA linha do maior elemento: linha %d\n", achar_linha(mat));
    printf("\nA coluna do maior elemento: coluna %d\n", achar_coluna(mat));
    printf("\nO menor elemento tem a posicao: MATRIZ[%d][%d]\n", achar_menor(mat,&col), col);
}



