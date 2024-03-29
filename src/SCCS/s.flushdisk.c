h24870
s 00007/00003/00035
d D 1.3 98/06/29 23:49:57 lm 4 3
c bugs.
cC
cK39708
cSAlpha2.11
cZ-07:00
e
s 00022/00001/00016
d D 1.2 97/10/31 18:07:27 lm 3 2
c make it have a standalone feature so that it can tell you if it
c flushed (Linux only).
cK35131
cZ-08:00
e
s 00017/00000/00000
d D 1.1 97/10/24 13:49:48 lm 2 1
c Initial revision
cK19467
e
s 00000/00000/00000
d D 1.0 97/10/24 13:49:47 lm 1 0
cHlm.bitmover.com
cK14057
cPsrc/flushdisk.c
cR816a5afb22774a0
cZ-07:00
c______________________________________________________________________
e
u
U
f e 0
f b
f x 33
t
lmbench flushdisk
T
I 2
#ifdef	linux
/*
 * flushdisk() - linux block cache clearing
 */

#include	<stdio.h>
#include	<sys/types.h>
I 4
#include	<fcntl.h>
E 4
#include	<unistd.h>
#include	<stdlib.h>
I 4
#include	<sys/ioctl.h>
E 4
#include	<linux/fs.h>

I 4
int
E 4
flushdisk(int fd)
{
D 3
	ioctl(fd, BLKFLSBUF, 0);
E 3
I 3
	int	ret = ioctl(fd, BLKFLSBUF, 0);
E 3
	usleep(100000);
I 3
	return (ret);
E 3
}
I 3

E 3
#endif
E 2
I 3

#ifdef	MAIN
I 4
int
E 4
main(int ac, char **av)
{
#ifdef	linux
	int	fd;
	int	i;

	for (i = 1; i < ac; ++i) {
D 4
		i = open(av[i], 0);
		if (flushdisk(i)) {
E 4
I 4
		fd = open(av[i], 0);
		if (flushdisk(fd)) {
E 4
			exit(1);
		}
D 4
		close(i);
E 4
I 4
		close(fd);
E 4
	}
#endif
	exit(0);
}
#endif
E 3
