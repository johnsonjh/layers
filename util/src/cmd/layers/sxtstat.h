/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) sxtstat.h: version 25.1 created on 12/2/91 at 16:00:16	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)sxtstat.h	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT:#ident	"attwin:cmd/layers/sxtstat.h	1.2"	*/
	
#ident	"@(#)layers:sxtstat.h	25.1"


#define	SXTIOCLINK	('b'<<8)
#define SXTIOCSTAT	(SXTIOCLINK|7)


/* the following structure is used for the SXTIOCSTAT ioctl call */
struct sxtblock
{
	char	input;		/* channels blocked on input  */
	char	output;		/* channels blocked on output */
};
