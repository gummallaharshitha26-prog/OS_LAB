#include <stdio.h>

int main()
{
    int indexBlock;
    int blocks[20];
    int n, i;

    printf("         INDEXED FILE ALLOCATION\n");
    printf("=====================================\n");

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("\nIndex Block = %d\n", indexBlock);

    printf("Blocks allocated through index block:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", blocks[i]);
    }

    printf("\n");

    return 0;
}
