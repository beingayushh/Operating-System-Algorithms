#include <stdio.h>
int main()
{
    int i, j, sum = 0, n, pos, trc, d, lr = -1, sm = 10000;
    printf("Enter number of cylinders: ");
    scanf("%d", &n);
    printf("Enter position of head: ");
    scanf("%d", &pos);
    printf("Enter the no of tracks you want to traverse: ");
    scanf("%d", &trc);

    int ar[trc];
    printf("Enter elements of disk queue: ");
    for (i = 0; i < trc; i++)
        scanf("%d", &ar[i]);

    printf("To move Left press '0' else '1'\n");
    scanf("%d", &d);

    if (d == 0)
    {
        for (i = 0; i < trc; i++)
        {
            if (ar[i] > lr)
                lr = ar[i];
        }
        for (i = 0; i < trc; i++)
        {
            if (ar[i] < sm)
                sm = ar[i];
        }
        printf("Largest is %d", lr);
        printf("smallest is %d", sm);
        sum = (pos - sm) + (lr - sm);
    }
    if (d == 1)
    {
        for (i = 0; i < trc; i++)
        {
            if (ar[i] < sm)
                sm = ar[i];
        }
        for (i = 0; i < trc; i++)
        {
            if (ar[i] > lr)
                lr = ar[i];
        }
        printf("smallest is %d", sm);
        printf("\nLargest is %d", lr);
        sum = (lr - pos) + (lr - sm);
    }
    printf("\nTotal head moment: %d", sum);
    printf("\nAvearge head moment: %.2f",(float)sum/trc);
    return 0;
}
