#pragma once
#ifndef __EE_242_Project_2__matrix__
#define __EE_242_Project_2__matrix__

#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

using std::vector;
using std::tuple;
class Matrix {
private:
    unsigned m_rowSize;
    unsigned m_colSize;
    vector<vector<double> > m_matrix;
public:
    Matrix(unsigned, unsigned, double);
    Matrix(const char *);
    Matrix(const Matrix &);
    ~Matrix();
    
    // Matrix Operations
    Matrix operator+(Matrix &);
    Matrix operator-(Matrix &);
    Matrix operator*(Matrix &);
    Matrix transpose();
    
    void input();
    
    // Scalar Operations
    Matrix operator+(double);
    Matrix operator-(double);
    Matrix operator*(double);
    Matrix operator/(double);
    
    // Aesthetic Methods
    double& operator()(const unsigned &, const unsigned &);
    void print() const;
    unsigned getRows() const;
    unsigned getCols() const;
    
    // Power Iteration
    tuple<Matrix, double, int> powerIter(unsigned, double);
    
    // Deflation
    Matrix deflation(Matrix &, double&);
};
#endif