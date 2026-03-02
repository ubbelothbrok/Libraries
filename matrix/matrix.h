#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>

// Matrix is represented as a 2D vector of doubles
using Matrix = std::vector<std::vector<double>>;

// --- Creation Helpers ---
Matrix zeros(int rows, int cols);
Matrix identity(int n);

// --- Basic Operations ---
Matrix add(const Matrix& A, const Matrix& B);
Matrix subtract(const Matrix& A, const Matrix& B);
Matrix multiply(const Matrix& A, const Matrix& B);
Matrix scalar_multiply(double scalar, const Matrix& A);

// --- Properties ---
int rows(const Matrix& A);
int cols(const Matrix& A);
bool is_square(const Matrix& A);

// --- Transformations ---
Matrix transpose(const Matrix& A);

// --- Advanced Operations ---
double determinant(const Matrix& A);
Matrix inverse(const Matrix& A);
Matrix power(const Matrix& A, int exponent);

// --- Utility ---
void print(const Matrix& A, std::ostream& out = std::cout);

#endif // MATRIX_H
