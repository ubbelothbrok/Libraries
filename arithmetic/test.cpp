#include <iostream>
#include "arithmetic.h"

int main() {
    try {
        std::cout << "Addition: 5 + 3 = " << add(5, 3) << std::endl;
        std::cout << "Subtraction: 10 - 4 = " << subtract(10, 4) << std::endl;
        std::cout << "Multiplication: 6 * 7 = " << multiply(6, 7) << std::endl;
        std::cout << "Division: 15 / 3 = " << divide(15, 3) << std::endl;
        std::cout << "Power: 2^3 = " << power(2, 3) << std::endl;
        std::cout << "Square root: sqrt(16) = " << square_root(16) << std::endl;
        std::cout << "Factorial: 5! = " << factorial(5) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}