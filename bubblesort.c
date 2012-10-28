#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *A, int n);

int main()
{
    int n;
    int i;

    printf("Input the number of array:\n");
    scanf("%d", &n);

    int *A = (int *)malloc(sizeof(int)*n);
    srand(n);
    for(i = 0; i < n; i++)
    {
        A[i] = rand()%100;
    }
    printf("0: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    bubblesort(A, n);
}

void bubblesort(int A[], int n)
{
    int i,j,k;
    int key,tmp;
    for(i = 0; i < n; i++)
    {
        for(j = n-1; j > i; j--)
        {
            if(A[j] < A[j-1])
            {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
        printf("%d: ", i);
        for(k = 0; k < n; k++)
        {
            printf("%d ", A[k]);
        }
        printf("\n");
    }
}
