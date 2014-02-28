//---------------------------------------------------------------------------

#pragma hdrstop

#include "mystring.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <string.h>

char *strtrim(char *str)
{
  char *p;
  int   n;

  p = str;
  while (*p!='\x0' && (*p==' ' || *p=='\t'))
  {
    p++;
  }
/*
  n = strlen(p) - 1;
  while((p+n)>=p && (*(p+n)==' ' || *(p+n)=='\n' || *(p+n)=='\t'))
  {
    *(p+n) = '\x0';
    n--;
  }
*/
  n = strlen(p) - 1;
  while(n>=0 && (*(p+n)==' ' || *(p+n)=='\n' || *(p+n)=='\t'))
  {
    *(p+n) = '\x0';
    n--;
  }
  strcpy(str,p);
  return(str);
}

char *mystrtok(char *str,char *muster)
{
  static char *merkestr;
  char *pstr,*sstr;
  char *mstr;

  if (str!=NULL)
  {
    pstr = str;
  }
  else
  {
    pstr = merkestr;
  }
  if (pstr==NULL) return(NULL);
  sstr = pstr;
  while (*pstr!='\x0')
  {
    mstr = muster;
    while(*mstr!='\x0')
    {
      if (*pstr==*mstr) break;
      mstr++;
    }
    if (*mstr!='\x0')
    {
      *pstr = '\x0';
      merkestr = pstr+1;
      return(sstr);
    }
    pstr++;
  }
  if (pstr!=sstr)
  {
    merkestr = NULL;
    return(sstr);
  }
  return(NULL);
}

