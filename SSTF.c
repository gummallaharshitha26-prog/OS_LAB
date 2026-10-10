#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head;
    int request[50], visited[50];
    int i, count, index, distance;
    int minDistance;
    int totalMovement = 0;

    printf("=====================================\n");
    printf("       DISK SCHEDULING - SSTF\n");
    printf("=====================================\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(count = 0; count < n; count++)
    {
        minDistance = 99999;
        index = -1;

        /* Find nearest unvisited request */
        for(i = 0; i < n; i++)
        {
            if(visited[i] == 0)
            {
                distance = abs(head - request[i]);

                if(distance < minDistance)
                {
                    minDistance = distance;
                    index = i;
                }
            }
        }

        /* Service the nearest request */
        visited[index] = 1;
        totalMovement += minDistance;
        head = request[index];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}
