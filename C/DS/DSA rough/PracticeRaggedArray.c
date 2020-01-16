//Ragged Array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rowNum, colNum, i, j;
    int **table;
    printf("\n enter the number of the  rows");
    scanf("%d", &rowNum);
    table = (int **)calloc(rowNum + 1, sizeof(int *));

    for (i = 0; i < rowNum; i++)
    {
        printf("Enter size of the %d row \n", i + 1);
        scanf("%d", &colNum);
        table[i] = (int *)calloc(colNum + 1, sizeof(int));
        printf("\n enter the %d row elements \t ", i + 1);

        for (j = 1; j <= colNum; j++)
        {
            scanf("%d", &table[i][j]);
            /* code */
        }

        table[i][0] = colNum;
        printf("size of row number [%d]=%d \n", i + 1, table[i][0]);

        /* code */
    }

    table[i] = NULL;

    for (i = 0; i < rowNum; i++)
    {
        printf("Displaying %d row elements \n", i + 1);
        for (j = 0; j < *table[i]; j++)
        {
            printf("%5d", table[i][j]);
            /* code */
        }
        printf("\n");
        /* code */
    }

    //free up the memory
    for (i = 0; i < rowNum; i++)
    {
        free(table[i]);
        /* code */
    }

    free(table);
    return 0;
}