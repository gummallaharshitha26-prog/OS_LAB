#include <stdio.h>

int main()
{
    int n, totalFrames;
    int minFrames[20];
    int i, sum = 0;

    printf("=====================================\n");
    printf("   MINIMUM NUMBER OF FRAMES\n");
    printf("=====================================\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    printf("Enter minimum frames required by each process:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &minFrames[i]);
        sum += minFrames[i];
    }

    if(sum > totalFrames)
    {
        printf("\nAllocation Not Possible!\n");
    }
    else
    {
        printf("\nFrame Allocation:\n");

        for(i = 0; i < n; i++)
        {
            printf("P%d -> %d frames\n", i + 1, minFrames[i]);
        }

        printf("Frames Used = %d\n", sum);
        printf("Frames Remaining = %d\n", totalFrames - sum);
    }

    return 0;
}
