#include <stdio.h>

//Programa que conta os pares de forma crescente de 0 a 30 e depois de forma decrescente de 1 em 1

void main(){

    int i;

    for(i=0; i<=30; i=i+2){
        printf("%d\n", i);
    }
    for(i=29; i>0; i--){
        printf("%d\n", i);
    }
}
