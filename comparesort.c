#include <stdio.h>
#include <stdlib.h>
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
/****************************************
 * BUBBLESORT(A)
 *  for i = 1 to length[A]
 *    do for j = length[A] downto i+1
 *      do if A[j] < A[j-1]
 *        then exchange A[j] <-> A[j-1]
 ****************************************        
 * worst-case running time: O(n^2)
 * **************************************/
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
/******************************************
 * SELECTSORT(A)
 *   for i = length(A) downto 1
 *     do for j = 0 to i
 *       do if A[key] < A[j]
 *         key = j
 *     exchange A[key] <-> A[j]
 * ****************************************
 * worst running time: O(n^2)
 * ****************************************/
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
/************************************
 * MERGESORT(A,p,r)
 *   if p<r
 *     then q = (p+r)/2
 *     MERGESORT(A,p,q)
 *     MERGESORT(A,q+1,r)
 *     MERGE(A,p,q,r)
 *
 * MERGE(a,p,q,r)
 *   j = q+1
 *   for i=p to q
 *     do if j < r
 *        then if A[i] <= A[j]
 *               B[k++] = A[i++]
 *             else
 *               B[k++] = A[j++]
 *        else
 *          B[k++] = A[i++]
 *   while j < r
 *     do B[k++] = A[j++]
 * **********************************
 * running time: O(nlgn)
 * **********************************/
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
/*****************************************
 * QUICKSORT(A,p,r)
 *   if p<r
 *     then q = PARTITION(A,p,r)
 *          QUICKSORT(A,p,q-1)
 *          QUICKSORT(A,q+1,r)
 * PARTITION(A,p,r)
 *   x=A[r]
 *   i=p-1
 *   for j=p to r-1
 *     do if A[j] <= x
 *           i = i+1
 *           exchange A[i] <-> A[j]
 *  exchange A[i+1] <-> A[r]
 *  return i+1
 * ***************************************
 * best-case  running time: O(nlgn)
 * worst-case running time: O(n^2)
 * ***************************************/
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
/***********************************************
 * MAX_HEAPIFY(A, i)
 *   l = LEFT(i)
 *   r = RIGHT(i)
 *   if l <= length(A) and A[l] > A[i]
 *     then largest = l
 *   if r <= length(A) and A[r] > A[largest]
 *     then largest = r
 *   if largest != i
 *     then exchange A[i] <-> A[largest]
 *          MAX_HEAPIFY(A, largest)
 * ***
 * BUILD_MAX_HEAP(A)
 *   heapsize = length(A)
 *   for i = length(A)/2 downto 1
 *     do MAX_HEAPIFY(A, i)
 * ***
 * HEAP_SORT(A)
 *   BUILD_MAX_HEAP(A)
 *   for i = length(A) downto 1
 *     do exchange A[0] <-> A[i]
 *        heapsize--;
 *        MAX_HEAPIFY(A, 0)
 * *********************************************
 * worst running time: O(nlogn)
 * *********************************************/
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
void buildheap(int A[], int n)
{
    int i;
    for(i = (n-1)/2; i > 0; i--)
    {
        max_heapify(A, n, i);
    }
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
