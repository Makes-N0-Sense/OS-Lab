#include <stdio.h>
void main(){
    int pid,ppid,getpid(void),getppid(void);
    pid = getpid();
    ppid = getppid();
    printf("pid = %d\nppid= %d\n",pid, ppid);
}