#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
void maij(){
    int fd;
    fd = creat("file.dat",S_IREAD/S_IWRITE);
    if(fd==-1){
        printf("errors in opening file\n");
    }
    else{
        printf("\nfile.dat opened for read/write access\n");
        printf("\nfile.dat is currently empty");
        close(fd);
    }
}