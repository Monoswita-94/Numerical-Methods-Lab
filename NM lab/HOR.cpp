#include <iostream>
using namespace std;

int main() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    double* a = new double[degree + 1];
    cout << "Enter the coefficients from constant term to highest degree term:\n";
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> a[i];
    }

    double x;
    cout << "Enter the value of x: ";
    cin >> x;

    // Apply Horner's rule
    double result = a[degree];
    for (int i = degree - 1; i >= 0; i--) {
        result = result * x + a[i];
    }

    cout << "\nValue of the polynomial at x = " << x << " is: " << result << endl;

    delete[] a;
    return 0;
}

