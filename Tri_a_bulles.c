#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_MAX  1000
#define NB_MIN  1
#define TRUE 1
#define FALSE 0

void Gen_Tab(int T[],int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        T[i] = rand()%(NB_MAX-NB_MIN)+NB_MIN;
    }
}

void Aff_Tab(int T[], int N)
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("%d |",T[i]);
    }
}

void Aff_TabRevers(int T[],int T_revers[],int N)
{
    int i,j;
    printf("\n\n");
    printf("TABLEAU TRIÉ INVERSEMENT :\n");

  for (i = N-1, j=0; i >= 0; i--, j++)
    T_revers[j] = T[i];

  for (i = 0; i < N; i++)
    T[i] = T_revers[i];

    for (i=0; i<N; i++)
    {
        if (T_revers != 0) 
        {
            printf("%d |",T_revers[i]);
        }
    }
}

double Tri_bulle (int T[], int N)
{
    int i,temp,x;
    int permut;
    double temps;
    clock_t start, stop;
    x=N;
    start = clock();
    do
    {
        x=x-1;
        permut=FALSE;

        for (i=0;i<x;i++)
        {
            if (T[i]>T[i+1])
            {
                temp=T[i];
                T[i]=T[i+1];
                T[i+1]=temp;
                permut=TRUE;
            }
        }
    }while (permut==TRUE);
    stop = clock();
    temps = (double)(stop-start)/CLOCKS_PER_SEC;
    return temps;
}

int main()
{
    int N,i,j;
    double temps;
    srand(time(NULL));
    printf("DONNEZ UNE TAILLE POUR LE TABLEAU QUE VOUS VOULEZ TRIER:");
    scanf("%d", &N);
    int * T= (int*)malloc(N*sizeof(int));
    int * Tr= (int*)malloc(N*sizeof(int));
    int * TT= (int*)malloc(N*sizeof(int));
    Gen_Tab(T,N);
    printf("finished \n");
    temps= Tri_bulle(T,N);
    printf("finished \n");
    printf("Temps d'execution 1 (Valeurs Aléatoires): %f \n", temps);
    for (i = N-1, j=0; i >= 0; i--, j++)
    Tr[j] = T[i];
    //for(i=0; i<N; i++) TT[i] = T[i];
    temps = Tri_bulle(Tr,N);
    printf("\nTemps d'execution 2 (Valeurs triées inversement): %f \n", temps);
    /*temps=Tri_bulle(T,N);
    printf("\nTemps d'execution 3 (Valeurs triées): %f", temps);
    printf("\n\n");*/

    return 0;
}
