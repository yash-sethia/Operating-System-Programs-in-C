#include<stdio.h>
#include<stdlib.h>

int closestJob(int queue[], int done[], int n, int head) {
    int temp = 10000, ans = -1;
    for (int i = 0; i < n; i++) {
        if (done[i] != 1) {
            if (abs(queue[i] - head) < temp) {
                temp = abs(queue[i] - head);
                ans = i;
            }
        }
    }
    return ans;
}

int main()
{
    int n, head, i, j, k, seek = 0, max, diff;
    float avg;

    max = 200;
    n = 8;

    int queue[] = {90, 120, 35, 122, 38, 128, 65, 68};
    head = 50;

    int done[8] = {0};

    for (j = 0; j < n; j++) {
        if (done[j] == 10000) {
            continue;
        }
        int closest = closestJob(queue, done, n, head);
        diff = abs(queue[closest] - head);
        done[closest] = 1;
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d \n", head, queue[closest], diff);
        head = queue[closest];
    }
    printf("Total seek time is %d\n", seek);
    avg = seek / (float)n;
    printf("Average seek time is %f\n", avg);
    return 0;
}
