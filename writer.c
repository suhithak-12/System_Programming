/* 
Suhithareddy Kantareddy
CSE 222
02/26/24

I had no probelm editing this file.
*/

/*
 * This programs makes a file and writes a block to it every few seconds.
 * It serves as the writer in the example of demonstrating  sharing a file
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
#define WRITER_WAIT_TIME 4
#define LOOPCNT 5

int main(int argc, char *argv[])
{
	char * fname = "concurrentoutput.txt"; //added the file that it was supposed to create
	int fd;
	ssize_t bytes;
	char buf[BUFSZ];
	size_t i, j;
	

	// deleted the section where we were expecting to get the file from user since we mentioned it above.
	


	/* open the input file for read only */
	fd = open(fname, O_WRONLY|O_CREAT|O_TRUNC, 0664);
	if (fd == -1)
	{
		fprintf(stderr, "open() failed, errno=%d\n", errno);
		return -2;
	}
	/* The write and wait loop. */
	do
	{
		/* Fill the buffer with the block number */
		printf("enter text, or -x to exit: ");
		fgets(buf, BUFSZ, stdin);


		size_t size = strlen(buf);

		/* Write the contents of the buffer to the file. */
		bytes = write(fd, buf, BUFSZ);
		if (bytes == -1)
		{
			fprintf(stderr, "write() failed, errno=%d\n", errno);
			close(fd);
			return(-3);
		}
		fprintf(stdout, "%ld bytes were written into file\n", bytes);

		if (buf[0] == '-' && buf[1] == 'x')
			break;

		/* Wait for a few seconds so the reader has a chance to read it */
		sleep(WRITER_WAIT_TIME);
	} while (1);

	printf("exiting......\n"); //exists if user input "-x"

	close(fd);
	return(0);
}
