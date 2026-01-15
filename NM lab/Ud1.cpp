#include <iostream>
using namespace std;

// Function to evaluate polynomial using Horner's Rule
double horner(int coeff[], int degree, int x) {
    double result = coeff[0];
    for (int i = 1; i <= degree; i++) {
        result = result * x + coeff[i];
    }
    return result;
}

int main() {
    int coeff[] = {1, -2, 5, 10};  // Coefficients for x^3 - 2x^2 + 5x + 10
    int degree = 3; // Degree of the polynomial
    int x = 5;  // Given value of x

    cout << "Value of the polynomial at x = " << x << " is " << horner(coeff, degree, x) << endl;
    return 0;
}

