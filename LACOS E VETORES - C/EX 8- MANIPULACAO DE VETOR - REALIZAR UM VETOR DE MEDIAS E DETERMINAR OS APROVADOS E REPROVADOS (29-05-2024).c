#include <stdio.h>

//Programa que manipula notas de alunos e apresenta a porcentagem de aprovados e reprovados

void main(){

    int i,apro,repro;
    float v[10], nota1,nota2,aprop,reprop, media;

    media = 0;
    apro = 0;
    repro = 0;

    for(i=0;i<10;i++){

        printf("Digite as duas notas do aluno %d\n", i+1);
        scanf("%f", &nota1);
        scanf("%f", &nota2);

        v[i] = ( nota1 + nota2 ) / 2;
    }
    for(i=0;i<10;i++){

        printf("A media do aluno %d = %.2f\n", i+1, v[i]);

        if(v[i]>=6){
            apro++;
        }
        else{
            repro++;
        }
        media = media + v[i]/10;
     }
        aprop = (float) apro * 100 / 10 ;
        reprop = (float) repro * 100 / 10 ;

        printf("O total de alunos aprovados = %d , que em percentual = %.2f%% \n", apro, aprop);
        printf("A media da turma = %.2f\n ", media);
        printf("O total de alunos reprovados = %d , que em percentual = %.2f%%\n", repro, reprop);



}

