#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
struct dirent *dptr;
int main(int age,char*argv[]){
    char buff[256];
    DIR *dirp;
    printf("\n Enter Directory Name: ");
    scanf("%s",buff);
    if((dirp=opendir(buff))==NULL){
        printf("Error");
        exit(1);
    }
    while(dptr=readdir(dirp)){
        printf("%s\n",dptr->d_name);
    }
    close(dirp);
}
