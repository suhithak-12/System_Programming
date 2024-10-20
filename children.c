/*
*Suhithareddy Kantareddy
*CSE 222
*04/10/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
    pid_t pid = fork(); //creating a child 
    if (pid == 0){ //if child created
        sleep(3);
        system(argv[1]); //executing thr blocker program with storing the status
        int status;
        wait(&status); //waiting for the blocker to complete and print the program
        if (WIFEXITED(status)) {
            printf("Child: Blocker exited normally wiht status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child: Blocker was terminated by signal %d\n", WTERMSIG(status));
        }
            printf("Child: Blocker's  pid is %d\n", getpid());
        }else {
            printf("Parent: child's pid is %d\n", pid);
            int status; //waiting for the child to finish and print status.
            wait(&status); //waiting for the blocker to complete and print the program
            if (WIFEXITED(status)) {
                printf("Parent: child exited normally with status %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)){
                printf("Parent Child was terminated by signal %d\n", WTERMSIG(status));
            }
        }
        return 0;
    }