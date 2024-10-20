/*Suhithareddy Kantareddy 
CSE 222
Files and Directories 

Gives info about the linked file using lstat()
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>  
#include <string.h>  


int main(int argc, char *argv[]){
    int ret;
    int fd; //file descriptor
    char *filename; //file name
    struct stat fileinfo; //info about the file
    
    if (argc > 1)           //getting thr file name
        filename = argv[1];
    else 
        filename = argv[0];
    
    ret = lstat(filename, &fileinfo);       //getting thr file using lstat()
    if (ret != 0)
    {
        fprintf("stat() failed, errno = %d\n", errno);
        return -1;
    }

    //printing out the info about file.
    printf("Information about symbolic link: %s\n", filename);
    printf("File type: ");
    switch (fileinfo.st_mode & S_IFMT) {
        case S_IFLNK:  printf("Symbolic Link\n");          break;
        case S_IFREG:  printf("Regular File\n");           break;
        case S_IFDIR:  printf("Directory\n");              break;
        case S_IFCHR:  printf("Character Special File\n"); break;
        case S_IFBLK:  printf("Block Special File\n");     break;
        case S_IFIFO:  printf("FIFO\n");                   break;
        case S_IFSOCK: printf("Socket\n");                 break;
        default:       printf("Unknown\n");                break;
    }

    printf("Size: %ld bytes\n", fileinfo.st_size);
    printf("Permissions: ");
    printf((fileinfo.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileinfo.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileinfo.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileinfo.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileinfo.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileinfo.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileinfo.st_mode & S_IROTH) ? "r" : "-");
    printf((fileinfo.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileinfo.st_mode & S_IXOTH) ? "x\n" : "-\n");

    exit(EXIT_SUCCESS);
}
