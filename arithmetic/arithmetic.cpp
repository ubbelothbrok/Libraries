#include "arithmetic.h"
#include <cmath>
#include <stdexcept>

// Basic arithmetic operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

// Advanced operations
double power(double base, int exponent) {
    double result = 1.0;
    bool negative = exponent < 0;
    exponent = abs(exponent);
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    if (negative) {
        result = 1.0 / result;
    }
    return result;
}

double square_root(double x) {
    if (x < 0) {
        throw std::invalid_argument("Square root of negative number");
    }
    return sqrt(x);
}

double factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial of negative number");
    }
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}