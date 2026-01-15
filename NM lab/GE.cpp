#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int N = 3;

int main() {
    double a[N][N + 1] = {
        {2, 1, 1, 10},
        {1, 4, 9, 16},
        {3, 2, 3, 18}
    };

    // Forward elimination
    for (int i = 0; i < N; i++) {
        // Pivoting
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
    double x[N];
    for (int i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Output the solution
    cout << "Solution using Gaussian Elimination:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;
    }

    return 0;
}

