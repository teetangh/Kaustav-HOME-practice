#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }
// void maxHeapify(int *arr, int n, int i)
// {
//     int largest = i;
//     int l = (2 * i);
//     int r = (2 * i) + 1;

//     while (l <= n && arr[l] > arr[largest])
//         largest = l;
//     while (r <= n && arr[r] > arr[largest])
//         largest = r;

//     if (largest != i)
//     {
//         swap(&arr[largest], &arr[i]);
//         maxHeapify(arr, n, largest);
//     }
// }

int main()
{
    int n;

    printf("\nEnter size of array\n");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    printf("\nPlease enter array elements\n");
    for (int i = 1; i <= n; i++)
        scanf(" %d", &arr[i]);

    // maxHeapify(arr, n, 1);

    printf("\nThe array elements after maxHeapify are\n");
    for (int i = 1; i <= n; i++)
        printf(" %d", arr[i]);
}