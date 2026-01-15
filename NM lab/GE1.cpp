#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int N = 3;
int main() {
    double a[N][N + 1];
    double x[N];
    cout << "Enter the coefficients and constants of the augmented matrix (row-wise):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << " (enter " << N + 1 << " values): ";
        for (int j = 0; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
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
    for (int i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    cout << "\nSolution using Gaussian Elimination:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;
    }
    return 0;
}
    `
