#include <stdio.h>

int mutex = 1, full = 0 , empty = 5 , x = 0;

void producer(){
    mutex = 0;
    full = full+1;
    empty = empty - 1;
    x = x+1;
    mutex = 1;
    printf("Producer Produced An Item %d\n",x);
}

void consumer(){
    mutex = 0;
    full = full - 1;
    empty = empty + 1;
    printf("Consumer Consumed An Item %d\n",x);
    x = x - 1;
    mutex = 1;
}
void main() {
    int i,ch=0;
    while(ch!=3){
        printf("1.Producer\n2.Consumer\n3.Exit\nEnter Choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                if(mutex==1 && empty!=0)
                    producer();
                else
                    printf("Buffer Is Full\n");
                break;
            case 2:
                if(mutex==1 && full!=0)
                    consumer();
                else
                    printf("Buffer is Empty\n");
                break;
            case 3:
                printf("Exiting...\n");
        }
    }
}