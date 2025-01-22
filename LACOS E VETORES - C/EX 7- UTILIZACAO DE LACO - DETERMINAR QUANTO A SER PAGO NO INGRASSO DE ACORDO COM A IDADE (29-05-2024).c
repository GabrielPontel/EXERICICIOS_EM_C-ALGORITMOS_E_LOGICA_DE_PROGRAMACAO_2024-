#include <stdio.h>

//Programa de laco for para realizar o valor a ser pago pelas pessoas

void main(){

    int contcri,contido,contint,contmeia,i,v[20];
    float total;

    contcri = 0;
    contido = 0;
    contint = 0;


    for( i=0 ; i<20 ; i++){

        printf("Digite a idade da pessoa %d\n", i+1);
        scanf("%d", &v[i]);

    }
    for( i=0 ; i<20 ; i++){

    if( ( v[i]>= 12) && ( v[i]<= 59 ) ){
        contint++;
    }
    else{
        if(v[i]>59){
            contido++;
        }
        else{
            contcri++;
        }
    }
    }

    contmeia = contido + contcri;
    total = contint * 18.00 + contmeia * 18.00/2;

    printf("A quantidade de entradas integrais vendidas = %d\n", contint);
    printf("A quantidade de meias entradas vendidas = %d\n", contmeia);
    printf("A quantidade de criancas que assistiram a sessão = %d\n", contcri);
    printf("A quantidade de idosos que assistiram a sessao = %d \n", contido );
    printf("O total arrecadado foi de R$ %.2f", total);

}
