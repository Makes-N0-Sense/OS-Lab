#include <stdio.h>
void main(){
	int i,pno,rno,j,k,count=0,check=0;
	int alloc[10][10], max[10][10] ,need[10][10], avail[10], comp[10],flag;
	
	
	printf("Enter No of Processes: ");
	scanf("%d",&pno);
	
	printf("Enter No of Resources: ");
	scanf("%d",&rno);
	

	printf("Enter Allocation Matrix: \n");
	for(i=0;i<pno;i++){
		for(j=0;j<rno;j++){
			printf("Enter Value %d %d: ", i,j);
			scanf("%d",&alloc[i][j]);
		}
	}
	
	printf("Enter Max Matrix: \n");
	for(i=0;i<pno;i++){
		for(j=0;j<rno;j++){
			printf("Enter Value %d %d: ", i,j);
			scanf("%d",&max[i][j]);
		}
	}
	
	for(i=0;i<rno;i++){
		printf("Enter Available Resource Value %d: ",i+1);
		scanf("%d",&avail[i]);
	}
	
	for(i=0;i<pno;i++){
		for(j=0;j<rno;j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
    printf("\nAllocation Matrix\n");
    for(i=0;i<pno;i++){
		for(j=0;j<rno;j++){
            printf("%d ",alloc[i][j]);
        }
        printf("\n");
    }

    printf("\nMax Matrix\n");
    for(i=0;i<pno;i++){
		for(j=0;j<rno;j++){
            printf("%d ",max[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed Matrix\n");
    for(i=0;i<pno;i++){
		for(j=0;j<rno;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailable\n");
	for(k=0;k<rno;k++){
        printf("%d ",avail[k]);
	}
    printf("\n");
	while(count < pno){
		for(i=0;i<pno;i++){
			flag=0;
			for(j=0;j<rno;j++){
				if(need[i][j] > avail[j])
					flag=1;
			}
			if(flag!=1 && comp[i]!=1){
				comp[i]=1;
				for(k=0;k<rno;k++){
					avail[k] = avail[k] + alloc[i][k];
					printf("%d ",avail[k]);
				}
				printf("\n");
			}
		}
		count++;	
	}
	
	for(i=0;i<rno;i++){
		if(comp[i]!=1){
			check = 1;
		}			
	}
	
	if(check==0)
		printf("System Is In Safe\n");
	else
		printf("System is not Safe\n");

}