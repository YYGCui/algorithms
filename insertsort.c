#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;

    printf("Input the number of array:\n");
    scanf("%d", &n);

    int *A = (int *)malloc(sizeof(int)*n);
/*
    printf("Input the %d numbers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
*/
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

    insertsort(A, n);
}

