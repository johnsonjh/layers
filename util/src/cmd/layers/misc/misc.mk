#	START NEW ARIX SCCS HEADER
#
#	@(#) misc.mk: version 25.1 created on 12/2/91 at 16:00:04
#
#	Copyright (c) 1990 by Arix Corporation
#	All Rights Reserved
#
#	@(#)misc.mk	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation
#
#	END NEW ARIX SCCS HEADER
#
#	Copyright (c) 1984 AT&T
#	  All Rights Reserved

#	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
#	The copyright notice above does not evidence any
#	actual or intended publication of such source code.

#	ATT: ident	"attwin:cmd/layers/misc/makefile	1.5"
#
#		Copyright 1985 AT&T
#

#ident	"@(#)layers/misc:misc.mk	25.1"

include	$(IROOT)/macdefs

INSDIR=$(ROOT)/usr/bin
INC = $(ROOT)/usr/include
#CFLAGS = -O -I$(INC)

all:	ismpx jterm jwin

ismpx:	ismpx.c		\
	$(INCRT)/stdio.h		\
	$(INCRT)/sys/jioctl.h		\
	$(CC) $(CFLAGS) -o ismpx ismpx.c

jterm:	jterm.c	\
	$(INCRT)/sys/jioctl.h	\
	$(CC) $(CFLAGS) -o jterm jterm.c

jwin:	jwin.c	\
	$(INCRT)/sys/jioctl.h	\
	$(CC) $(CFLAGS) -o jwin jwin.c

install:	all
	$(INS) ispmx $(INSDIR)/ismpx
	chmod 755 $(INSDIR)/ismpx
	chgrp bin $(INSDIR)/ismpx
	chown bin $(INSDIR)/ismpx
	$(INS) jterm $(INSDIR)/jterm
	chmod 755 $(INSDIR)/jterm
	chgrp bin $(INSDIR)/jterm
	chown bin $(INSDIR)/jterm
	$(INS) jwin $(INSDIR)/jwin
	chmod 755 $(INSDIR)/jwin
	chgrp bin $(INSDIR)/jwin
	chown bin $(INSDIR)/jwin

clean:

clobber:
	rm -f ismpx jterm jwin
