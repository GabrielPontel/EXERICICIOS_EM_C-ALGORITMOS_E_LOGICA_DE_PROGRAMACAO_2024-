#include <stdio.h>

/*
Fazer um programa em linguagem C utilizando fun��es, capaz de preencher uma matriz de 10 por
10 com zeros e posteriormente inserir em posi��es aleat�rias 20 n�meros aleat�rios entre 2 e 20, e
seja capaz de simular um jogo de batalha naval, do usu�rio contra a m�quina. Com os seguintes
crit�rios:
� o jogo deve possuir 20 rodadas;
� a cada rodada o usu�rio escolhe a posi��o (linha e coluna) onde vai atirar, se nessa posi��o
tiver um n�mero zero, o usu�rio n�o atingiu nada e nenhum ponto � computado; Caso na
posi��o for encontrado um n�mero diferente de zero, o n�mero encontrado � a quantidade de
pontos obtida pelo usu�rio.
� O computador far� a jogada logo ap�s o usu�rio, gerando de forma aleat�ria a posi��o onde vai
atirar, e seguindo a mesma mec�nica do usu�rio.
� Ao final das 20 rodadas, quem obteve a maior quantidade de pontos ser� o vencedor.
*/

//Funcao para zerar a matriz onde tera os pontos
void zerar_matriz(int mat[10][10])
{
    int i,j;
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            mat[i][j]=0;
}

//Funcao para zerar a matriz  a ser apresentada
void zerar_apresentar(char mat[10][10])
{
    int i,j;
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
            mat[i][j]='*';
}

//Funcao para apresentar a matriz
void apresentar_mat(char mat[10][10])
{
    int i, j;
    printf("   0  1  2  3  4  5  6  7  8  9   \n");
    for(i=0; i<10; i++)
    {
        printf("%d  ", i);
        for(j=0; j<10; j++)
        {
            printf("%c  ", mat[i][j]);
        }
        printf("\n");
    }
}

//Funcao para colocar os pontos e suas posicoes aleatoriamente
void colocar_pontos(int mat[10][10])
{
    int linha, coluna, i;
    for(i=0; i<20; i++)
    {

        linha=rand()%10;
        coluna=rand()%10;
        if(mat[linha][coluna]==0)
        {
            mat[linha][coluna]=rand()%19+2;
        }
        else
        {
            i--;
        }
    }
}

//Funcao para validar a posicao
int val_pos(char texto[])
{
    int pos;
    do
    {
        printf("Digite a %s:", texto);
        scanf("%d", &pos);
        if(pos<0||pos>9)
            printf("Digite um numero valido\n");

    }while(pos<0||pos>9);
    return pos;
}

//Funcao para limpar o terminal
void pausa_limpar()///Melissa a gente aprendeu com o Welinton, tira ponto dele :)
{
    system("pause");
    system("cls");
}

int escolher_pos(int mat[10][10], char apres[10][10], int *pontos_maq)
{
    int linha, coluna, i;
    int pontos_usu=0;
    *pontos_maq=0;

    for(i=0; i<40; i++)
    {
        if(i%2==0)
        {
            printf("\n----------------------------------------------------------\n"
               "\t\tTENTATIVA USUARIO\t\t\n"
               "----------------------------------------------------------\n");
        }
        else
        {
            printf("\n----------------------------------------------------------\n"
               "\t\tTENTATIVA MAQUINA\t\t\n"
               "----------------------------------------------------------\n");
        }
        apresentar_mat(apres);
        if(i%2==0)
        {
        linha=val_pos("linha");
        coluna=val_pos("coluna");
        }
        else
        {
            linha=rand()%10;
            coluna=rand()%10;

        }

        if(apres[linha][coluna]=='*')
        {

            if(mat[linha][coluna]!=0)
            {
                if(i%2!=0)
                *pontos_maq+=mat[linha][coluna];
                else
                pontos_usu+=mat[linha][coluna];
                apres[linha][coluna]='X';
            }
        }
        else{
             i--;
             printf("\n\nopcao  invalida\n\n");

        }

            printf("\n--------------------PONTOS--------------------\n\nUsuario: %d\nMaquina: %d\n", pontos_usu, *pontos_maq);
            printf("---------------------------------------------\n\n");
            pausa_limpar();

    }
    return pontos_usu;
}

//Funcao para apresentar quem ganhou
void achar_ganhador(int pontos_usu, int pontos_maq)
{
    if(pontos_usu>pontos_maq)
        printf("\n------------------------GANHADOR USUARIO------------------------\n\n");
    else{
      if(pontos_usu<pontos_maq)
      {
         printf("\n------------------------GANHADOR MAQUINA------------------------\n\n");
      }
      else
      {
          printf("\n------------------------EMPATE------------------------\n\n");
      }
    }
}

void main()
{
    srand(time(NULL));
    int mat[10][10],pontos_usuario,pontos_maquina;
    char apres[10][10];

    zerar_matriz(mat);
    zerar_apresentar(apres);
    colocar_pontos(mat);
    pontos_usuario = escolher_pos(mat,apres, &pontos_maquina);
    achar_ganhador(pontos_usuario, pontos_maquina);

}
