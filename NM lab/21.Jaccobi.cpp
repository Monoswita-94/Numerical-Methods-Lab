#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Coefficients
    double a1, b1, c1, d1;
    double a2, b2, c2, d2;
    double a3, b3, c3, d3;

    // User input
    cout << "Enter coefficients for equation 1 (a1x + b1y + c1z = d1): ";
    cin >> a1 >> b1 >> c1 >> d1;

    cout << "Enter coefficients for equation 2 (a2x + b2y + c2z = d2): ";
    cin >> a2 >> b2 >> c2 >> d2;

    cout << "Enter coefficients for equation 3 (a3x + b3y + c3z = d3): ";
    cin >> a3 >> b3 >> c3 >> d3;

    double x0 = 0, y0 = 0, z0 = 0; // Initial guess
    double x1, y1, z1;
    int max_iter;
    cout << "Enter number of iterations: ";
    cin >> max_iter;
    cout << fixed;
    for (int i = 1; i <= max_iter; i++) {
        // Jacobi formulas
        x1 = (d1 - (b1 * y0) - (c1 * z0)) / a1;
        y1 = (d2 - (a2 * x0) - (c2 * z0)) / b2;
        z1 = (d3 - (a3 * x0) - (b3 * y0)) / c3;

        cout << "Iteration " << i << ": x = " << x1 << ", y = " << y1 << ", z = " << z1 << endl;

        // Update for next iteration
        x0 = x1;
        y0 = y1;
        z0 = z1;
    }

    return 0;
}
