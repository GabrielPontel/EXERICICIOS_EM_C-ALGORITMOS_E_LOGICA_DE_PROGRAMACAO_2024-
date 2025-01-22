#include <stdio.h>

//Programa de laco no qual o usuario digita a quantidade de notas a serem lancadas
//e apos digita-las e realizado a media

void main(){

    int i,quantidade;
    float nota, media, soma;

    printf("Digite a quantidade de notas:\n");
    scanf("%d", &quantidade);
    printf("\n");

    soma = 0;

    for(i=0;i<quantidade;i++){
        scanf("%f", &nota);
        soma += nota;
    }
    media = (float)soma / quantidade;
    printf("A media foi de : %.2f", media);
}
