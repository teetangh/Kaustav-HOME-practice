#include <stdio.h>

char *ptr[] = {"DSisEasy", "SOweLIKE", "NOT", "YEs"};
char **ptr1[] = {ptr + 3, ptr + 2, ptr + 1, ptr};
char ***ptr2 = ptr1;
void main()
{
    printf("%s\t", **ptr2);
    printf("%s\t", **++ptr2);
    printf("%s\t", *--*ptr2 );
    printf("%s\t", *--*++ptr2 );
}