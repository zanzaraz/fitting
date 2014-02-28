//---------------------------------------------------------------------------

#pragma hdrstop

#include "cfitting_plane.h"

#include  <math.h>


//---------------------------------------------------------------------------
#pragma package(smart_init)


extern int    gDebugLevel;
extern double gConvergence;

/*************************************************/

TReal plane_equation(TReal *x,TReal *para)
{
  TReal ret;
  TReal a,b,c;

  a       = para[0];
  b       = para[1];
  c       = para[2];

  ret = a*x[0] + b*x[1] + c*x[2] - 1.0;

  return(ret);
}

TReal* d_plane_equation(TReal *x,TReal *para,TReal *df)
{
  TReal a,b,c;

  a       = para[0];
  b       = para[1];
  c       = para[2];


  df[0] = x[0];  // df/da
  df[1] = x[1];  // df/db
  df[2] = x[2];  // df/dc

  return(df);
}


bool fitting_plane(double *X,double *Y,double *Z,int count,double *norm,double *d,double *Qxx)
{
  Cfitting_it  fitting_it(gDebugLevel>=4,gConvergence);
  TReal   ubk[3];
  TReal **x;  // Parameter
  TReal  *y;  // abhängige Variable
  int     i;
  bool    ret;
  int     iter;
  TReal   convergence;

  fitting_it.coords_as_array(X,Y,Z,count,&x,&y);
  /* approx. values */
  ubk[0] = ubk[1] = 0.0;
  ubk[2] = ubk[3] = 1.0;


  ret = fitting_it.approximation(y,count,x,count,ubk,3,Qxx,
               &iter,&convergence,
               plane_equation,
               d_plane_equation
               );
  if (ret==true)
  {
    *d = 1.0/hypot(hypot(ubk[0],ubk[1]),ubk[2]);
    for (i=0;i<3;i++) norm[i] = *d * ubk[i] ;
  }
  fitting_it.free_array(x,y,count);
  return(ret);
}
