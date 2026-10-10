#include <stdio.h>

int main()
{
    int n, i;
    int at[20], bt[20], rt[20], priority[20];
    int ct[20], wt[20], tat[20];
    int completed = 0, current_time = 0;
    int highest, highest_priority;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time, Burst Time and Priority for each process:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);

        rt[i] = bt[i];
    }

    // Preemptive Priority Scheduling
    while (completed < n)
    {
        highest = -1;
        highest_priority = 9999;

        // Find highest priority process
        for (i = 0; i < n; i++)
        {
            if (at[i] <= current_time && rt[i] > 0)
            {
                if (priority[i] < highest_priority)
                {
                    highest_priority = priority[i];
                    highest = i;
                }
            }
        }

        // CPU is idle
        if (highest == -1)
        {
            current_time++;
            continue;
        }

        // Execute for one unit of time
        rt[highest]--;
        current_time++;

        // Process completed
        if (rt[highest] == 0)
        {
            completed++;

            ct[highest] = current_time;
            tat[highest] = ct[highest] - at[highest];
            wt[highest] = tat[highest] - bt[highest];

            avg_wt += wt[highest];
            avg_tat += tat[highest];
        }
    }

    // Display result
    printf("\n--------------------------------------------------------");
    printf("\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT");
    printf("\n--------------------------------------------------------");

    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t\t%d\t%d\t%d",
               i + 1,
               at[i],
               bt[i],
               priority[i],
               ct[i],
               wt[i],
               tat[i]);
    }

    printf("\n--------------------------------------------------------");

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
