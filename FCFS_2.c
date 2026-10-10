#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, i;
    int requests[50];
    int totalMovement = 0;

    printf("=====================================\n");
    printf("      DISK SCHEDULING - FCFS\n");
    printf("=====================================\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(i = 0; i < n; i++)
    {
        totalMovement += abs(head - requests[i]);
        head = requests[i];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}
