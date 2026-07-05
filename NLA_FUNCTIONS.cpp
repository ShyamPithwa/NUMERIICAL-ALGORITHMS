#include <matrix.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 2-NORM
double tnorm(vector<double> &a)
{
  double n = a.size();
  double norm, s=0.0;
  for (double i = 0; i < n; i++)
  {
    s += pow(a[i], 2);
  }
  norm = sqrt(s);
  return norm;
}

// 2 norm for Matrix colunm
double tnorm(Matrix &A, int k)
{
  int n = A.getCols();
  double norm, s=0.0;
  for (int i = 0; i < n; i++)
  {
    s += pow(A(i, k), 2);
  }
  norm = sqrt(s);
  return norm;
}

// Function to access colunm
vector<double> access_colunm(Matrix& A, int k)
{
  int c = A.getRows();
  vector<double> colunm(c);
  for (int i = 0; i < c; i++)
  {
    colunm[i] = A(i, k);
  }
  return colunm;
}

//For Multiplication of scalar to whole vector
vector<double> VS_Multiplication(vector<double>& v,double k){
    int n=v.size();
    for(int i=0;i<n;i++){
      v[i] *=k;
    }
    return v;
}

//Dot/inner product
double Dot_product(vector<double>Q,vector<double>P){
  
  if(Q.size()==P.size()){
    int n=Q.size();
    double r=0;
    for(int i=0;i<n;i++){
      r+=P[i]*Q[i];
    }
    return r;
  }

  else{
     cout<<"INVALID OPERATION"<<endl;
     return -1;
  }
}

//Vector Subtraction
vector<double> Vec_Sub(vector<double> A,vector<double> B){
  if(A.size()==B.size()){
   int n=A.size();
   vector<double> C(n);
   for(int i=0;i<n;i++){
    C[i]=A[i]-B[i];
   }
   return C;
  }
  else return {};
} 

//To update colunms
void set_column(Matrix &A, int k, const vector<double> &col)
{
    if (col.size() != A.getRows())
    {
        cout << "Invalid column size" << endl;
        return;
    }

    for (int i = 0; i < A.getRows(); i++)
    {
        A(i, k) = col[i];
    }
}

// Modified Gram schmidt
Matrix MG_Schmidt(Matrix &A)
{
  int m = A.getCols();
  int n = A.getRows();
  Matrix V = A;
  for(int i=0;i<m;i++){
    vector<double> v = access_colunm(V,i);
  double r = tnorm(v);
  vector<double> q =VS_Multiplication(v,1.0/r);
  set_column(V,i,q);
    for(int j=i+1;j<m;j++){
      vector<double> vj=access_colunm(V,j);
      double z= Dot_product(q,vj);
     vector<double> proj = VS_Multiplication(q, z);
      vj=Vec_Sub(vj,proj);
      set_column(V,j,vj);
    }
  }
  return V;
}