#include <stdio.h>
#include <stdlib.h>
#include "../algorithms.h"

int binarysearch(int A[], int p, int q, int x)
{
    int n,res = 0;
    while(p < q)
    {
        n = (p+q)/2;
        if(x < A[n])
        {
            q = n;
        }
        else if(x > A[n])
        {
            p = n+1;
        }
        else
        {
            res = 1;
            break;
        }
    }
    return res;
}
void searchadds(int A[], int n, int x)
{
    int i;
    int x1,x2;

    for(i = 1; i < n; i++)
    {
        x1 = A[i-1];
        if(x1 < x)
        {
            x2=x-x1;
            if(binarysearch(A, i, n-1, x2) == 1)
            {
                printf("find: %d = %d + %d\n", x, x1, x2);
            }
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int n,x;
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

    mergesort(A, 0, n-1, n);
    printf("Input the number for search:\n");
    scanf("%d", &x);
    searchadds(A, n, x);
}

