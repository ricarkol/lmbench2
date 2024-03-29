# $Id$

# Make targets:
#
# lmbench	[default] builds the benchmark suite for the current os/arch
# results	builds, configures run parameters, and runs the benchmark
# rerun		reruns the benchmark using the same parameters as last time
# clean		cleans out sources and run configuration
# clobber	clean and removes the bin directories
# shar		obsolete, use cd .. && make shar
# depend	builds make dependencies (needs gcc)
#
# This is largely self configuring.  Most stuff is pretty portable.  You
# may have problems with the mhz program.  
#
# OS config.  If you aren't one of the known OS's (see ../scripts/os)
# then you need to make a target in this makefile with the flags that
# you need.  First fix os to spit out your os and then create a target
# here.  Please mail me that info so I can update the makefile.
#
# If you don't have gcc, try make CC=cc and see if that works.

# I finally know why Larry Wall's Makefile says "Grrrr".
SHELL=/bin/sh

CC = `../scripts/compiler`
AR = ar
ARCREATE = cr
BASE=/usr/local		# base of installation location
O= ../bin/unknown
D= ../doc
TRUE=/bin/true
OS=`../scripts/os`
TARGET=`../scripts/target`
BINDIR=../bin/$(OS)
CONFIG=../bin/$(OS)/`../scripts/config`
UTILS=../scripts/target ../scripts/os ../scripts/gnu-os ../scripts/compiler \
	../scripts/info ../scripts/info-template ../scripts/version \
	../scripts/config ../scripts/config-run ../scripts/results \
	../scripts/lmbench ../scripts/build
INSTALL=cp
RESULTS=Results/$(OS)
SAMPLES=lmbench/Results/aix/rs6000 lmbench/Results/hpux/snake \
	lmbench/Results/irix/indigo2 lmbench/Results/linux/pentium \
	lmbench/Results/osf1/alpha lmbench/Results/solaris/ss20* 

LDLIBS=/usr/lib/libtirpc.a -ltirpc -lm
COMPILE=$(CC) $(CFLAGS) -I/usr/include/tirpc -L/usr/lib -ltirpc $(CPPFLAGS) $(LDFLAGS)

INCS =	bench.h lib_tcp.h lib_udp.h stats.h timing.h

SRCS =  bench.h bw_file_rd.c bw_mmap_rd.c 				\
	bw_pipe.c bw_tcp.c hello.c lat_connect.c lat_ctx.c		\
	lat_fs.c lat_mem_rd.c lat_mmap.c lat_pagefault.c lat_pipe.c	\
	lat_proc.c lat_rpc.c lat_syscall.c lat_tcp.c lat_udp.c		\
	lib_tcp.c lib_udp.c mhz.c lib_timing.c lat_sig.c 		\
	memsize.c bw_unix.c lat_unix.c lmdd.c loop_o.c timing_o.c	\
	timing.h stats.h lib_tcp.h lib_udp.h  enough.c lat_select.c	\
	msleep.c bw_mem.c lat_fifo.c lmhttp.c lat_http.c	\
	disk.c flushdisk.c lat_unix_connect.c lib_unix.c lib_stats.c \
	lib_unix.h names.h version.h

EXES =	$O/bw_file_rd $O/bw_mmap_rd $O/bw_pipe $O/bw_tcp $O/hello	\
	$O/lat_select $O/lat_pipe $O/lat_rpc $O/lat_syscall $O/lat_tcp	\
	$O/lat_udp $O/lat_mmap $O/mhz $O/lat_proc $O/lat_pagefault	\
	$O/lat_connect $O/lat_fs $O/lat_sig $O/lat_mem_rd $O/lat_ctx	\
	$O/memsize $O/lat_unix $O/bw_unix $O/lmdd $O/timing_o $O/enough	\
	$O/msleep $O/loop_o $O/bw_mem $O/lat_fifo $O/lmhttp $O/lat_http	\
	$O/disk $O/lat_unix_connect $O/flushdisk

MAN1 =	lmdd.1 $D/bargraph.1 $D/graph.1 $D/pgraph.1 $D/rccs.1

MAN3 =	$D/lmbench.3 $D/reporting.3 $D/results.3 $D/timing.3

MAN8 =	$D/bw_file_rd.8 $D/bw_mem_cp.8 $D/bw_mem_rd.8 $D/bw_mem_wr.8	\
	$D/bw_mmap_rd.8 $D/bw_pipe.8 $D/bw_tcp.8 $D/lat_connect.8	\
	$D/lat_ctx.8 $D/lat_fs.8 $D/lat_mem_rd.8 $D/lat_mmap.8		\
	$D/lat_pagefault.8 $D/lat_pipe.8 $D/lat_proc.8 $D/lat_rpc.8 	\
	$D/lat_syscall.8 $D/lat_tcp.8 $D/lat_udp.8 $D/lmbench.8 	\
	$D/lmdd.8 $D/mhz.8 

LIBOBJS= $O/lib_tcp.o $O/lib_udp.o $O/lib_unix.o $O/lib_timing.o $O/lib_stats.o

lmbench: $(UTILS)
	@env CFLAGS=-O ../scripts/build all

results: lmbench
	@../scripts/config-run
	@../scripts/results

rerun: lmbench
	@if [ ! -f $(CONFIG) ]; then ../scripts/config-run; fi
	@../scripts/results

install: lmbench
	$(MAKE) O=$(BINDIR) install-target

install-target:
	if [ ! -d $(BASE) ]; then mkdir $(BASE); fi
	if [ ! -d $(BASE)/bin ]; then mkdir $(BASE)/bin; fi
	if [ ! -d $(BASE)/include ]; then mkdir $(BASE)/include; fi
	if [ ! -d $(BASE)/lib ]; then mkdir $(BASE)/lib; fi
	if [ ! -d $(BASE)/man ]; then mkdir $(BASE)/man; fi
	if [ ! -d $(BASE)/man/man1 ]; then mkdir $(BASE)/man/man1; fi
	if [ ! -d $(BASE)/man/man3 ]; then mkdir $(BASE)/man/man3; fi
	if [ ! -d $(BASE)/man/man8 ]; then mkdir $(BASE)/man/man8; fi
	cp $(EXES) $(BASE)/bin
	cp $(INCS) $(BASE)/include
	cp $O/lmbench.a $(BASE)/lib/libmbench.a
	cp $(MAN1) $(BASE)/man/man1
	cp $(MAN3) $(BASE)/man/man3
	cp $(MAN8) $(BASE)/man/man8


# No special handling for all these
all: $(EXES) bk.ver

Wall:
	@env CFLAGS="-Wall -ansi" ../scripts/build

debug:
	@env CFLAGS=-g ../scripts/build

bk.ver: ../SCCS/s.ChangeSet
	-echo  `bk prs -hr+ -d'$$if(:SYMBOL:){:SYMBOL: }:UTC:' ../ChangeSet;` > bk.ver
	touch bk.ver

dist:
	@if [ "X`cd ..; bk sfiles -c`" != "X" ]; then echo "modified files!"; false; fi
	@if [ "X`cd ..; bk pending`" != "X" ]; then echo "pending changes!"; false; fi
	cd ..; for d in . doc results scripts src; do \
		(cd $$d; bk clean; bk get -s); \
	done
	rm -f bk.ver
	make bk.ver
	cp -rp .. ../../lmbench-2dist
	rm -rf ../../lmbench-2dist/bin/*

get $(SRCS):
	get -s $(SRCS)

edit get-e:
	get -e -s $(SRCS)

clean:
	/bin/rm -f ../bin/*/CONFIG.* ../bin/*/*.[oa]
	-bk clean

clobber:
	/bin/rm -rf ../bin* SHAR
	-bk clean

shar:
	cd ../.. && shar lmbench/Results/Makefile $(SAMPLES) lmbench/scripts/* lmbench/src/Makefile lmbench/src/*.[ch] > lmbench/SHAR

depend: ../scripts/depend
	../scripts/depend

$(UTILS):
	@cd ../scripts; make get

$O/lmbench.a: lib_timing.c lib_tcp.c lib_udp.c lib_unix.c lib_stats.c bench.h timing.h stats.h lib_tcp.h lib_udp.h names.h
	$(COMPILE) -c lib_timing.c -o $O/lib_timing.o
	$(COMPILE) -c lib_tcp.c -o $O/lib_tcp.o
	$(COMPILE) -c lib_udp.c -o $O/lib_udp.o
	$(COMPILE) -c lib_unix.c -o $O/lib_unix.o
	$(COMPILE) -c lib_stats.c -o $O/lib_stats.o
	/bin/rm -f $O/lmbench.a
	$(AR) $(ARCREATE) $O/lmbench.a $(LIBOBJS)
	-ranlib $O/lmbench.a

# Do not remove the next line, $(MAKE) depend needs it
# MAKEDEPEND follows
$O/rhttp:  rhttp.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/rhttp rhttp.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/http:  http.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/http http.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/flushdisk:  flushdisk.c 
	$(COMPILE) -DMAIN -o $O/flushdisk flushdisk.c

$O/mhz: mhz.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/mhz mhz.c $O/lmbench.a $(LDLIBS) -ltirpc -lm

$O/lat_ctx: lat_ctx.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_ctx lat_ctx.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lmhttp:  lmhttp.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lmhttp lmhttp.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_http:  lat_http.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_http lat_http.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/bw_file_rd:  bw_file_rd.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/bw_file_rd bw_file_rd.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/bw_mem:  bw_mem.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/bw_mem bw_mem.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/bw_mmap_rd:  bw_mmap_rd.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/bw_mmap_rd bw_mmap_rd.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/bw_pipe:  bw_pipe.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/bw_pipe bw_pipe.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/bw_tcp:  bw_tcp.c bench.h timing.h stats.h lib_tcp.h $O/lmbench.a
	$(COMPILE) -o $O/bw_tcp bw_tcp.c $O/lmbench.a $(LDLIBS) -ltirpc -ltirpc

$O/bw_unix:  bw_unix.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/bw_unix bw_unix.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/disk:  disk.c flushdisk.c bench.h timing.h stats.h lib_tcp.h $O/lmbench.a
	$(COMPILE) -o $O/disk disk.c flushdisk.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/clock:  clock.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/clock clock.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/hello:  hello.c $O/lmbench.a
	$(COMPILE) -o $O/hello hello.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_alarm:  lat_alarm.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_alarm lat_alarm.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_connect:  lat_connect.c lib_tcp.c bench.h lib_tcp.h timing.h stats.h $O/lmbench.a
	$(COMPILE) -o $O/lat_connect lat_connect.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_unix_connect:  lat_unix_connect.c lib_tcp.c bench.h lib_tcp.h timing.h stats.h $O/lmbench.a
	$(COMPILE) -o $O/lat_unix_connect lat_unix_connect.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_fs:  lat_fs.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_fs lat_fs.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_mem_rd:  lat_mem_rd.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_mem_rd lat_mem_rd.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_mem_rd2:  lat_mem_rd2.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_mem_rd2 lat_mem_rd2.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_mem_wr:  lat_mem_wr.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_mem_wr lat_mem_wr.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_mem_wr2:  lat_mem_wr2.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_mem_wr2 lat_mem_wr2.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_mmap:  lat_mmap.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_mmap lat_mmap.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_mmaprd:  lat_mmaprd.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_mmaprd lat_mmaprd.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_pagefault:  lat_pagefault.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_pagefault lat_pagefault.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_pipe:  lat_pipe.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_pipe lat_pipe.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_fifo:  lat_fifo.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_fifo lat_fifo.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_proc:  lat_proc.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_proc lat_proc.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_rpc:  lat_rpc.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_rpc lat_rpc.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_sig:  lat_sig.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_sig lat_sig.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_syscall:  lat_syscall.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_syscall lat_syscall.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_select:  lat_select.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_select lat_select.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_tcp:  lat_tcp.c timing.h stats.h bench.h lib_tcp.h $O/lmbench.a
	$(COMPILE) -o $O/lat_tcp lat_tcp.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_udp:  lat_udp.c timing.h stats.h bench.h lib_udp.h $O/lmbench.a
	$(COMPILE) -o $O/lat_udp lat_udp.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lat_unix:  lat_unix.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lat_unix lat_unix.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lib_tcp:  lib_tcp.c bench.h lib_tcp.h $O/lmbench.a
	$(COMPILE) -o $O/lib_tcp lib_tcp.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lib_udp:  lib_udp.c bench.h lib_udp.h $O/lmbench.a
	$(COMPILE) -o $O/lib_udp lib_udp.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/lmdd:  lmdd.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/lmdd lmdd.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/enough:  enough.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/enough enough.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/loop_o:  loop_o.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/loop_o loop_o.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/timing_o:  timing_o.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/timing_o timing_o.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/memsize:  memsize.c timing.h stats.h bench.h $O/lmbench.a
	$(COMPILE) -o $O/memsize memsize.c $O/lmbench.a $(LDLIBS) -ltirpc

$O/msleep:  msleep.c timing.h stats.h bench.h 
	$(COMPILE) -o $O/msleep msleep.c
