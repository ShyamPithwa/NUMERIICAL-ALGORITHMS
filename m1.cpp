#include <iostream>
#include "factorizations.h"
#include "matrix.h"
#include "NLA_FUNCTIONS.h"
using namespace std;

int main()
{
    int rows, cols;

    cout << "Householder QR Factorization\n";
    cout << "----------------------------\n";

    cout << "Number of rows: ";
    if (!(cin >> rows) || rows <= 0)
    {
        cout << "Please enter a positive whole number.\n";
        return 1;
    }

    cout << "Number of columns: ";
    if (!(cin >> cols) || cols <= 0)
    {
        cout << "Please enter a positive whole number.\n";
        return 1;
    }

    Matrix A(rows, cols, 0.0);
    A.input();

    Matrix R = Householder_QR(A);

    cout << "\nInput matrix A:\n";
    A.print();
    cout << "\nUpper-triangular matrix R:\n";
    R.prettyPrint();

    return 0;
}
