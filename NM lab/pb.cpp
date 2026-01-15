#include <iostream>
using namespace std;

int main() {
    const int n = 4;
    double x[n], y[n];

    // User input
    cout << "Enter 4 values for x: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter 4 values for y: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    // Summations
    double sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    double sum_y = 0, sum_xy = 0, sum_x2y = 0;

    for (int i = 0; i < n; i++) {
        double xi = x[i], yi = y[i];
        sum_x += xi;
        sum_x2 += xi * xi;
        sum_x3 += xi * xi * xi;
        sum_x4 += xi * xi * xi * xi;
        sum_y += yi;
        sum_xy += xi * yi;
        sum_x2y += xi * xi * yi;
    }

    // Normal equations matrix for a + bx + cx^2
    double A[3][4] = {
        {n, sum_x, sum_x2, sum_y},
        {sum_x, sum_x2, sum_x3, sum_xy},
        {sum_x2, sum_x3, sum_x4, sum_x2y}
    };

    // Gaussian Elimination
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            double ratio = A[j][i] / A[i][i];
            for (int k = 0; k < 4; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    // Back substitution
    double c = A[2][3] / A[2][2];
    double b = (A[1][3] - A[1][2] * c) / A[1][1];
    double a = (A[0][3] - A[0][1] * b - A[0][2] * c) / A[0][0];

    cout << "\nFitted Parabola: y = " << a << " + " << b << "x + " << c << "x^2" << endl;

    return 0;
}
