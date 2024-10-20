/* 
Suhithareddy Kantareddy
CSE 222
02/26/24
writing this code was easy after i read about how to write fread.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start = clock(), diff; //variables to measure time

    FILE *file; //file pointer 
    char *buffer; //pointer to hold content
    long file_size; //to store file size

    file = fopen("Lorempsum.txt", "rb"); //to open file for reading

    //checking if the file opening was succesful.
    if (file == NULL) {
        fprintf(stderr, "couldn't open file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END); //moving thw file pointer to the end of file
    file_size = ftell(file); //getting current position of file pointer
    rewind(file); //rewinding file to the beggining of file

    buffer = (char*) malloc(sizeof(char) * file_size); //allocating memory for buffer to hold content from file. 
 
    //checking if memory allocation was successful
    if (buffer == NULL) { 
        fprintf(stderr, "Can't allocate memory for buffer\n");
        return 1;
    }

    fread(buffer, 1, file_size, file); //reading file into buffer
    fclose(file); //closing the file
    free(buffer); //dynamically allocating memory for buffer 
 
    //calculating time difference
    diff = clock() - start;
    int msec = diff *1000 / CLOCKS_PER_SEC;
    printf("%d seconds taken\n", msec/1000);

    return 0;
}