#include <stdio.h>

//Programa de manipulacao de funcoes, no qual faz a transformacao da temperatura Celsius entre Fahrenheit

/*
Fa�a um programa com um menu com duas op��es:
a)  Celsius -> Fahrenheit - onde ser� solicitado ao usu�rio uma temperatura em graus Celsius e apresent�-la conver
tida em graus Fahrenheit. Fazer uma fun��o que resolva a seguinte f�rmula de convers�o: F = (9 * C + 160) / 5,
sendo F a temperatura em Fahrenheit e C a temperatura em Celsius.
b)  Fahrenheit -> Celsius � onde ser� solicitado ao usu�rio uma temperatura em graus Farenheit e apresent�-la con
vertida em graus Celsius. A f�rmula de convers�o �: C = (F � 32) * (5/9), sendo F a temperatura em Farenheit e C
a temperatura em Celsius.
*/

//Ler temperatura
float ler_temp()
{
    float temp;
    printf("Digite a temperatura no qual deseja alterar:\n");
    scanf("%f", &temp);
    return temp;
}

//Celsus --> Fahrenheit
float trans_Fah(float temp)
{
    float F;
    F = (float)(9*temp+160)/5;
    return F;
}

//Fahrenheit --> Celsus
float trans_Cel(float temp)
{
    float C;
    C = (float)(5.0/9)*(temp-32);
    return C;
}

//Escolher opcao
char esc_opcao()
{
    char opcao;
    do{
        printf("Digite a opcao desejada:\n(a) Celsius-->Fahrenheit\n(b)Fahrenheit-->Celsius\n");
        scanf(" %c", &opcao);
        if(opcao!='a'&&opcao!='b')
            printf("Opcao invalida , digite novamente\n");
    }while(opcao!='a'&&opcao!='b');
    return opcao;
}

void main()
{
    float C, F, temp;
    char opcao;
    opcao = esc_opcao();
    temp = ler_temp();
    if(opcao=='a')
    {
        F = trans_Fah(temp);
        printf("A temperatura em Fahrenheit = %.2f", F);
    }
    else
    {
        C = trans_Cel(temp);
        printf("A temperatura em Celsius = %.2f", C);
    }
}
