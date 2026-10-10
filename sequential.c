#include <stdio.h>

int main()
{
    int start, length;
    int i;
    printf("       SEQUENTIAL FILE ALLOCATION\n");
    printf("=====================================\n");

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks: ");
    scanf("%d", &length);

    printf("\nAllocated Blocks:\n");

    for(i = 0; i < length; i++)
    {
        printf("%d ", start + i);
    }

    printf("\n");

    return 0;
}
