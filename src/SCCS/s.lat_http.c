h03150
s 00005/00007/00112
d D 1.5 98/06/29 22:37:32 lm 6 5
c Redo to compile clean with -Wall.
cC
cK34536
cSAlpha2.11
cZ-07:00
e
s 00009/00001/00110
d D 1.4 98/02/25 10:12:30 lm 5 4
c add echo flag.
cK35460
e
s 00021/00011/00090
d D 1.3 97/10/31 18:07:11 lm 4 3
c stop feature
cK27839
e
s 00010/00002/00091
d D 1.2 97/10/30 18:32:27 lm 3 2
c fix a bug w/ numeric hostnames (IP).
cK19562
cZ-08:00
e
s 00093/00000/00000
d D 1.1 97/10/19 23:48:53 lm 2 1
c Initial revision
cK05149
e
s 00000/00000/00000
d D 1.0 97/10/19 23:48:52 lm 1 0
cHlm.bitmover.com
cK58926
cPsrc/lat_http.c
cRbb3831f9effa4c1c
cZ-07:00
c______________________________________________________________________
e
u
U
f e 0
f b
f x 33
t
lmbench lat_http.c
T
I 2
/*
 * lat_http.c - simple HTTP transaction latency test
 *
 * usage: lat_http hostname [port] < filelist
 *
 * Copyright (c) 1994-6 Larry McVoy.  Distributed under the FSF GPL with
 * additional restriction that results may published only if
 * (1) the benchmark is unmodified, and
 * (2) the version in the sccsid below is included in the report.
 * Support for this development by Sun Microsystems is gratefully acknowledged.
 */
char	*id = "$Id$\n";

#include "bench.h"

char	*buf;
int	debug;
I 3
D 4
I 5
int	echo;
E 5
char	*rest = 
"Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, */*\r\n\r\n\n";
E 3
E 4

I 6
int
E 6
http(char *server, char *file, int prog)
{
	int     sock;
	int     n;
	int	b = 0;

	sock = tcp_connect(server, prog, SOCKOPT_REUSE);
D 3
	sprintf(buf, "GET /%s HTTP/1.0\r\n\r\n", file);
E 3
I 3
	sprintf(buf, "GET /%s HTTP/1.0\r\n\r\n\n", file);
E 3
	if (debug) {
		printf(buf);
	}
	write(sock, buf, strlen(buf));
I 3
D 4
	/* write(sock, rest, strlen(rest)); */
E 3
E 4
	while ((n = read(sock, buf, XFERSIZE)) > 0) {
I 3
D 4
		/*
		if (debug) {
			write(1, buf, n);
		}
		*/
E 3
E 4
		b += n;
I 5
		if (echo) {
			write(1, buf, n);
		}
E 5
	}
	close(sock);
	if (debug) {
		printf("Got %d\n", b);
	}
	return (b);
}

I 4
I 6
void
E 6
killhttp(char *server, int prog)
{
	int     sock;

	sock = tcp_connect(server, prog, SOCKOPT_REUSE);
	write(sock, "EXIT", 4);
	close(sock);
}

E 4
I 6
void chop(register char *s) { while (*s && *s != '\n') s++; *s = 0; }

E 6
int
main(int ac, char **av)
{
	char	*server;
D 6
	int     pid = getpid(), i, prog;
E 6
I 6
	int     i, prog;
E 6
	uint64	total = 0;
	uint64	usecs = 0;
	double	avg;
	char	*name = av[0];
	char	file[1024];
I 4
D 6
	int	kill = 0;
E 4
E 6

	if (ac > 1 && !strcmp("-d", av[1])) {
		debug++;
		ac--, av++;
	}
I 5
	if (ac > 1 && !strcmp("-e", av[1])) {
		echo++;
		ac--, av++;
	}
E 5
	if (ac < 2) {
D 4
D 5
		fprintf(stderr, "Usage: %s [-d] serverhost [port] < list\n",
E 4
I 4
		fprintf(stderr, "Usage: %s [-d] [-]serverhost [port] < list\n",
E 4
E 5
I 5
		fprintf(stderr, "Usage: %s [-d] [-e] [-]serverhost [port] < list\n",
E 5
		    name);
		exit(1);
	}
	server = av[1];
	av++, ac--;	/* eat server */
D 3
	if (atoi(av[ac - 1]) != 0) {
E 3
I 3
	if (ac > 1 && atoi(av[ac - 1]) != 0) {
E 3
		prog = -atoi(av[ac - 1]);
		ac--;	/* eat port */
	} else {
		prog = -80;
	}
I 4
	if (server[0] == '-') {
		server++;
		killhttp(server, prog);
		exit(0);
	}
E 4
	i = 0;
D 4
	start(0);
E 4
	buf = valloc(XFERSIZE);
I 4
	bzero(buf, XFERSIZE);
E 4
	while (fgets(file, sizeof(file), stdin)) {
		chop(file);
I 4
		start(0);
E 4
		total += http(server, file, prog);
I 4
		usecs += stop(0,0);
E 4
		i++;
	}
D 4
	usecs += stop(0,0);
E 4
	avg = total;
	avg /= (i - 1);
	if (avg > 1000) {
		avg /= 1000;
		fprintf(stderr, "Avg xfer: %.1fKB, ", avg);
	} else {
		fprintf(stderr, "Avg xfer %d, ", (int)avg);
	}
I 4
	settime(usecs);
E 4
	latency((uint64)1, total);
I 4
	exit(0);
E 4
}

D 6
chop(register char *s)
{
	while (*s && *s != '\n') s++;
	*s = 0;
}
E 2
E 6
