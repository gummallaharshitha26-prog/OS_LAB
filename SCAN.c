#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, diskSize, direction;
    int request[50];
    int i, j, temp;
    int totalMovement = 0;

    printf("=====================================\n");
    printf("       DISK SCHEDULING - SCAN\n");
    printf("=====================================\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &diskSize);

    printf("Enter direction (1 = Right, 0 = Left): ");
    scanf("%d", &direction);

    /* Sort requests in ascending order */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nSeek Sequence: %d", head);

    if(direction == 1)
    {
        /* Move towards right */
        for(i = 0; i < n; i++)
        {
            if(request[i] >= head)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }

        /* Move to end of disk */
        if(head != diskSize - 1)
        {
            totalMovement += abs(head - (diskSize - 1));
            head = diskSize - 1;

            printf(" -> %d", head);
        }

        /* Reverse direction */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] < head)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }
    }
    else
    {
        /* Move towards left */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] <= head)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }

        /* Move to beginning of disk */
        if(head != 0)
        {
            totalMovement += head;
            head = 0;

            printf(" -> %d", head);
        }

        /* Reverse direction */
        for(i = 0; i < n; i++)
        {
            if(request[i] > head)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}
