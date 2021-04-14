#include<stdio.h>
#include<math.h>
int main()
{
    int n, head, i, j, k, seek = 0, max, diff;
    float avg;

    max = 200;
    n = 8;

    int queue[] = {0, 90, 120, 35, 122, 38, 128, 65, 68};
    head = 50;

    queue[0] = head;

    for (j = 0; j <= n - 1; j++) {
        diff = queue[j + 1] > queue[j] ? queue[j + 1] - queue[j] : queue[j] - queue[j + 1];
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d \n", queue[j], queue[j + 1], diff);
    }
    printf("Total seek time is %d\n", seek);
    avg = seek / (float)n;
    printf("Average seek time is %f\n", avg);
    return 0;
}
