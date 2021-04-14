#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void signal_sigq(int sig_id) {
	printf("Signal #%d Caught! \n", sig_id);
	exit(0);
}

int main() {
	pid_t pid, id1;
	signal(SIGINT, SIG_IGN); 
	signal(SIGQUIT, SIG_DFL);
	pid = fork();
	id1 = getpid();
	int x = 10;
	printf("The id of the main process is : %d", id1);
	if(pid<0) {
		fprintf(stderr, "Fork has failed \n");	
		return 1;
	}
	else if(pid == 0) {
		pid_t childid, parentid;
		childid = getpid();
		parentid = getppid();
		printf("\n Child process \n");
		printf("\n Child Process Id : %d \n", childid);
		printf("\n Parent Process Id : %d \n", parentid); 
		printf("1. Press Ctrl + C to end child process \n");
		printf("2. Press Ctrl + \\ to exit \n");	
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, signal_sigq);
		while(1) {
			printf("Inside Child Process while loop !! \n");
			sleep(1);
		}
		x = 11;
	}
	else {
		wait(NULL);
		printf("\nChild process over :) \n");
		printf("\n %d \n", x);
	}
	return 0;
}
