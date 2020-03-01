#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    swap(&arr[3], &arr[4]);

    printf("\nThe array elements after bubble sorting are\n");
    for (int i = 0; i < 6; i++)
        printf(" %d", arr[i]);
}