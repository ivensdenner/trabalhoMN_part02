#include "DirectMethods.h"
#include <iostream>
#include <cmath>

#define MATRIX_MODE int
#define FROM_1_TO_N 0
#define FROM_0_TO_BN 1

using namespace std;

void printLU(SquareMatrix *LU, MATRIX_MODE mode) {
    int dimension;

    if (mode == FROM_1_TO_N)
        dimension = LU->get_dimension() - 1;
    else
        dimension = LU->get_dimension();

    // Imprimindo Matriz L
    std::cout << "Matriz L:" << std::endl;
    for (int i = 0; i < dimension; i++) {
        std::cout << "[\t";
        for (int j = 0; j < dimension; j++) {
            double value;
            if (j < i) {
                if (mode == FROM_1_TO_N)
                    value = LU->get_value(i + 1, j + 1);
                else
                    value = LU->get_value(i, j);
            }
            else if (i == j)
                value = 1;
            else
                value = 0;

            std::cout << value << "\t";
        }
        std::cout << "]" << std::endl;
    }

    // Imprimindo Matriz U
    std::cout << "Matriz U:" << std::endl;
    for (int i = 0; i < dimension; i++) {
        std::cout << "[\t";
        for (int j = 0; j < dimension; j++) {
            double value;
            if (j >= i)
                if (mode == FROM_1_TO_N)
                    value = LU->get_value(i + 1, j + 1);
                else
                    value = LU->get_value(i, j);
            else
                value = 0;

            std::cout << value << "\t";
        }
        std::cout << "]" << std::endl;
    }
}

int escolhe_pivo(SquareMatrix *A, int k, double *pv){
    int r;
    int n = A->get_dimension();

    *pv = abs (A->get_value(k,k));
    r = k;
    for(int i = (k+1); k <= n; k++){
        if (abs(A->get_value(i,k))> *pv){
            *pv = abs(A->get_value(i,k));
            r = i;
        }
    }
    return r;
}

void permuta(VectorN *p, SquareMatrix *A, int k, int r){
    double aux = p->get_value(k);
    int n = A->get_dimension();
    
    p->set_value(r,k);
    p->set_value(aux,r);
    for (int j = 1; j<=n; j++){
        aux = A->get_value(k,j);
        A->set_value(A->get_value(r,j),k,j);
        A->set_value(aux,r,j);
    }
}

VectorN *subst_sucessivas_mod(int n, SquareMatrix *A, VectorN *b){
    double soma;
    VectorN *x;
    x = new VectorN(n+1);
    
    for(int i = 1; i<=n ; i++){
        soma = 0;
        for (int j = 1; j<=(i-1); j++)
            soma = soma + A->get_value(i,j)*x->get_value(j);
        
        x->set_value(b->get_value(i)-soma, i);
    }
    return x;
}

VectorN *subst_retroativas(int n , SquareMatrix *A, VectorN *b){
    double soma;
    VectorN *x;
    x = new VectorN(n+1);
    
    x->set_value(b->get_value(n)/A->get_value(n,n), n);
    
    
    for (int i = n-1; i>=1;i--){
        soma = 0;
        for(int j = i+1; j<=n; j++)
            soma += (A->get_value(i,j)*x->get_value(j));
        
        x->set_value((b->get_value(i)-soma)/A->get_value(i,i),i);
    }
    return x;
}

VectorN *FatoracaoLU(int n, SquareMatrix *A, VectorN *b){
    
    VectorN *p, *blin, *x, *y;
    x = new VectorN(n+1);
    y = new VectorN(n+1);
    p = new VectorN(n+1);
    blin = new VectorN(n+1);
    double *pv;
    pv = new double();
    double m;
    int r;
    
    //inicializaÁao do vetor de permutacoes
    
    for (int i=1; i<=n;i++)
        p->set_value(i,i);
    
    for (int k=1; k<= n-1; k++){
        
        r = escolhe_pivo(A, k, pv);
        if (*pv==0)
            cout << "Matriz Singular" << endl;
        
        if (r != k) permuta(p, A, k, r);
        
        
        //guarda fatores m em A
        for (int i=k+1; i <= n; i++){
            m = A->get_value(i,k)/ A->get_value(k,k);
            A->set_value(m,i,k);
            for (int j=k+1; j<=n;j++)
                A->set_value(A->get_value(i,j)-(m*A->get_value(k,j)),i,j);
        }
        
        
        
    }
    
    //aplica permutaÁoes em b
    for (int i=1; i <= n; i++){
        r= p->get_value(i);
        blin->set_value(b->get_value(r),i);
    }
    printLU(A, FROM_1_TO_N);
    // Ly=b
    y = subst_sucessivas_mod(n,A,blin);
    // Ux = y
    x = subst_retroativas(n,A,y);
    return x;
    
}

SquareMatrix* getDoolittleLUMatrix(SquareMatrix& A)
{
    int dimension = A.get_dimension();
    double alpha = 0;
    
    SquareMatrix *LU = new SquareMatrix(A);
    
    // Encontrando matriz LU
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < i; j++)
        {
            alpha = LU->get_value(i, j);
            for (int k = 0; k < j; k++)
                alpha -= (LU->get_value(i, k) * LU->get_value(k, j));
            
            LU->set_value(alpha / LU->get_value(j, j), i, j);
        }
        
        for (int j = i; j < dimension; j++)
        {
            alpha = LU->get_value(i, j);
            for (int k = 0; k < i; k++)
                alpha -= (LU->get_value(i, k) * LU->get_value(k, j));
            
            LU->set_value(alpha, i, j);
        }
    }
    
    return LU;
}

VectorN *forwardSubstitution(SquareMatrix& A, VectorN& b)
{
    int dimension = A.get_dimension();
    double soma;
    VectorN *x;
    x = new VectorN(dimension);
    
    for(int i = 0; i < dimension; i++){
        soma = 0;
        for (int j = 0; j < i; j++)
            soma = soma + A.get_value(i,j) * x->get_value(j);
        
        x->set_value(b.get_value(i)-soma, i);
    }
    
    return x;
}

VectorN *backwardSubstitution(SquareMatrix& A, VectorN& b)
{    
    int dimension = A.get_dimension();
    double soma;
    VectorN *x;
    x = new VectorN(dimension);
    
    x->set_value(b.get_value(dimension - 1) / A.get_value( dimension - 1, dimension - 1), dimension - 1);
    
    
    for (int i = dimension - 2; i >= 0; i--){
        soma = 0;
        for(int j = i + 1; j < dimension; j++)
            soma += (A.get_value(i, j) * x->get_value(j));
        
        x->set_value((b.get_value(i)-soma) / A.get_value(i,i),i);
    }
    
    return x;
}

VectorN *doolittleLU(SquareMatrix& A, VectorN& b)
{
    SquareMatrix *LU = getDoolittleLUMatrix(A);
    VectorN *x;
    VectorN *y;

    printLU(LU, FROM_0_TO_BN);
    
    // Separando matriz LU
    SquareMatrix *L = new SquareMatrix(LU->get_dimension());
    for (int i = 0; i < L->get_dimension(); i++)
        L->set_value(1, i, i);
    SquareMatrix *U = new SquareMatrix(LU->get_dimension());
    
    for (int i = 0; i < L->get_dimension(); i++)
    {
        for (int j = 0; j < L->get_dimension(); j++)
        {
            if (j < i)
                L->set_value(LU->get_value(i, j), i, j);
            else
                U->set_value(LU->get_value(i, j), i, j);
        }
    }
    
    y = forwardSubstitution(*L, b);
    x = backwardSubstitution(*U, *y);
    
    return x;
}
