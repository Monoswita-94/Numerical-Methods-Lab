#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int N = 3; // Number of variables

int main() {
    double a[N][N + 1]; // Augmented matrix
    double x[N];        // Solution vector

    // Input augmented matrix
    cout << "Enter the coefficients and constants of the augmented matrix (row-wise):\n";
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << " (enter " << N + 1 << " values): ";
        for (int j = 0; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    // Forward elimination
    for (int i = 0; i < N; i++) {
        // Check for zero pivot
        if (fabs(a[i][i]) < 1e-8) {
            cout << "Mathematical Error: Zero pivot encountered." << endl;
            return -1;
        }

        for (int j = i + 1; j < N; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = i; k <= N; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back substitution
    for (int i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Output the solution
    cout << "\nSolution using Gaussian Elimination:\n";
    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;
    }

    return 0;
}

