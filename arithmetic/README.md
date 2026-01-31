# Arithmetic Library

A simple C++ library for basic and advanced arithmetic operations.

## Files

- `arithmetic.h`: Header file with function declarations
- `arithmetic.cpp`: Implementation of the arithmetic functions
- `test.cpp`: Example usage and testing

## Functions

### Basic Operations
- `double add(double a, double b)`: Returns a + b
- `double subtract(double a, double b)`: Returns a - b
- `double multiply(double a, double b)`: Returns a * b
- `double divide(double a, double b)`: Returns a / b (throws exception on division by zero)

### Advanced Operations
- `double power(double base, int exponent)`: Returns base^exponent
- `double square_root(double x)`: Returns square root of x (throws exception for negative numbers)
- `double factorial(int n)`: Returns n! (throws exception for negative n)

## Compilation

To compile the library and test:

```bash
g++ -c arithmetic.cpp -o arithmetic.o
g++ test.cpp arithmetic.o -o test
./test
```

## Usage

Include the header in your code:

```cpp
#include "arithmetic.h"
```

Then use the functions as needed.

## Error Handling

Functions throw `std::invalid_argument` for invalid inputs (division by zero, square root of negative, factorial of negative).