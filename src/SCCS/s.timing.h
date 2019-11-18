h53694
s 00001/00000/00044
d D 1.9 98/06/29 22:37:50 lm 10 9
c Redo to compile clean with -Wall.
cC
cHlm.bitmover.com
cK36570
cSAlpha2.11
cZ-07:00
e
s 00005/00001/00039
d D 1.8 98/05/07 15:38:53 staelin 9 8
c - changed return type of t_overhead()
c - added declaration for "getpagesize()"
cHhpisc8.lempel
cK33743
cZ-00:00
e
s 00002/00001/00038
d D 1.7 97/10/31 18:06:23 lm 8 7
c use_result -> use_int/pointer
cK28293
cZ-08:00
e
s 00023/00022/00016
d D 1.6 97/06/15 22:38:58 lm 7 6
c lint
cK25887
e
s 00001/00003/00037
d D 1.5 97/06/14 18:24:01 lm 6 5
c loop
cK23674
e
s 00006/00000/00034
d D 1.4 97/06/12 21:30:06 lm 5 4
c new timing interfaces.
cK27003
e
s 00001/00001/00033
d D 1.3 97/04/23 22:49:58 lm 4 3
c lint.
cK12853
cZ-07:00
e
s 00001/00000/00033
d D 1.2 96/12/16 12:30:15 lm 3 2
c *** empty log message ***
cK12750
e
s 00033/00000/00000
d D 1.1 96/11/13 16:15:00 lm 2 1
c Initial revision
cK10364
e
s 00000/00000/00000
d D 1.0 96/11/13 16:14:59 lm 1 0
cHlm.bitmover.com
cK21532
cPsrc/timing.h
cRb03b538da693ddd3
cZ-08:00
c______________________________________________________________________
e
u
U
f e 0
f b
f x 33
t
T
I 2
/* timing.c */
D 6
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
E 6

#define	uint64	unsigned long long

D 7
void	rusage(void);
void	timing(FILE *out);
void	start(struct timeval *tv);
uint64	stop(struct timeval *begin, struct timeval *end);
uint64	now(void);
double	Now(void);
uint64	delta(void);
E 7
I 7
char	*p64(uint64 big);
char	*p64sz(uint64 big);
E 7
double	Delta(void);
I 7
double	Now(void);
E 7
void	adjust(int usec);
void	bandwidth(uint64 bytes, uint64 times, int verbose);
I 7
int	bytes(char *s);
void	context(uint64 xfers);
uint64	delta(void);
int	get_enough(int);
uint64	get_n(void);
E 7
void	kb(uint64 bytes);
D 7
void	mb(uint64 bytes);
E 7
I 7
double	l_overhead(void);
char	last(char *s);
E 7
void	latency(uint64 xfers, uint64 size);
D 7
void	context(uint64 xfers);
void	nano(char *s, uint64 n);
E 7
I 7
void	mb(uint64 bytes);
E 7
void	micro(char *s, uint64 n);
void	micromb(uint64 mb, uint64 n);
void	milli(char *s, uint64 n);
I 7
void	morefds(void);
void	nano(char *s, uint64 n);
uint64	now(void);
E 7
void	ptime(uint64 n);
D 7
void	tvsub(struct timeval *tdiff, struct timeval *t1, struct timeval *t0);
double	timespent(void);
char	*p64(uint64 big);
char	*p64sz(uint64 big);
char	last(char *s);
int	bytes(char *s);
void	use_result(uint64 result);
E 2
I 3
D 4
E 7
I 7
void	rusage(void);
void	save_n(uint64);
E 7
int	settime(uint64 usecs);
E 3
E 4
I 4
void	settime(uint64 usecs);
E 4
I 5
I 7
void	start(struct timeval *tv);
uint64	stop(struct timeval *begin, struct timeval *end);
E 7
D 9
double	t_overhead(void);
I 6
D 7
E 9
I 9
uint64	t_overhead(void);
E 9
double	l_overhead(void);
E 6
int	get_enough(int);
uint64	get_n(void);
void	save_n(uint64);
E 7
I 7
double	timespent(void);
void	timing(FILE *out);
E 7
uint64	tvdelta(struct timeval *, struct timeval *);
D 7
uint64	usecs_spent();
E 5
E 7
I 7
void	tvsub(struct timeval *tdiff, struct timeval *t1, struct timeval *t0);
D 8
void	use_result(uint64 result);
E 8
I 8
void	use_int(int result);
void	use_pointer(void *result);
E 8
uint64	usecs_spent(void);
E 7
I 9
I 10
void	touch(char *buf, int size);
E 10

#if defined(hpux) || defined(__hpux)
int	getpagesize();
#endif
E 9
