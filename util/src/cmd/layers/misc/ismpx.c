/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) ismpx.c: version 25.1 created on 12/2/91 at 15:59:54	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)ismpx.c	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT: #ident	"misc:ismpx.c	2.4"			*/

#ident	"@(#)layers/misc:ismpx.c	25.1"

#include <stdio.h>
#include <sys/jioctl.h>

main(argc, argv)
	int   argc;
	char *argv[];
{
	if (argc != 1)
		if (!(argc == 2 && (strcmp("-s", argv[1]) == 0 ||
		                    strcmp("-",  argv[1]) == 0 ))) {
			fprintf(stderr, "usage: ismpx [-s]\n");
			exit(1);
		}
	if (ioctl(0, JMPX, 0) == -1){
		if(argc==1)
			printf("no\n");
		exit(1);
	}
	if (argc == 1)
		printf("yes\n");
	exit(0);
}
