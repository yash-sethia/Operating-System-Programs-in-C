#include <stdio.h>

struct process
{
    int arrival_time, burst_time, waiting_time, turn_around_time, remaining_time, completion_time;
} Q1[10], Q2[10], Q3[10];

int n;

void sortByArrival()
{
    struct process temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Q1[i].arrival_time > Q1[j].arrival_time)
            {
                temp = Q1[i];
                Q1[i] = Q1[j];
                Q1[j] = temp;
            }
        }
    }
}

int main()
{
    int i, j, k = 0, r = 0, time = 0, time_quantum1 = 5, time_quantum2 = 8, flag = 0;
    n = 4;

    Q1[0].arrival_time = 0;
    Q1[0].burst_time = 8;
    Q1[0].remaining_time = Q1[0].burst_time;

    Q1[1].arrival_time = 1;
    Q1[1].burst_time = 4;
    Q1[1].remaining_time = Q1[1].burst_time;

    Q1[2].arrival_time = 2;
    Q1[2].burst_time = 9;
    Q1[2].remaining_time = Q1[2].burst_time;

    Q1[3].arrival_time = 3;
    Q1[3].burst_time = 15;
    Q1[3].remaining_time = Q1[3].burst_time;

    sortByArrival();

    time = Q1[0].arrival_time;

    printf("\n");

    printf("Processes completed in first queue following RR with qt=5 : \n");
    printf("Process   Arrival Time   Burst Time   Waiting Time   Turn Around Time \n");

    for (i = 0; i < n; i++)
    {
        if (Q1[i].remaining_time <= time_quantum1)
        {

            time += Q1[i].remaining_time;
            Q1[i].remaining_time = 0;
            Q1[i].turn_around_time = time - Q1[i].arrival_time;
            Q1[i].waiting_time = time - Q1[i].arrival_time - Q1[i].burst_time;
            printf("   P%d\t\t%d\t\t%d\t    %d\t\t  %d\n", i + 1, Q1[i].arrival_time, Q1[i].burst_time, Q1[i].waiting_time, Q1[i].turn_around_time);
        }
        else
        {
            Q2[k].waiting_time = time;
            time += time_quantum1;
            Q1[i].remaining_time -= time_quantum1;
            Q2[k].burst_time = Q1[i].remaining_time;
            Q2[k].remaining_time = Q2[k].burst_time;
            Q2[k].arrival_time = Q1[i].arrival_time;
            k = k + 1;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("\n\nProcesses completed in second queue following RR with qt=8 : \n");
        printf("Process   Arrival Time   Burst Time   Waiting Time   Turn Around Time \n");
    }
    for (i = 0; i < k; i++)
    {
        if (Q2[i].remaining_time <= time_quantum2)
        {
            time += Q2[i].remaining_time;
            Q2[i].turn_around_time = time - Q2[i].arrival_time;
            Q2[i].waiting_time = Q2[i].turn_around_time - time_quantum1 - Q2[i].remaining_time;
            Q2[i].remaining_time = 0;
            printf("   P%d\t\t%d\t\t%d\t    %d\t\t  %d\n", i + 1, Q2[i].arrival_time, Q2[i].burst_time, Q2[i].waiting_time, Q2[i].turn_around_time);
        }
        else
        {
            Q3[r].arrival_time = Q2[i].arrival_time;
            time += time_quantum2;
            Q2[i].remaining_time -= time_quantum2;
            Q3[r].burst_time = Q2[i].remaining_time;
            Q3[r].remaining_time = Q3[r].burst_time;
            r = r + 1;
            flag = 2;
        }
    }

    if (flag == 2)
    {
        printf("\n\nProcesses completed in third queue following FCFS : \n");
        printf("Process   Arrival Time   Burst Time   Waiting Time   Turn Around Time \n");
    }

    for (i = 0; i < r; i++)
    {
        if (i == 0)
            Q3[i].completion_time = Q3[i].burst_time + time;
        else
            Q3[i].completion_time = Q3[i - 1].completion_time + Q3[i].burst_time;
    }

    for (i = 0; i < r; i++)
    {
        Q3[i].turn_around_time = Q3[i].completion_time;
        Q3[i].waiting_time = Q3[i].turn_around_time - Q3[i].arrival_time - time_quantum1 - time_quantum2 - Q3[i].burst_time;
        printf("   P%d\t\t%d\t\t%d\t    %d\t\t  %d\n", i + 1, Q3[i].arrival_time, Q3[i].burst_time, Q3[i].waiting_time, Q3[i].turn_around_time);
    }
    printf("\n");
}
