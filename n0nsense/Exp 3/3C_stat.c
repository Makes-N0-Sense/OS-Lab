#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void){
    char path[10];
    struct stat *nfile;
    nfile = (struct stat*)malloc(sizeof(struct stat));
    printf("Enter Name Of File Whose Statistics Has To: ");
    scanf("%s",path);
    stat(path,nfile);
    printf("User id : %d\n", nfile->st_uid);
    printf("User Blksize : %d\n", nfile->st_blksize);
    printf("User atime : %d\n", nfile->st_atime);
    printf("User mtime : %d\n", nfile->st_mtime);
    printf("User size : %d\n", nfile->st_size);
    printf("User mode : %d\n", nfile->st_mode);
}