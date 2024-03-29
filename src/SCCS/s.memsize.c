h50427
s 00029/00011/00091
d D 1.13 99/09/02 22:47:55 lm 14 13
c dunno
cC
cHwork.bitmover.com
cK28066
e
s 00004/00004/00098
d D 1.12 98/06/29 22:37:48 lm 13 12
c Redo to compile clean with -Wall.
cK11840
cSAlpha2.11
e
s 00002/00002/00100
d D 1.11 97/06/25 10:25:01 lm 12 11
c 64 bit types
cK09868
e
s 00001/00001/00101
d D 1.10 97/06/15 22:38:58 lm 11 10
c lint
cK08508
e
s 00000/00001/00102
d D 1.9 97/06/12 21:30:06 lm 10 9
c new bench.h macros.
cK08246
cZ-07:00
e
s 00004/00003/00099
d D 1.8 96/11/11 03:36:51 lm 9 8
c Auto adjusting changes.
cK09929
e
s 00009/00005/00093
d D 1.7 96/11/08 20:04:25 lm 8 7
c gcc -Wall cleanup.
cK08157
cZ-08:00
e
s 00008/00004/00090
d D 1.6 95/10/25 18:03:42 lm 7 6
c fixing a bug.
cK00920
e
s 00023/00036/00071
d D 1.5 95/10/25 16:06:33 lm 6 5
c *** empty log message ***
cK62740
e
s 00002/00002/00105
d D 1.4 95/08/31 17:17:26 lm 5 4
c remove pagesize dependcy.
cK18481
e
s 00007/00004/00100
d D 1.3 95/08/30 20:41:49 lm 4 3
c *** empty log message ***
cK19335
e
s 00035/00019/00069
d D 1.2 95/08/03 21:05:56 lm 3 2
c take a max count; print the results.
cK14222
cZ-07:00
e
s 00088/00000/00000
d D 1.1 95/02/14 11:03:38 lm 2 1
c Initial revision
cK59731
e
s 00000/00000/00000
d D 1.0 95/02/14 11:03:37 lm 1 0
cHlm.bitmover.com
cK11395
cPsrc/memsize.c
cR37f652d1bab57b36
cZ-08:00
c______________________________________________________________________
e
u
U
f e 0
f b
f x 33
t
Figure out memory size.
T
I 2
/*
D 3
 * memsize_malloc.c - figure out how big the malloc area is.
E 3
I 3
 * memsize.c - figure out how much memory we have to use.
E 3
 *
D 3
 * Usage: memsize_malloc
E 3
I 3
 * Usage: memsize [max_wanted_in_MB]
E 3
 *
 * Copyright (c) 1995 Larry McVoy.  Distributed under the FSF GPL with
 * additional restriction that results may published only if
 * (1) the benchmark is unmodified, and
 * (2) the version in the sccsid below is included in the report.
 */
char	*id = "$Id$\n";

D 9
D 10
#include "timing.c"
E 9
I 9
#include "timing.h"
E 10
#include "bench.h"
E 9

#define	CHK(x)	if ((x) == -1) { perror("x"); exit(1); }

#ifndef	TOO_LONG
D 3
D 6
#define	TOO_LONG	500	/* usecs */
E 3
I 3
#define	TOO_LONG	200	/* usecs */
E 3
E 6
I 6
#define	TOO_LONG	10	/* usecs */
E 6
#endif

D 8
main(ac, av)
	char **av;
E 8
I 8
void	timeit(char *where, int size);
D 12
D 13
void	touch(char *p, char *end, int range);
E 12
I 12
static	void touch(char *p, char *end, int range);
E 12
E 13
I 13
static	void touchRange(char *p, char *end, int range);
E 13

int
main(int ac, char **av)
E 8
{
D 3
	char *where;
	int	size = 128 * 1024 * 1024;
E 3
I 3
	char	*where;
	char	*tmp;
	size_t	size;
E 3
I 4
	size_t	max;
E 4

D 3
	write(2, id, strlen(id));
	for (where = 0; !where; where = malloc(size))
		size -= 1024*1024;
	printf("Alloced %dMB\n", size>>20);
E 3
I 3
	if (ac == 2) {
D 4
		size = atoi(av[1]) * 1024 * 1024;
E 4
I 4
		max = size = atoi(av[1]) * 1024 * 1024;
E 4
	} else {
D 4
		size = 1024 * 1024 * 1024;
E 4
I 4
		max = size = 1024 * 1024 * 1024;
E 4
	}
	/*
	 * Binary search down and then linear search up
	 */
	for (where = 0; !where; where = malloc(size)) {
		size >>= 1;
	}
D 14
	free(where);
I 6
	tmp = 0;
E 6
	do {
I 6
		if (tmp) {
			free(tmp);
		}
E 14
I 14
	while (size < max) {
		free(where);
E 14
E 6
		size += 1024*1024;
D 14
		tmp = malloc(size);
D 6
		if (tmp)
E 6
I 6
		if (tmp) {
E 6
			where = tmp;
D 4
I 6
I 7
		} else {
E 14
I 14
		where = malloc(size);
		if (!where) {
E 14
			size -= 1024*1024;
I 14
			where = malloc(size);
			if (!where) {
				perror("malloc");
				exit(1);
			}
			break;
E 14
E 7
		}
E 6
	} while (tmp);
E 3
E 4
I 4
D 14
	} while (tmp && (size < max));
E 14
I 14
	} 
E 14
E 4
	timeit(where, size);
D 11
	exit(0);
E 11
I 11
	return (0);
E 11
}

D 6
D 8
/*
 * Go backwards through the file in 4K chunks, increasing size until
D 3
 * we start having to page.
E 3
I 3
 * we start to page.
E 3
 * If the pages are all in memory, we should be able to do a reference
 * in less than 5 usecs.  
 */
E 6
timeit(where, size)
	char	*where;
E 8
I 8
void
timeit(char *where, int size)
E 8
{
D 6
	char	*end = where + size - 16*1024;
E 6
	int	sum = 0;
	int	n;
D 7
	int	range;
D 6
E 7
	char	*p;
D 5
	int	psize = getpagesize();
E 5
I 5
	int	stride = 4096;
E 5
E 6
I 6
	char	*end = where + size;
E 6
I 7
	int	range;
E 7

D 3
	/*
	 * Try and clean dirty pages
	 */
	sync();
	sleep(2);

E 3
	if (size < 1024*1024 - 16*1024) {
D 3
		printf("Bad size\n");
E 3
I 3
		fprintf(stderr, "Bad size\n");
E 3
		return;
	}

D 6
	for (range = 1024*1024; range < size - 16*1024; range += 1024*1024) {
		touch(where, range);
I 3
		/*
		 * Try and clean dirty pages so pageout can dump them.
		 */
		sync();
		sleep(1);
E 3
E 6
I 6
	/* Go up in 1MB chunks until we find one too big */
	for (range = 2*1024*1024; range <= size; range += 1<<20) {
D 13
		touch(where, end, range);
E 6
D 9
E 13
I 13
		touchRange(where, end, range);
E 13
		start();
D 5
D 6
E 9
I 9
		start(0);
E 9
D 13
		for (n = 0, p = where + range; p >= where; p -= psize) {
E 5
I 5
		for (n = 0, p = where + range; p >= where; p -= stride) {
E 5
			sum += *p;
			n++;
		}
		sum = stop(sum);

		/*
		 * We did N references in sum usecs.
		 */
D 3
		printf("%dMB range, %d usecs/reference\n",
E 3
I 3
		fprintf(stderr, "%dMB range, %d usecs/reference\n",
E 3
		    range/(1024*1024), sum/n);
D 3
E 6
I 6
		touch(where, end, range);
D 9
E 13
I 13
		touchRange(where, end, range);
E 13
		sum = stop();
E 9
I 9
		sum = stop(0, 0);
E 9
		n = range / 4096;
E 6
		if ((sum / n) > TOO_LONG)
E 3
I 3
		if ((sum / n) > TOO_LONG) {
D 6
			printf("%d\n", (range - 1024*1024) >> 20);
E 3
D 4
E 6
I 6
			fprintf(stderr, "\n");
			printf("%d\n", (range>>20) - 1);
E 6
			break;
I 3
E 4
I 4
			exit(0);
E 4
		}
E 3
I 6
D 8
		fprintf(stderr, "%dMB OK\r", range/(1024*1024), sum/n);
E 6
E 8
I 8
		fprintf(stderr, "%dMB OK\r", range/(1024*1024));
E 8
	}
I 4
D 6
	printf("%d\n", size>>20);

E 4
E 6
I 6
	fprintf(stderr, "\n");
	printf("%d\n", (size>>20));
E 6
}

D 6
I 8
D 12
void
E 8
E 12
I 12
static void
E 12
D 13
touch(char *p, int range)
E 6
I 6
touch(char *p, char *end, int range)
E 6
E 13
I 13
touchRange(char *p, char *end, int range)
E 13
{
D 6
D 7
	while (range > 0) {
E 6
I 6
	while (range > 0 && (p < end)) {
E 6
		*p = 0;
D 6
		p += 1024;
		range -= 1024;
E 6
I 6
		p += 4096;
E 7
I 7
	char	*tmp = p;

	while (range > 0 && (tmp < end)) {
		*tmp = 0;
		tmp += 4096;
E 7
		range -= 4096;
E 6
	}
I 14
}

#undef	malloc
#undef	free

char	*
Malloc(int n)
{
	char	*p = malloc(n);

	fprintf(stderr, "malloc(%d) = %x\n", n, p);
	return (p);
}

Free(char *p)
{
	fprintf(stderr, "free(%x)\n", p);
	free(p);
E 14
}
E 2
