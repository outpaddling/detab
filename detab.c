/*
    Copyright (c) 1994-2003, Jason W. Bacon, Acadix Consulting, LLC
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are
    met:

    Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer. Redistributions
    in binary form must reproduce the above copyright notice, this list of
    conditions and the following disclaimer in the documentation and/or
    other materials provided with the distribution. 

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
    IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
    TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
*/


/**********************************************************************
  Author:
  Created:
  Modifications:
  Description:
  Arguments:
  Return values:
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

int     main(int argc,char *argv[])

{
    FILE    *infile;
    int     ch,
	    col = 0;
    
    switch(argc)
    {
	case    1:
	    infile = stdin;
	    break;
	case    2:
	    infile = fopen(argv[1],"r");
	    if ( infile == NULL )
	    {
		perror(argv[0]);
		exit(EX_NOINPUT);
	    }
	    break;
	default:
	    fprintf(stderr,"Usage: %s [input file]\n",argv[0]);
	    return(EX_USAGE);
	    break;
    }

    while ( (ch = getc(infile)) != EOF )
    {
	switch(ch)
	{
	    case    '\t':
		do
		    putchar(' ');
		while ( ++col % 8 );
		break;
	    case    '\n':   /* No break - let it flow to putchar */
		col = 0;
	    default:
		putchar(ch);
		break;
	}
    }
    return EX_OK;
}

