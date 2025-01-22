#include <stdio.h>
/*
Fazer um programa em linguagem C capaz de trabalhar com operação sobre vetores inteiros. fazer um menu de
opções que permita que o usuário selecione a operação a ser realizada, contendo as seguintes operações:
a) Ler dois vetores inteiros a e b, com 5 elementos;
b) Colocar os elementos dos dois vetores a e b, em um terceiro vetor c com tamanho de 10 elementos;
c) Imprimir qual dos dois (a e b) tem a maior soma de elementos;
d) Multiplicar os elementos do vetor c (tamanho 10) por um valor x (inteiro) digitado pelo usuário e apresentar esse ve
tor;
e) Trocar os elementos entre os vetores a e b.
f)
Apresentar os elementos dos vetores a e b.
*/

//funcao para preencher um vetor
void preencher_vet(int vet[])
{
    int i;
    for(i=0; i<5; i++)
    {
        printf("Vetor [%d]:", i);
        scanf("%d", &vet[i]);
    }
}

//funcao que preenchera os dois vetores
void ler_vetores(int a[], int b[])
{
    printf("Digite o valor do primeiro vetor:\n");
    preencher_vet(a);
    printf("Digite o valor do segundo vetor:\n");
    preencher_vet(b);
}

//Funcao que somara todos os conteudos de um vetor
int soma_vetor(int v[])
{
    int soma=0, i;
    for(i=0; i<5; i++)
    {
        soma+=v[i];
    }
    return soma;
}

//funcao que apresentara qual é o maior vetor
void dif_vet(int a[], int b[])
{
    int soma1;
    int soma2;

    soma1 = soma_vetor(a);
    soma2 = soma_vetor(b);

    if(soma1>soma2)
    {
        printf("\n\nA soma do vetor (a) e maior");

    }
    else
    {

        if(soma1<soma2)
        {
            printf("\n\nA soma do vetor (b) e maior");
        }
        else
            printf("\n\nA soma dos dois vetores sao iguais");
    }
}

//funcao que preenche um terceiro vetor apartir de outros dois
void coloc_vetC(int a[], int b[], int c[])
{
    int i, tl=0;
    for(i=0; i<5; i++)
    {
        c[tl]=a[i];
        tl++;
    }
    for(i=0; i<5; i++)
    {
        c[tl]=b[i];
        tl++;
    }
}

//Funcao que multiplica o vetor inteiro por um elemento
void mult_vetC(int c[])
{
    int i, x;
    printf("Digite um valor para multiplicar\nDigite: ");
    scanf("%d", &x);
    for(i=0; i<10; i++)
    {
        c[i]=c[i]*x;
    }
}

//Funcao que troca os valores de um vetor parao outro e vice-versa
void trocar_vet(int a[], int b[])
{
    int i, valor;
    for(i=0; i<5; i++)
    {
        valor=a[i];
        a[i]=b[i];
        b[i]=valor;
    }
}

//funcao que apresenta um vetor
void apres_vet(int a[], int tl)
{
    int i;
    for(i=0; i<tl; i++)
    {
        printf("vetor [%d]: %d\n", i, a[i]);
    }

}

void main()
{
    int a[5], b[5], c[10], somaA, somaB, sair=0;
    char opcao;
    ler_vetores(a, b);

    do
    {
        printf("-----------------MENU VETOR-----------------\n(A)Colocar elementos do vetor A e B em um vetor C\n(B)Imprimir a maior soma\n(C)Multiplicar vetor C por um valor X\n(D)Trocar elementos do vetor A e B\n(E)Apresentar os elementos de A e B\n(F)Sair do programa\nDIGITE:");
        scanf(" %c", &opcao);
        while(opcao!='A'&&opcao!='B'&&opcao!='C'&&opcao!='D'&&opcao!='E'&&opcao!='F')
        {
            printf("\nDigite novamente um valor valido...\n\n");
            printf("-----------------MENU VETOR-----------------\n(A)Colocar elementos do vetor A e B em um vetor C\n(B)Imprimir a maior soma\n(C)Multiplicar vetor C por um valor X\n(D)Trocar elementos do vetor A e B\n(E)Apresentar os elementos de A e B\n(F)Sair do programa\nDIGITE:");
            scanf(" %c", &opcao);
        }
        switch(opcao)
        {
        case 'A':
            coloc_vetC(a, b, c);
            break;
        case 'B':
            dif_vet(a, b);
            break;
        case 'C':
            mult_vetC(c);
            printf("-----------------vetor C-----------------\n\n");
            apres_vet(c, 10);
            break;
        case 'D':
            trocar_vet(a, b);
            break;
        case 'E':
            printf("-----------------vetor A-----------------\n\n");
            apres_vet(a, 5);
            printf("-----------------vetor B-----------------\n\n");
            apres_vet(b, 5);
            break;
        case 'F':
            sair=1;
            break;
        }
    }
    while(sair!=1);




}
