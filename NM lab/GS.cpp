#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Coefficients of the equations
    double a[3][4] = {
        {10, 1, 1, 12},
        {2, 10, 1, 13},
        {2, 2, 10, 14}
    };

    // Initial guesses
    double x[3] = {0, 0, 0};
    double prev_x[3] = {0, 0, 0};

    // Tolerance and maximum iterations
    double tolerance = 1e-6;
    int max_iterations = 100;

    cout << fixed << setprecision(6);
    cout << "Gauss-Seidel Iteration Method:\n";

    for (int iteration = 1; iteration <= max_iterations; ++iteration) {
        // Store previous values
        for (int i = 0; i < 3; ++i) {
            prev_x[i] = x[i];
        }

        // Update x[0]
        x[0] = (a[0][3] - a[0][1]*x[1] - a[0][2]*x[2]) / a[0][0];

        // Update x[1]
        x[1] = (a[1][3] - a[1][0]*x[0] - a[1][2]*x[2]) / a[1][1];

        // Update x[2]
        x[2] = (a[2][3] - a[2][0]*x[0] - a[2][1]*x[1]) / a[2][2];

        // Display current iteration
        cout << "Iteration " << iteration << ": ";
        cout << "x1 = " << x[0] << ", x2 = " << x[1] << ", x3 = " << x[2] << endl;

        // Check for convergence
        if (fabs(x[0] - prev_x[0]) < tolerance &&
            fabs(x[1] - prev_x[1]) < tolerance &&
            fabs(x[2] - prev_x[2]) < tolerance) {
            cout << "\nConverged in " << iteration << " iterations.\n";
            break;
        }

        // If maximum iterations reached without convergence
        if (iteration == max_iterations) {
            cout << "\nDid not converge within the maximum number of iterations.\n";
        }
    }

    // Final solution
    cout << "\nFinal Solution:\n";
    cout << "x1 = " << x[0] << "\n";
    cout << "x2 = " << x[1] << "\n";
    cout << "x3 = " << x[2] << "\n";

    return 0;
}

