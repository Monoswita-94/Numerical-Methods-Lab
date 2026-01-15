#include <iostream>
using namespace std;

int main() {
    // Coefficients of the polynomial x^3 - 2x^2 + 5x + 10
    // In the form: a[0] + a[1]x + a[2]x^2 + a[3]x^3
    double a[] = {10, 5, -2, 1};
    int n = 3; // Degree of polynomial
    double x = 5; // Value at which to evaluate

    // Apply Horner's rule
    double result = a[n];
    for (int i = n-1; i >= 0; i--) {
        result = result * x + a[i];
    }

    cout << "Value of polynomial at x = " << x << " is: " << result << endl;





    return 0;
}
