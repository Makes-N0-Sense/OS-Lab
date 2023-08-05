#include <stdio.h>
void main(){
	int i,j,pno,bno;
	
	struct process{
		int size;
		int flag;
	}p[20];
	
	int flag=0;
	
	int temp[2]={0,0};
	
	int block[20];
	
	printf("Enter No Of Processes: ");
	scanf("%d",&pno);
	
	for(i=0;i<pno;i++){
		printf("Enter Process %d Size: ",i);
		scanf("%d",&p[i].size);
	}
	
	printf("Enter No Of Blocks: ");
	scanf("%d",&bno);
	
	for(i=0;i<bno;i++){
		printf("Enter Block %d Size: ",i);
		scanf("%d",&block[i]);
	}
	
	for(i=0;i<pno;i++){
		temp[0] = 0;
		flag=0;
		for(j=0;j<bno;j++){
			if( block[j] > p[i].size ){
				flag=1;
				if(temp[0] == 0){
					temp[0] = block[j] - p[i].size;
					temp[1] = j;
				}
				else if(temp[0] > block[j] - p[i].size){
					temp[0] = block[j] - p[i].size;
					temp[1] = j;
				}	
			}
		}
		if(flag!=0 && p[i].flag != 1){
				p[i].flag = 1;
				block[temp[1]] = block[temp[1]] - p[i].size;
				printf("Process %d is Allocated to Block %d\n",i,temp[1]);
		}
	}
	
	for(i=0;i<pno;i++)
		if(p[i].flag!=1){
			printf("Process %d Will Wait\n",i);
		}
	
}

