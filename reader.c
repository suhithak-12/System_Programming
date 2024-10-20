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
#define READER_WAIT_TIME 1
#define LOOPCNT 5

int main(int argc, char *argv[])
{
	char * fname = "concurrentoutput.txt"; //adding the file to read
	int fd;
	ssize_t bytes;
	size_t count;
	char buf[BUFSZ+1];
	size_t i, j;
	char *bufadr;

	//deleted the section where we were expecting to get the file from user since we mentioned it above.


	/* open the input file for read only */
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "open() failed, errno=%d\n", errno);
		return -2;
	}
	/* The read loop. */
	for(i = 1; i < LOOPCNT; i++)
	{
		/* read a block at each iteration */
		count = BUFSZ;
		bufadr = buf;
		while(count > 0)
		{
			bytes = read(fd, bufadr, count);
			if(bytes == -1)
			{
				fprintf(stderr, "read() failed, errno=%d\n", errno); // when the program doesnt read.
				close(fd);
				return(-3);
			}
			count = count - bytes;
			bufadr = bufadr + bytes;
		}
		buf[BUFSZ] = '\0';
		fprintf(stdout, "Just read the following block:\n%s\n", buf);
	}
	/* close file */
	close(fd);
	return(0);
}
