#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

static char message[] = "Hello World";
int main(){
    int fd;
    char buffer[80];
    fd = open("new2file.txt",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
    if(fd!=-1){
        printf("File.tx opened for read or write access\n");
        write(fd,message,sizeof(message));
        lseek(fd, 0, SEEK_SET);
        if(read(fd,buffer,sizeof(message))==sizeof(message))
            printf("\"%s\" was written to file\n",buffer);
        else{
            printf("ERROR!!!\n");
            close(fd);
        }
    }
    else{
        printf("File already Exists\n");
        exit(0);
    }
}