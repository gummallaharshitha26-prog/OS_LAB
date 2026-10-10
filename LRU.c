#include <stdio.h>

int main()
{
    int pages[50], frames[10], recent[10];
    int n, f;
    int i, j, k;
    int found, pos;
    int pageFaults = 0;
    int time = 0;
    int least;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        recent[i] = 0;
    }

    printf("\nLRU Page Replacement\n");

    for(i = 0; i < n; i++)
    {
        found = 0;
        time++;

        /* Check whether page is present */
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                recent[j] = time;
                break;
            }
        }

        /* Page fault */
        if(found == 0)
        {
            pageFaults++;

            /* Find empty frame */
            pos = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* If no empty frame, find least recently used */
            if(pos == -1)
            {
                least = recent[0];
                pos = 0;

                for(j = 1; j < f; j++)
                {
                    if(recent[j] < least)
                    {
                        least = recent[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            recent[pos] = time;
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
