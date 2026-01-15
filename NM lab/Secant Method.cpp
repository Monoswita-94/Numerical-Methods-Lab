#include <iostream>
#include <cmath>
#include <iomanip>  // For controlling the output precision
using namespace std;

// Function to represent the equation f(x) = x^3 - 5x^2 - 29
double f(double x) {
    return pow(x, 3) - 5 * pow(x, 2) - 29;
}

// Secant Method Implementation
void secantMethod(double x0, double x1, double tolerance, int maxIterations) {
    double x2, f0, f1, error;
    int iteration = 1;

    cout << "Iteration\t x0\t\t x1\t\t x2\t\t f(x2)" << endl;

    do {
        f0 = f(x0);
        f1 = f(x1);

        // Compute next approximation using Secant formula
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        error = fabs(x2 - x1);  // Absolute error

        // Display the current iteration, x0, x1, x2, and f(x2) with proper formatting
        cout << iteration << "\t\t" << fixed << setprecision(6) << x0 << "\t" << x1 << "\t" << fixed << setprecision(6) << x2 << "\t" << fixed << setprecision(6) << f(x2) << endl;

        // Update values for next iteration
        x0 = x1;
        x1 = x2;
        iteration++;

        // Stop if error is within the desired precision
        if (error < tolerance) {
            break;
        }

    } while (iteration <= maxIterations);

    // Display the root found with 3 decimal places
    cout << "\nRoot found: " << fixed << setprecision(3) << x2 << " (correct to 3 decimal places)\n";
}

int main() {
    double x0, x1;
    int maxIterations = 100;  // Maximum allowed iterations
    double tolerance = 0.001; // Precision required (3 decimal places)

    // User input for initial guesses
    cout << "Enter first initial guess: ";
    cin >> x0;
    cout << "Enter second initial guess: ";
    cin >> x1;

    secantMethod(x0, x1, tolerance, maxIterations);

    return 0;
}
