#include <stdio.h>

//Programa para o usuario digitar varios numeros e a partir desses
//dados apresentara a quantidade de positivos e negativos

void main(){

    int var,N,neg,pos,i;

    printf("Quantos numeros sera digitado:\n");
    scanf("%d", &N);

    pos = 0;
    neg = 0;

    printf("Digite os %d numeros:\n", N);

    for(i=0;i<N;i++){
        scanf("%d", &var);

    if(var>0){
        pos++;
    }
    else{
        neg++;
    }

    }
    printf("tem %d numeros positivos\n", pos);
    printf("Tem %d numeros negativos\n", neg);

}
