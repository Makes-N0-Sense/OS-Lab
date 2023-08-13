#include <stdio.h>
void main(){
	int i,j,k,pno,bno,a=0;
	
	struct block{
		int size;
		int allot[10];
	}B[20];
	
	struct process{
		int size;
		int flag;
	}P[10];
	
	printf("Enter No Of Processes: ");
	scanf("%d",&pno);
	for(i=0;i<pno;i++){
		printf("Enter Process %d Size: ",i);
		scanf("%d",&P[i].size);
	}
	
	
	printf("Enter No Of Blocks: ");
	scanf("%d",&bno);
	for(i=0;i<bno;i++){
		printf("Enter Block %d Size: ",i);
		scanf("%d",&B[i].size);
	}
	
	for(i=0;i<pno;i++){
		for(j=0;j<bno;j++){
			if(P[i].size<=B[j].size && P[i].flag != 1){
				B[j].allot[a]=i;
				a++;
				B[j].size = B[j].size - P[i].size;
				P[i].flag = 1;
				printf("Process %d is Allocated to Block %d\n",i,j);
			}
		}
	}
	
	for(i=0;i<pno;i++){
		if(P[i].flag!=1){
			printf("Process %d have to wait!\n",i);	
		}
	}
}