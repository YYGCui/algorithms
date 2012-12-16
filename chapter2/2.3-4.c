/************************************
 * INSERTSORT(A, n)
 *   if n > 0
 *     do INSERTSORT(A, n-1)
 *        INSERT(A, n)
 * ***
 * INSERT(A, n)
 *   key = A[n-1]
 *   i = n - 2
 *   while i>0 and A[i]>key
 *          do A[i+1] = A[i]
 *             i = i-1
 *   A[i+1] = key
 * **********************************
 * worst-case running time: O(n^2)
 * **********************************/
#include <stdio.h>
#include <stdlib.h>

void insertsort(int *A, int n);
void insert(int A[], int n);
int bits;

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
    bits = 1;
    i = n;
    while (i / 10 > 0)
    {
        i /= 10;
        bits++;
    }
    printf("%.*d: ", bits, 0);
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    insertsort(A, n);
}

void insertsort(int A[], int n)
{
    if(n > 0)
    {
        insertsort(A, n-1);
        insert(A, n);
    }
}

void insert(int A[], int n)
{
    int i = n-2;
    int an=A[n-1];

    while(i >= 0 && A[i] > an)
    {
        A[i+1] = A[i];
        i--;
    }

    A[i+1] = an;
    printf("%.*d: ", bits, n);
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
