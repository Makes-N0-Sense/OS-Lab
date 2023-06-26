#include <stdio.h>

void main() {
    int process_arr[10],burst_arr[10],waiting_arr[10],turn_around[10];
    int n,i,j,temp;
    int tot_wait,tot_turn;
    
    printf("Enter No of Processes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Enter Process No: ");
        scanf("%d",&process_arr[i]);
        
        
        printf("Enter Burst Time: ");
        scanf("%d",&burst_arr[i]);
    }
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(burst_arr[j]>burst_arr[j+1]){
                temp = burst_arr[j];
                burst_arr[j] = burst_arr[j+1];
                burst_arr[j+1] = temp;
                
                temp = process_arr[j];
                process_arr[j] = process_arr[j+1];
                process_arr[j+1] = temp;
            }
        }
    }
    
    waiting_arr[0]=0;
    tot_wait = 0;
    tot_turn = 0;
    for(i=1;i<n;i++){
        waiting_arr[i] = waiting_arr[i-1] + burst_arr[i-1];
        tot_wait += waiting_arr[i];
    }
    
    for(i=0;i<n;i++){
        turn_around[i] = waiting_arr[i]+burst_arr[i];
        tot_turn += turn_around[i];
    }
    
    printf("Waiting time: ");
    for(i=0;i<n;i++){
        printf("%d ",waiting_arr[i]);
    }
    printf("\nTotal Waiting Time: %d \nAverage Waiting Time: %d",tot_wait,(tot_wait/n));
    printf("\nTurn Around time: ");
    for(i=0;i<n;i++){
        printf("%d ",turn_around[i]);
    }
    printf("\nTotal Turn Around Time: %d \nAverage Turn Around Time: %d",tot_turn,(tot_turn/n));
}
