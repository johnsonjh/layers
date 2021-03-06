/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) xts.c: version 25.1 created on 12/2/91 at 16:00:44	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)xts.c	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT:#ident	"xt:xts.c	2.3"	*/
	
#ident	"@(#)layers:xts.c	25.1"


/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
**	Print out Xt driver statistics
*/

char		Usage[]	=	"Usage: %s [-f]\n";

#include	"stdio.h"

char *		name;
int		display;

void		error();

extern void	xtstats();

extern char	_sobuf[];


#define		Fprintf		(void)fprintf
#define		SYSERROR	(-1)



int
main(argc, argv)
	int		argc;
	char *		argv[];
{
	name = *argv++;

	while ( --argc )
	{
		if ( argv[0][0] == '-' )
			switch ( argv[0][1] )
			{
			 case 'f':	display++;	break;
			 default:	error("bad flag '%c'", (char *)argv[0][1]);
					return 1;
			}
		else
		{
			error("unrecognised argument '%s'", argv[0]);
			return 1;
		}
		argv++;
	}

	setbuf(stdout, _sobuf);
	xtstats(0, stdout);
	if ( display )
		Fprintf(stdout, "\f");

	return 0;
}



void
error(s1, s2)
	char *	s1;
	char *	s2;
{
	Fprintf(stderr, "%s - error - ", name);
	Fprintf(stderr, s1, s2);
	Fprintf(stderr, "\n");
	Fprintf(stderr, Usage, name);
}
