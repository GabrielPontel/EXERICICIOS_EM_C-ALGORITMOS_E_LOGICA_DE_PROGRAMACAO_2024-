#include <stdio.h>

/*
Na sua turma ser� realizada a elei��o para representante de sala, as turmas tem no m�ximo 50 alunos, os candida
tos foram: Marcos da Silva e a Ana Claudia de Alcantara. Para controlar a elei��o deve ser implementado um pro
grama em linguagem C capaz de representar uma urna eletr�nica, onde todos os alunos da turma poder�o votar,
sendo que as op��es s�o M � Marcos da Silva, A - Ana Claudia de Alcantara, B - Branco, X � para finalizar e qualquer
outro valor � um voto nulo. Ap�s a finaliza��o da elei��o deve-se apresentar um resumo contendo:
a) Total de alunos que votaram;
b) Total de votos para o Marcos da Silva;
c) Total de votos para a Ana Claudia;
d) Quantidade de votos brancos;
e) Quantidade de votos nulos;
f)
Percentual de votos v�lidos, ou seja, sem contar brancos e nulos;
g) Percentual de votos de cada um dos candidatos, considerando apenas os votos v�lidos;
h) Caso a quantidade de votos v�lidos n�o alcance 50% deve-se apresentar a mensagem �A elei��o n�o foi v�lida�
i)
Se a elei��o for v�lida apresentar o nome do novo representante de sala ou se houve empate.
*/

//Funcao para preencher o vetor
int ler_vet(char vet[])
{
    int tl=0;
    printf("----------------------------------\nM � Marcos da Silva\nA - Ana Claudia de Alcantara\nB - Branco\nX � para finalizar\nQualquer outro valor e um voto nulo\n----------------------------------\nDigite o voto do aluno %d", tl+1);
    scanf(" %c", &vet[tl]);
    while(vet[tl]!='X'&&tl<50)
    {
        tl++;
        printf("----------------------------------\nM � Marcos da Silva\nA - Ana Claudia de Alcantara\nB - Branco\nX � para finalizar\nQualquer outro valor e um voto nulo\n----------------------------------\nDigite o voto do aluno %d", tl+1);
        scanf(" %c", &vet[tl]);
    }

    return tl;
}

//Funcao vai varrer o vetor e encontrar a quantidade q votaram , retornando ela
int quant_votos_nulos(char vet[], int tl)
{
    int i,cont=0;
    for(i=0; i<tl; i++)
    {
        if(vet[i]!='M'&&vet[i]!='A'&&vet[i]!='B')
            cont++;
    }
    return cont;
}

//Funcao para contar quantas vezes tem um caracter determinado por uma variavel, retornando tal quantidade
int quant_caracter(char vet[], int tl, char det)
{
    int i,cont=0;
    for(i=0;i<tl;i++)
        if(vet[i]==det)
            cont++;
    return cont;
}

//Funcao para contar e retornar a quantidade de votos validos, ou seja sem votos brancos e nulos
int quant_votos_validos(char vet[], int tl)
{
    int i,cont=0;
    for(i=0; i<tl; i++)
    {
        if(vet[i]=='M'||vet[i]=='A')
            cont++;
    }
    return cont;
}

//funcao para realizar o percentual de votos validos
float percent_votos_validos(char vet[], int tl)
{
    return ((float)quant_votos_validos(vet, tl)/tl)*100;
}

//funcao para calcular a porcentagem
float calc_percent(char vet[], int tl, char aux)
{
    float percent;
    int quant,validos;
    quant = quant_caracter(vet,tl,aux);
    validos = quant_votos_validos(vet,tl);

    percent = ((float)quant/validos)*100;
    return percent;
}

//funcao para apresentar quem ganhou
void quem_ganhou(char vet[], int tl)
{
    int Marcos,Ana;
    Marcos = quant_caracter(vet,tl,'M');
    Ana = quant_caracter(vet,tl,'A');
    if(Marcos == Ana)
    {
        printf("\nHouve um empate\n");
    }
    else if(Marcos>Ana)
    {
        printf("\nMarcos ganhou a eleicao\n");
    }
    else
    {
        printf("\nAna Claudia ganhou a eleicao\n");
    }

}

void main()
{
    int branco,Marcos,Ana,nulo,valido,tl;
    char vet[50],aux;
    float percent;

    tl=ler_vet(vet);
    printf("\nO total de alunos que votaram = %d\n", tl);

    Marcos = quant_caracter(vet,tl,'M');
    printf("O total de votos em Marcos da Silva = %d\n", Marcos);

    Ana = quant_caracter(vet,tl,'A');
    printf("O total de votos para a Ana Claudia = %d\n", Ana);

    branco = quant_caracter(vet,tl,'B');
    printf("A quantidade de votos brancos = %d\n", branco);

    nulo = quant_votos_nulos(vet,tl);
    printf("A quantidade de votos nulos = %d\n", nulo);

    percent = percent_votos_validos(vet,tl);
    printf("Percentual de votos validos = %.2f%%%\n", percent);

    percent = calc_percent(vet,tl,'M');
    printf("O percentual de votos em Marcos da Silva = %.2f%%%\n", percent);

    percent = calc_percent(vet,tl,'A');
    printf("O percentual de votos em Ana Claudia de Alcantara = %.2f%%%\n", percent);

    if(percent_votos_validos(vet,tl)<50)
        printf("A elei��o nao foi valida");
    else
    quem_ganhou(vet,tl);
}
