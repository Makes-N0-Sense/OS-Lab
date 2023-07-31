#include <stdio.h>
void main(){
	int i,pno,rno,j,k,count=0,flag=0;
	int alloc[10][10], max[10][10] ,need[10][10], avail[10], comp[10];
	
	
	printf("Enter No of Processes: ");
	scanf("%d",&pno);
	
	printf("Enter No of Resources: ");
	scanf("%d",&rno);
	

	printf("Enter Allocation Matrix: \n");
	for(i=0;i<rno;i++){
		for(j=0;j<pno;j++){
			printf("Enter Value %d %d: ", i,j);
			scanf("%d",&alloc[i][j]);
		}
	}
	
	printf("Enter Max Matrix: \n");
	for(i=0;i<rno;i++){
		for(j=0;j<pno;j++){
			printf("Enter Value %d %d: ", i,j);
			scanf("%d",&max[i][j]);
		}
	}
	
	for(i=0;i<rno;i++){
		printf("Enter Available Resource Value %d: ",i+1);
		scanf("%d",&avail[i]);
	}
	
	for(i=0;i<rno;i++){
		for(j=0;j<pno;j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
	while(count < pno){
		for(i=0;i<rno;i++){
			for(j=0;j<pno;j++){
				if(need[i][j] > avail[j] && comp[i]!=1){
					comp[i]=1;
					for(k=0;k<rno;k++){
						avail[k] = avail[k]+alloc[i][k];
					}
				}
			}
		}
		count++;	
	}
	
	for(i=0;i<rno;i++){
		if(comp[i]!=1){
			flag = 1;
		}			
	}
	
	if(flag==0)
		printf("System Is In Safe\n");
	else
		printf("System is not Safe\n");

}
