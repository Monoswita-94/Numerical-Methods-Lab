#include <iostream>
using namespace std;

const int N = 5;

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    double x[N], y[N][N];

    // Input x values
    cout << "Enter " << " x values:\n";
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    // Input y values
    cout << "Enter corresponding y = f(x) values:\n";
    for (int i = 0; i < N; i++) {
        cin >> y[i][0];
    }

    // Create forward difference table
    for (int j = 1; j < N; j++) {
        for (int i = 0; i < N - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Input the value of x to interpolate
    double value;
    cout << "Enter the value of x to interpolate: ";
    cin >> value;

    // Calculate h and u
    double h = x[1] - x[0];
    double u = (value - x[0]) / h;

    // Newton's forward formula
    double result = y[0][0];
    double term = 1;

    for (int i = 1; i < N; i++) {
        term *= (u - (i - 1));
        result += (term * y[0][i]) / factorial(i);
    }

    cout << "The interpolated value at x = " << value << " is: " << result << endl;

    return 0;
}
