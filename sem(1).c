/*
*Suhithareddy Kantareddy
*04/16/24
*CSE 222
*first question on assignment 
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <unistd.h>

int main() {
    struct semid_ds sem_info; //structure used to hold the information of the semaphore
    int sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0600); //creating a semaphore 
    if (sem_id == -1) { //checking if the semaphore was succesfully created.
        printf("Failed :("); //printing failed if an error is caused.
        return 1;
    }
    
    // getting semaphore information and storing it in sem_info
    if (semctl(sem_id, 0, IPC_STAT, &sem_info) == -1) {
        return 1;
    }

    //printing the semaphores info
    printf("Semaphore Settings and Limits:\n");
    printf("Maximum value for semaphores per semaphore set: %ld\n", sysconf(_SC_SEM_NSEMS_MAX));
    printf("Maximum value for semaphores per process: %ld\n", sysconf(_SC_SEM_VALUE_MAX));
    printf("Maximum number of semaphore sets per process: %ld\n", sysconf(_SC_SEM_NSEMS_MAX));
    printf("Maximum number of semaphore sets in the system: %ld\n", sysconf(_SC_SEM_NSEMS_MAX));
    
    
    //cleaning up
    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        return 1;
    }

    return 0;
}
