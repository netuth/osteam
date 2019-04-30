#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 

int main()
{
	int i, limit=0, total = 0, x, counter = 0, time_quantum, cnt=0;
	int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
	float average_wait_time, average_turnaround_time, Norm_turnaround_time = 0.0;
	printf("\nEnter Total Number of Processes:\t");
	scanf("%d", &limit);
	x = limit;
	for (i = 0; i < limit; i++)
	{
		printf("\nEnter Details of Process[%d]\n", i + 1);
		printf("Arrival Time:\t");
		scanf("%d", &arrival_time[i]);
		printf("Burst Time:\t");
		scanf("%d", &burst_time[i]);
		temp[i] = burst_time[i];
	}
	printf("\nEnter Time Quantum:\t");
	scanf("%d", &time_quantum);
	printf("\nPID\t\tBurst Time\t Arrival Time\t Turnaround Time\t Waiting Time\t Normalized Turnaround Time\n");
	for (total = 0, i = 0; x != 0;)
	{
		if (temp[i] <= time_quantum && temp[i] > 0)
		{
			total = total + temp[i];
			temp[i] = 0;
			counter = 1;
		}
		else if (temp[i] > 0)
		{
			temp[i] = temp[i] - time_quantum;
			total = total + time_quantum;
		}
		if (temp[i] == 0 && counter == 1)
		{
			x--;
			
			Norm_turnaround_time = (float)(total - arrival_time[i])/ (float)burst_time[i];
			printf("\nPID:%d\t\t%d \t\t %d\t\t %d\t\t\t %d\t\t %.2f", i + 1, burst_time[i],arrival_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i],Norm_turnaround_time);
			
			wait_time = wait_time + total - arrival_time[i] - burst_time[i];
			
			turnaround_time = turnaround_time + total - arrival_time[i];
			
			
			counter = 0;
		}
		if (i == limit - 1)
		{
			i = 0;
		}
		else if (arrival_time[i + 1] <= total)
		{
			i++;
		}
		else
		{
			i = 0;
		}
	}
	average_wait_time = wait_time * 1.0 / limit;
	average_turnaround_time = turnaround_time * 1.0 / limit;
	
	printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
	printf("\nEnd time:\t\t%f", (float)total);
	printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
	return 0;
}