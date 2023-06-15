#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t forks[5];


void *philosopher(void *args)
{
  int i=*((int *)args);
  while(1==1)
  {
    if((i+1)%2==0){
      sem_wait(&forks[(i+1)%5]);
      printf("Fork %d Fetched for for philosopher %d \n",(i+1)%5,i);
      sem_wait(&forks[i]);
      printf("Fork %d Fetched for for philosopher %d \n",i,i);
    }
    else{
      sem_wait(&forks[i]);
      printf("Fork %d Fetched for for philosopher %d \n",i,i);
      sem_wait(&forks[(i+1)%5]);
      printf("Fork %d Fetched for for philosopher %d \n",(i+1)%5,i);
    }
    printf("\nPhilosopher %d Eats\n\n",i+1);
    sem_post(&forks[i]);
    printf("Fork %d Released by for philosopher %d \n",i,i);
    sem_post(&forks[(i+1)%5]);
    printf("Fork %d Released by for philosopher %d \n",(i+1)%5,i);
    sleep(2);
  }
}

void main(){
  for (int i = 0; i < 5; i++) {
    sem_init(&forks[i], 0, 1);
  }
  
  pthread_t philosophers[5];
  int philosopher_ids[5];
  
 
  for (int i = 0; i < 5; i++) {
    philosopher_ids[i] = i;
    pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
  }
  

  for (int i = 0; i < 5; i++) {
    pthread_join(philosophers[i], NULL);
  }
  
}
  