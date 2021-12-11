#include <stdio.h>
#include <conio.h>

struct bankers
{
    int allocated[30];
    int max[30];
    int need[30];
};

int main()
{
    int n, m;
    printf("Enter number of process: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    struct bankers process[n];
    int avaliable[30];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Process[%d]\n", i);
        printf("Enter allocated: ");
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &process[i].allocated[j]);
        }
        printf("Enter maximum: ");
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &process[i].max[j]);
            process[i].need[j] = process[i].max[j] - process[i].allocated[j];
        }
    }

    printf("Enter Avaliable:");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avaliable[i]);
    }

    int p, y, z, result = 0, c = 0, arr[100], index = 0;

    p = 1;
    y = 0;
    while (p != 0)
    {
        for (int i = 0; i < n; i++)
        {
            z = 0;
            for (int j = 0; j < m; j++)
            {
                if (process[i].need[j] <= avaliable[j] && process[i].need[0] != -1)
                {
                    z++;
                }
            }
            if (z == m)
            {
                for (int j = 0; j < m; j++)
                {
                    avaliable[j] += process[i].allocated[j];
                }
                y++;
                result = 1;
                process[i].need[0] = -1;
                arr[index] = i;
                index++;
                c++;
            }
        }
        if (y == n)
        {
            p = 0;
            printf("System is in safe state\n");
            for (int k = 0; k < c; k++)
            {
                printf("p%d->", arr[k]);
            }
        }
        if (result == 0)
        {
            printf("Not in safe state");
            break;
        }
    }
}
