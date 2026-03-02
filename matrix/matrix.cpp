#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

// ─────────────────────────────────────────────
//  Internal helpers
// ─────────────────────────────────────────────
static void check_same_size(const Matrix& A, const Matrix& B) {
    if (A.size() != B.size() || A[0].size() != B[0].size())
        throw std::invalid_argument("Matrix dimensions do not match");
}

static void check_square(const Matrix& A) {
    if (A.size() != A[0].size())
        throw std::invalid_argument("Matrix must be square");
}

static void check_multipliable(const Matrix& A, const Matrix& B) {
    if (A[0].size() != B.size())
        throw std::invalid_argument(
            "Number of columns in A must equal number of rows in B");
}

// ─────────────────────────────────────────────
//  Creation helpers
// ─────────────────────────────────────────────
Matrix zeros(int rows, int cols) {
    return Matrix(rows, std::vector<double>(cols, 0.0));
}

Matrix identity(int n) {
    Matrix I = zeros(n, n);
    for (int i = 0; i < n; ++i) I[i][i] = 1.0;
    return I;
}

// ─────────────────────────────────────────────
//  Properties
// ─────────────────────────────────────────────
int rows(const Matrix& A) { return static_cast<int>(A.size()); }
int cols(const Matrix& A) { return A.empty() ? 0 : static_cast<int>(A[0].size()); }
bool is_square(const Matrix& A) { return rows(A) == cols(A); }

// ─────────────────────────────────────────────
//  Basic operations
// ─────────────────────────────────────────────
Matrix add(const Matrix& A, const Matrix& B) {
    check_same_size(A, B);
    int r = rows(A), c = cols(A);
    Matrix result = zeros(r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    check_same_size(A, B);
    int r = rows(A), c = cols(A);
    Matrix result = zeros(r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

Matrix multiply(const Matrix& A, const Matrix& B) {
    check_multipliable(A, B);
    int r = rows(A), inner = cols(A), c = cols(B);
    Matrix result = zeros(r, c);
    for (int i = 0; i < r; ++i)
        for (int k = 0; k < inner; ++k)
            for (int j = 0; j < c; ++j)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

Matrix scalar_multiply(double scalar, const Matrix& A) {
    int r = rows(A), c = cols(A);
    Matrix result = zeros(r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[i][j] = scalar * A[i][j];
    return result;
}

// ─────────────────────────────────────────────
//  Transformations
// ─────────────────────────────────────────────
Matrix transpose(const Matrix& A) {
    int r = rows(A), c = cols(A);
    Matrix result = zeros(c, r);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[j][i] = A[i][j];
    return result;
}

// ─────────────────────────────────────────────
//  Determinant  (Gaussian elimination)
// ─────────────────────────────────────────────
double determinant(const Matrix& A) {
    check_square(A);
    int n = rows(A);
    Matrix M = A;          // working copy
    double det = 1.0;
    int sign = 1;

    for (int col = 0; col < n; ++col) {
        // Partial pivoting
        int pivot = -1;
        for (int row = col; row < n; ++row) {
            if (std::abs(M[row][col]) > 1e-12) { pivot = row; break; }
        }
        if (pivot == -1) return 0.0;   // singular
        if (pivot != col) {
            std::swap(M[pivot], M[col]);
            sign *= -1;
        }
        det *= M[col][col];
        double inv = 1.0 / M[col][col];
        for (int row = col + 1; row < n; ++row) {
            double factor = M[row][col] * inv;
            for (int k = col; k < n; ++k)
                M[row][k] -= factor * M[col][k];
        }
    }
    return sign * det;
}

// ─────────────────────────────────────────────
//  Inverse  (Gauss-Jordan with augmented matrix)
// ─────────────────────────────────────────────
Matrix inverse(const Matrix& A) {
    check_square(A);
    int n = rows(A);
    // Build [A | I]
    Matrix aug(n, std::vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) aug[i][j] = A[i][j];
        aug[i][i + n] = 1.0;
    }

    for (int col = 0; col < n; ++col) {
        // Partial pivoting
        int pivot = -1;
        double best = 0.0;
        for (int row = col; row < n; ++row) {
            if (std::abs(aug[row][col]) > best) {
                best = std::abs(aug[row][col]);
                pivot = row;
            }
        }
        if (pivot == -1 || best < 1e-12)
            throw std::invalid_argument("Matrix is singular and cannot be inverted");
        if (pivot != col) std::swap(aug[pivot], aug[col]);

        double inv = 1.0 / aug[col][col];
        for (int k = 0; k < 2 * n; ++k) aug[col][k] *= inv;

        for (int row = 0; row < n; ++row) {
            if (row == col) continue;
            double factor = aug[row][col];
            for (int k = 0; k < 2 * n; ++k)
                aug[row][k] -= factor * aug[col][k];
        }
    }

    // Extract right half
    Matrix result = zeros(n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = aug[i][j + n];
    return result;
}

// ─────────────────────────────────────────────
//  Matrix power  (repeated multiplication)
// ─────────────────────────────────────────────
Matrix power(const Matrix& A, int exponent) {
    check_square(A);
    if (exponent < 0)
        throw std::invalid_argument(
            "Negative exponents not supported; compute inverse first");
    int n = rows(A);
    Matrix result = identity(n);
    Matrix base = A;
    int exp = exponent;
    // Fast exponentiation by squaring
    while (exp > 0) {
        if (exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

// ─────────────────────────────────────────────
//  Utility: print
// ─────────────────────────────────────────────
void print(const Matrix& A, std::ostream& out) {
    int r = rows(A), c = cols(A);
    for (int i = 0; i < r; ++i) {
        out << "[ ";
        for (int j = 0; j < c; ++j) {
            out << std::setw(10) << std::fixed << std::setprecision(4) << A[i][j];
            if (j < c - 1) out << "  ";
        }
        out << " ]\n";
    }
}
