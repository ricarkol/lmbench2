h24570
s 00097/00000/00000
d D 1.1 97/10/19 23:49:05 lm 2 1
c Initial revision
cC
cK00059
cSAlpha2.11
e
s 00000/00000/00000
d D 1.0 97/10/19 23:49:04 lm 1 0
cHlm.bitmover.com
cK55858
cPsrc/lib_unix.c
cR98550639d79890cd
cZ-07:00
c______________________________________________________________________
e
u
U
f e 0
f b
f x 33
t
lmbench lib_unix.c
T
I 2
/*
 * unix_lib.c - routines for managing UNIX connections.
 *
 * Positive port/program numbers are RPC ports, negative ones are UNIX ports.
 *
 * Copyright (c) 1994-1996 Larry McVoy.
 */
#define		_LIB /* bench.h needs this */
#include	"bench.h"

/*
 * Get a UNIX socket, bind it.
 */
int
unix_server(char *path)
{
	int	sock;
	struct	sockaddr_un s;

#ifdef	LIBUNIX_VERBOSE
	fprintf(stderr, "unix_server(%s, %u)\n", prog, rdwr);
#endif
	if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}
	bzero((void*)&s, sizeof(s));
	s.sun_family = AF_UNIX;
	strcpy(s.sun_path, path);
	if (bind(sock, (struct sockaddr*)&s, sizeof(s)) < 0) {
		perror("bind");
		exit(2);
	}
	if (listen(sock, 100) < 0) {
		perror("listen");
		exit(4);
	}
	return (sock);
}

/*
 * Unadvertise the socket
 */
int
unix_done(int sock, char *path)
{
	close(sock);
	unlink(path);
	return (0);
}

/*
 * Accept a connection and return it
 */
int
unix_accept(int sock)
{
	struct	sockaddr_un s;
	int	newsock, namelen;

	namelen = sizeof(s);
	bzero((void*)&s, namelen);

retry:
	if ((newsock = accept(sock, (struct sockaddr*)&s, &namelen)) < 0) {
		if (errno == EINTR)
			goto retry;
		perror("accept");
		exit(6);
	}
	return (newsock);
}

/*
 * Connect to the UNIX socket advertised as "path" and
 * return the connected socket.
 */
int
unix_connect(char *path)
{
	struct	sockaddr_un s;
	int	sock;

	if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}
	bzero((void*)&s, sizeof(s));
	s.sun_family = AF_UNIX;
	strcpy(s.sun_path, path);
	if (connect(sock, (struct sockaddr*)&s, sizeof(s)) < 0) {
		perror("connect");
		exit(4);
	}
	return (sock);
}

E 2
