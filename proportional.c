#include <stdio.h>

int main()
{
    int n, totalFrames;
    int size[20], allocation[20];
    int i, totalSize = 0;
    int allocated = 0;

    printf("=====================================\n");
    printf("      PROPORTIONAL ALLOCATION\n");
    printf("=====================================\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    printf("Enter size of each process:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &size[i]);
        totalSize += size[i];
    }

    printf("\nFrame Allocation:\n");

    for(i = 0; i < n; i++)
    {
        allocation[i] =
            (size[i] * totalFrames) / totalSize;

        allocated += allocation[i];

        printf("P%d -> %d frames\n",
               i + 1, allocation[i]);
    }

    printf("Frames Allocated = %d\n", allocated);
    printf("Frames Remaining = %d\n",
           totalFrames - allocated);

    return 0;
}
