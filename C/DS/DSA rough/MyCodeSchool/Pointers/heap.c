#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("Enter the size of the array \n");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\t \n");
    //free(A);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\t \n");
    int *B = (int *)realloc(A, (2 * n));
    for (int i = 0; i < 2 * n; i++)
    {
        printf("%d ", B[i]);
    }
}