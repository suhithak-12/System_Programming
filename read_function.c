/* 
Suhithareddy Kantareddy
CSE 222
02/26/24

writing this code was easy and i didn't have any problems with it just some errors here adn there but i figured them out.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main() {
    clock_t start = clock(), diff; //variables to measure time

    int fd; //file descriptor
    char *buffer; //to hold file content
    long file_size; //to store file size

    fd = open("Lorempsum.txt", O_RDONLY); //opening the file for reading
    
    // checking if file opeing was succesfull
    if (fd < 0) {
        fprintf(stderr, "Couldn't open file\n");
        return 1;
    }

    file_size = lseek(fd, 0, SEEK_END); //getting the size of the file
    lseek(fd, 0, SEEK_SET); //moving the file pointer back to begining

    buffer = (char*) malloc(sizeof(char) * file_size); //allocate memory for buffer to hold file content

    //checking if memory allocation was succesful
    if (buffer == NULL) {
        fprintf(stderr, "Couldn't allocate memory\n");
        return 1;
    }

    read(fd, buffer, file_size); //reading file content into buffwe
    close(fd); //closing file
    free(buffer); //dynamically allocating memory for buffer


    //calculating time difference
    diff = clock() - start;
    int msec = diff * 1000/ CLOCKS_PER_SEC;
    printf("%d seconds taken\n", msec/1000);

    return 0;
}
