/* 
Suhithareddy Kantareddy
CSE 222
02/26/24
writing this code was easy but i had to look up how to do reav functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/uio.h>

#define BUF_SIZE 1024

int main() {
    clock_t start = clock(), diff; //variales to mesure time

    int fd; //file descriptor 
    char buffer[BUF_SIZE]; //buffer to store data
    struct iovec iov[1]; //scatter gather I/O
    ssize_t bytes, total_bytes = 0; //total bytes 

    fd = open("Lorempsum.txt", O_RDONLY); //open file for reading

    //checking if the file opening was successful
    if (fd < 0) { 
        fprintf(stderr, "Can't open file\n");
        return 1;
    }

    iov[0].iov_base = buffer;
    iov[0].iov_len = BUF_SIZE;

    //read data from file 
    while ((bytes = readv(fd, iov, 1)) > 0) { 
        total_bytes += bytes;
    }

    //check if reading failed
    if (bytes < 0 ){ 
        fprintf(stderr, "Can't read files\n");
        return 1;
    } 
    
     //calculate time difference
    diff = clock() - start;
    int msec = diff *1000 / CLOCKS_PER_SEC; 
    printf( "%d seconds taken\n", msec/1000);

    close(fd);

    return 0;
}