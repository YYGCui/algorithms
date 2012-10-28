#include <stdio.h>
#include <stdlib.h>

void heapsort(int *A, int n);
void buildheap(int *A, int n);
void max_heapify(int *A, int n, int r);

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

    heapsort(A, n);
}

void heapsort(int A[], int n)
{
    int i, j, heapsize = n;
    int tmp;
    buildheap(A, n);

    printf("X: ");
    for(j = 0; j < n; j++)
    {
        printf("%d ", A[j]);
    }
    printf("\n");
    for(i = n-1; i > 0; i--)
    {
        tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        heapsize--;
        max_heapify(A, heapsize, 0);
        printf("%d: ", n-i);
        for(j = 0; j < n; j++)
        {
            printf("%d ", A[j]);
        }
        printf("\n");
    }
}

void buildheap(int A[], int n)
{
    int i;
    for(i = (n-1)/2; i > 0; i--)
    {
        max_heapify(A, n, i);
    }
}

void max_heapify(int A[], int n, int i)
{
    int left = 2*(i+1)-1;
    int right = 2*(i+1);
    int largest = i;
    int tmp;

    if(left < n && A[left] > A[largest])
    {
        largest = left;
    }
    if(right < n && A[right] > A[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;

        max_heapify(A, n, largest);
    }
}
