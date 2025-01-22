#include <stdio.h>

/*
Faça um programa em linguagem C utilizando funções que leia a nota dos dois bimestres dos alunos de uma turma,
sabendo que a turma tem no máximo 50 alunos, e armazene em dois diferentes vetores e seja capaz de:
a) Calcular a média de cada um dos alunos e armazenar em um terceiro vetor;
b) Apresentar a média final dos alunos;
c) Média da turma;
d) Total e percentual de alunos reprovados.
*/

//funcao para validar a quantidade de alunos
int val_quantidade_alunos()
{
    int tl;
    do
    {
        printf("Digite a quantidade de alunos:");
        scanf("%d", &tl);
        if(tl<0||tl>50)
        {
            printf("Digite um valor valido...\n");
        }
    }
    while(tl<0||tl>50);
}

//funcao que preenche os vetores de notas
int ler_nota(float n1[], float n2[])
{
    int tl, i;
    tl = val_quantidade_alunos();
    printf("Digite as duas notas:\n");
    for(i=0; i<tl; i++)
    {
        printf("Aluno %d:\n", i+1);
        printf("Nota 1:");
        do{
            scanf("%f", &n1[i]);
            if(n1[i]<0||n1[i]>10)
                printf("Digite uma nota valida\n");
        }while(n1[i]<0||n1[i]>10);

        printf("Nota 2:");
         do{
            scanf("%f", &n2[i]);
            if(n2[i]<0||n2[i]>10)
                printf("Digite uma nota valida\n");
        }while(n2[i]<0||n2[i]>10);
    }
    return tl;
}

//funcao que realiza um vetor de medias
void media_vetor(float n1[], float n2[], float media[], int tl)
{
    int i;
    for(i=0; i<tl; i++)
    {
        media[i]=(float)(n1[i]+n2[i])/2;
    }
}

//funcao que apresenta um vetor
void apresentar_vetor(float v[], int tl)
{
    int i;
    printf("A media da sala e:\n");
    for(i=0; i<tl; i++)
    {
        printf("Aluno %d: %.2f\n", i+1, v[i]);
    }
}

//funcao que realiza a soma das media e as divide entre os alunos realizando a media geral
float media_geral(float media[], int tl)
{
    int i, geral=0;
    for(i=0; i<tl; i++)
        geral+=media[i];
    geral=geral/tl;
    return geral;
}

//funcao que realiza o percentual de nota do aluno
float percentual_aluno(float media[], int tl)
{
    int i, soma=0;
    float perc;


    for(i=0;i<tl;i++)
        if(media[i]<6)
            soma++;
    perc=((float)soma/tl)*100;
    return perc;

}

void main()
{
    float n1[50], n2[50], media[50];
    int tl;

    tl=ler_nota(n1, n2);
    media_vetor(n1, n2, media, tl);
    apresentar_vetor(media, tl);
    printf("A media da turma e:%.2f\n", media_geral(media, tl));
    printf("O percentual da turma e:%.2f\n", percentual_aluno(media, tl));
}
