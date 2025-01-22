#include <stdio.h>

//Programa faz a tabuada de um numero inserido pelo usuario

void main(){

    int i,tabuada,conta;

    printf("Digite um numero para fazer a tabuada:\n");
    scanf("%d", &tabuada);
    printf("\n");

    for(i=1;i<=10;i++){
        conta = tabuada * i;
        printf("%d\n", conta);
    }


}
