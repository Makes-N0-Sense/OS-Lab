#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void main(){
    int pid,status,existch;
    if((pid=fork())==1){
        perror("Error");
        exit(0);
    }
    if(pid==0){
        sleep(1);
        printf("Child Process\n");
        exit(0);
    }
    else{
        printf("parent process\n");
        if((existch=wait(&status))==1)
        {
            perror("during wait()");
            exit();
        }
    }
    printf("parent existing\n");
    exit(0);
}