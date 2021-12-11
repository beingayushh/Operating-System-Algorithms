#include <stdio.h>
#include<conio.h>

int main()
{
    int queue[100], q_size, head, seek = 0, diff;
    float avg;


    printf("Enter the cylinder no. in request queue: ");
    scanf("%d", &q_size);

    printf("Enter queue elements: ");
    for (int i = 1; i <= q_size; i++)
    {
        scanf("%d", &queue[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    queue[0] = head;

    for (int j = 0; j <= q_size - 1; j++)
    {
        diff = abs(queue[j] - queue[j + 1]);
        seek += diff;
    }

    printf("\nTotal head moments: %d", seek);
    avg = seek / (float)q_size;
    printf("\nAverage head moment: %.2f", avg);

    return 0;
}
