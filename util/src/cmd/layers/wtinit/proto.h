/*	START NEW ARIX SCCS HEADER			*/
/*							*/
/*	@(#) proto.h: version 25.1 created on 12/2/91 at 16:00:26	*/
/*							*/
/*	Copyright (c) 1990 by Arix Corporation		*/
/*	All Rights Reserved				*/
/*							*/
#ident	"@(#)proto.h	25.1	12/2/91 Copyright (c) 1990 by Arix Corporation"
/*							*/
/*	END NEW ARIX SCCS HEADER			*/
/*							*/
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	ATT: #ident	"32ld:proto.h	2.5"			*/

#ident	"@(#)layers/wtinit:proto.h	25.1"

/*
 *	Protocol definition for 68ld bootstrap.
 *
 *	Packets are formatted as follows:
 *
 *	0x80^Seq | Size | 4 bytes of address | 0 or more data bytes | CRC1 | CRC2
 *
 *	where PKTASIZE <= Size <= (PKTASIZE+MAXPKTDSIZE).
 *
 *	If Size == PKTASIZE then the address is the start address.
 *	If Size > PKTASIZE then the data bytes are loaded contiguously at the address.
 *
 *	Acknowledgements consist of the first (Seq) byte
 *	from each correctly received packet. Timeouts, or
 *	out-of-sequence acks, cause the retransmission of
 *	all un-acknowledged packets.
 */

#define	MAXPKTSIZE	128		/* Efficient size for system */
#define	PKTHDRSIZE	2		/* Seq + Size */
#define	PKTCRCSIZE	2		/* CRC 16 */
#define	PKTASIZE	4		/* sizeof(long) on MC68000 */
#define	MAXPKTDSIZE	MAXPKTSIZE-(PKTHDRSIZE+PKTCRCSIZE+PKTASIZE)

#define	PTYP		0xc0		/* Masked with Seq to guarantee non-zero */
#define	ACKON		0x80		/* Ack expected for this packet */
#define	ACKOFF		0xc0		/* No ack expected, but remember any error */
#define	NOCRC		0x40		/* No error detection on packet */
/*#define	SEQMASK		((~PTYP)&0xff) doesn't work */
#define	SEQMASK		((~PTYP)&0x3f)	/* seq. no must be <0100  (why?? dunno) */
#define	SEQMOD		(SEQMASK+1)

#define	NPBUFS		2		/* Transmission is multi buffered */

extern char		freepkts;

extern int		crc();
extern void		pinit();
extern void		precv();
extern int		psend();
extern void		ptimeout();
extern void		pstats();

extern void		Write();
