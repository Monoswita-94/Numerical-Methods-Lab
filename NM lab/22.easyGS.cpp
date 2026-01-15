#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int N = 3; // Number of variables
    double a[N][N + 1]; // Augmented matrix
    double x[N] = {0, 0, 0}; // Initial guesses x1 = x2 = x3 = 0

    // Input the augmented matrix
    cout << "Enter coefficients and constants (row-wise):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << " (a" << i+1 << "1 a" << i+1 << "2 a" << i+1 << "3 b" << i+1 << "): ";
        for (int j = 0; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    int iterations;
    cout << "Enter number of iterations: ";
    cin >> iterations;

    // Gauss-Seidel Iteration
    cout << "\nGauss-Seidel Iteration Steps:\n";
    cout << fixed << setprecision(6);

    for (int step = 1; step <= iterations; step++) {
        double newX[N];

        for (int i = 0; i < N; i++) {
            double sum = a[i][N]; // Start with the RHS

            for (int j = 0; j < N; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j]; // Subtract other variables
            }

            newX[i] = sum / a[i][i]; // Solve for current variable
        }

        // Update all values
        for (int i = 0; i < N; i++) {
            x[i] = newX[i];
        }

        // Display current iteration values
        cout << "Iteration " << step << ": ";
        for (int i = 0; i < N; i++) {
            cout << "x" << i + 1 << " = " << x[i] << "  ";
        }
        cout << endl;
    }

    // Final result
    cout << "\nFinal Solution:\n";
    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}

