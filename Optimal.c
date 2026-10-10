#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f;
    int i, j, k;
    int found, pos;
    int pageFaults = 0;
    int farthest, nextUse;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        /* Check whether page is present */
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
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

            /* If all frames are full */
            if(pos == -1)
            {
                farthest = -1;

                for(j = 0; j < f; j++)
                {
                    nextUse = n + 1;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            nextUse = k;
                            break;
                        }
                    }

                    if(nextUse > farthest)
                    {
                        farthest = nextUse;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
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
