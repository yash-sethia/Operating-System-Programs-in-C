#include<stdio.h>
int main()
{
    int no_of_frames, no_of_pages, frames[10], counter = 0, time[10] = {0}, flag1, flag2, i, j, pos, faults = 0;
    no_of_pages = 18;
    no_of_frames = 3;
    int pages[] = {0, 4, 1, 4, 2, 4, 3, 4, 2, 4, 0, 4, 1, 4, 2, 4, 3, 4};


    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }
    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = 1;
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = 1;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0) {
            int t = 0;
            while (1) {
                if (time[t] == 1) {
                    time[t] = 0;
                }
                else {
                    pos = t;
                    break;
                }
                t = (t + 1) % no_of_frames;
            }
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = 1;
        }
        printf("\n");
        for (j = 0; j < no_of_frames; ++j) {
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
