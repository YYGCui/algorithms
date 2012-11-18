/********************************
 * sum two binary number A and B
 * ******************************
 * running time: O(n)
 * *****************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    int sum,flag = 0;

    printf("input the size of array A/B: ");

    do
    {
        scanf("%d", &n);
    }
    while (n < 1 && printf("size should big than 1, input again: ") != -1);

    char *A = (char *)malloc(sizeof(char) * n);
    char *B = (char *)malloc(sizeof(char) * n);
    char *C = (char *)malloc(sizeof(char) * (n+1));

    for(i = 0; i < n; i++)
    {
        A[i] = rand() % 2;
        B[i] = rand() % 2;
    }

    printf("binary A:    ");
    for (i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");

    printf("binary B:    ");
    for (i = 0; i < n; i++)
    {
        printf("%d", B[i]);
    }
    printf("\n");

    for (i = n - 1; i >= 0; i--)
    {
        sum = A[i] + B[i] + flag;
        C[i+1] = sum % 2;
        flag = (sum > 1) ? 1 : 0;
    }
    C[0] = flag;

    printf("binary A+B: ");
    for (i = 0; i <= n; i++)
    {
        printf("%d", C[i]);
    }
    printf("\n");

    return 0;
}
