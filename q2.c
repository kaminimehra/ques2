#include<stdio.h>
main()
{
	int timer=0,i=0,bt=0;
	int n,y,x;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	int process[n],arrival[n],burst_time[n],updated_burst_time[n],process_arrived[n],complete[n];
	int turnaround_time[n],waiting_time[n];
	double priority[n];
	int s;
	for(s=0;s<n;s++)
	{
		printf("Enter arrival time , burst time of process %d",s+1);
		process[s]=100+s+1;//to give automatic process id to different processes.
		process_arrived[s]=1;
		scanf("%d",&arrival[s]);
		scanf("%d",&burst_time[s]);
		updated_burst_time[s]=burst_time[s];
		complete[s]=0;//setting completion time of process to 0 to act as reffernece.
		priority[s]=0;//setting initial priority of all process to 0
	}
	int k,p,q;
	while(1)
	{
		for(k=0;k<n;k++)
		{
			if(timer>=arrival[k] && updated_burst_time[k]!=(-1)) 
			{
				//calculation of priority.
				priority[k]=1+((timer-arrival[k])/updated_burst_time[k]);
			}
		}
		for(p=0;p<n;p++)
		{
			for(q=0;q<n-1-p;q++)
			{
				if(priority[q]<priority[q+1] && process_arrived[q]!=0 && process_arrived[q+1]!=0)
				{
					//swapping priority
					priority[q]=priority[q]+priority[q+1];
					priority[q+1]=priority[q]-priority[q+1];
					priority[q]=priority[q]-priority[q+1];
					//swapping process arrived(wdout using third variable)
					process_arrived[q]=process_arrived[q]+process_arrived[q+1];
					process_arrived[q+1]=process_arrived[q]-process_arrived[q+1];
					process_arrived[q]=process_arrived[q]-process_arrived[q+1];
				}

