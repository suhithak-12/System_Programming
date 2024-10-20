/*
*Suhithareddy Kantareddy
*CSE 222
*04/10/2024
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t set;
    sigfillset(&set);
    sigprocmask(SIG_BLOCK, &set, NULL); //blocking all the signals 

    printf("All signals are blocked\n"); //printing a message that the signals are blocked 

    sleep(3); //watiing for 3 seconds.

    sigprocmask(SIG_UNBLOCK, &set, NULL); //unblocking the signals 
    printf("Signals are no longer blocked\n"); //Printing a message that the the signals are unblocked.

    return 0;
}