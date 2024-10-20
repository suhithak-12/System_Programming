/* 
Suhithareddy Kantareddy
CSE 222
02/26/24

I had no problems editing this code but putting in a quote took me the longest and the most challenging..
*/


/*
 * This programs opens a file and writes to a number of kilobytes to it using
 * asynchronous I/O
 * From the textbook: "System Programming" by jin-Jwei Chen
 */

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>  /* memset()  */
#include <stdlib.h>  /* atoi() */
#include <aio.h>

#define BUFSZ (100*1024)
char buf[BUFSZ] = " 'Do one thing every day that scares you.' -Eleanor Roosevelt";

int main(int argc, char *argv[])
{
	char *fname = "asynchronous_output.txt";
	int fd;
	ssize_t bytes;
	size_t count;
	int status;
	int nkbs=20;
	struct aiocb aiocb;
	
	if (argc > 2)
	{
		nkbs = atoi(argv[2]);
		if (nkbs <= 0 || nkbs > 100)
		{
			nkbs = 1;
		}
	}

	/* open the input file for write only */
	fprintf(stdout, "Writing %u KBs to file %s\n", nkbs, fname);
	fd = open(fname, O_WRONLY|O_CREAT|O_TRUNC);
	if (fd == -1)
	{
		fprintf(stderr, "open() failed, errno=%d\n", errno);
		return -2;
	}


	
	// /* initialize entire buffer with 'A' */
	// memset(buf, 65, BUFSZ);
	count = nkbs * 1024;

	/* fill in the aio control block */
	memset((void *)&aiocb, 0, sizeof(aiocb));
	aiocb.aio_fildes = fd;
	aiocb.aio_buf = buf;
	aiocb.aio_nbytes = count;
	/* write the amount specified to the file */
	status = aio_write(&aiocb);
	if (status == 0)
	{
		fprintf(stdout, "The aio write request has been enqueued.\n");
	}
	else if(status == -1)
	{
		fprintf(stderr, "aio_write() call failed, errno=%d\n", errno);
		close(fd);
		return(-3);
	}

	/*           Do some other processing here             */
	/*           Otherwise we don't need async I/O         */
	// fprintf(stdout, "Doing something while waiting.\n");

	/* Wait for the async I/O operation to complete */
	status = EINPROGRESS;
	while(status == EINPROGRESS)
	{
		printf("Suhitha Kantareddy :)");
		status = aio_error(&aiocb);
	}
	fprintf(stdout, "The async I/O operation completed. aio_error returned %d\n", status);
	switch(status)
	{
		case 0:
			fprintf(stdout,"The async I/O operation completed successfully.\n");
			break;
		case ECANCELED:
			fprintf(stdout,"The async I/O operation was canceled.\n");
			break;
		default:
			fprintf(stdout,"The async I/O operation encountered an error %d\n", status);
			break;
	}
	/* Get fiinal return value of he async I/O call */
	bytes = aio_return(&aiocb);
	if(status == -1)
	{
		fprintf(stderr, "Async write operation failed, errno=%d\n", errno);
		close(fd);
		return (-4);
	}
	fprintf(stdout, "%ld bytes were written to the file.\n", bytes);
	/* close file */
	close(fd);
	return(0);
}
