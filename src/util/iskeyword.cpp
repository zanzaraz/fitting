/*
  X d e s y
  ---------

  Modul:    iskeyword.cpp
  Version:  1.0
  Datum:    14.02.2007
  Autor:    F. Kern

  Beschreibung:

  Position innerhalb einer Schlüsselwort-Liste bestimmen

  fkern@xdesy.de
  www.xdesy.de
*/
//---------------------------------------------------------------------------
//#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include <string.h>

#include "iskeyword.h"
#include "mystring.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

static char *keywFalse[]={"0",
                  "false","f",
                  "falsch",
                  "nein","n",
                  "no",
                  NULL
                  };
static char *keywTrue[]={"1",
                  "true","t",
                  "wahr",
                  "ja","j",
                  "yes","y",
                  NULL
                  };


int isKeyword(char *str,char **keys)
{
  int i;

  i = 0;
  while(keys[i]!=NULL && strcmp(str,keys[i])) i++;
  return(keys[i]==NULL ? -1 : i);
}


int isKeywordTrueFalse(char *str)
{
 if (isKeyword(str,keywTrue)!=-1) return(1);
 if (isKeyword(str,keywFalse)!=-1) return(0);
 return(-1);
}


int isKeywordAlternativen(char *str,char **keys)
{
  int    i,n;
  size_t l;
  char *pstr;
  char  mstr[256];

  i = 0;
  pstr = NULL;
  while(keys[i]!=NULL && pstr==NULL)
  {
    strcpy(mstr,keys[i]);
    pstr = mystrtok(mstr,"|");
    while (pstr!=NULL && (n=strncmp(str,pstr,l=strlen(pstr))))
    {
      pstr = mystrtok(NULL,"|");
    }
    if (pstr==NULL) i++;
  }
  return(pstr==NULL ? -1 : i);
}

