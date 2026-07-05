#ifndef GRAMSCHMIDT_H
#define GRAMSCHMIDT_H

#include "matrix.h"

Matrix MG_Schmidt(Matrix &A);

double tnorm(std::vector<double>& a);
double tnorm(Matrix &A, int k);

std::vector<double> access_colunm(const Matrix &A, int k);
void set_column(Matrix &A, int k, const std::vector<double>& col);

std::vector<double> VS_Multiplication(std::vector<double>& v, double k);
double Dot_product(std::vector<double> Q, std::vector<double> P);
std::vector<double> Vec_Sub(std::vector<double> A, std::vector<double> B);

#endif