#include<stdio.h>
int request[100][100] = {{0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 0, 1}, {1, 0, 1, 0, 1}};
int alloc[100][100] = {{1, 0, 1, 1, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 0}};
int need[100][100] = {0};
int max_resources[100] = {2, 1, 1, 2, 1};
int avail[100] = {0};
//int request[100][100] = {{0,0,0},{2,0,2},{0,0,0},{1,0,0},{0,0,2}};
//int alloc[100][100] = {{0,1,0},{2,0,0},{3,0,3},{2,1,1},{0,0,2}};
//int need[100][100];
//int max_resources[100] = {7, 2, 4};
int n = 4, r = 3;


void show()
{
    int i, j;

    printf("Process\t Allocation\t Request\t Available\t");

    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t ", i + 1);

        for (j = 0; j < r; j++)
        {
            printf("%d ", alloc[i][j]);
        }

        printf("\t");

        for (j = 0; j < r; j++)
        {
            printf("%d ", request[i][j]);
        }

        printf("\t");

        if (i == 0)
        {
            for (j = 0; j < r; j++)
                printf("%d ", max_resources[j]);
        }

    }
}

int allocNotNull(int arr[100][100], int i, int r) {
    for (int j = 0; j < r; j++) {
        if (arr[i][j] != 0) {
            return 0;
        }
    }
    return 1;
}


void cal()
{
    int finish[100], temp, need[100][100], flag = 1, k, c1 = 0;
    int safe[100];
    int i, j;

    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
        int ctr = 0;
        for (j = 0; j < r; j++) {
            if (alloc[i][j] == 0) {
                ctr++;
            }
        }
        if (ctr == r) {
            finish[i] = 1;
        }
    }
    // Need matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = request[i][j];
        }
    }

    for (int l = 0; l < r; l++) {
        avail[l] = max_resources[l];
        for (int m = 0; m < n; m++) {
            avail[l] = avail[l] - alloc[m][l];
        }
    }

    printf("\n");

    while (flag)
    {
        flag = 0;

        for (i = 0; i < n; i++)
        {
            int c = 0;

            for (j = 0; j < r; j++)
            {
                if ((finish[i] == 0) && (need[i][j] <= avail[j]))
                {
                    c++;

                    if (c == r)
                    {
                        for (k = 0; k < r; k++)
                        {
                            avail[k] += alloc[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        // printf("P%d->",i);
                        if (finish[i] == 1)
                        {
                            i = n;
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (finish[i] == 1)
        {
            c1++;
        }
        else
        {
            printf("P%d->", i);
        }

    }

    if (c1 == n)
    {
        printf("\n The system is not in deadlock");
    }
    else
    {
        printf("\n System is in dead lock. The above mentioned processes are deadlocked");
    }
}

int main()
{
    int i, j;
    printf("********** Modified Banker's Algo for Deadlock Detection ************\n");
    show();
    cal();
    return 0;
}
