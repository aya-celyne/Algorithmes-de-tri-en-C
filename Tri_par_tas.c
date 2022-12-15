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

void swap(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
void retablir_tas(int arr[], int n, int i) 
  {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      retablir_tas(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
double faireTas(int arr[], int n) 
  {
    double temps;
    clock_t start, stop;
    start = clock();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      retablir_tas(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      retablir_tas(arr, i, 0);
    }
    stop =clock();
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
    /*tableau trié inversement*/
    int * Tr= (int*)malloc(N*sizeof(int));
    /*tableau trié*/
    int * TT= (int*)malloc(N*sizeof(int));
    Gen_Tab(T,N);
    temps = faireTas(T,N);
    printf("Temps d'execution 1 (Valeurs Aléatoires): %f \n", temps);
    for (i = N-1, j=0; i >= 0; i--, j++)
    Tr[j] = T[i];
    for(i=0; i<N; i++) TT[i] = T[i];
    temps = faireTas(Tr,N);
    printf("\nTemps d'execution 2 (Valeurs triées inversement): %f \n", temps);
    temps=faireTas(T,N);
    printf("\nTemps d'execution 3 (Valeurs triées): %f", temps);
    printf("\n\n");
    return 0;
}
