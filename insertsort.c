/************************************
 * INSERTSORT(A)
 *   for j=2 to length[A]
 *     do key=A[j]
 *        j = j-1
 *        while i>0 and A[i]>key
 *          do A[i+1] = A[i]
 *             i = i-1
 *        A[i+1] = key
 * **********************************
 * worst-case running time: O(n^2)
 * **********************************/
#include <stdio.h>
#include <stdlib.h>

void insertsort(int *A, int n);

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

void insertsort(int A[], int n)
{
    int i,j,k;
    int key,tmp;
    for(i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }

        tmp = A[j+1];
        A[j+1] = key;
        key = tmp;

        printf("%d: ", i);
        for(k = 0; k < n; k++)
        {
            printf("%d ", A[k]);
        }
        printf("\n");
    }
}
