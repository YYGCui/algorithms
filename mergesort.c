#include <stdio.h>
#include <stdlib.h>

void mergesort(int *A, int start, int end, int n);
void merge(int *A, int start, int middle, int end);

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

    mergesort(A, 0, n-1, n);
}

void mergesort(int A[], int start, int end, int n)
{
    int middle;
    int i;
    static int j = 1;

    if(start < end)
    {
        middle = (start + end) / 2;
        mergesort(A, start, middle, n);
        mergesort(A, middle+1, end, n);
        merge(A, start, middle, end);

        printf("%d: ", j++);
        for(i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}

void merge(int A[], int start, int middle, int end)
{
    int *B = (int *)malloc(sizeof(int)*(end - start));

    int i,j,k = 0;
    i = start;
    j = middle+1;
    while(i <= middle)
    {
        if(j <= end)
        {
            if(A[i] <= A[j])
            {
                B[k++] = A[i++];
            }
            else
            {
                B[k++] = A[j++];
            }
        }
        else
        {
            B[k++] = A[i++];
        }
    }

    while(j <= end)
    {
        B[k++] = A[j++];
    }

    for(i = 0; i < k; i++)
    {
        A[start+i] = B[i];
    }

    free(B);
}
