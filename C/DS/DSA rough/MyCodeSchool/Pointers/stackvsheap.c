#include <stdio.h>

int q = 100;
int Square(int x)
{
    printf("%d \t \n", q);
    return x * x;
}

int SquareOfSum(int x, int y)
{
    int z = Square(x + y);
    return z;
}

int main()
{
    int a = 4, b = 8;

    int total = SquareOfSum(a, b);
    printf("output = %d", total);
}
