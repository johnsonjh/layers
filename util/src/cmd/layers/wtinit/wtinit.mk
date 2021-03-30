#	START NEW ARIX SCCS HEADER
#
#	@(#) wtinit.mk: version 25.1 created on 12/2/91 at 16:00:34
#
#	Copyright (c) 1990 by Arix Corporation
#	All Rights Reserved
#
#	@(#)wtinit.mk	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation
#
#	END NEW ARIX SCCS HEADER
#
#	Copyright (c) 1984 AT&T
#	  All Rights Reserved

#	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
#	The copyright notice above does not evidence any
#	actual or intended publication of such source code.

#	ATT: ident	"attwin:cmd/layers/wtinit/makefile	1.5"
#
#		Copyright 1985 AT&T
#

#ident	"@(#)layers/wtinit:wtinit.mk	25.1"

include	$(IROOT)/macdefs

INC = $(ROOT)/usr/include
#CFLAGS = -O -I$(INC)

all:	wtinit

wtinit:	wtinit.o proto.o pcheck.o
	$(CC) $(CFLAGS) -o wtinit wtinit.o proto.o pcheck.o

wtinit.o:	wtinit.c	\
		$(INCRT)/fcntl.h	\
		$(INCRT)/termio.h	\
		$(INCRT)/a.out.h	\
		$(INCRT)/stdio.h	\
		$(INCRT)/errno.h	\
		$(INCRT)/sys/jioctl.h	\
		proto.h	\
		$(INCRT)/signal.h	\
		$(INCRT)/sys/types.h	\
		$(INCRT)/sys/stat.h	\
	$(CC) $(CFLAGS) -c wtinit.c

proto.o:	proto.c
		$(INCRT)/signal.h	\
		$(INCRT)/stdio.h	\
		proto.h	\
	$(CC) $(CFLAGS) -c proto.c

pcheck.o:	pcheck.c
	$(CC) $(CFLAGS) -c pcheck.c


install:	all
	if [ ! -d $(ROOT)/usr/lib/layersys ] ;\
	then \
		mkdir $(ROOT)/usr/lib/layersys ;\
		chmod 755 $(ROOT)/usr/lib/layersys ;\
		chgrp bin $(ROOT)/usr/lib/layersys ;\
		chown bin $(ROOT)/usr/lib/layersys ;\
	fi 
	$(INS) wtinit $(ROOT)/usr/lib/layersys/wtinit
	chmod 755 $(ROOT)/usr/lib/layersys/wtinit
	chgrp bin $(ROOT)/usr/lib/layersys/wtinit
	chown bin $(ROOT)/usr/lib/layersys/wtinit

clean:
	rm -f wtinit.o proto.o pcheck.o

clobber: clean
	rm -f wtinit
