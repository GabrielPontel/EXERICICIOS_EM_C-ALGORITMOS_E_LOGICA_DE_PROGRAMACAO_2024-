#include <stdio.h>

//Programa apresenta o quadrado e cubo dos numeros de 0 a 20

void main(){

    int i,quad,cubo;

    for(i=1; i<=20; i++ ){
        quad = i*i;
        cubo = i*i*i;
        printf("%d -> %d e %d\n", i, quad, cubo);
    }
}
