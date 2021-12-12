#include <stdio.h>
#include <conio.h>

int findmax(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, at[20], bt[20], ct[20], wt[20], ta[20], rt[20], st[20], idle_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter burst time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[i] > at[j + 1])
            {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
            }
        }
    }

    float sum, tat = 0.0, twt = 0.0, cpu_utilization = 0, length_cycle = 0;

    for (int i = 0; i < n; i++)
    {
        sum += bt[i];
        ct[i] = sum;

        ta[i] = ct[i] - at[i];
        wt[i] = ta[i] - bt[i];
        rt[i] = wt[i];

        tat += ta[i];
        twt += wt[i];

        st[i] = (i == 0) ? at[i] : findmax(at[i], ct[i - 1]);
        idle_time += (i == 0) ? 0 : (st[i] - ct[i - 1]);
    }

    length_cycle = ct[n - 1] - st[0];
    cpu_utilization = (float)(length_cycle - idle_time) / (length_cycle);

    printf("\nAverage Turnaround Time: %.2f", tat / (float)n);
    printf("\nAverage Watitng Time: %.2f", twt / (float)n);
    printf("\nAverage Response Time: %.2f", twt / (float)n);
    printf("\nThroughput: %f", (float)n / length_cycle);
    printf("\nCPU utilization: %f", cpu_utilization * 100);
}
