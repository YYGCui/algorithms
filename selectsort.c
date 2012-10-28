#include <stdio.h>
#include <stdlib.h>

void selectsort(int *A, int n);

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

    selectsort(A, n);
}

void selectsort(int A[], int n)
{
    int i,j,k;
    int key,tmp;
    for(i = n-1; i > 0; i--)
    {
        key = 0;
        for(j = 0; j <= i; j++)
        {
            if(A[key] < A[j])
            {
                key = j;
            }
        }

        tmp = A[key];
        A[key] = A[i];
        A[i] = tmp;

        printf("%d: ", n-i);
        for(k = 0; k < n; k++)
        {
            printf("%d ", A[k]);
        }
        printf("\n");
    }
}
