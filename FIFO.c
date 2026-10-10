#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f;
    int i, j, k;
    int pointer = 0;
    int pageFaults = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            frames[pointer] = pages[i];
            pointer = (pointer + 1) % f;
            pageFaults++;
        }

        printf("%d : ", pages[i]);

        for(k = 0; k < f; k++)
        {
            if(frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }

        if(found == 0)
            printf("Page Fault");
        else
            printf("Hit");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
