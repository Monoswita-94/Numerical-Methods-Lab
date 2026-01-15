#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    double x[N], y[N];


    cout << "Enter " << N << " values for x:\n";
    for (int i = 0; i < N; i++) {
        cout << "x[" << i + 1 << "]: ";
        cin >> x[i];
    }

    cout << "Enter " << N << " values for y:\n";
    for (int i = 0; i < N; i++) {
        cout << "y[" << i + 1 << "]: ";
        cin >> y[i];
    }


    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;


    for (int i = 0; i < N; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }


    double b = (N * sum_xy - sum_x * sum_y) / (N * sum_x2 - sum_x * sum_x);
    double a = (sum_y - b * sum_x) / N;


    cout << "\nLeast Squares Line Equation: y = " << a << " + " << b << "x" << endl;

    return 0;
}
