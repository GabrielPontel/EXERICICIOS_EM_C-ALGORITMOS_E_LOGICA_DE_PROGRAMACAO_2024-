#include <stdio.h>

//PROGRAMA QUE APRESENTA EM UMA ORDEM EXPECIFICA SOMANDO OS DOIS ITEMS ANTERIORES A ELE

void main (){

    int N,i,v[100];

    printf("Digite um numero: ");
    scanf("%d", &N);

    v[0] = 1;
    v[1] = 1;

    if(N==1){
        printf("%d", v[0]);
    }
    else if(N==2){
    printf("%d, ", v[0]);
    printf("%d, ", v[1]);
    }
    else if(N>=3){
        printf("%d, ", v[0]);
        printf("%d, ", v[1]);

        for(i=2; i<N ; i++ ) {
            v[i]= v[i-1] + v[i-2];
            printf("%d, ", v[i]);

       }
    }



}
