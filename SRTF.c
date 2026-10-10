#include <stdio.h>

int main()
{
    int n, i;
    int at[20], bt[20], rt[20];
    int ct[20], wt[20], tat[20];
    int completed = 0;
    int current_time = 0;
    int shortest;
    int min_rt;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time and Burst Time
    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];   // Remaining time
    }

    // SRTF Scheduling
    while (completed != n)
    {
        shortest = -1;
        min_rt = 9999;

        // Find process with shortest remaining time
        for (i = 0; i < n; i++)
        {
            if (at[i] <= current_time && rt[i] > 0)
            {
                if (rt[i] < min_rt)
                {
                    min_rt = rt[i];
                    shortest = i;
                }
            }
        }

        // If no process has arrived
        if (shortest == -1)
        {
            current_time++;
            continue;
        }

        // Execute selected process for 1 unit
        rt[shortest]--;
        current_time++;

        // Process completed
        if (rt[shortest] == 0)
        {
            completed++;

            ct[shortest] = current_time;

            tat[shortest] = ct[shortest] - at[shortest];

            wt[shortest] = tat[shortest] - bt[shortest];

            avg_wt += wt[shortest];
            avg_tat += tat[shortest];
        }
    }

    // Display results
    printf("\n--------------------------------------------------");
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT");
    printf("\n--------------------------------------------------");

    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               wt[i],
               tat[i]);
    }

    printf("\n--------------------------------------------------");

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
