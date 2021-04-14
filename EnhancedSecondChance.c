#include <stdio.h>
struct map {
    int schance, sChanceModify;
};

int findPage(int s[], int frames, int page) {
    for (int i = 0; i < frames; i++) {
        if (s[i] == page) {
            return 1;
        }
    }
    return 0;
}

int pageFaults(int pages[], int modify[], int n, int frames)
{
    int s[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, ctr = 0;
    struct map second_chance[10];
    int page_faults = 0;

    for (int i = 0; i < 10; i ++) {
        second_chance[i].schance = 10000;
        second_chance[i].sChanceModify = 10000;
    }

    for (int i = 0; i < frames; i++)
    {
        if (!findPage(s, frames, pages[i]))
        {
            s[i] = pages[i];
            page_faults++;
            second_chance[pages[i]].schance = 0;
        }
        else
        {
            second_chance[pages[i]].schance = 1;
        }

        second_chance[pages[i]].sChanceModify = modify[i];
        for (int j = 0; j < frames; j++) {
            printf("%d \t", s[j]);
        }
        printf("\n");
    }

    for (int i = frames + 1; i < n; i++)
    {
        if (!findPage(s, frames, pages[i]))
        {
            int lru = 100000, val;
            for (int i = 0; i < 10; i++)
            {
                if (second_chance[i].schance * 2 + second_chance[i].sChanceModify < lru)
                {
                    val = i;
                    lru = second_chance[i].schance * 2 + second_chance[i].sChanceModify;
                }
            }
            s[val] = pages[i];
            second_chance[pages[i]].schance = 0;
            second_chance[pages[i]].sChanceModify = modify[i];
            page_faults++;
        }
        else
        {
            second_chance[pages[i]].schance = 1;
            second_chance[pages[i]].sChanceModify = modify[i];
        }
        for (int j = 0; j < frames; j++) {
            printf("%d \t", s[j]);
        }
        printf("\n");
    }


    return page_faults;
}

int main()
{
    int n, frames;
    n = 7;
    int reference[] = {0, 4, 1, 4, 2, 4, 3};
    int modify[] = {0, 0, 1, 1, 1, 0, 1};
    frames = 3;

    printf("Frame are like this : \n");

    printf("The no. of page faults is : %d \n", pageFaults(reference, modify, n, frames));
    return 0;
}
