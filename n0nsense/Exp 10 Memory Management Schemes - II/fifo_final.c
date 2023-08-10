#include <stdio.h>
void main(){
	int frames[10],pages[10];
	int pno,fno,i,j,nextFrame=0,found,pageFault=0;
	
	printf("Enter No of Pages: ");
	scanf("%d", &pno);
	
	for(i=0;i<pno;i++){
		printf("Enter Reference String %d: ",i);
		scanf("%d",&pages[i]);
	}
	
	printf("Enter No Of Frames: ");
	scanf("%d",&fno);
	
	for(i=0;i<fno;i++){
		frames[i] = -1;
	}
	
	for(i=0;i<pno;i++){
		found=0;
		for(j=0;j<fno;j++){
			if(frames[j]==pages[i]){
				found=1;
				break;
			}
		}
		if(found==0){
			frames[nextFrame] = pages[i];
			nextFrame = (nextFrame + 1 )%fno;
			pageFault++;
		}
		for(j=0;j<fno;j++){
			if(frames[j]==-1)
				printf("- ");
			else
				printf("%d ",frames[j]);
		}
		printf("\n");
		
	}
	
	printf("Page Faults = %d\n", pageFault);
}
