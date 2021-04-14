#include<stdio.h>
#include<math.h>
int main()
{
    int queue[20], n, head, i, j, k, seek = 0, max, diff, temp, temp1 = 0, temp2 = 0;
    float avg;
    max = 200;
    head = 50;
    n = 8;
    int queue1[] = {90, 120, 122, 128, 65, 68};
    int queue2[] = {35, 38};
    temp1 = 6;
    temp2 = 2;
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    for (i = 1, j = 0; j < temp1; i++, j++)
        queue[i] = queue1[j];

    queue[i] = max;

    queue[i + 1] = 0;

    for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
        queue[i] = queue2[j];

    queue[0] = head;

    for (j = 0; j <= n + 1; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
    }
    printf("Total seek time is %d\n", seek);
    avg = seek / (float)n;
    printf("Average seek time is %f\n", avg);
    return 0;
}
