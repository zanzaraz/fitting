//---------------------------------------------------------------------------

#pragma hdrstop

#include "cfitting_util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#ifdef WITH_FITTING_UTILS

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

FILE          *fperr=stderr;
bool          isQuiet=false;
int            QuietMode=1;

static char   buffer[2048];

void __default_meldung(char *str)
{

}

static Tmeldung extern_wmeldung=__default_meldung;

void Init_externmeldung(Tmeldung ex_wmeldung)
{
  isQuiet   = true;
  QuietMode = 2;
  if (ex_wmeldung!=NULL) extern_wmeldung = ex_wmeldung;
}

void ProtoMeldung(char *fmt,...)
{
  va_list va;

  va_start(va,fmt);

  if (!isQuiet)     vfprintf(stderr,fmt,va);
  if (QuietMode==2)
  {
    vsprintf(buffer,fmt,va);
    extern_wmeldung(buffer);
  }
  va_end(va);
}

void Meldung(char *fmt,...)
{
  va_list va;

  va_start(va,fmt);

  if (!isQuiet)
  {
    vfprintf(stderr,fmt,va);
  }

  va_end(va);
}

void Error(char *fmt,...)
{
  char str[81];
  va_list va;

  va_start(va,fmt);
  fprintf(fperr,"\nError");
  vsprintf(str,fmt,va);
  fprintf(fperr,"%s",str);
  va_end(va);
  exit(1);
}

FILE *myfopen(const char *filename,const char *mode)
{
  FILE *fp;

  fp = NULL;
  fp = fopen(filename,mode);
  if (fp==NULL)
  {
    Error("'%s' %s",filename,
#if defined(__TURBOC__) || defined(__SC__) || defined(__GCC_HPUX__) || defined(__MSC__)
#ifdef __TURBOC__ > 0x5600
           ""
#else
           strerror(errno)
#endif
#else
           /* perror() */ ""
#endif
    );
  }
  return(fp);
}


#endif