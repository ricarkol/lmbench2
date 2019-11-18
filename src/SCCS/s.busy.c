h30431
s 00010/00000/00000
d D 1.1 99/12/08 09:18:28 lm 2 1
cC
cF1
cO-rw-r--r--
e
s 00000/00000/00000
d D 1.0 99/12/08 09:18:28 lm 1 0
c BitKeeper file /home/lm/lmbench/src/busy.c
cHwork.bitmover.com
cPsrc/busy.c
cR66f642dc353072aa
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
volatile int i;

main()
{

	nice(10);
	for (;;) getppid();
	//for (;;) i++;
	exit(i);
}
E 2
I 1
E 1
