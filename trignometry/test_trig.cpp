#include <iostream>
#include "trignometry.h"

int main() {
    try {
        double angle_rad = degrees_to_radians(45.0); // 45 degrees in radians
        std::cout << "Sine of 45°: " << sine(angle_rad) << std::endl;
        std::cout << "Cosine of 45°: " << cosine(angle_rad) << std::endl;
        std::cout << "Tangent of 45°: " << tangent(angle_rad) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}


