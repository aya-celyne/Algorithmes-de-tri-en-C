#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

void Tri_insertion (int T[], int N)
{
      int i,j,temp,stop;

      for (i=1;i<N;i++)
      {
          j=i-1;
          stop=FALSE;
          while ((j>=0)&&(stop==FALSE))
          {
            if (T[j+1]>T[j])
            {
                stop=TRUE;
            }
            else
            {
                temp=T[j];
                T[j]=T[j+1];
                T[j+1]=temp;
                j--;
            }

          }
      }
}

int main()
{
    /*int i,k,n;
    clock_t d,f;
    printf("Donner la taille :  ");
    scanf("%d",&n);


    int* tab = (int*)malloc(n*sizeof(int));

    Gen_Tab(tab,n);

    Aff_Tab(tab,n);

    d=clock();
    Tri_insertion(tab,n);
    f=clock();
    
    printf("\n tab tri\n");

    Aff_Tab(tab,n);
    double temp_exe=(double)(f-d)/CLOCKS_PER_SEC;
    printf("\n - le temps d'execution est %f \n",temp_exe);*/

    

    int N;
    double temps;
    clock_t start, stop;   
    srand(time(NULL));
    printf("DONNEZ UNE TAILLE POUR LE TABLEAU QUE VOUS VOULEZ TRIER:");
    scanf("%d", &N);
    int * T= (int*)malloc(N*sizeof(int));
    int * Tr= (int*)malloc(N*sizeof(int));
    Gen_Tab(T,N);
    printf("\n");
    printf("TABLEAU AVANT LE TRI: \n");
    Aff_Tab(T,N);
    printf("\n\n");
    printf("TABLEAU APRES LE TRI : \n");
    start = clock();
    Tri_insertion(T,N);
    stop = clock();
    Aff_Tab (T,N);
    Aff_TabRevers(T,Tr,N);
    temps=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\n\n");
    printf("Temps d'execution 1 (Valeurs Aléatoires): %f", temps);
    start = clock();
    Tri_insertion(Tr,N);
    stop = clock();
    temps=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nTemps d'execution 2 (Valeurs triées inversement): %f", temps);
    start = clock();
    Tri_insertion(T,N);
    stop = clock();
    temps=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nTemps d'execution 3 (Valeurs triées): %f", temps);
    printf("\n\n");

    return 0;
}