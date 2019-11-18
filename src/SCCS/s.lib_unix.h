h41356
s 00008/00000/00000
d D 1.1 99/12/08 09:17:17 lm 2 1
cC
cF1
cO-rw-r--r--
e
s 00000/00000/00000
d D 1.0 99/12/08 09:17:17 lm 1 0
c BitKeeper file /home/lm/lmbench/src/lib_unix.h
cHwork.bitmover.com
cPsrc/lib_unix.h
cRa4141822484ace9
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
/* lib_unix.c */
#ifndef	_LIB_UNIX_H_
#define	_LIB_UNIX_H_
int unix_server(char *path);
int unix_done(int sock, char *path);
int unix_accept(int sock);
int unix_connect(char *path);
#endif
E 2
I 1
E 1
