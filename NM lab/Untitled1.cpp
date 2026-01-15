#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    double x[N], y[N];

    cout << "Enter " << N << " x-values (equally spaced):\n";
    for (int i = 0; i < N; i++) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
    }

    cout << "Enter corresponding " << N << " y-values (f(x)):\n";
    for (int i = 0; i < N; i++) {
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    double h = x[1] - x[0]; // Step size

    double delta1 = y[1] - y[0];
    double delta2 = y[2] - 2 * y[1] + y[0];
    double delta3 = y[3] - 3 * y[2] + 3 * y[1] - y[0];
    double delta4 = y[4] - 4 * y[3] + 6 * y[2] - 4 * y[1] + y[0];

    double first_derivative = (1.0 / h) * (delta1 - delta2 / 2.0 + delta3 / 3.0 - delta4 / 4.0);
    double second_derivative = (1.0 / (h * h)) * (delta2 - delta3 + (11.0 / 12.0) * delta4);

    cout << "\nFirst derivative at x = " << x[0] << " is: " << first_derivative << endl;
    cout << "Second derivative at x = " << x[0] << " is: " << second_derivative << endl;

    return 0;
}
