#include <stdio.h>

/*
Os alunos do IFSP se inscreveram no programa de auxílio alimentação. Esses alunos foram classificados de acordo
com a renda, além de outros fatores. A assistente social do IFSP fez uma lista com os prontuários em ordem de
classificação, ela deseja fazer a consulta de forma rápida, para isso solicitou aos alunos do primeiro ano do curso
Técnico em Informática que implementassem um programa. Faça um programa em linguagem C capaz de:
a) Preencher um vetor contendo N valores referentes aos prontuários dos alunos;
b) Com a digitação do prontuário de um aluno, apresentar a posição que esse aluno está na lista de classificação;
c) Considerando que serão beneficiados X alunos, apresentar o prontuário desses X primeiros alunos;
d) Apresentar a classificação completa dos alunos.
Obs. Para cada um dos processos, somente 50 alunos podem fazer inscrição.
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
