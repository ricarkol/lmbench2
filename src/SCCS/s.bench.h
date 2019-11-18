h35522
s 00002/00000/00228
d D 1.34 00/10/30 13:42:36 staelin 35 34
c - Add protocol flags for TCP_SELECT
cC
cHhpli8.hpli.hpl.hp.com
cK24769
cZ+02:00
e
s 00001/00001/00227
d D 1.33 00/09/24 11:48:37 lm 34 33
c Fix a pmap buglet on openbsd.
cC
cHopenbsd.bitmover.com
cK18584
e
s 00007/00007/00221
d D 1.32 00/08/03 17:38:25 lm 33 32
c Use 15 bit port numbers, we must have a signed/unsigned bug.
cC
cHva.bitmover.com
cK14962
e
s 00007/00004/00221
d D 1.31 00/08/03 13:40:19 lm 32 31
c Do not use the portmapper.
cC
cHwork.bitmover.com
cK17151
cZ-07:00
e
s 00004/00004/00221
d D 1.30 00/07/31 16:41:16 staelin 31 30
c - Change type of iterations variable in BENCH_INNER from uint64 to u_long
cC
cK12055
e
s 00001/00000/00224
d D 1.29 00/06/26 10:05:52 staelin 30 29
c - Add #include <time.h> for aix
cC
cK11690
cZ+03:00
e
s 00047/00098/00177
d D 1.28 00/02/02 09:57:41 staelin 29 28
c - Added some #ifdefs as a start on the Windows port
c - Modified the BENCH macros so bad measurements are
c   ignored.  (e.g., measurements that are not greater
c   than zero are ignored)
c - Removed some old macros that aren't used anymore
cC
cHhpli8.hpli.hpl.hp.com
cK10193
cZ+02:00
e
s 00001/00001/00274
d D 1.27 98/06/29 23:49:44 lm 28 27
c lib_unix.j
cC
cK03233
cSAlpha2.11
e
s 00001/00001/00274
d D 1.26 98/06/29 22:37:21 lm 27 26
c Redo to compile clean with -Wall.
cHlm.bitmover.com
cK01373
e
s 00002/00002/00273
d D 1.25 98/05/19 17:20:46 lm 26 25
c Undef debug.
cHwork
cK01914
cZ-07:00
e
s 00052/00041/00223
d D 1.24 98/05/07 15:31:12 staelin 25 24
c - changed the result_t data structure
c - modified the BENCH* macros so t_overhead() and l_overhead()
c   are subtracted
cHhpisc8.lempel
cK05959
cZ-00:00
e
s 00008/00000/00256
d D 1.23 98/03/29 14:40:57 lm 24 23
c *** empty log message ***
cK31186
cZ-08:00
e
s 00018/00004/00238
d D 1.22 97/10/19 23:44:34 lm 23 22
c some stuff for bw_mem.c
cK22674
e
s 00001/00001/00241
d D 1.21 97/06/23 23:27:09 lm 22 21
c carl's diffs.
cK55292
e
s 00005/00003/00237
d D 1.20 97/06/15 22:38:58 lm 21 20
c lint
cK52754
e
s 00001/00001/00239
d D 1.19 97/06/15 14:23:34 lm 20 19
c different rpc #.
cK47807
e
s 00017/00011/00223
d D 1.18 97/06/14 18:23:42 lm 19 18
c more loop junk
cK47718
e
s 00009/00006/00225
d D 1.17 97/06/13 20:28:08 lm 18 17
c better timing loop.
cK35303
e
s 00092/00036/00139
d D 1.16 97/06/12 21:30:06 lm 17 16
c new bench.h macros.
cK33049
e
s 00040/00000/00135
d D 1.15 97/06/10 20:46:51 lm 16 15
c carl's version.
cK54672
e
s 00004/00004/00131
d D 1.14 97/05/27 16:03:14 lm 15 14
c more timing loop diddling.
cK44711
e
s 00013/00008/00122
d D 1.13 97/04/23 22:50:45 lm 14 13
c lint.
cK44391
cZ-07:00
e
s 00005/00004/00125
d D 1.12 97/02/12 19:28:01 lm 13 12
c *** empty log message ***
cK33585
e
s 00003/00001/00126
d D 1.11 96/11/13 16:09:37 lm 12 11
c opentoclose
cK30741
e
s 00050/00013/00077
d D 1.10 96/11/11 03:36:51 lm 11 10
c Auto adjusting changes.
cK28930
cZ-08:00
e
s 00001/00000/00089
d D 1.9 96/05/30 00:33:07 lm 10 9
c no what strings
cK14058
e
s 00002/00000/00087
d D 1.8 96/05/21 23:15:45 lm 9 8
c *** empty log message ***
cK12630
cZ-07:00
e
s 00006/00000/00081
d D 1.7 96/01/24 17:09:19 lm 8 7
c Make everything use XFERSIZE
cK10769
e
s 00001/00001/00080
d D 1.6 96/01/22 23:58:16 lm 7 6
c *** empty log message ***
cK62020
e
s 00002/00000/00079
d D 1.5 95/11/12 14:45:29 lm 6 5
c *** empty log message ***
cK61905
cZ-08:00
e
s 00001/00001/00078
d D 1.4 95/06/21 14:02:20 lm 5 4
c SOCKBUF -> 1MB
cK60120
cZ-07:00
e
s 00011/00003/00068
d D 1.3 95/03/10 11:27:31 lm 4 3
c SOCKOPT_ stuff for automagic socket optimizations.
cK60076
e
s 00003/00000/00068
d D 1.2 95/02/14 11:01:17 lm 3 2
c hacks for udp_bw.c
cK49655
e
s 00068/00000/00000
d D 1.1 94/11/18 00:49:48 lm 2 1
c Initial revision
cK43621
e
s 00000/00000/00000
d D 1.0 94/11/18 00:49:47 lm 1 0
cHlm.bitmover.com
cK26325
cPsrc/bench.h
cRad8c6e375dc87a5c
cV3
cZ-08:00
c______________________________________________________________________
e
u
U
f e 0
f x 0x21
f b
t
lmbench src
T
I 2
/*
D 25
D 26
 * $Id$
E 25
I 25
 * $Id: bench.h,v 1.22 1997/10/20 06:44:34 lm Exp lm $
E 25
E 26
I 26
 * $Id$
E 26
 */
I 16
#ifndef _BENCH_H
#define _BENCH_H

I 29
#ifdef WIN32
#include <windows.h>
typedef unsigned char bool_t;
#endif

E 29
E 16
I 17
I 24
#include	<assert.h>
E 24
#include        <ctype.h>
E 17
#include        <stdio.h>
I 29
#ifndef WIN32
E 29
#include        <unistd.h>
I 29
#endif
E 29
I 16
#include        <stdlib.h>
E 16
D 17
#include        <sys/types.h>
E 17
I 17
#include        <fcntl.h>
E 17
#include        <signal.h>
I 4
#include        <errno.h>
I 29
#ifndef WIN32
E 29
E 4
I 17
D 21
#include        <math.h>
E 21
I 21
#include        <strings.h>
I 29
#endif
E 29
E 21
#include        <sys/types.h>
I 29
#ifndef WIN32
E 29
#include        <sys/mman.h>
I 29
#endif
E 29
#include        <sys/stat.h>
I 29
#ifndef WIN32
E 29
#include        <sys/wait.h>
I 30
#include	<time.h>
E 30
#include        <sys/time.h>
#include        <sys/socket.h>
I 23
#include        <sys/un.h>
E 23
#include        <sys/resource.h>
#include	<rpc/rpc.h>
I 29
#endif
I 34
#define	NO_PORTMAPPER	/* needs to be up here, lib_*.h look at it */
E 34
E 29
#include	"stats.h"
#include	"timing.h"
#include	"lib_tcp.h"
#include	"lib_udp.h"
E 17
D 28

D 14
I 24
D 26
E 28
I 28
#include	"lib_unix.h"
E 28
#define DEBUG
E 26
I 26

E 26

#ifdef	DEBUG
#	define		debug(x) fprintf x
#else
#	define		debug(x)
#endif
I 32
D 34
#define	NO_PORTMAPPER
E 34
E 32
E 24
#ifdef	NO_PORTMAPPER
#define	TCP_XACT	3962
#define	TCP_CONTROL	3963
#define	TCP_DATA	3964
#define	TCP_CONNECT	3965
E 14
I 14
D 33
#ifdef	NO_PORTMAPPER	/* not recently tested */
D 32
#define	TCP_XACT	-3962
#define	TCP_CONTROL	-3963
#define	TCP_DATA	-3964
#define	TCP_CONNECT	-3965
E 32
I 32
#define	TCP_XACT	-61234
#define	TCP_CONTROL	-61235
#define	TCP_DATA	-61236
#define	TCP_CONNECT	-61237
#define	UDP_XACT	-61238
#define	UDP_DATA	-61239
E 33
I 33
#ifdef	NO_PORTMAPPER
I 35
#define TCP_SELECT	-31233
E 35
#define	TCP_XACT	-31234
#define	TCP_CONTROL	-31235
#define	TCP_DATA	-31236
#define	TCP_CONNECT	-31237
#define	UDP_XACT	-31238
#define	UDP_DATA	-31239
E 33
E 32
E 14
#else
I 35
#define	TCP_SELECT	(u_long)404038	/* XXX - unregistered */
E 35
#define	TCP_XACT	(u_long)404039	/* XXX - unregistered */
#define	TCP_CONTROL	(u_long)404040	/* XXX - unregistered */
#define	TCP_DATA	(u_long)404041	/* XXX - unregistered */
#define	TCP_CONNECT	(u_long)404042	/* XXX - unregistered */
#define	UDP_XACT 	(u_long)404032	/* XXX - unregistered */
I 3
#define	UDP_DATA 	(u_long)404033	/* XXX - unregistered */
E 3
#define	VERS		(u_long)1
#endif

I 3
D 4
I 8
#define	UNIX_CONTROL	"/tmp/lmbench.ctl"
#define	UNIX_DATA	"/tmp/lmbench.data"
#define	UNIX_LAT	"/tmp/lmbench.lat"

E 8
#ifndef	SOCKBUF
E 3
#define	SOCKBUF	(48*1024)	/* the magic size on suns */
I 3
#endif
E 3
E 4
I 4
/*
 * socket send/recv buffer optimizations
 */
D 13
#define	SOCKOPT_READ	0
#define	SOCKOPT_WRITE	1
#define	SOCKOPT_RDWR	2
#define	SOCKOPT_NONE	4
E 4
E 13
I 13
#define	SOCKOPT_READ	0x0001
#define	SOCKOPT_WRITE	0x0002
#define	SOCKOPT_RDWR	0x0003
#define	SOCKOPT_PID	0x0004
I 14
#define	SOCKOPT_REUSE	0x0008
E 14
#define	SOCKOPT_NONE	0
E 13

I 4
D 5
I 6
#ifndef SOCKBUF
E 6
#define	SOCKBUF		(128*1024)
E 5
I 5
#define	SOCKBUF		(1024*1024)
E 5
I 6
#endif
E 6
D 14
#define	SOCKSTEP	(16*1024)
E 14

E 4
I 8
I 9
#ifndef	XFERSIZE
E 9
#define	XFERSIZE	(64*1024)	/* all bandwidth I/O should use this */
I 9
#endif
E 9

E 8
D 29
#ifdef SYS5
E 29
I 29
#if defined(SYS5) || defined(WIN32)
E 29
#define	bzero(b, len)	memset(b, 0, len)
#define	bcopy(s, d, l)	memcpy(d, s, l)
#define	rindex(s, c)	strrchr(s, c)
#endif
D 12
D 23

E 12
#define	ulong	unsigned long
I 12
E 23
I 23
#define	gettime		usecs_spent
#define	streq		!strcmp
#define	ulong		unsigned long
E 23

I 29
#ifdef WIN32
#include <process.h>
#define getpid _getpid
#endif

E 29
I 23
#define	SMALLEST_LINE	32		/* smallest cache line size */
E 23
#define	TIME_OPEN2CLOSE

E 12
#define	GO_AWAY	signal(SIGALRM, exit); alarm(60 * 60);
I 10
D 11
D 18
#define	ENOUGH	400000
E 10
E 11
I 11
#define	SHORT	 1000000
D 17
#define	MEDIUM	 5000000
#define	LONGER	10000000	/* for networking, etc */
#define	ENOUGH	SHORT
I 16
E 17
I 17
#define	MEDIUM	 2000000
#define	LONGER	10000000	/* for networking data transfers */
#define	ENOUGH	1000000		/* default */
E 17
E 18
I 18
#define	REAL_SHORT	   50000
#define	SHORT	 	 1000000
#define	MEDIUM	 	 2000000
D 23
#define	LONGER		10000000	/* for networking data transfers */
E 23
I 23
#define	LONGER		 7500000	/* for networking data transfers */
E 23
#define	ENOUGH		REAL_SHORT
E 18

D 17
I 19
#define	TRIES		11

typedef struct {
D 25
	uint64	u;
	uint64	n;
E 25
I 25
	int	N;
	uint64	u[TRIES];
	uint64	n[TRIES];
E 25
} result_t;
D 25
void    insertinit(result_t *r, int n);
void    insertsort(uint64, uint64, result_t *, int);
E 25
I 25
void    insertinit(result_t *r);
void    insertsort(uint64, uint64, result_t *);
void	save_median();
void	save_minimum();
void	save_results(result_t *r);
void	get_results(result_t *r);
E 25

E 19
I 23
D 25
#define	BENCHO(loop_body, overhead_body, enough)  			\
	{ double __oh;							\
	BENCH(overhead_body, enough);					\
	__oh = gettime();						\
	__oh /= get_n();						\
	BENCH(loop_body, enough);					\
	settime((uint64)(gettime() - (get_n() * __oh)));		\
	}
E 25

E 23
D 25
#define LOOP(loop_body, loop_size, result, N, usecs, enough, t_overhead, l_overhead)		\
{									\
	static long	_N = 1;						\
timit:	(N) = 1;							\
E 17
I 17
#define	BENCH(loop_body, enough)  					\
D 22
	if (enough == 0) {						\
D 18
D 19
E 22
I 22
	if (enough == 0 || get_enough(enough) <= 100000) {		\
E 22
		uint64	tmp, tmp2, min = 1<<31;				\
E 18
I 18
		double	tmp, tmp2;					\
		uint64	min = 1<<31;					\
E 18
		int	i, n = 1;					\
		for (i = 0; i < 10; ++i) {				\
E 19
I 19
		result_t r[TRIES];					\
		int	i;						\
		uint64	u;						\
I 21
		double	tmp;						\
E 21
		insertinit(r, TRIES);					\
I 23
		loop_body;			/* warm the cache */	\
E 23
		for (i = 0; i < TRIES; ++i) {				\
E 19
D 23
			BENCH1(loop_body, 0);				\
D 19
D 21
E 23
I 23
			BENCH1(loop_body, enough);			\
E 23
			tmp = usecs_spent();				\
			tmp /= get_n();					\
			tmp2 = min; tmp2 /= n;				\
			if (tmp < tmp2) {				\
				min = usecs_spent(); n = get_n(); 	\
			}						\
E 19
I 19
			u = usecs_spent() - (get_n() * l_overhead());	\
E 21
I 21
			tmp = l_overhead();  tmp *= (double)get_n();	\
			u = usecs_spent() - (uint64)tmp;		\
E 21
			insertsort(u, get_n(), r, TRIES);		\
E 19
		}							\
D 19
		save_n((uint64)n); settime(min);			\
E 19
I 19
		save_n(r[TRIES/2].n); settime(r[TRIES/2].u);		\
E 19
	} else {							\
I 23
		if (enough < LONGER) {loop_body;} /* warm the cache */	\
E 23
E 25
I 25
#define	BENCHO(loop_body, overhead_body, enough) { 			\
	int 		__i, __N;					\
	double 		__oh;						\
	result_t 	__overhead, __r;				\
	insertinit(&__overhead); insertinit(&__r);			\
	__N = (enough == 0 || get_enough(enough) <= 100000) ? TRIES : 1;\
	if (enough < LONGER) {loop_body;} /* warm the cache */		\
	for (__i = 0; __i < __N; ++__i) {				\
		BENCH1(overhead_body, enough);				\
D 29
		insertsort(gettime(), get_n(), &__overhead);		\
E 29
I 29
		if (gettime() > 0) 					\
			insertsort(gettime(), get_n(), &__overhead);	\
E 29
E 25
		BENCH1(loop_body, enough);				\
I 25
D 29
		insertsort(gettime(), get_n(), &__r);			\
E 29
I 29
		if (gettime() > 0) 					\
			insertsort(gettime(), get_n(), &__r);		\
E 29
E 25
	}								\
I 25
	for (__i = 0; __i < __r.N; ++__i) {				\
		__oh = __overhead.u[__i] / (double)__overhead.n[__i];	\
		__r.u[__i] -= (uint64)((double)__r.n[__i] * __oh);	\
	}								\
	save_results(&__r);						\
}
E 25

I 25
#define	BENCH(loop_body, enough) { 					\
D 27
	long		__i, __N, __n = 1;				\
E 27
I 27
	long		__i, __N;					\
E 27
	result_t 	__r;						\
	insertinit(&__r);						\
	__N = (enough == 0 || get_enough(enough) <= 100000) ? TRIES : 1;\
	if (enough < LONGER) {loop_body;} /* warm the cache */		\
	for (__i = 0; __i < __N; ++__i) {				\
		BENCH1(loop_body, enough);				\
D 29
		insertsort(gettime(), get_n(), &__r);			\
E 29
I 29
		if (gettime() > 0) 					\
			insertsort(gettime(), get_n(), &__r);		\
E 29
	}								\
	save_results(&__r);						\
}
E 25

#define	BENCH1(loop_body, enough) { 					\
I 25
	double		__usecs;					\
	BENCH_INNER(loop_body, enough);  				\
	__usecs = gettime();						\
	__usecs -= t_overhead() + get_n() * l_overhead();		\
D 29
	settime((uint64)__usecs);					\
E 29
I 29
	settime(__usecs >= 0. ? (uint64)__usecs : 0.);			\
E 29
}
	
#define	BENCH_INNER(loop_body, enough) { 				\
E 25
D 29
	static long	__iterations = 1;				\
E 29
I 29
D 31
	static uint64	__iterations = 1;				\
E 31
I 31
	static u_long	__iterations = 1;				\
E 31
E 29
D 25
	long		__n;						\
	double		__result;					\
E 25
	int		__enough = get_enough(enough);			\
I 25
D 29
	long		__n;						\
E 29
I 29
D 31
	uint64		__n;						\
E 31
I 31
	u_long		__n;						\
E 31
E 29
	double		__result = 0.;					\
E 25
									\
E 17
D 23
D 25
	loop_body;	/* warm the instruction cache */		\
I 17
E 23
	for (;;) {							\
E 17
E 25
I 25
	while(__result < 0.95 * __enough) {				\
E 25
D 29
	start(0);							\
D 17
	for ((N) = _N; (N) > 0; --(N)) {				\
E 17
I 17
	for (__n = __iterations; __n > 0; __n--) {			\
E 17
		loop_body;						\
	}								\
D 17
	usecs = stop(0,0);						\
E 17
I 17
	__result = stop(0,0);						\
D 18
D 25
	/* printf("u=%.0f n=%d\n", __result,__iterations); /**/		\
E 18
I 18
	/* printf("u=%.0f n=%d\n", __result,__iterations); 		\
	*/								\
E 18
	save_n((uint64)__iterations);					\
	__result -= t_overhead();					\
E 25
	if (__result < 0.99 * __enough || __result > 1.2 * __enough) {	\
		if (__result > 150) {					\
			double	tmp = __iterations / __result;		\
			tmp *= 1.1 * __enough;				\
D 21
			__iterations = tmp + 1;				\
E 21
I 21
			__iterations = (long)(tmp + 1);			\
E 21
		} else							\
			__iterations *= 10;				\
	}								\
E 29
I 29
		start(0);						\
		for (__n = __iterations; __n > 0; __n--) {		\
			loop_body;					\
		}							\
		__result = stop(0,0);					\
		if (__result < 0.99 * __enough 				\
		    || __result > 1.2 * __enough) {			\
			if (__result > 150.) {				\
				double	tmp = __iterations / __result;	\
				tmp *= 1.1 * __enough;			\
D 31
				__iterations = (uint64)(tmp + 1);	\
E 31
I 31
				__iterations = (u_long)(tmp + 1);	\
E 31
			} else {					\
D 31
				if (__iterations > (uint64)1<<40) {	\
E 31
I 31
				if (__iterations > (u_long)1<<27) {	\
E 31
					__result = 0.;			\
					break;				\
				}					\
				__iterations <<= 3;			\
			}						\
		}							\
E 29
D 25
	if (__result >= 0.95 * __enough) 				\
		break;							\
	} /* for */							\
	settime((uint64)(usecs_spent() - t_overhead()));		\
E 25
I 25
	} /* while */							\
	save_n((uint64)__iterations); settime((uint64)__result);	\
E 25
D 29
}

#if 0
E 17
	/*  \
D 17
	   fprintf(stderr, "\tN=%d u=%lu", _N, (unsigned long)usecs);	\
E 17
I 17
	   fprintf(stderr, "\tN=%d u=%lu", __interations, (unsigned long)usecs);	\
E 17
	   fflush(stderr);\
D 17
	   fprintf(stderr, " c=%.2f\tr=%.2f\n", (double)usecs/_N,	\
		((double)usecs - t_overhead - _N * l_overhead)		\
		/ (double)(_N * (loop_size)));  			\
E 17
I 17
	   fprintf(stderr, " c=%.2f\tr=%.2f\n", (double)usecs/__interations,	\
		((double)usecs - t_overhead - __interations * l_overhead)		\
		/ __interations );  			\
E 17
	*/ \
D 17
	result  = (double)usecs;					\
	result -= t_overhead + _N * l_overhead;				\
	result /= (double)(_N * loop_size);				\
	if ((double)usecs < 0.99 * (double)enough			\
	    || (double)usecs > 1.2 * (double)enough) {			\
		if (usecs > 150)					\
			_N = (int)(1.1 * (double)enough * ((double)_N /	\
					(double)usecs)) + 1; 		\
		else							\
			_N *= 10;					\
	}								\
	if ((double)usecs < 0.95 * (double)enough) 			\
		goto timit;						\
	N = _N;								\
}
E 17
I 17
#endif
E 17

E 16
/*
 * Standard timing loop.  Usage:
 *
 *	LOOP_FIRST(N, usecs, time)
 *	<code that you want timed>
 *	LOOP_LAST(N, usecs, time)
 *
 * time is how long you think it should run to be accurate.
 * "N" is a variable that will be set to the number of times it 
 * took to get "usecs" duration.  You then use N & usecs to print
 * out your results.
 * 
 * Notes: 
 *
 * Adjust the amount of time proportional to how
 * far we need to go.  We want time/usecs to be ~1.
 *
 * For systems with low resolution clocks, usecs can
 * be 0 or very close to 0.  We don't know how 
 * much time we spent, it could be anywhere from
 * 1 to 9999 usecs.  We pretend it was 1000 usecs.
 * The 129 value is because some systems bump the
 * timeval each time you call gettimeofday().
 */
#define	LOOP_FIRST(N, usecs, time)			\
	N = 0;						\
	do {						\
		if (!N) {				\
			N = 1;				\
		} else {				\
D 17
			double	adj;			\
			int	n;			\
E 17
I 17
			double	__adj;			\
			int	__n;			\
E 17
			if (usecs <= 129) {		\
				usecs = 1000;		\
			}				\
D 15
D 17
			adj = (time * 1.5)/usecs;	\
E 15
I 15
			adj = (int)((time * 1.5)/usecs + .9);	\
E 15
			n = N * adj;			\
I 15
			/*printf("\tN=%.2f u=%.2f a=%.2f n=%d\n", \
			    (double)N, (double)usecs, adj, n);  \
E 17
I 17
			__adj = (int)((time * 1.5)/usecs + .9);	\
			__n = N * __adj;			\
			/* printf("\tN=%.2f u=%.2f a=%.2f n=%d\n", \
			    (double)N, (double)usecs, __adj, __n);  \
E 17
			*/ \
E 15
D 17
			N = n <= N ? N+1 : n;		\
E 17
I 17
			N = __n <= N ? N+1 : __n;	\
E 17
		}					\
D 14
		usecs = N;				\
E 14
I 14
timit:		usecs = N;				\
E 14
		start(0);				\
		while (usecs--) {
E 11

D 11
void	exit();
void	start();
ulong	stop();
D 7
void	adjust();
E 7
I 7
ulong	adjust();
E 7
void	rusage();
void	bandwidth();
void	kb();
void	mb();
void	micro();
void	milli();
void	ptime();
void	tvsub();
E 11
I 11
#define	LOOP_LAST(N, usecs, time)			\
		}					\
D 14
	} while ((usecs = stop(0, 0)) < time);
E 11
E 14
I 14
		usecs = stop(0,0);			\
D 15
		/*printf("\tN=%.2f u=%.2f c=%.2f\n",	\
		(double)N, (double)usecs, (double)usecs/N);  \
		*/ \
E 15
	} while (usecs < time);				
E 14

I 11
I 17
#define	OBENCH(test, enough, result) { 				\
	int	__bench_n, __bench_i, __bench_enough;		\
								\
	__bench_enough = get_enough(enough);			\
	test;							\
	LOOP_FIRST(__bench_n, __bench_i, __bench_enough);	\
	test;							\
	LOOP_LAST(__bench_n, __bench_i, __bench_enough);	\
	result = __bench_i;					\
	result -= t_overhead();					\
	result /= __bench_n;					\
	/*							\
	printf("usecs=%d n=%d c=%f r=%f\n", __bench_i, __bench_n, \
	    (double)__bench_i/__bench_n, result);		\
	*/							\
E 29
}
E 17

E 11
I 14

E 14
/*
 * Generated from msg.x which is included here:

	program XACT_PROG {
	    version XACT_VERS {
		char
		RPC_XACT(char) = 1;
    	} = 1;
	} = 3970;

 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <rpc/types.h>

D 20
#define XACT_PROG ((u_long)3970)
E 20
I 20
#define XACT_PROG ((u_long)404040)
E 20
#define XACT_VERS ((u_long)1)
#define RPC_XACT ((u_long)1)
#define RPC_EXIT ((u_long)2)
extern char *rpc_xact_1();
extern char *client_rpc_xact_1();
E 2
I 16

#endif /* _BENCH_H */
E 16
