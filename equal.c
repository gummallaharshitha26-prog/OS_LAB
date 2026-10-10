#include <stdio.h>

int main()
{
    int n, totalFrames;
    int framesPerProcess, remaining;
    int i;

    printf("=====================================\n");
    printf("          EQUAL ALLOCATION\n");
    printf("=====================================\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    framesPerProcess = totalFrames / n;
    remaining = totalFrames % n;

    printf("\nFrame Allocation:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d -> %d frames\n", i + 1, framesPerProcess);
    }

    printf("Frames Remaining = %d\n", remaining);

    return 0;
}
