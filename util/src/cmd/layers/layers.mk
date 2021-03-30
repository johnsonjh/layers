#	START NEW ARIX SCCS HEADER
#
#	@(#) layers.mk: version 25.1 created on 12/2/91 at 15:59:48
#
#	Copyright (c) 1990 by Arix Corporation
#	All Rights Reserved
#
#	@(#)layers.mk	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation
#
#	END NEW ARIX SCCS HEADER
#
#	Copyright (c) 1984 AT&T
#	  All Rights Reserved

#	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
#	The copyright notice above does not evidence any
#	actual or intended publication of such source code.

#	ATT: ident	"attwin:cmd/layers/makefile	1.12"
#
#		Copyright 1985 AT&T
#

#ident	"@(#)layers:layers.mk	25.1"

include	$(IROOT)/macdefs

INSDIR=$(ROOT)/usr/bin
INSLIB=$(ROOT)/usr/lib/layersys
INC = $(ROOT)/usr/include
LIB = $(ROOT)/usr/lib
#CFLAGS = -O -I$(INC)

#all:	layersys/lsys.873 set_enc.j relogin xtd xts xtt 
#	cd wtinit; $(MAKE) -ef wtinit.mk install
#	cd misc; $(MAKE) -ef misc.mk install
#	cd $(IROOT)/uts/3b2/io; $(MAKE) -ef xt.mk install

all:
	echo layers: NOT SUPPORTED

layers:	libwindows_mk layers.o xtraces.o xtstats.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o layers layers.o xtraces.o \
		xtstats.o ../../lib/libwindows/libwindows.a

relogin:	relogin.c		\
		$(INCRT)/sys/types.h	\
		$(INCRT)/utmp.h		\
		$(INCRT)/stdio.h	\
		$(INCRT)/pwd.h
	$(CC) $(CFLAGS) -o relogin relogin.c

xtd:	xtd.c \
	$(INCRT)/sys/param.h  	\
	$(INCRT)/sys/types.h  	\
	$(INCRT)/sys/tty.h  	\
	$(INCRT)/sys/jioctl.h  	\
	$(INCRT)/sys/xtproto.h  	\
	$(INCRT)/sys/xt.h  	\
	$(INCRT)/stdio.h
	$(CC) $(CFLAGS) -o xtd xtd.c

xts:	xts.o xtstats.o
	$(CC) $(CFLAGS) -o xts xts.o xtstats.o

xtt:	xtt.o xtraces.o
	$(CC) $(CFLAGS) -o xtt xtt.o xtraces.o

layers.o:	layers.c  \
		$(INCRT)/sys/types.h	\
		$(INCRT)/sys/stat.h	\
		$(INCRT)/sys/errno.h	\
		$(INCRT)/sys/tty.h	\
		$(INCRT)/sys/jioctl.h	\
		$(INCRT)/sys/xtproto.h	\
		$(INCRT)/sys/xt.h	\
		$(INCRT)/sys/termio.h	\
		$(INCRT)/fcntl.h	\
		$(INCRT)/signal.h	\
		$(INCRT)/stdio.h	\
		sxtstat.h

xts.o:	xts.c  \
	$(INCRT)/stdio.h

xtt.o:	xtt.c	\
	$(INCRT)/sys/types.h	\
	$(INCRT)/sys/tty.h	\
	$(INCRT)/sys/jioctl.h	\
	$(INCRT)/sys/xtproto.h	\
	$(INCRT)/sys/xt.h	\
	$(INCRT)/stdio.h

xtraces.o:	xtraces.c	\
		$(INCRT)/stdio.h	\
		$(INCRT)/sys/param.h	\
		$(INCRT)/sys/types.h	\
		$(INCRT)/sys/tty.h	\
		$(INCRT)/sys/jioctl.h	\
		$(INCRT)/sys/xtproto.h	\
		$(INCRT)/sys/xt.h

xtstats.o:	xtstats.c	\
		$(INCRT)/sys/types.h	\
		$(INCRT)/sys/tty.h	\
		$(INCRT)/sys/jioctl.h	\
		$(INCRT)/sys/xtproto.h	\
		$(INCRT)/sys/xt.h	\
		$(INCRT)/stdio.h

install:  all

#install:	all
#	if [ ! -d $(ROOT)/usr/lib/layersys ] ;\
#	then \
#		mkdir $(ROOT)/usr/lib/layersys ;\
#		chmod 755 $(ROOT)/usr/lib/layersys ;\
#		chgrp bin $(ROOT)/usr/lib/layersys ;\
#		chown bin $(ROOT)/usr/lib/layersys ;\
#	fi 
#	$(INS) layers $(INSDIR)/layers
#	chmod 4755 $(INSDIR)/layers
#	chgrp bin $(INSDIR)/layers
#	chown root $(INSDIR)/layers
#	$(INS) xtd $(INSDIR)/xtd
#	chmod 755 $(INSDIR)/xtd
#	chgrp bin $(INSDIR)/xtd
#	chown bin $(INSDIR)/xtd
#	$(INS) xts $(INSDIR)/xts
#	chmod 755 $(INSDIR)/xts
#	chgrp bin $(INSDIR)/xts
#	chown bin $(INSDIR)/xts
#	$(INS) xtt $(INSDIR)/xtt
#	chmod 755 $(INSDIR)/xtt
#	chgrp bin $(INSDIR)/xtt
#	chown bin $(INSDIR)/xtt
#	$(INS) relogin $(INSLIB)/relogin
#	chmod 4755 $(INSLIB)/relogin
#	chgrp bin $(INSLIB)/relogin
#	chown root $(INSLIB)/relogin
#	$(INS) layersys/lsys.873 $(INSLIB)/lsys.8\;7\;3
#	chown bin $(INSLIB)/lsys.8\;7\;3
#	chgrp bin $(INSLIB)/lsys.8\;7\;3
#	chmod 755 $(INSLIB)/lsys.8\;7\;3
#	$(INS) set_enc.j $(INSLIB)/set_enc.j
#	chown bin $(INSLIB)/set_enc.j
#	chgrp bin $(INSLIB)/set_enc.j
#	chmod 755 $(INSLIB)/set_enc.j


#### WHAT?????
#	cd ../../lib/libwindows; $(MAKE) -f libwindows.mk install

clean:
#	rm -f layers.o xts.o xtt.o xtraces.o xtstats.o 
#	cd wtinit; $(MAKE) -ef wtinit.mk clean
#	cd misc; $(MAKE) -ef misc.mk clean
#	cd $(IROOT)/uts/3b2/io; $(MAKE) -ef xt.mk clean

#	cd ../../lib/libwindows; $(MAKE) -f libwindows.mk clean

clobber:
#	rm -f layers.o xts.o xtt.o xtraces.o xtstats.o layers relogin xtd xts xtt
#	cd wtinit; $(MAKE) -ef wtinit.mk clobber
#	cd misc; $(MAKE) -ef misc.mk clobber
#	cd $(IROOT)/uts/3b2/io; $(MAKE) -ef xt.mk clobber

#	cd ../../lib/libwindows; $(MAKE) -f libwindows.mk clobber
