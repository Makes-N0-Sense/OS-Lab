#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/stat.h>

struct data{
  int items[10];
  sem_t empty,full,mutex;
  };
  
void main()
{
  int i=0;
  int shmid=shm_open("/buffer",O_CREAT|O_RDWR,0777);
  ftruncate(shmid,sizeof(struct data));
  
  struct data* sharedmem= (struct data*)mmap(NULL,sizeof(struct data),PROT_WRITE|PROT_READ,MAP_SHARED,shmid,0);
  
  
  if(sharedmem==MAP_FAILED)
  {
    printf("\n Map creation failed...\n");
  }

  while(1==1)
  {
    sem_getvalue(&(sharedmem->full),&i);
    
    if(i==0){
      printf("Buffer Empty... Waiting For Producer...\n");
      sleep(2);
      while(i==0)
      {
        sem_getvalue(&(sharedmem->full),&i);
      }
    }
    else
    {
        sem_wait(&(sharedmem->full));
        sem_wait(&(sharedmem->mutex));   
        sem_getvalue(&(sharedmem->empty),&i);
        printf("Item Consumed.. %d at position %d \n",sharedmem->items[9-i],9-i);
        sem_post(&(sharedmem->empty));
        sem_post(&(sharedmem->mutex)); 
        
      
    }
    sleep(2);
  }
}
