#include <stdio.h>

/*
Os alunos do IFSP se inscreveram no programa de aux�lio alimenta��o. Esses alunos foram classificados de acordo
com a renda, al�m de outros fatores. A assistente social do IFSP fez uma lista com os prontu�rios em ordem de
classifica��o, ela deseja fazer a consulta de forma r�pida, para isso solicitou aos alunos do primeiro ano do curso
T�cnico em Inform�tica que implementassem um programa. Fa�a um programa em linguagem C capaz de:
a) Preencher um vetor contendo N valores referentes aos prontu�rios dos alunos;
b) Com a digita��o do prontu�rio de um aluno, apresentar a posi��o que esse aluno est� na lista de classifica��o;
c) Considerando que ser�o beneficiados X alunos, apresentar o prontu�rio desses X primeiros alunos;
d) Apresentar a classifica��o completa dos alunos.
Obs. Para cada um dos processos, somente 50 alunos podem fazer inscri��o.
*/

//Funcao para ler o vetor de inteiro
void ler_vet(int vet[], int *tl)
{
    int aux;
    *tl=0;
    printf("Caso queira sair digite 0\nDigite o prontuario do aluno %d:PE", *tl+1);
    scanf("%d", &aux);
    while(aux!=0 && *tl<50)
    {
        vet[*tl] = aux;
        (*tl)++;
        printf("Caso queira sair digite 0\nDigite o prontuario do aluno %d:PE", *tl+1);
        scanf("%d", &aux);
    }
}

//Funcao procura o prontuario desejado dentro do vetor
int pos_aluno(int v[], int tl)
{
    int i, pront, pos=-1;
    printf("\n\nQual o prontuario voce quer saber a classificacao:PE");
    scanf("%d", &pront);
    for(i=0;i<tl; i++)
    {
        if(pront==v[i])
        {
            pos=i;
        }
    }
    return pos;
}

//funcao que forca o usuario colocar um numero positivo
int validar_prem(int tl)
{
    int prem;
    do
    {
        printf("Quantos auxilios iram ser distribuidos:\n");
        scanf("%d", &prem);
    }while(prem<0);
    return prem;
}

//funcao para apresentar todos os alunos contemplados
void apresentar_alunos_contemplados(int v[], int tl)
{
    int i,prem;
    prem = validar_prem(tl);
    printf("Os cotemplados sao:\n");
    for(i=0;i<tl&&i<prem;i++)
    {
        printf("PE%d\n", v[i]);
    }
}

//Funcao para mostrar as classificacoes dos alunos
void apres_vet(int v[], int tl)
{
    int i;
    printf("\n\n--------------------A classificacao dos alunos--------------------\n\n");
    for(i=0;i<tl;i++)
    {
        printf("Aluno - %d - PE%d\n",i+1, v[i]);
    }
}

void main()
{
    int v[50], tl, posicao;

    ler_vet(v,&tl);
    posicao =pos_aluno(v,tl);
    if(posicao != -1)
        printf("A posicao do aluno : %d\n", posicao+1);
    else
        printf("Nao existe esse prontuario no sistema\n");
    apresentar_alunos_contemplados(v,tl);
    apres_vet(v,tl);
}
