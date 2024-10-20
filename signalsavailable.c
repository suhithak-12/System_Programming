/*
*Suhithareddy Kantareddy
*CSE 222
*04/10/2024
*/


#include <stdio.h>
#include <signal.h>
#include <string.h>


int main(){
    for(int n = 1; n <=64; n++){ //looping through the signals 1-64
        if(signal(n, SIG_IGN) != SIG_ERR){ //checking if signal n can be ignored
            printf("Signal %d (%s): Supported\n", n, strsignal(n)); //if supported then print message and their descriptions.
        } 
    }
    return 0;
}