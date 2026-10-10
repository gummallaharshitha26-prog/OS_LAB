#include <stdio.h>

int main()
{
    int blocks[20];
    int n, i;

    printf("          LINKED FILE ALLOCATION\n");
    printf("=====================================\n");

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("\nLinked Allocation:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d", blocks[i]);

        if(i < n - 1)
            printf(" -> ");
        else
            printf(" -> NULL");
    }

    printf("\n");

    return 0;
}
