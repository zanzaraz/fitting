/*
  X d e s y
  ---------

  Modul:    Getopt.cpp
  Version:  1.0
  Datum:    15.12.2008
  Autor:    F. Kern

  Beschreibung:

  Verarbeitung von Aufrufparametern


  fkern@xdesy.de
  www.xdesy.de
*/
#include <stdio.h>

#include "getopt.h"

static int  optind=1,opterr=1;
static char optmark='-';

void next_opt(void)
{
  optind++;
}

void init_getopt(int opti,int opte,char optm)
{
  optind  = opti;
  opterr  = opte;
  optmark = optm;
}

char getopt(int argc,char *argv[],char *optstring,char **optarg)
{
  char *opt;
  char *optstr;
  static int inopt=0;

  optstr = optstring;
  *optarg = NULL;
  if (optind>=argc) return(EOF);
  if (*argv[optind]!=optmark && inopt==0) 
  {
    *optarg = argv[optind];
    optind++;
    return('!');
  }
  opt = argv[optind] + 1 + inopt;
  if (*opt==optmark)
  {
    optind++; return(EOF);
  }
  if (*opt=='\x0') opt = " ";

  while(*optstr++ != *opt)
  {
    if (*optstr=='\x0')
    {
      *optarg = opt;
      optind++;
      if (opterr) printf("ERROR: illegal option flag: %c\n",*opt);
      return('?');
    }
  }
  if (*optstr==':')
  {
    inopt = 0;
    optind++;
    if (opt[1]!='\x0')
    {
      *optarg = &opt[1];
    } 
    else
    {
/*
      *optarg = argv[optind++];
*/
    }

  }
  else if (opt[1]!='\x0') inopt++;
  else
  {
    inopt = 0;
    optind++;
  }
  return(*opt);
}

/*#define DEBUG*/

#ifdef DEBUG
void main(int argc,char *argv[])
{
  int  opt;
  char *optarg;

  init_getopt(1,1,'-');
  while ((opt=getopt(argc,argv,"i:c:kab",&optarg))!=EOF)
  {
    if (opt=='?') break;
    printf("Option: %c Argument:%s\n",opt,(optarg==NULL ? "" : optarg));
  }
}
#endif

