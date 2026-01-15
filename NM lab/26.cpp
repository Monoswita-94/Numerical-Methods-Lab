#include <iostream>
using namespace std;

int main() {
    const int N = 5; // Number of data points
    double x[N], y[N]; // Arrays to store x and y values

    // Input x values
    cout << "Enter " << N << " x-values (equally spaced):\n";
    for (int i = 0; i < N; i++) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
    }

    // Input corresponding y = f(x) values
    cout << "Enter corresponding " << N << " y-values (f(x)):\n";
    for (int i = 0; i < N; i++) {
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    // Calculate step size (assumes equally spaced x values)
    double h = x[1] - x[0];

    // Calculate forward differences at x0
    double delta1 = y[1] - y[0];
    double delta2 = y[2] - 2 * y[1] + y[0];
    double delta3 = y[3] - 3 * y[2] + 3 * y[1] - y[0];
    double delta4 = y[4] - 4 * y[3] + 6 * y[2] - 4 * y[1] + y[0];

    // Compute first derivative using Newton's forward difference formula
    double first_derivative = (1.0 / h) * (delta1 - delta2 / 2.0 + delta3 / 3.0 - delta4 / 4.0);

    // Compute second derivative using Newton's forward difference formula
    double second_derivative = (1.0 / (h * h)) * (delta2 - delta3 + (11.0 / 12.0) * delta4);

    // Output results
    cout << "\nFirst derivative at x = " << x[0] << " is: " << first_derivative << endl;
    cout << "Second derivative at x = " << x[0] << " is: " << second_derivative << endl;

    return 0;
}
