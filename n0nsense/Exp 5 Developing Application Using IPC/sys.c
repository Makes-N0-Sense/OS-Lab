#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSZ 27

int main() {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    key = 5678;

    // Create a shared memory segment using shmget.
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment using shmat.
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Now you can use the shared memory segment to communicate between processes.
    // Don't forget to detach from the segment using shmdt when you're done.

    return 0;
}
