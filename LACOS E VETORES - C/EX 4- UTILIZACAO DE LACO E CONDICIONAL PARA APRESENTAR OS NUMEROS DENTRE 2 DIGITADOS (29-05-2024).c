#include <stdio.h>

//Programa apresentara ao usuario os numeros dentre os dois digitados

void main(){

    int num1,num2;

    printf("Digite dois numeros:\n");
    scanf("%d %d", &num1, &num2);
    printf("\n");


    if(num1>num2){

        for(num2;num2<=num1;num2++){
            printf("%d\n", num2);
        }
    }
    else
    {
        for(num1;num1<=num2;num1++){
            printf("%d\n", num1);
        }
    }

}
