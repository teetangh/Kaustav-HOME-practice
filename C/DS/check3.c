#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    struct student
    {
        int *regno;
        char *name[20];
        float *cgpa;
    } s1[20], s2, *s3;

    int reg = 20;
    s1->regno = &reg;

    strcpy(s2.name, "ABCD");

    s3 = (struct student *)malloc(sizeof(struct student));
    s3->regno = &reg;

    printf("%d\n",*s1->regno);
    printf("%s\n",s2.name);
    printf("%d\n",s3->regno);

}