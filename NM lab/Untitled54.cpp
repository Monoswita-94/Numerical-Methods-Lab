#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    double x[n], fx[n];

    // Input x values
    cout << "Enter 5 equally spaced x values: ";
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // Input corresponding f(x) values
    cout << "Enter corresponding 5 f(x) values: ";
    for (int i = 0; i < n; ++i) {
        cin >> fx[i];
    }

    // Step size
    double h = x[1] - x[0];

    // First derivative using forward difference (3-point)
    double first_derivative = (-3 * fx[0] + 4 * fx[1] - fx[2]) / (2 * h);

    // Second derivative using forward difference (4-point)
    double second_derivative = (2 * fx[0] - 5 * fx[1] + 4 * fx[2] - fx[3]) / (h * h);

    // Output results
    cout << "\nAt x = " << x[0] << ":" << endl;
    cout << "First Derivative ≈ " << first_derivative << endl;
    cout << "Second Derivative ≈ " << second_derivative << endl;

    return 0;
}
