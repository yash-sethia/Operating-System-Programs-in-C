#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf( "So the process tree can be shown as : \n" );
    printf("\t\t P1 \n");
    printf("\tP2");
    printf("\t\t\t P3 \n");    
    printf("P4 \n");
}
int main()
{
    pid_t pid = fork();
    pid_t pid2 = fork();
    if (pid > 0 && pid2 > 0)
    {
        sleep(3);
        printf("Parent Process P1, with Process ID: %d \n", getpid());

        print();
    }
    else if (pid == 0 && pid2 > 0)
    {
        sleep(2);
        printf("First Child Process P2, with Process ID: %d\n", getpid());
        printf("My Parent Process has Process ID: %d\n", getppid());
        printf("\n");
    }
    else if (pid > 0 && pid2 == 0)
    {
        sleep(1);
        printf("Second Child Process P3, with Process ID: %d \n", getpid());
        printf("My Parent Process has Process ID: %d \n", getppid());
        printf("\n");
    }
    else
    {
        printf("Third Child Process P4, with Process ID: %d \n", getpid());
        printf("My Parent Process has Process ID: %d \n", getppid());
        printf("\n");
    }

    return 0;
}
