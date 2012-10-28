#include <stdio.h>
#include <stdlib.h>

void quicksort(int *A, int start, int end, int num);
int partation(int *A, int start, int end, int num);

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

    quicksort(A, 0, n, n);
}

void quicksort(int A[], int start, int end, int n)
{
    int i;
    int part;

    if(start < end)
    {
        part = partation(A, start, end, n);
        quicksort(A, start, part, n);
        quicksort(A, part+1, end, n);
    }

}
    
int partation(int A[], int start, int end, int n)
{
    int key = A[end-1];
    int i, j = start-1;
    int tmp;
    static int k = 1;

    for(i = start; i < end-1; i++)
    {
        if(A[i] <= key)
        {
            j++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[++j];
    A[j] = A[end-1];
    A[end-1] = tmp;

    printf("%d: ",k++);
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return j;
}
