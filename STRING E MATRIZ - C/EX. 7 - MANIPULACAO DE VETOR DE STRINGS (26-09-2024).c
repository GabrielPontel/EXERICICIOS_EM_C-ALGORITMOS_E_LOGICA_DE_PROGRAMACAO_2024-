#include <stdio.h>
#include <string.h>
#define TF 5

/*
Fazer um programa em linguagem C utilizando fun��es capaz de simular uma lista de nomes e seja
poss�vel:
a. Determinar a quantidade de pessoas que os nomes iniciam com uma determinada letra;
b. Determinar a posi��o na lista de um determinado nome;
c. Localizar a quantidade de ocorr�ncia de uma determinada letra;
d. Apresentar todos os nomes iniciados com uma determinada string;
e. A posi��o da pessoa que possui o maior nome;
f.
Apresentar apenas os primeiros nomes das pessoas da lista;
g. Apresentar apenas o sobrenome das pessoas da lista;
h. Apresentar a pessoa que possui mais palavras em seu nome.
*/

//Funcao que preenchera o vetor de string
int ler_nome(char mat[TF][50])
{
    int tl=0;
    char aux[50];
    printf("Digite os nomes:\n");
    do
    {
        fgets(aux, 50, stdin);
        if(aux[strlen(aux)-1]=='\n')
        {
            aux[strlen(aux)-1]='\0';
        }
        if(strcmp(aux, "")!=0)
        {
            strcpy(mat[tl], aux);
            tl++;
        }
    }
    while(tl<TF&&strcmp(aux, "")!=0);
    return tl;
}

//Funcao para retornar a quantidade de pessoas que comecam com a letra escolhida
int encontrar_quant_inicial(char mat[TF][50], int tl)
{
    int i, cont=0;
    char letra;

    fflush(stdin);
    printf("Digite a incial que gostaria saber:");
    scanf(" %c", &letra);
    for(i=0; i<tl; i++)
    {
        if(mat[i][0]==letra)
        {
            cont++;
        }
    }
    return cont;
}

//Funcao para retornar a posicao de um nome desejado no vetor
int pos_nome(char mat[TF][50], int tl)
{
    int i, pos=-1;
    char aux[50];

    fflush(stdin);
    printf("Digite o nome desejado:\n");
    fgets(aux, 50, stdin);
    if(aux[strlen(aux)-1]=='\n')
    {
        aux[strlen(aux)-1]='\0';
    }
    for(i=0; i<tl; i++)
    {
        if(strcmp(aux, mat[i])==0)
            pos=i;
    }
    return pos;
}

//Funcao para retornar a quantidade de vezes que um caracter desejado aparece
int encontrar_letra(char mat[TF][50], int tl)
{
    int i, j, cont=0;
    char letra;

    printf("Digite a letra desejada:\n");
    scanf(" %c", &letra);
    for(i=0; i<tl; i++)
    {
        j=0;
        while(mat[i][j]!='\0')
        {
            if(mat[i][j]==letra)
                cont++;
            j++;
        }
    }
    return cont;
}


void nome_string(char mat[TF][50], int tl)
{
    int i, j, cont;
    char aux[50];
    fflush(stdin);
    printf("Digite a string desejada:\n");
    fgets(aux, 50, stdin);
    if(aux[strlen(aux)-1]=='\n')
    {
        aux[strlen(aux)-1]='\0';
    }
    for(i=0; i<tl ; i++)
    {
        j=0;
        cont=0;
        while(mat[i][j]!='\0'&&j<strlen(aux))
        {
            if(mat[i][j]==aux[j])
            {
                cont++;
            }
            j++;
        }
        if(strlen(aux)==cont)
            printf("%s\n\n", mat[i]);
    }
}

//Funcao para encontrar o nome da pessoa que apresenat mais caracteres
int apresentar_maior(char mat[TF][50], int tl)
{
    int i, maior, pos;

    maior=strlen(mat[0]);
    pos=0;
    for(i=0; i<tl; i++)
    {
        if( maior < strlen(mat[i]) )
        {
            maior=strlen(mat[i]);
            pos=i;
        }
    }
    return pos;
}

//Funcao para apresentar somente o nome das pessoas
void apresentar_nome(char mat[TF][50], int tl)
{
    int i, j;
    printf("Os primeiros nomes serao:\n");
    for(i=0; i<tl; i++)
    {
        j=0;
        while(mat[i][j]!=' '&&mat[i][j]!='\0')
        {
            printf("%c", mat[i][j]);
            j++;
        }
        printf("\n\n");
    }
}

//Funcao que ira apresentar o sobrenome das pessoas contidas na matriz
void apresentar_sobrenome(char mat[TF][50], int tl)
{
    int i, j;

    printf("Os sobrenome serao:\n");
    for(i=0; i<tl; i++)
    {
        j=0;
        while(mat[i][j]!=' '&&mat[i][j]!='\0')
            j++;
        if(mat[i][j]==' ')
            j++;
        while(mat[i][j]!='\0')
        {
            printf("%c", mat[i][j]);
            j++;
        }
        printf("\n");
    }
}

//Funcao para encontrar o nome com mais palavras
void achar_maior_nome(char mat[TF][50], int tl)
{
    int i, cont;
    int pos, maior=-1, j;
    for(i=0; i<tl; i++)
    {
        j=0;
        cont=0;
        while(mat[i][j]!='\0')
        {
            if(mat[i][j]==' ')
            {
                cont++;
            }
            j++;
        }
        cont++;
        if(maior<cont)
        {
            maior=cont;
            pos=i;
        }
    }
    printf("O nome com mais palavra:%s\n\n", mat[pos]);
}
void main()
{

    char mat[TF][50];
    int tl, pos;
    tl=ler_nome(mat);
    printf("A quantidade comeca com esse caracter e: %d\n\n", encontrar_quant_inicial(mat, tl));
    pos=pos_nome(mat, tl);
    if(pos==-1)
    {
        printf("Nome nao encontrado...\n\n");
    }
    else
    {
        printf("O nome esta na posicao: %d\n\n", pos+1);
    }
    printf("A quantidade de letras desejadas:%d\n\n", encontrar_letra(mat, tl));
    nome_string(mat, tl);
    printf("A posicao do maior nome e:%d\n\n", apresentar_maior(mat, tl)+1);
    apresentar_nome(mat, tl);
    apresentar_sobrenome(mat, tl);
    achar_maior_nome(mat, tl);


}
