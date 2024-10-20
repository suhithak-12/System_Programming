
/* 
Suhithareddy Kantareddy
CSE 222
02/26/24

I had no problems editing this code as well.
*/

/*
 * This programs opens a file and reads a block to it every time.
 * It serves as the reader in the example of demonstrating  sharing a file
 * between multiple concurrent processes.
 * From the textbook: "System Programming" by jin-Jwei Chen
 */

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>  /* memset()  */

#define BUFSZ 512

int main(int argc, char *argv[])
{
	char * fname = "randomSuhithaKantareddy.txt"; //file name 
	int fd;
    off_t offset, offset_ret;
	ssize_t bytes;
	size_t count;
	char buf[BUFSZ];
	

	/* open the input file for read only, this was failing so changed it a little*/
	fd = open(fname, O_WRONLY|O_CREAT|O_TRUNC, 0664);
	if (fd == -1)
	{
		fprintf(stderr, "open() failed, errno=%d\n", errno);
		return -2;
	}

    char dashes[256]; //setting the file to 256 - characters according to the assignment
    for (int i = 0; i < 256; i++)
        dashes[i] = '-';
    write(fd, dashes, 256);

    char name[20] = "Suhitha Kantareddy"; //making a string

    offset = 4; // setting the offset to 4
    offset_ret = lseek(fd, offset, SEEK_SET); //using the lseek() as the assignment wanted us to
    if (offset == -1)
    {
        fprintf(stderr, "lseek() failed, errno=%d\n", errno);
        close(fd);
        return (-4);
    }

    bytes = write(fd, name, 20);
    if (bytes == -1)
    {
        fprintf(stderr, "write() failed, errno=%d\n", errno);
        close(fd);
        return (-4);
    }
	close(fd);
	return(0);
}
