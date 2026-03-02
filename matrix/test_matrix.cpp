#include <iostream>
#include "matrix.h"

void section(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    try {
        // ── Sample matrices ──────────────────────────────────
        Matrix A = {{1, 2}, {3, 4}};
        Matrix B = {{5, 6}, {7, 8}};
        Matrix C = {{1, 2, 3}, {4, 5, 6}};    // 2x3
        Matrix D = {{7, 8}, {9, 10}, {11, 12}}; // 3x2

        // ── Addition ─────────────────────────────────────────
        section("Addition (A + B)");
        print(add(A, B));

        // ── Subtraction ──────────────────────────────────────
        section("Subtraction (A - B)");
        print(subtract(A, B));

        // ── Scalar multiply ──────────────────────────────────
        section("Scalar Multiply (3 * A)");
        print(scalar_multiply(3.0, A));

        // ── Matrix multiplication ─────────────────────────────
        section("Matrix Multiply (A * B)");
        print(multiply(A, B));

        section("Matrix Multiply (C [2x3] * D [3x2])");
        print(multiply(C, D));

        // ── Transpose ────────────────────────────────────────
        section("Transpose of C [2x3]");
        print(transpose(C));

        // ── Determinant ──────────────────────────────────────
        section("Determinant of A");
        std::cout << "det(A) = " << determinant(A) << "\n";

        Matrix E = {{3, 8}, {4, 6}};
        std::cout << "det(E) = " << determinant(E) << "\n";

        // ── Inverse ──────────────────────────────────────────
        section("Inverse of A");
        Matrix Ainv = inverse(A);
        print(Ainv);

        section("Verify: A * A^-1 should be Identity");
        print(multiply(A, Ainv));

        // ── Matrix Power ─────────────────────────────────────
        section("A^3 (matrix power)");
        print(power(A, 3));

        // ── Identity / Zeros helpers ──────────────────────────
        section("3x3 Identity");
        print(identity(3));

        section("2x4 Zeros");
        print(zeros(2, 4));

        // ── Error handling demo ───────────────────────────────
        section("Error Handling: multiply incompatible matrices");
        try {
            multiply(A, C);  // 2x2 * 2x3 is fine, try 2x3 * 2x2
        } catch (...) {}

        try {
            Matrix bad = {{1, 2, 3}, {4, 5, 6}};
            Matrix bad2 = {{1, 2}, {3, 4}};
            multiply(bad, bad2); // 2x3 * 2x2 → incompatible
        } catch (const std::exception& e) {
            std::cout << "Caught: " << e.what() << "\n";
        }

        section("Error Handling: singular matrix inverse");
        try {
            Matrix singular = {{1, 2}, {2, 4}};
            inverse(singular);
        } catch (const std::exception& e) {
            std::cout << "Caught: " << e.what() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
