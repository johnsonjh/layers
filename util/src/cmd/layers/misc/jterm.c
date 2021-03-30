/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) jterm.c: version 25.1 created on 12/2/91 at 15:59:57	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)jterm.c	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT: #ident	"misc:jterm.c	2.5"			*/

#ident	"@(#)layers/misc:jterm.c	25.1"

#include <sys/jioctl.h>

main() {
	int rv = 0;

	if (ioctl(2, JTERM, 0))
		rv = 1;

	exit(rv);
}
