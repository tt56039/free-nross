/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "COPYRIGHT" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */

/* $Header: /cvsroot/linphone/linphone/gsmlib/toast.h,v 1.1.1.1 2001/11/19 19:50:11 smorlat Exp $ */

#ifndef	TOAST_H
#define	TOAST_H				/* Guard against multiple includes */

#include "config.h"

#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <ctype.h>
#include <signal.h>

#include <errno.h>
#ifndef	HAVE_ERRNO_DECL
	 extern int	errno;
#endif

#ifdef	HAVE_LIMITS_H
#include <limits.h>
#endif

#ifdef	HAVE_FCNTL_H
# include <fcntl.h>
#endif

#ifdef	HAVE_UTIME
# ifdef	HAVE_UTIME_H
#  include <utime.h>
# endif
#endif

#include "gsm.h"

#ifndef	S_ISREG
#define	S_ISREG(x)	((x) & S_IFREG)
#endif	/* S_ISREG */


# define	READ	"rb"
# define	WRITE	"wb"
#ifdef  O_BINARY
# define	O_WRITE_EXCL	O_WRONLY|O_CREAT|O_EXCL|O_BINARY
#else
# define	O_WRITE_EXCL	O_WRONLY|O_CREAT|O_EXCL
#endif

#ifndef SIGHANDLER_T
#define SIGHANDLER_T	void	/* what does a signal handler return? */
#endif


#ifdef	HAVE_STRING_H
#include	<string.h>
#else
#	ifdef HAVE_STRINGS_H
#	include <strings.h>
#	else
#		include "proto.h"

		extern int	strlen	P((char *));
		extern char *	strcpy  P((char *, char *));
		extern char *	strcat  P((char *,  char *));
		extern char *	strrchr P((char *, int));

#		include "unproto.h"
#	endif
#endif


#ifdef	HAVE_STDLIB_H
#include	<stdlib.h>
#else
#	include "proto.h"
#	ifdef	HAVE_MALLOC_H
#	include <malloc.h>
#	else
		extern char	* malloc P((unsigned));
#	endif
	extern int	exit P((int));
#	include "unproto.h"
#endif


#ifdef	HAVE_UNISTD_H
#	include	<unistd.h>
#endif

/*
 *	This suffix is tacked onto/removed from filenames
 *	similar to the way freeze and compress do it.
 */
#define	SUFFIX_TOASTED		".gsm"

#include	"proto.h"

extern int 	audio_init_input P((void)), audio_init_output P((void));
extern int	ulaw_input   P((gsm_signal*)), ulaw_output   P((gsm_signal *));
extern int	alaw_input   P((gsm_signal*)), alaw_output   P((gsm_signal *));
extern int	linear_input P((gsm_signal*)), linear_output P((gsm_signal *));

#endif		/* TOAST_H */
