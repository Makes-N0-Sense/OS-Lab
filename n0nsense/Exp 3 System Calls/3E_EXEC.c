#include <stdio.h>
#include <stdlib.h>
void main(){
    int pid;
    char *args[]={"/bin/ls","-1",0};
    printf("\n Parent Process\n");
    pid=fork();
    if(pid==0){
        Execv("/bin/ls",args);
        printf("Child Process\n");
    }
    else{
        wait();
        printf("Parent Process\n");
        Exit(0);}}
    }
}