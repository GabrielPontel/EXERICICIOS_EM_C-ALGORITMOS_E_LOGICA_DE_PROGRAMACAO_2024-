#include <stdio.h>

//Programa que apartir de um numero digitado pelo usuario gera seu fatorial

void main(){

    int fat,i,num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    fat = 1;
    for(i=2;i<=num;i++){
        fat = fat * i;
    }
    printf("O fatorial do %d e %d\n", num , fat);

}
