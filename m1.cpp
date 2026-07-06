#include <iostream>
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
    Matrix B = MG_Schmidt(A);
    cout<<"ORIGINAL MATRIX:\n";
    A.print();
    cout<<"SET OF ORTHOGONAL VECTORS Q\n"<<flush;
    B.print();
    Matrix I =B.transpose()*B;
    cout<<"QxQ(transpose)"<<endl;
    I.print();
    return 0;
}