#include<stdio.h>
 
struct process
{
      int pname;
      int arrival, burst, ct, waiting_time, turnaround_time, pri;
      int done;
} ready_queue[5];

void create_structure_object(struct process *temp, int user_name, int user_arrival, int user_burst, int user_pri) {

      (*temp).pname = user_name;
      (*temp).arrival = user_arrival;
      (*temp).burst = user_burst;
      (*temp).ct = 0;
      (*temp).waiting_time = 0;
      (*temp).turnaround_time = 0;
      (*temp).pri = user_pri;
      (*temp).done = 0;
 
}
 
void sort_acc_arrival()
{
      struct process temp;
      int i, j;
      for(i = 0; i < 5 - 1; i++)
      {
            for(j = i + 1; j < 5; j++)
            {
                  if(ready_queue[i].arrival > ready_queue[j].arrival)
                  {
                        temp = ready_queue[i];
                        ready_queue[i] = ready_queue[j];
                        ready_queue[j] = temp;
                  }
            }
      }
}
 
void main()
{

      int i, time = 0, burst = 0, largest;
      char c;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
        create_structure_object(&ready_queue[0], 1, 0, 3, 3);
        create_structure_object(&ready_queue[1],2, 2, 1, 5);
        create_structure_object(&ready_queue[2],3, 0, 2, 2);
        create_structure_object(&ready_queue[3],4, 0, 1, 1);
        create_structure_object(&ready_queue[4],5, 0, 3, 4);
     
      burst = 10;
      
      sort_acc_arrival();
      ready_queue[5].pri = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
      for(time = ready_queue[0].arrival; time < burst;)
      {
            largest = 6;
            for(i = 0; i < 5; i++)
            {
                  if(ready_queue[i].arrival <= time && ready_queue[i].done != 1 && ready_queue[i].pri > ready_queue[largest].pri)
                  {
                        largest = i;
                  }
            }
            time = time + ready_queue[largest].burst;
            ready_queue[largest].ct = time;
            
            ready_queue[largest].waiting_time = ready_queue[largest].ct - ready_queue[largest].arrival - ready_queue[largest].burst;
            
            ready_queue[largest].turnaround_time = ready_queue[largest].ct - ready_queue[largest].arrival;
            
            ready_queue[largest].done = 1;
            wait_time = wait_time + ready_queue[largest].waiting_time;
            turnaround_time = turnaround_time + ready_queue[largest].turnaround_time;
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", ready_queue[largest].pname, ready_queue[largest].arrival, ready_queue[largest].burst, ready_queue[largest].pri, ready_queue[largest].waiting_time);
      }
      average_waiting_time = wait_time / 5;
      average_turnaround_time = turnaround_time / 5;
      printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
      printf("Average Turnaround Time:\t%f\n", average_turnaround_time);
}
