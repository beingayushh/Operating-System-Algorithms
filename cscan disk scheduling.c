#include <stdio.h>

int main()
{
    int sum = 0, n, pos, trc, d, lr = -1, sm = 10000, ind = 0;
    printf("Enter number of tracks: ");
    scanf("%d", &n);
    printf("Enter position of head: ");
    scanf("%d", &pos);
    printf("Enter the no of tracks you want to traverse: ");
    scanf("%d", &trc);

    int ar[trc];
    printf("Enter elements of disk queue: ");
    for (int i = 0; i < trc; i++)
        scanf("%d", &ar[i]);

    for (int i = 0; i < trc - 1; i++)
    {
        for (int j = 0; j < trc - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < trc; i++)
    {
        if (ar[i] > pos)
        {
            ind = i;
            break;
        }
    }

    printf("To move Left press '0' else '1'\n");
    scanf("%d", &d);

    if (d == 0)
    {
        sum = (n - 1) + (pos) + (n - ar[ind] - 1);
    }

    if (d == 1)
    {
        sum = (n - 1) + (n - pos - 1) + ar[ind - 1];
    }

    printf("\nTotal head moment: %d", sum);
    printf("\nAverage head moment: %.2f", (float)sum / trc);

    return 0;
}
