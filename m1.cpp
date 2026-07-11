#include <iostream>
#include "factorizations.h"
#include "matrix.h"
#include "NLA_FUNCTIONS.h"
using namespace std;

int main()
{
    int r,c;
    cout<<"ENTER NUMBER OF ROWS: \n"<<flush;
    cin>>r;
    cout<<"ENTER NUMBER OF COLOUNMS:\n"<<flush;
    cin>>c;
    Matrix A(r, c, 0);
    A.input();
    Matrix B = Householder_QR(A);
    A.print();
    B.print();
    return 0;
}