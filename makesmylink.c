/*Suhithareddy Kantareddy 
CSE 222
Files and Directories 

makes a new symbolic link               
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]){
    int ret;
    char *filename, *symlinkname;

    if(argc > 2) //getting the names of the files.
    {
        filename = argv[1];
        symlinkname = argv[2];
    } else {
        fprintf(stderr, "Usage- %s filename Symlinkname\n", argv[0]);
        return -1;
    }

    ret = symlink(filename,symlinkname); //creating thr symlinks using the symlink().
    if (ret == -1){
        fprintf(stderr, "Symlink failed, errno = %d", errno);
        return -2;
    }
    return 0;
}