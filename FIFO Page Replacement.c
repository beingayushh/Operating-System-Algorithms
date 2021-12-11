#include <stdio.h>
#include <conio.h>

int main()
{
    int a[50], b[50];
    int pages, frames, i, j, h, pf, temp, z;

    printf("Enter pages: ");
    scanf("%d", &pages);

    printf("Enter frames: ");
    scanf("%d", &frames);

    printf("Enter reference string: ");
    for (int i = 0; i < pages; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < frames; i++)
    {
        b[i] = -1;
    }

    i = 0;
    j = 0;
    h = 0;
    while (i < pages)
    {
        if (b[i] == -1 && i < frames)
        {
            b[i] = a[i];
            pf++;
        }
        else
        {
            z = 0;
            for (int j = 0; j < frames; j++)
            {
                if (a[i] == b[j])
                {
                    h++;
                }
                else
                {
                    z++;
                }
            }
            if (z == frames)
            {
                pf++;
                for (int j = 0; j < frames - 1; j++)
                {
                    temp = b[j];
                    b[j] = b[j + 1];
                    b[j + 1] = temp;
                }
                b[frames - 1] = a[i];
            }
        }
        i++;
    }
    printf("Page faults: %d\n", pf);
    printf("page hits: %d", h);
    printf("\nPage Fault ratio: %.2f", (float)pf / pages);
    printf("\nPage Hit ratio: %.2f", (float)h / pages);
}
