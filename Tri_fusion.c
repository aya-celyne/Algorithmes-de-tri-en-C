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

void fusion(int tableau[],int deb1,int fin1,int fin2)
 {
        
        int *table1;
        int deb2=fin1+1;
        int compt1=deb1;
        int compt2=deb2;
        int i;
        table1=malloc((fin1-deb1+1)*sizeof(int));

       
        for(i=deb1;i<=fin1;i++)
            {
            table1[i-deb1]=tableau[i];
            }
                        
        for(i=deb1;i<=fin2;i++)
            {        
            if (compt1==deb2) 
                {
                break; 
                }
            else if (compt2==(fin2+1)) 
                {
                tableau[i]=table1[compt1-deb1]; 
                compt1++;
                }
            else if (table1[compt1-deb1]<tableau[compt2])
                {
                tableau[i]=table1[compt1-deb1];
                compt1++;
                }
            else
                {
                tableau[i]=tableau[compt2];
                compt2++;
                }
            }
        free(table1);
        
}
        

void tri_fusion_bis(int tableau[],int deb,int fin)
        {
        if (deb!=fin)
            {
            int milieu=(fin+deb)/2;
            tri_fusion_bis(tableau,deb,milieu);
            tri_fusion_bis(tableau,milieu+1,fin);
            fusion(tableau,deb,milieu,fin);
            }
        }

double tri_fusion(int tableau[],int longueur)
     {
        double temps;
        clock_t start, stop;
        start = clock();
        if (longueur>0)
            {
            tri_fusion_bis(tableau,0,longueur-1);
            }
        stop = clock();
        temps=(double)(stop-start)/CLOCKS_PER_SEC;
        return temps;
     }

int main()
{
    int N,i,j;
    double temps,temps2,temps3;
    srand(time(NULL));
    printf("DONNEZ UNE TAILLE POUR LE TABLEAU QUE VOUS VOULEZ TRIER:");
    scanf("%d", &N);
    int * T= (int*)malloc(N*sizeof(int));
    int * Tr= (int*)malloc(N*sizeof(int));
    int * TT= (int*)malloc(N*sizeof(int));
    Gen_Tab(T,N);
    printf("finished \n");
    temps = tri_fusion(T,N);
    printf("finished \n");
    for (i = N-1, j=0; i >= 0; i--, j++)
    Tr[j] = T[i];
    /*for(i=0; i<N; i++) TT[i] = T[i];*/
    printf("Temps d'execution 1 (Valeurs Aléatoires): %f \n", temps);
    temps2 = tri_fusion(Tr,N);
    printf("\nTemps d'execution 2 (Valeurs triées inversement): %f \n", temps2);
    /*temps3 = tri_fusion(TT,N);
    printf("\nTemps d'execution 3 (Valeurs triées): %f \n", temps3);*/

    return 0;
}
