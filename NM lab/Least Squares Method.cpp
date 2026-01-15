#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    double x[N], y[N];

    // Taking user input
    cout << "Enter " << N << " values for x:\n";
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    cout << "Enter " << N << " values for y:\n";
    for (int i = 0; i < N; i++) {
        cin >> y[i];
    }

    // Summation variables
    double sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    double sum_y = 0, sum_xy = 0, sum_x2y = 0;

    for (int i = 0; i < N; i++) {
        double xi = x[i], yi = y[i];
        sum_x += xi;
        sum_x2 += xi * xi;
        sum_x3 += xi * xi * xi;
        sum_x4 += xi * xi * xi * xi;
        sum_y += yi;
        sum_xy += xi * yi;
        sum_x2y += xi * xi * yi;
    }

    // Coefficient matrix
    double D =  N * (sum_x2 * sum_x4 - sum_x3 * sum_x3)
              - sum_x * (sum_x * sum_x4 - sum_x2 * sum_x3)
              + sum_x2 * (sum_x * sum_x3 - sum_x2 * sum_x2);

    double Da = sum_y * (sum_x2 * sum_x4 - sum_x3 * sum_x3)
              - sum_x * (sum_xy * sum_x4 - sum_x2y * sum_x3)
              + sum_x2 * (sum_xy * sum_x3 - sum_x2 * sum_x2y);

    double Db = N * (sum_xy * sum_x4 - sum_x2y * sum_x3)
              - sum_y * (sum_x * sum_x4 - sum_x2 * sum_x3)
              + sum_x2 * (sum_x * sum_x2y - sum_xy * sum_x2);

    double Dc = N * (sum_x2 * sum_x2y - sum_x3 * sum_xy)
              - sum_x * (sum_x * sum_x2y - sum_xy * sum_x2)
              + sum_y * (sum_x * sum_x3 - sum_x2 * sum_x2);

    // Calculate coefficients
    double a = Da / D;
    double b = Db / D;
    double c = Dc / D;

    cout << "\nLeast Squares Parabola: y = " << a << " + " << b << "x " << c << " x^2" << endl;

    return 0;
}
