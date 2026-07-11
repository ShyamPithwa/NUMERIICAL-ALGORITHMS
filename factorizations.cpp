#include "matrix.h"
#include "NLA_FUNCTIONS.h"
#include <iostream>
using namespace std;

Matrix Householder_QR(const Matrix &A)
{
    Matrix M = A;
    int n = A.getCols();
    int m = A.getRows();
   
    for (int i = 0; i < min(m-1, n); i++)
    {
        Matrix A_sub = Sub_Matrix(M, i, m - 1, i, n - 1);
        vector<double> x = access_colunm(A_sub, 0);
        vector<double> e(x.size(), 0.0);
        e[0] = 1.0;
        double y = tnorm(x);
        double z = (x[0] >= 0) ? 1.0 : -1.0;
        vector<double> v = VS_Multiplication(e, y * z);
        v = Vec_Add(v, x);
        double v1 = tnorm(v);
        if (v1 == 0.0) continue;
        v = VS_Multiplication(v, 1 / v1);
        Matrix temp = VM_multiplication(v, A_sub);
        Matrix update = OuterProduct(v, temp) * 2.0;
        A_sub = A_sub - update;
        InsertSubMatrix(M, A_sub, i, i);
    }
    return M;
}