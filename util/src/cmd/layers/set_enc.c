/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) set_enc.c: version 25.1 created on 12/2/91 at 16:00:11	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)set_enc.c	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT:#ident	"xt:set_enc.c	1.3"	*/
	
#ident	"@(#)layers:set_enc.c	25.1"


/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/
/*
 * Routine to change ENCODING option remotely
 *
 * Usage:
 *
 *	wtinit set_encoding.j 1		# or 0
 *
 */

#include	<dmd.h>
#include	<setup.h>

#define	BRAM_SIZE	2048
char *itox();

main()
{
	int value;

	wait(RCV);
	value = (rcvchar() & 0x7f) - '0';
	spl7();
	ENCODE_ENABLE = value;
	setbram();
	spl0();
}
