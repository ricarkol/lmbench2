h43473
s 00001/00001/00007
d D 1.3 00/01/31 16:29:28 lm 4 3
c Updates for BitKeeper.
cC
cHlm.bitmover.com
e
s 00002/00002/00006
d D 1.2 98/03/30 01:02:55 lm 3 2
c SCCS
cC
cHwork.home
e
s 00008/00000/00000
d D 1.1 94/11/23 17:44:02 lm 2 1
c Initial revision
e
s 00000/00000/00000
d D 1.0 94/11/23 17:44:01 lm 1 0
cHlm.bitmover.com
cPscripts/Makefile
cR5e85834849ee718e
cZ-08:00
c______________________________________________________________________
e
u
U
f e 0
f b
f x 34
t
T
I 2
# Makefile for lmbench scripts subdir.
#$Id$

get:
D 3
	rccs get -s 
E 3
I 3
	get -s 
E 3

clean:
D 3
	rccs clean -e -s
E 2
E 3
I 3
D 4
	clean
E 4
I 4
	-bk clean
E 4
E 3
