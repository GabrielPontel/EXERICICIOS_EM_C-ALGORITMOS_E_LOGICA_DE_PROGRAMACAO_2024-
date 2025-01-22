#include <stdio.h>
#include <string.h>
/*
O padr�o ABNT para a escrita de trabalhos acad�micos � largamente utilizado no Brasil, as
refer�ncias bibliogr�ficas possuem o seguinte padr�o de composi��o:
SOBRENOME, Nome. Titulo da Publica��o. Editora: Cidade, Ano.
Fazer um programa em linguagem C capaz de apresentar uma refer�ncia bibliogr�fica de acordo
com o padr�o ABNT, onde o usu�rio digitar� os dados e ser� gerada uma string contendo o padr�o
ABNT.
*/

//Funcao para ler o vetor
void ler_vet(char v[], char texto[])
{
    printf("Digite %s:", texto);
    fgets(v, 50, stdin);
    if(v[strlen(v)-1]=='\n')
    v[strlen(v)-1]='\0';
    v[0]=toupper(v[0]);
}

//Funcao para ler o int
void ler_ano(char v[])
{
    int ano;
    printf("Digite ano:");
    scanf("%d", &ano);
    itoa(ano, v, 10);
}

//Funcao para deixar as letras da string em maiusculo
void fuc_maiusculo(char sobrenome[])
{
    int i=0;
    while(sobrenome[i]!='\0')
    {
        sobrenome[i] = toupper(sobrenome[i]);
        i++;
    }
}

//Funcao para organizar a string principal
void contatenar_string(char sobrenome[],char nome[],char titulo[], char editora[], char cidade[], char ano[], char completo[])
{

    strcpy(completo, sobrenome);
    strcat(completo, ", ");
    strcat(completo, nome);
    strcat(completo, ". ");
    strcat(completo, titulo);
    strcat(completo, ". ");
    strcat(completo, editora);
    strcat(completo, ": ");
    strcat(completo, cidade);
    strcat(completo, ", ");
    strcat(completo, ano);
    strcat(completo, ".");

}

void main()
{
    char nome[50], sobrenome[50], titulo[50], editora[50], cidade[50], ano[50], completo[300];

    ler_vet(sobrenome, "sobrenome");
    fuc_maiusculo(sobrenome);
    ler_vet(nome, "nome");
    ler_vet(titulo, "titulo");
    ler_vet(editora, "editora");
    ler_vet(cidade, "cidade");
    ler_ano(ano);
    contatenar_string(sobrenome, nome, titulo, editora, cidade, ano, completo);
    puts(completo);
}
