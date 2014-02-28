//---------------------------------------------------------------------------

#pragma hdrstop

#include "cfitting_circle.h"

#include <stdlib.h>
#include <math.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)

extern int    gDebugLevel;
extern double gConvergence;

TReal circle_equation(TReal *x,TReal *para)
{
  TReal ret;
  TReal xm,ym,r;

  xm       = para[0];
  ym       = para[1];
  r        = para[2];
         // r = sqrt( (x-xm)^2 + (y-ym)^2 )
  ret = hypot(x[0]-xm,x[1]-ym) - r;

  return(ret);
}

TReal* d_circle_equation(TReal *x,TReal *para,TReal *df)
{
  TReal xm,ym,r;

  xm       = para[0];
  ym       = para[1];
  r        = para[2];

  df[0] = - (x[0]-xm)/hypot(x[0]-xm,x[1]-ym);  // df/dxm
  df[1] = - (x[1]-ym)/hypot(x[0]-xm,x[1]-ym);  // df/dym
  df[2] = -1.0;                                // df/dr

  return(df);
}

bool fitting_circle(double *X,double *Y,int count,double *xm,double *r,double *Qxx)
{
  Cfitting_it  fitting_it(gDebugLevel>=4,gConvergence);
  TReal   ubk[3];
//  TReal   Qxx[3*3];
  TReal **x;  // Parameter
  TReal  *y;  // abhängige Variable
  int     i;
  bool    ret;
  int     iter;
  TReal   convergence;

  fitting_it.coords_as_array(X,Y,NULL,count,&x,&y);

  /* approx. values */
  ubk[0] = ubk[1] = 0.0;
  ubk[2] = 1.0;

  ret = fitting_it.approximation(y,count,x,count,ubk,3,Qxx,
               &iter,&convergence,
               circle_equation,
               d_circle_equation
               );

  if (ret==true)
  {
    for (i=0;i<2;i++) xm[i] = ubk[i] ;
    *r = ubk[2];
  }
  fitting_it.free_array(x,y,count);
  return(ret);
}
