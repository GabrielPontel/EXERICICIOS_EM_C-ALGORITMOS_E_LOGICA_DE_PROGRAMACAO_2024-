#include <stdio.h>

//programa faz manipulacao de um vetor preenchido pelo usuario

void main(){

    float v[20],maior,menor,soma,media;
    int i;

    //preenchimento do vetor
    for(i=0; i<20; i++){
        printf("VETOR[%d] = ", i+1);
        scanf("%f", &v[i]);
    }

    maior=v[0];
    menor=v[0];
    soma=0;

    for(i=0;i<20;i++){
        //condicoes para encontrar o maior e menor elemento
        if(menor>v[i]){
            menor=v[i];
        }
        if(maior<v[i]){
            maior=v[i];
        }
        soma = soma + v[i];
    }

    media = (float)soma/20;

    printf("O menor = %.2f\n", menor);
    printf("O maior = %.2f\n", maior);
    printf("A soma = %.2f\n", soma);
    printf("A media = %.2f\n", media);

}
