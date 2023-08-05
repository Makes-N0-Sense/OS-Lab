#include <stdio.h>
void main(){
	int n,i,tot_wait=0,tot_turn=0;
	int pro_arr[20],bur_arr[20],wait_time[20],turn_time[20];
	
	
	printf("Enter No. Of Processes: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Enter Process-%d Name:",i+1);
		scanf("%d",&pro_arr[i]);
		
		printf("Enter Process-%d BurstTime:",i+1);
		scanf("%d",&bur_arr[i]);
	}
	
	printf("\nProcesses: ");
	for(i=0;i<n;i++){
		printf("P%d ",pro_arr[i]);
	}
	
	printf("\nBurst Times: ");
	for(i=0;i<n;i++){
		printf("%d ",bur_arr[i]);
	}
	printf("\n");
	
	wait_time[0] = 0;
	
	for(i=1;i<n;i++){
		wait_time[i] = bur_arr[i-1] + wait_time[i-1];
		tot_wait += wait_time[i];
	}
	
	turn_time[0]=bur_arr[0];
	tot_turn = bur_arr[0];
	
	
	for(i=1;i<n;i++){
		turn_time[i] = turn_time[i-1] + bur_arr[i];
		tot_turn += turn_time[i];
	}
	
	printf("\nWaiting Times: ");
	for(i=0;i<n;i++){
		printf("%d ",wait_time[i]);
	}
	printf("\n");
	
		printf("\nTurn Around Times: ");
	for(i=0;i<n;i++){
		printf("%d ",turn_time[i]);
	}
	printf("\n");
	
	printf("\nTotal Waiting Time: %d\n",tot_wait);
	printf("Average Waiting Time: %d\n",tot_wait/n);
	
	printf("Total Turn Around Time: %d\n",tot_turn);
	printf("Average Turn Around Time: %d\n",tot_turn/n);
	
}
