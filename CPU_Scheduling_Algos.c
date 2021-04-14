#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>
void FCFS() {
	int burst[5] = {10, 29, 3, 7, 12};
	int wait[5], turnaround[5];
	int wt = 0, tt = 0;
	for(int i = 0; i < 5; i++) {
		wait[i] = wt;
		printf("%d | Process %d | ", wt, i);
		tt += burst[i];
		printf("%d| ", tt);
		turnaround[i] = tt;
		wt += burst[i];
	}
	printf("\n");	
	float avg_w = 0.0, avg_t = 0.0;
	for(int i = 0; i < 5; i++) {
		avg_w += wait[i];
	}
	avg_w = (float)(avg_w / 5);
	
	for(int i = 0; i < 5; i++) {
		avg_t += turnaround[i];
	}
	avg_t = (float)(avg_t / 5);
	
	printf("The average waiting time is = %f \n", avg_w);
	printf("The average turnaround time is = %f \n", avg_t);
}

void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
                
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
void SJF() {
	int burst[5] = {10, 29, 3, 7, 12};
	selectionSort(burst, 5);
	int wait[5], turnaround[5];
	int wt = 0, tt = 0;
	for(int i = 0; i < 5; i++) {
		wait[i] = wt;
		printf(" %d | Process %d | ", wt, i);
		tt += burst[i];
		printf("%d| ", tt);
		turnaround[i] = tt;
		wt += burst[i];
	}
	printf("\n");
	float avg_w = 0.0, avg_t = 0.0;
	for(int i = 0; i < 5; i++) {
		avg_w += wait[i];
	}
	avg_w = (float)(avg_w / 5);
	for(int i = 0; i < 5; i++) {
		avg_t += turnaround[i];
	}
	avg_t = (float)(avg_t / 5);
	printf("The average waiting time is = %f \n", avg_w);
	printf("The average turnaround time is = %f \n", avg_t);
}
void sort_acc_priority(int *burst, int p[]) {
	int copy[5] = {0};
	for(int i = 0; i < 5; i++) {
		copy[p[i] - 1] = burst[i];
	}
	for(int i = 0; i < 5; i++) {
		burst[i] = copy[i];
	}
}
void Priority() {
	int burst[5] = {10, 1, 2, 1, 5};	
	int pri[5] = {3, 1, 4, 5, 2};
	int wait[5], turnaround[5];
	int wt = 0, tt = 0;
	sort_acc_priority(burst, pri);
    	printf("\n");

	for(int i = 0; i < 5; i++) {
		wait[i] = wt;
		printf("%d | Process %d | ", wt, i);
		tt += burst[i];
		printf("%d| ", tt);
		turnaround[i] = tt;
		wt += burst[i];
	}
	printf("\n");
		
	float avg_w = 0.0, avg_t = 0.0;
	
	for(int i = 0; i < 5; i++) {
		avg_w += wait[i];
	}
	avg_w = (float)(avg_w / 5);
	
	for(int i = 0; i < 5; i++) {
		avg_t += turnaround[i];
	}
	
	avg_t = (float)(avg_t / 5);
	
	printf("The average waiting time is = %f \n", avg_w);
	printf("The average turnaround time is = %f \n", avg_t);
	
}

int isAllDone(int done[]) {
	for(int i = 0; i < 3; i++) {
		if(done[i] == 0)
			return 1;
	}
	return 0;
}

void addWait(int *wait, int done[], int curr) {
	for(int i = 0; i < 3; i++) {
		if(i != curr && done[i] == 0) {
			wait[i]++;
		}
	}
}
int jobChange(int done[], int curr) {
    int temp = curr;
	curr = (curr + 1) % 3;
	while(done[curr] == 1) {
		curr = (curr + 1) % 3;
        if(temp == curr)
            return 0;
    }

	return curr;
}

void RoundRobin() {
	int wait[3] = {0};
	int burst[3] = {24, 3, 3};
	int tq = 4;
	int t = 0;
	int done[3] = {0}, curr = 0;
	while(isAllDone(done)) {
		t++;
		burst[curr]--;
		if(burst[curr] == 0) {
			done[curr] = 1;
            		t = t + (tq - (t % tq));
            		addWait(wait, done, curr);
			curr = jobChange(done, curr);
            		continue;
		}
		addWait(wait, done, curr);
		if(t % tq == 0) {
			curr = jobChange(done, curr);
		}
	}
	printf("\n");
		
	float avg_w = 0.0, avg_t = 0.0;
	
	for(int i = 0; i < 3; i++) {
		avg_w += wait[i];
	}

	avg_w = (float)(avg_w / 3);

	printf("The average waiting time is = %f \n", avg_w);
}
int main() {
	while(1) {
		printf("*MENU* \n");
		printf("1. First Come First Serve Algo \n");
		printf("2. Shortest Job First Algo \n");
		printf("3. Priority Scheduling \n");
        	printf("4. Round Robin Algorithm \n");
		printf("5. Exit \n");
		printf("Enter you choice (1 / 2 / 3 / 4 / 5) \n");
		int ch;
		scanf("%d", &ch);
		switch(ch) {
			case 1: 
				FCFS();
				break;
			case 2:
				SJF();
				break;
            case 3:
				Priority();
				break;
            case 4:
				RoundRobin();
				break;
			case 5:
				exit(0);
			default: 
				printf("ERROR: Wrong Choice");
		}
	}	
