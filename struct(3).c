/*
*Suhithareddy Kantareddy
*04/16/24
*CSE 222
*third question on assignemnt
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int main() {
    int sem_id; // Semaphore ID
    struct semid_ds sem_info; //holds the infor of the semaphore

    //Creating a semaphore or get the existing one
    sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0600);
    if (sem_id == -1) {
        printf("failed"); //printing failed if an error is caused.
        return 1;
    }

    //Getting semaphore information
    if (semctl(sem_id, 0, IPC_STAT, &sem_info) == -1) {
        return 1;
    }

    //Displaing semaphore information
    printf("Semaphore Information:\n");
    printf("Owner's user ID: %d\n", sem_info.sem_perm.uid);
    printf("Owner's group ID: %d\n", sem_info.sem_perm.gid);
    printf("Creator's user ID: %d\n", sem_info.sem_perm.cuid);
    printf("Creator's group ID: %d\n", sem_info.sem_perm.cgid);
    printf("Permissions: 0%o\n", sem_info.sem_perm.mode);
    printf("Number of semaphores in the set: %ld\n", sem_info.sem_nsems);
    printf("Last semop() time: %ld seconds\n", sem_info.sem_otime);
    printf("Last change time: %ld seconds\n", sem_info.sem_ctime);

    //Cleaning up
    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        return 1;
    }

    return 0;
}
