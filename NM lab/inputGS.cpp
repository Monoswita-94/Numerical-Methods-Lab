#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    const int N = 3;
    double a[N][N + 1];
    double x[N] = {0};
    cout << "Enter the coefficients and constants of the augmented matrix (row-wise):" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Row " << i + 1 << " (enter " << N + 1 << " values): ";
        for (int j = 0; j <= N; ++j) {
            cin >> a[i][j];
        }
    }
    int max_iterations;
    cout << "Enter the number of iterations to perform: ";
    cin >> max_iterations;
    cout << fixed << setprecision(6);
    cout << "\nGauss-Seidel Iteration Method:\n";
    for (int iteration = 1; iteration <= max_iterations; ++iteration) {
        for (int i = 0; i < N; ++i) {
            double sum = a[i][N];
            for (int j = 0; j < N; ++j) {
                if (j != i) {
                    sum -= a[i][j] * x[j];
                }
            }
            x[i] = sum / a[i][i];
        }
        cout << "Iteration " << iteration << ": ";
        for (int i = 0; i < N; ++i) {
            cout << "x" << i + 1 << " = " << x[i] << " ";
        }
        cout << endl;
    }
    cout << "\nFinal Solution after " << max_iterations << " iterations:\n";
    for (int i = 0; i < N; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}


