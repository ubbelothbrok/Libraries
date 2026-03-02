# Matrix Library

A C++ library for matrix arithmetic operations.

## Files

- `matrix.h`: Header file with type definitions and function declarations
- `matrix.cpp`: Implementation of all matrix operations
- `test_matrix.cpp`: Example usage and testing

## Matrix Type

Matrices are represented as `std::vector<std::vector<double>>` aliased as `Matrix`.

## Functions

### Creation Helpers
| Function | Description |
|---|---|
| `zeros(rows, cols)` | Returns a matrix of all zeros |
| `identity(n)` | Returns an n×n identity matrix |

### Basic Operations
| Function | Description |
|---|---|
| `add(A, B)` | Element-wise addition (same dimensions required) |
| `subtract(A, B)` | Element-wise subtraction (same dimensions required) |
| `multiply(A, B)` | Matrix multiplication (cols of A must equal rows of B) |
| `scalar_multiply(s, A)` | Multiply every element by scalar `s` |

### Properties
| Function | Description |
|---|---|
| `rows(A)` | Returns the number of rows |
| `cols(A)` | Returns the number of columns |
| `is_square(A)` | Returns `true` if A is a square matrix |

### Transformations
| Function | Description |
|---|---|
| `transpose(A)` | Returns the transpose of A |

### Advanced Operations
| Function | Description |
|---|---|
| `determinant(A)` | Determinant via Gaussian elimination with partial pivoting |
| `inverse(A)` | Inverse via Gauss-Jordan elimination (throws if singular) |
| `power(A, n)` | A raised to integer power n using fast exponentiation |

### Utility
| Function | Description |
|---|---|
| `print(A)` | Pretty-prints the matrix to `std::cout` (or a custom stream) |

## Compilation

```bash
g++ -std=c++17 -c matrix.cpp -o matrix.o
g++ -std=c++17 test_matrix.cpp matrix.o -o test_matrix
./test_matrix
```

## Usage

```cpp
#include "matrix.h"

Matrix A = {{1, 2}, {3, 4}};
Matrix B = {{5, 6}, {7, 8}};

Matrix C  = multiply(A, B);
Matrix At = transpose(A);
double d  = determinant(A);
Matrix Ai = inverse(A);

print(C);
```

## Error Handling

All functions throw `std::invalid_argument` for:
- Mismatched dimensions in `add` / `subtract`
- Incompatible dimensions in `multiply`
- Non-square matrix passed to `determinant`, `inverse`, `power`
- Singular matrix passed to `inverse`
