#include <stdio.h>

void main()
{
    struct sample
    {
        char name[7],*str;
    };
    struct sample s1 = {"Udupiaa", "Manipal"};
    printf("%c", *s1.str-1);
}