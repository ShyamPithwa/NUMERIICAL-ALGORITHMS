#include "matrix.h"
#include "NLA_FUNCTIONS.h"
#include <iostream>
using namespace std;

Matrix Householder_QR(const Matrix &A)
{
    Matrix M = A;
    int n = A.getCols();
    int m = A.getRows();
    vector<double> e(m);
    e[0] = 1;
    for (int i = 1; i < m; i++)
    {
        e[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        vector<double> x = access_colunm(A, i);
        if (i != 0)
        {
            x.erase(x.begin(), x.begin() + i - 1);
        }
        double y = tnorm(x);
        int z = x[0] / abs(x[0]);
        vector<double> v = VS_Multiplication(e, y * z);
        v = Vec_Add(v, x);
        double v1 = tnorm(v);
        v = VS_Multiplication(v, 1 / v1);
    }
}