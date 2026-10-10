#include <stdio.h>

int main()
{
    int pages, pageSize;
    int pageTable[20];
    int logicalAddress;
    int pageNumber, offset;
    int physicalAddress;
    int i;

    printf("=====================================\n");
    printf("       PAGING MEMORY MANAGEMENT\n");
    printf("=====================================\n");

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("\nEnter Page Table:\n");

    for(i = 0; i < pages; i++)
    {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("\nEnter Logical Address: ");
    scanf("%d", &logicalAddress);

    /* Calculate page number and offset */
    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    if(pageNumber >= pages)
    {
        printf("\nInvalid Logical Address!\n");
    }
    else
    {
        physicalAddress = pageTable[pageNumber] * pageSize + offset;

        printf("\nPage Number       : %d", pageNumber);
        printf("\nOffset            : %d", offset);
        printf("\nFrame Number      : %d", pageTable[pageNumber]);
        printf("\nPhysical Address  : %d\n", physicalAddress);
    }

    printf("=====================================\n");

    return 0;
}
