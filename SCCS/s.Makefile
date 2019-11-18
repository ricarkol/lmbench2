h16623
s 00005/00003/00068
d D 1.16 00/01/31 16:29:28 lm 17 16
c Updates for BitKeeper.
cC
cHlm.bitmover.com
e
s 00011/00015/00060
d D 1.15 98/03/30 01:00:54 lm 16 15
c Convert to SCCS
cC
cHwork.home
e
s 00006/00000/00069
d D 1.14 98/03/29 14:39:44 lm 15 14
c mkrelease.
cZ-08:00
e
s 00003/00003/00066
d D 1.13 97/10/25 10:52:22 lm 14 13
c I dunno why Carl thinks this helps, but OK.
e
s 00010/00006/00059
d D 1.12 97/10/24 13:51:53 lm 13 12
c *** empty log message ***
e
s 00005/00005/00060
d D 1.11 97/06/13 21:45:14 lm 12 11
c *** empty log message ***
e
s 00001/00001/00064
d D 1.10 95/10/25 22:12:42 lm 11 10
c *** empty log message ***
e
s 00001/00001/00064
d D 1.9 95/10/25 22:09:52 lm 10 9
c fix get.
e
s 00001/00001/00064
d D 1.8 95/09/28 11:15:47 lm 9 8
c bin
cZ-07:00
e
s 00001/00001/00064
d D 1.7 95/03/10 18:32:05 lm 8 7
c better clean target.
e
s 00012/00012/00053
d D 1.6 94/12/05 15:25:04 lm 7 6
c $(MAKE)
e
s 00001/00001/00064
d D 1.5 94/11/25 17:52:57 lm 6 5
c split.
e
s 00001/00000/00064
d D 1.4 94/11/25 17:33:45 lm 5 4
c clean
e
s 00003/00002/00061
d D 1.3 94/11/25 17:27:18 lm 4 3
c clean
e
s 00001/00000/00062
d D 1.2 94/11/25 17:21:38 lm 3 2
c get in .
e
s 00062/00000/00000
d D 1.1 94/11/25 17:19:58 lm 2 1
c Initial revision
e
s 00000/00000/00000
d D 1.0 94/11/25 17:19:57 lm 1 0
cHlm.bitmover.com
cPMakefile
cRb47aad8cf4afe990
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
# Makefile for top level of lmbench
# $Id$

D 7
# Possible things to make:
E 7
I 7
# Possible things to $(MAKE):
E 7
#
# build		(default) go to the source directory and build the benchmark
# results	go to the source directory and build and run the benchmark
# rerun		run the benchmark again
# see		see the results that came with this release
D 12
#		Go to the Results directory and read the Makefile.
E 12
I 12
#		Go to the results directory and read the Makefile.
E 12
# doc.lpr	print the documentation
# doc.x		preview the documentation (needs X, groff, pic, etc)
D 7
# clean		go to the subdirs and make clean
# get		make sure all files are checked out
E 7
I 7
# clean		go to the subdirs and $(MAKE) clean
# get		$(MAKE) sure all files are checked out
E 7
# shar		build a shippable shar archive

SHELL=/bin/sh

D 13
D 16
build:
D 7
E 13
I 13
build: rccs
E 13
E 16
I 16
build: 
E 16
	cd src && make
E 7
I 7
	cd src && $(MAKE)
E 7

D 13
D 16
results:
D 7
E 13
I 13
results: rccs
E 13
E 16
I 16
D 17
results: 
E 17
I 17
results: FRC
E 17
E 16
	cd src && make results
E 7
I 7
	cd src && $(MAKE) results
E 7

D 13
D 16
rerun:
D 7
E 13
I 13
rerun: rccs
E 13
E 16
I 16
rerun: 
E 16
	cd src && make rerun
E 7
I 7
	cd src && $(MAKE) rerun
E 7

see:
D 7
D 11
D 12
	cd Results && make summary percent | more
E 7
I 7
	cd Results && $(MAKE) summary percent | more
E 7
E 11
I 11
	cd Results && $(MAKE) summary percent 2>/dev/null | more
E 11
E 12
I 12
	cd results && $(MAKE) summary percent 2>/dev/null | more
E 12

doc.lpr:
D 7
	cd doc && make PS && lpr *.PS
E 7
I 7
	cd doc && $(MAKE) PS && lpr *.PS
E 7

doc.x:
D 7
	cd doc && make x
E 7
I 7
	cd doc && $(MAKE) x
E 7

D 13
D 16
clean:
D 12
E 13
I 13
clean: rccs
E 13
E 16
I 16
D 17
clean: 
E 17
I 17
clobber clean: 
E 17
E 16
	for i in doc src Results scripts; do \
E 12
I 12
	for i in doc src results scripts; do \
E 12
		echo ===== $$i =====; \
D 7
D 8
D 16
		(cd $$i && co -q Makefile && make clean); \
E 7
I 7
		(cd $$i && co -q Makefile && $(MAKE) clean); \
E 7
E 8
I 8
		(cd $$i && if [ ! -f Makefile ]; then co -q Makefile; fi && $(MAKE) clean); \
E 8
E 16
I 16
		(cd $$i && $(MAKE) clean); \
E 16
	done
D 4
D 9
	/bin/rm -f SHAR bin/*
E 4
I 4
	/bin/rm -f bin/*
E 9
I 9
	/bin/rm -rf bin/*
E 9
D 14
D 16
	rccs clean -s -e
E 4
E 14
I 14
	./rccs clean -s -e
E 14
E 16
I 16
D 17
	clean 
E 17
I 17
	-bk clean 
E 17
E 16

D 13
D 16
get:
D 12
E 13
I 13
get: rccs
E 13
E 16
I 16
get: 
E 16
	for i in doc src Results scripts; do \
E 12
I 12
	for i in doc src results scripts; do \
E 12
		echo ===== $$i =====; \
D 10
D 16
		(cd $$i && rccs get -s); \
E 10
I 10
		(cd $$i && co -q RCS/*,v); \
E 10
E 16
I 16
		(cd $$i && co -q); \
E 16
	done
I 3
D 14
D 16
	rccs get -s
E 3
E 14
I 14
	./rccs get -s
E 14
E 16
I 16
	@co -q
E 16

D 13
D 16
info:
D 12
E 13
I 13
info: rccs
E 13
E 16
I 16
info: 
E 16
	for i in doc src Results scripts; do \
E 12
I 12
	for i in doc src results scripts; do \
E 12
		echo ===== $$i =====; \
D 14
D 16
		(cd $$i && rccs info); \
E 14
I 14
		(cd $$i && ./rccs info); \
E 14
E 16
I 16
		(cd $$i && info); \
E 16
	done

I 15
release: scripts/mkrelease
	scripts/mkrelease

scripts/mkrelease:
	cd scripts && co mkrelease

E 15
# XXX - . must be named lmbench for this to work
shar:
D 7
	make clean
I 5
E 7
I 7
	$(MAKE) clean
E 7
	co -q Makefile
E 5
D 7
	make get
E 7
I 7
	$(MAKE) get
E 7
	cd .. && \
	find lmbench -type f -print  | egrep -v 'noship|RCS' > /tmp/FILES
D 4
D 6
	cd .. && shar -S < /tmp/FILES > lmbench/SHAR
E 2
E 4
I 4
	cd .. && shar -S < /tmp/FILES > lmbench.SHAR
E 4
E 6
I 6
	cd .. && shar -S -a -n lmbench1.0 -L 50K < /tmp/FILES 
I 17

FRC:
E 17
E 6
I 13
D 16

rccs:
	co -p scripts/RCS/rccs,v > rccs
	chmod +x rccs
E 13
E 16
