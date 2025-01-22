#include <stdio.h>
#include <math.h>

//Programa de laco no qual o usuario digita o tempo desejado em segundos a ser analizado
//e o sistema apresenat ao usuario a velocidade e a distancia em cada segundo com uma gravidade de 10 m/s2

void main()
{

    int tempo,//tempo em segundos
        velocidade[100],//m/s
        i,
        grav=10;

    float distancia[100];// m

    printf("Digite o tempo em segundos a ser analizado..: ");
    scanf("%d", &tempo);

    for(i=0; i<=tempo; i++)
    {
        velocidade[i] = i * grav;
    }

    for(i=0; i<=tempo; i++)
    {
        distancia[i]= 0.5 * grav * pow(i,2) ;
        // Sei que tambem poderia fazer sem a math (i*i), no entanto quero me acustumar com a biblioteca.
    }

    for(i=0; i<=tempo; i++)
    {
        printf("No segundo %d a velociade vai ser de %d m/s, enquanto a distancia %.2f metros\n", i, velocidade[i], distancia[i]);
    }



}
