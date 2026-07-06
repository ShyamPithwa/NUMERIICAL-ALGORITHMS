#include <iostream>
#include "matrix.h"
#include "NLA_FUNCTIONS.h"
using namespace std;

int main()
{
    Matrix A(2, 2, 0);
    A.input();
    Matrix B = MG_Schmidt(A);
    B.print();
    cout<<"SET OF ORTHOGONAL VECTORS"<<endl;
    return 0;
}