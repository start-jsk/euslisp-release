///////////////////////////////////////////////////////////////////////////////
///
/// $Id: nr.h 195 2010-03-13 05:50:28Z k-okada $
///
/// Copyright (c) 1987- JSK, The University of Tokyo.  All Rights Reserved.
///
/// This software is a collection of EusLisp code for robot applications,
/// which has been developed by the JSK Laboratory for the IRT project.
/// For more information on EusLisp and its application to the robotics,
/// please refer to the following papers.
///
/// Toshihiro Matsui
/// Multithread object-oriented language euslisp for parallel and
///  asynchronous programming in robotics
/// Workshop on Concurrent Object-based Systems,
///  IEEE 6th Symposium on Parallel and Distributed Processing, 1994
///
/// Permission to use this software for educational, research
/// and non-profit purposes, without fee, and without a written
/// agreement is hereby granted to all researchers working on
/// the IRT project at the University of Tokyo, provided that the
/// above copyright notice remains intact.  
///

#ifndef _NR_H_
#define _NR_H_

static eusfloat_t sqrarg;
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg*sqrarg)

static eusfloat_t maxarg1, maxarg2;
#define FMAX(a,b) (maxarg1=(a),maxarg2=(b),(maxarg1) > (maxarg2) ? (maxarg1) : (maxarg2))

static int iminarg1, iminarg2;
#define IMIN(a,b) (iminarg1=(a),iminarg2=(b),(iminarg1) < (iminarg2) ? (iminarg1) : (iminarg2))

#define SIGN(a,b) ((b) >= 0.0 ? fabs(a) : -fabs(a))
#define SWAP(g,h) {y=(g);(g)=(h);(h)=y;}

#define NR_END 1
#define FREE_ARG char*

void nrerror(char error_text[]);
eusfloat_t *nr_vector(int nl, int nh);
eusfloat_t **nr_matrix(int nrl, int nrh, int ncl, int nch);
void free_nr_vector(eusfloat_t *v, int nl, int nh);
void free_nr_matrix(eusfloat_t **m, int nrl, int nrh, int ncl, int nch);

#define TINY 1.0e-20
void lubksb(eusfloat_t **a, int n, int *indx, eusfloat_t b[]);
int  ludcmp(eusfloat_t **a, int n, int *indx, eusfloat_t *d);

int svdsolve(eusfloat_t **a, int m, int n, eusfloat_t *b, eusfloat_t *x);
void svbksb(eusfloat_t **u, eusfloat_t *w, eusfloat_t **v, int m, int n, eusfloat_t *b, eusfloat_t *x);
int svdcmp(eusfloat_t **a, int m, int n, eusfloat_t *w, eusfloat_t **v);

eusfloat_t pythag(eusfloat_t a, eusfloat_t b);

static copymat(dest,src,size)
pointer dest,src;
register int size;
{ register int i;
  register eusfloat_t *rv=dest->c.ary.entity->c.fvec.fv;
  register eusfloat_t *mv=src->c.ary.entity->c.fvec.fv;
  size=size*size;
  for (i=0; i<size; i++) rv[i]=mv[i]; }

#endif //_NR_H_
