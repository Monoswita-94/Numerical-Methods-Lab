#include <iostream>
#include <cmath>
#include <iomanip>

// Define the function f(x) = x^3 - 9x + 1
double f(double x) {
    return x * x * x - 9 * x + 1;
}

// Implement the bisection method
void bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        std::cerr << "Incorrect initial guesses. The function must have opposite signs at a and b." << std::endl;
        return;
    }

    double c;
    while ((b - a) / 2.0 > tolerance) {
        // Find the midpoint
        c = (a + b) / 2.0;

        // Check if the midpoint is the root or if the interval is sufficiently small
        if (std::abs(f(c)) <= tolerance) {
            break;
        }

        // Decide the side to repeat the steps
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    std::cout << "The root is: " << std::fixed << std::setprecision(5) << c << std::endl;
}

int main() {
    double a, b;
    const double tolerance = 1e-5; // Tolerance for five decimal places

    // User inputs for initial guesses
    std::cout << "Enter the first guess: ";
    std::cin >> a;
    std::cout << "Enter the second guess: ";
    std::cin >> b;

    // Call the bisection method
    bisection(a, b, tolerance);

    return 0;
}
