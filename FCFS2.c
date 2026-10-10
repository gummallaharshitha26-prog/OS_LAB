#include <stdio.h>

int main()
{
    int n, i, j;
    int pid[20], at[20], bt[20], ct[20], wt[20], tat[20];
    int temp;
    float avg_wt = 0, avg_tat = 0;
    int current_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nEnter Arrival Time for P%d: ", pid[i]);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Sort according to Arrival Time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate CT, WT and TAT
    for (i = 0; i < n; i++)
    {
        if (current_time < at[i])
        {
            current_time = at[i];
        }

        current_time = current_time + bt[i];

        ct[i] = current_time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }

    // Display results
    printf("\n--------------------------------------------------");
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT");
    printf("\n--------------------------------------------------");

    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n--------------------------------------------------");
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
