#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int shortest, min;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    // SRTF Scheduling
    while(completed < n)
    {
        shortest = -1;
        min = 9999;

        // Find process with shortest remaining time
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                shortest = i;
            }
        }

        // If no process has arrived
        if(shortest == -1)
        {
            time++;
            continue;
        }

        // Execute selected process for 1 unit
        rt[shortest]--;
        time++;

        // Check if process is completed
        if(rt[shortest] == 0)
        {
            completed++;

            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            avgWT += wt[shortest];
            avgTAT += tat[shortest];
        }
    }

    // Display results
    printf("\n-----------------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-----------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    printf("-----------------------------------------------------\n");
    printf("Average Waiting Time = %.2f\n", avgWT / n);
    printf("Average Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
