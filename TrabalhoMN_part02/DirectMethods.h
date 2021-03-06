#ifndef DIRECT_METHODS_H
#define DIRECT_METHODS_H

#include "SquareMatrix.h"
#include "VectorN.h"

int escolhe_pivo(SquareMatrix *A, int k, double *pv, int *r);
void permuta(VectorN *p, SquareMatrix *A, int k, int r);
VectorN *subst_sucessivas_mod(int n, SquareMatrix *A, VectorN *b);
VectorN *subst_retroativas(int n , SquareMatrix *A, VectorN *b);
VectorN *FatoracaoLU(int n, SquareMatrix *A, VectorN *b);
VectorN *doolittleLU(SquareMatrix& A, VectorN& b);

#endif
