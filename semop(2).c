/*
*Suhithareddy Kantareddy
*04/16/24
*CSE 222
*second question on assignment 
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int main() {
    int sem_id; // Semaphore ID
    int last_pid; // PID of the last process that executed semop()
    struct semid_ds sem_info; //structure for holding the semaphore information
    struct sembuf sem_def; //structure for defining the semaphores operations.


    // Creating a semaphore or getting the existing one
    sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0600);
    if (sem_id == -1) {
        printf("failed:("); //printing failed if an error is caused.
        return 1;
    }

    //Performing a semaphore operation to trigger some activity
    sem_def.sem_num = 0;
    sem_def.sem_op = 0;
    sem_def.sem_flg = 0;
    if (semop(sem_id, &sem_def, 1) == -1) {
        return 1;
    }

    
    //getting the PID of the lst process that performed a semaphore operation as asked in the assignment.
    last_pid = semctl(sem_id, 0, GETPID, 0);
    if (last_pid == -1) {
        return 1;
    }

    printf("PID of the last process that executed semop(): %d\n", last_pid);


    //Getting semaphore information
    if (semctl(sem_id, 0, IPC_STAT, &sem_info) == -1) {
        return 1;
    }

    //Cleaning up
    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        return 1;
    }

    return 0;
}
