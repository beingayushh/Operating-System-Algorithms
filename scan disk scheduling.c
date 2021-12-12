#include <stdio.h>
int main()
{
    int i, j, sum = 0, n, pos, trc, d, lr = -1, sm = 10000;
    printf("Enter number of cylinders: ");
    scanf("%d", &n);
    printf("Enter position of head: ");
    scanf("%d", &pos);
    printf("Enter no of tracks: ");
    scanf("%d", &trc);

    int ar[trc];
    printf("Enter elements of disk queue: ");
    for (i = 0; i < trc; i++)
        scanf("%d", &ar[i]);

    printf("To move Left press '0' else '1': ");
    scanf("%d", &d);

    if (d == 0)
    {
        for (i = 0; i < trc; i++)
        {
            if (ar[i] > lr)
                lr = ar[i];
        }
        printf("Largest is %d", lr);
        sum = (pos - 1) + (lr - 1);
    }

    if (d == 1)
    {
        for (i = 0; i < trc; i++)
        {
            if (ar[i] < sm)
                sm = ar[i];
        }
        printf("smallest is %d", sm);
        sum = (n - 1 - pos) + (n - 1 - sm);
    }
    printf("\nTotal head moments: %d", sum);
    printf("\nAverage head moments: %.2f", (float)sum / trc);
    return 0;
}
