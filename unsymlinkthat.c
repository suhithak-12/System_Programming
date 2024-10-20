/*Suhithareddy Kantareddy 
CSE 222
Files and Directories 

unlinks the file using unlink().
*/
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>  

int main(int argc, char *argv[]){
    int ret;

    if (argc <= 1){                         //getting the file or link name 
        fprintf(stdout, "Usage: %s pathname\n", argv[0]);
        return -1;
    }

    ret = unlink(argv[1]);                  // removing the file or link using unlink()
    if (ret == -1){
        fprintf(stderr, "unlink() failed, errno = %d\n", errno);
        return -2;
    }
    return 0;
}