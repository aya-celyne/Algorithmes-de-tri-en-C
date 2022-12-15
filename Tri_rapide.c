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
    if (N > 1000)
    {
        for (i=0; i<N; i++)
        {
            printf("%d |",T[i]);
        }
    }else printf("<Tableau très grand>");
      
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

    if (N<=1000)
    {
        for (i=0; i<N; i++)
        {
            if (T_revers != 0) 
            {
                printf("%d |",T_revers[i]);
            }
        }
    }else printf("<Tableau très grand>");
    
}

typedef struct maillon maillon;
typedef maillon* Tptr;

typedef struct maillon
{
    int val;
    maillon* adr;
};

typedef maillon* TypePile;

void LibererP (Tptr p)
{
    free(p);
}

void Aff_val(Tptr p, int v)
{
    p->val = v;
}

void Aff_adr(Tptr p, Tptr q)
{
    p->adr = q;
}

int Valeur (Tptr p)
{
    return p->val;
}

Tptr Suivant (Tptr p)
{
    return p->adr;
}

Tptr Allouer(Tptr* p)
{
    *p = (Tptr)malloc(sizeof(maillon));
}

void CreerPile(TypePile* P)
{
    *P = NULL;
}

int PileVide(TypePile P)
{
    return (P == NULL);
}

void Empiler(TypePile* P, int val)
{
    Tptr Q;

    Allouer(&Q);
    Aff_val(Q, val);
    Aff_adr (Q, *P);
    *P = Q;
}

void Depiler (TypePile* P, int* val)
{
    Tptr Sauv;

    if (!PileVide(*P))
    {
        Sauv = *P;
        *val = Valeur(*P);
        *P = Suivant (*P);
        LibererP(Sauv);
    }
    else
        printf("\nERREUR: Pile vide !\n");
}

void AffichPile (TypePile P)
{
    Tptr Q;

    if (!PileVide(P))
    {
        Q = P;
        printf(" -----\n");
        while (Q != NULL)
        {
            printf("| %3d |\n", Valeur(Q));
            Q = Suivant(Q);
        }
        printf(" -----\n");
    }
    else
        printf("\nPile vide !\n");
}

void permut (int* p_pivot , int* Bsup)
    {
        int tmp;
        tmp=*p_pivot;
        *p_pivot=*Bsup;
        *Bsup=tmp;
    }

double Tri_rapide (int T[], int N)
{
    double temps;
    clock_t start, stop;
    int Binf,Bsup,i,pivot,p_pivot;
    TypePile P;
    start = clock();
    CreerPile (&P);
    Empiler(&P,0);
    Empiler (&P,N-1);

    while (!PileVide(P))
    {
        Depiler (&P, &Bsup);
        Depiler (&P, &Binf);
        pivot=T[Bsup];
        p_pivot=Binf;
        for (i=Binf; i<=Bsup-1; i++)
        {
            if (T[i]<=pivot)
            {
                permut(&T[i],&T[p_pivot]);
                p_pivot++;
            }
        }
        permut(&T[p_pivot], &T[Bsup]);
        if (p_pivot+1 <Bsup)
        {
            Empiler(&P,p_pivot+1);
            Empiler(&P,Bsup);
        }
        if (p_pivot-1>Binf)
        {
            Empiler(&P,Binf);
            Empiler(&P,p_pivot-1);

        }
    }
    stop = clock();
    temps=(double)(stop-start)/CLOCKS_PER_SEC;

    return temps;
}

int main()
{
    int N,i,j;
    double temps,temps2,temps3;
    clock_t start, stop,startT,stopT;   
    srand(time(NULL));
    printf("DONNEZ UNE TAILLE POUR LE TABLEAU QUE VOUS VOULEZ TRIER:");
    scanf("%d", &N);
    printf("\n");
    int * T= (int*)malloc(N*sizeof(int));
    int * Tr= (int*)malloc(N*sizeof(int));
    int * TT= (int*)malloc(N*sizeof(int));
    Gen_Tab(T,N);
    printf("finished \n");
    temps=Tri_rapide(T,N);
    printf("finished \n");
    for (i = N-1, j=0; i >= 0; i--, j++) 
        Tr[j] = T[i];
    /*for(i=0; i<N; i++) 
        TT[i] = T[i];*/

    //printf("Temps d'execution 1 (Valeurs Aléatoires): %f \n", temps);
    temps2= Tri_rapide(Tr,N);
    printf("\nTemps d'execution 2 (Valeurs triées inversement): %f \n", temps2);
    /*temps3=Tri_rapide(TT,N);
    printf("\nTemps d'execution 3 (Valeurs triées): %f \n\n", temps3);*/

    return 0;
}
