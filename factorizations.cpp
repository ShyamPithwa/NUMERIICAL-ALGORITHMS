#include "matrix.h"
#include "NLA_FUNCTIONS.h"
#include<iostream>
using namespace std;

Matrix Householder_QR(const Matrix& A){
    int n=A.getCols();
    int m=A.getRows();
    vector<int> x1(m);
    x1[0]=1;
    for(int i=1;i<m;i++){
    x1[i]=0;
    }
    for(int i=0;i<n;i++){
        Matrix x = Sub_Matrix(A,i,m-1,i,m-1);
        int z = 
    }
}