/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) jwin.c: version 25.1 created on 12/2/91 at 16:00:01	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)jwin.c	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT: #ident	"misc:jwin.c	2.4"			*/

#ident	"@(#)layers/misc:jwin.c	25.1"

#include <stdio.h>
#include <sys/jioctl.h>

struct jwinsize win;
main(argc,argv)
char *argv[];
{
	if (argc != 1) {
		fprintf(stderr,"usage: jwin\n");
		exit(1);
	}

	if (ioctl(0, JMPX, 0) == -1) {
		fprintf(stderr,"jwin: not mpx\n");
		exit(1);
	} else {
		ioctl(0, JWINSIZE, &win);
		printf("bytes:\t%d %d\n", win.bytesx, win.bytesy);
		if (win.bitsx != 0 || win.bitsy != 0)
			printf("bits:\t%d %d\n", win.bitsx, win.bitsy);
		exit(0);
	}
}
