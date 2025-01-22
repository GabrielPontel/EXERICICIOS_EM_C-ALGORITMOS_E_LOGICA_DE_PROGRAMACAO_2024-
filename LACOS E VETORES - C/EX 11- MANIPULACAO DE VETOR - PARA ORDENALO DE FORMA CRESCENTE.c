#include <stdio.h>

//Programa com funcao de ordenar um vetor do tamanho e com os numeros que o usuario deseja

void main()
{

    float v[100],menor,x;
    int i,j,posmenor,TL;

    printf("Digite o tamanho do vetor a ser ordenado: ");
    scanf("%d", &TL);

    for(i=0; i<TL; i++)
    {
        printf("VETOR[%d] = ", i+1);
        scanf("%f", &v[i]);
    }


    for(i=0; i<TL-1; i++)
    {
        menor=v[i];
        posmenor=i;

        for(j=i; j<TL; j++)
            if(menor>v[j])
            {
                menor=v[j];
                posmenor=j;
            }
        x = v[i];
        v[i] = menor;
        v[posmenor] = x;
    }

    printf("O vetor em sua forma ordenada ficara assim...: \n");
    for(i=0; i<TL; i++)
    {
        printf("%.2f\n", v[i]);
    }


}
