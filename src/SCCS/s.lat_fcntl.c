h05293
s 00130/00000/00000
d D 1.1 99/12/08 09:18:19 lm 2 1
cC
cF1
cO-rw-r--r--
e
s 00000/00000/00000
d D 1.0 99/12/08 09:18:19 lm 1 0
c BitKeeper file /home/lm/lmbench/src/lat_fcntl.c
cHwork.bitmover.com
cPsrc/lat_fcntl.c
cR13b82230576b9707
cZ-08:00
c______________________________________________________________________
e
u
U
f e 0
f x 32
t
T
I 2
#include "bench.h"

/*
 * lat_pipe.c - pipe transaction test
 *
 * Copyright (c) 1994 Larry McVoy.  Distributed under the FSF GPL with
 * additional restriction that results may published only if
 * (1) the benchmark is unmodified, and
 * (2) the version in the sccsid below is included in the report.
 * Support for this development by Sun Microsystems is gratefully acknowledged.
 */
char	*id = "$Id: lat_pipe.c,v 1.8 1997/06/16 05:38:58 lm Exp $\n";

#include "bench.h"

struct	flock lock, unlock;
struct	flock s1, s2;
int	fd1, fd2;

/*
 * Create two files, use them as a ping pong test.
 * Process A:
 *	lock(1)
 *	unlock(2)
 * Process B:
 *	unlock(1)
 *	lock(2)
 * Initial state:
 *	lock is locked
 *	lock2 is locked
 */

#define	waiton(fd)	fcntl(fd, F_SETLKW, &lock)
#define	release(fd)	fcntl(fd, F_SETLK, &unlock)

void
procA()
{
	if (waiton(fd1) == -1) {
		perror("lock of fd1 failed\n");
		exit(1);
	}
	if (release(fd2) == -1) {
		perror("unlock of fd2 failed\n");
		exit(1);
	}
	if (waiton(fd2) == -1) {
		perror("lock of fd2 failed\n");
		exit(1);
	}
	if (release(fd1) == -1) {
		perror("unlock of fd1 failed\n");
		exit(1);
	}
}

void
procB()
{
	if (release(fd1) == -1) {
		perror("unlock of fd1 failed\n");
		exit(1);
	}
	if (waiton(fd2) == -1) {
		perror("lock of fd2 failed\n");
		exit(1);
	}
	if (waiton(fd1) == -1) {
		perror("lock of fd1 failed\n");
		exit(1);
	}
	if (release(fd2) == -1) {
		perror("unlock of fd2 failed\n");
		exit(1);
	}
}

int
main()
{
	char	buf[10000];
	int	pid;

	unlink("/tmp/lmbench-fcntl.1");
	unlink("/tmp/lmbench-fcntl.2");
	if ((fd1 = open("/tmp/lmbench-fcntl.1", O_CREAT|O_RDWR, 0666)) == -1) {
		perror("create");
		exit(1);
	}
	if ((fd2 = open("/tmp/lmbench-fcntl.2", O_CREAT|O_RDWR, 0666)) == -1) {
		perror("create");
		exit(1);
	}
	write(fd1, buf, sizeof(buf));
	write(fd2, buf, sizeof(buf));
	lock.l_type = F_WRLCK;
	lock.l_whence = 0;
	lock.l_start = 0;
	lock.l_len = 1;
	unlock = lock;
	unlock.l_type = F_UNLCK;
	if (waiton(fd1) == -1) {
		perror("lock1");
		exit(1);
	}
	if (waiton(fd2) == -1) {
		perror("lock2");
		exit(1);
	}
	if (fork()) {
		wait(0);
	}
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	}
	if (pid > 0) {
		waiton(fd1);
		BENCH(procA(), SHORT);
		micro("Fcntl lock latency", get_n());
		kill(pid, 15);
	} else {
		waiton(fd2);
		for ( ;; ) {
			procB();
		}
	}
	return (0);
}
E 2
I 1
E 1
