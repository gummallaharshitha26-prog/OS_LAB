#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, direction;
    int request[50];
    int i, j, temp;
    int totalMovement = 0;
    int index;

    printf("=====================================\n");
    printf("      DISK SCHEDULING - C-LOOK\n");
    printf("=====================================\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

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
        /* Find first request >= head */
        index = 0;

        while(index < n && request[index] < head)
        {
            index++;
        }

        /* Service requests towards right */
        for(i = index; i < n; i++)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];

            printf(" -> %d", head);
        }

        /*
         * Jump directly to the smallest request.
         * No disk end is visited.
         */
        if(index > 0)
        {
            totalMovement += abs(head - request[0]);
            head = request[0];

            printf(" -> %d", head);

            /* Service remaining requests */
            for(i = 1; i < index; i++)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }
    }
    else
    {
        /* Find last request <= head */
        index = n - 1;

        while(index >= 0 && request[index] > head)
        {
            index--;
        }

        /* Service requests towards left */
        for(i = index; i >= 0; i--)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];

            printf(" -> %d", head);
        }

        /*
         * Jump directly to the largest request.
         * No disk beginning is visited.
         */
        if(index < n - 1)
        {
            totalMovement += abs(head - request[n - 1]);
            head = request[n - 1];

            printf(" -> %d", head);

            /* Service remaining requests */
            for(i = n - 2; i > index; i--)
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
