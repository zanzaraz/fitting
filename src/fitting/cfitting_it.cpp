//---------------------------------------------------------------------------

#pragma hdrstop

#include "cfitting_it.h"

#include <stdlib.h>
#include "cfitting_util.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Cfitting_it::Cfitting_it()
{
  gIsDebug     = false;
  gConvergence = 1e-09;
}

Cfitting_it::Cfitting_it(bool isdebug,double convergence)
{
  gIsDebug     = isdebug;
  gConvergence = convergence;
}

bool Cfitting_it::approximation(
                 TReal *beob,int n,TReal **para,int np,
                 TReal *ubk ,int u,
                 TReal *Qxx,
                 int *iter,TReal *convergence,
                 Tapproxfunction      func,
                 Tdiffapproxfunction dfunc
              )
{
  bool ret;
  int   i;
  TReal *merke_ubk;
  TReal damping;

  ProtoMeldung("#observed values = %d\n",n);
  ProtoMeldung("#unknown values  = %d\n",u);
  merke_ubk = (TReal *) calloc(u,sizeof(TReal));

  for (i=0;i<u;i++) merke_ubk[i] = ubk[i];
  damping      =   1.0;
  *convergence = gConvergence;
  *iter = 0;
  do
  {
     ProtoMeldung("damping = %.6lf: ",damping);
     ret = _approxfunc(beob,n,para,np,ubk,u,Qxx,
               damping,iter,convergence,
               func,
               dfunc,
               gIsDebug
               );
    if (*iter==0) ProtoMeldung("no convergence.\n");
    else          ProtoMeldung("successfull approximation after %d iterations\n",*iter);
    if (ret==false)
    {
      for (i=0;i<u;i++) ubk[i] = merke_ubk[i];
      damping = damping / 2.0;
    }
  }
  while (ret==false && damping>0.2);
  free(merke_ubk);

  return(ret);
}


bool Cfitting_it::variancepropagation(TReal *ubk  ,int u,
                                      TReal *para ,
                                      int f,
                                      TReal *sigmaxx,
                                      TReal *sigmaff,
                                      Tdiffapproxfunction dfunc
                                     )
{
  return(_variancepropagation(ubk ,u,para,f,sigmaxx,sigmaff,dfunc,gIsDebug));
}



void Cfitting_it::coords_as_array(TReal *X,TReal *Y,TReal *Z,int n,TReal ***x,TReal **y)
{
  int dim,j;
  int i;

  dim = 0;
  dim += X==NULL ? 0 : 1;
  dim += Y==NULL ? 0 : 1;
  dim += Z==NULL ? 0 : 1;

  *x    = (TReal **) calloc(n,sizeof(TReal *));
  *y    = (TReal *)  calloc(n,sizeof(TReal));

  for (i=0;i<n;i++)
  {
    (*x)[i] = (TReal *) calloc(dim,sizeof(TReal));   // z = f(x,y,z)

    j = 0;
    if (X!=NULL)
    {
      (*x)[i][j] = X[i];
      j++;
    }
    if (Y!=NULL)
    {
      (*x)[i][j] = Y[i];
      j++;
    }
    if (Z!=NULL)
    {
      (*x)[i][j] = Z[i];
      j++;
    }
    (*y)[i] = 0.0;
  }
}

void Cfitting_it::free_array(TReal **x,TReal *y,int n)
{
  for (int i=0;i<n ;i++ ) free(x[i]);
  free(y);
  free(x);
}

