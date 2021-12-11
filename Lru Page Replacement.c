#include <stdio.h>

void lru(int string[20], int n, int size)
{
    int frames[n];

    for (int i = 0; i < n; i++)
        frames[i] = -1;

    int index = -1;

    int page_miss = 0;
    int page_hits = 0;

    for (int i = 0; i < size; i++)
    {
        int symbol = string[i];
        int flag = 0;

        int full = 0;

        for (int j = 0; j < n; j++)
        {
            if (symbol == frames[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            page_hits += 1;
        }
        else
        {

            if (full == 0)
            {
                index = (index + 1) % n;
                frames[index] = symbol;
                page_miss += 1;
            }

            else
            {

                int pos = 999;
                int index = -1;

                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < size; k++)
                    {
                        if (frames[j] == string[k])
                        {
                            if (pos > k)
                            {
                                pos = k;
                                index = j;
                                break;
                            }
                        }
                    }
                }

                frames[index] = symbol;
            }
        }
    }
    page_miss = page_miss-1;
    printf("\nPage hits: %d", page_hits);
    printf("\nPage faults: %d", page_miss);
    printf("\nPage fault ratio: %.2f",(float)page_miss/size);
    printf("\nPage hit ratio: %.2f",(float)page_hits/size);
}

int main(void)
{
    int pages,frames;
    printf("Enter Pages: ");
    scanf("%d",&pages);

    printf("Enter Frames: ");
    scanf("%d",&frames);

    int a[50];
    printf("Enter reference string: ");
    for(int i=0;i<pages;i++){
        scanf("%d",&a[i]);
    }
    lru(a, frames, pages);
}
