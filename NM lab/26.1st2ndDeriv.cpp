#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    double x[N], y[N];

    // Taking user input
    cout << "Enter 5 values for x (equally spaced):\n";
    for (int i = 0; i < N; i++) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
    }

    cout << "Enter 5 corresponding values for y = f(x):\n";
    for (int i = 0; i < N; i++) {
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    double h = x[1] - x[0]; // Step size

    // Calculate forward differences at x0 = x[0]
    double delta1 = y[1] - y[0]; //
    double delta2 = y[2] - 2 * y[1] + y[0]; // Δ²y
    double delta3 = y[3] - 3 * y[2] + 3 * y[1] - y[0]; // Δ³y
    double delta4 = y[4] - 4 * y[3] + 6 * y[2] - 4 * y[1] + y[0]; // Δ4y4

    // First Derivative using Newton's formula
    double first_derivative = (1.0 / h) * (delta1 - delta2 / 2.0 + delta3 / 3.0 - delta4 / 4.0);

    // Second Derivative using Newton's formula
    double second_derivative = (1.0 / (h * h)) * (delta2 - delta3 + (11.0 / 12.0) * delta4);

    // Display the results
    cout << "\nFirst derivative at x = " << x[0] << " is: " << first_derivative << endl;
    cout << "Second derivative at x = " << x[0] << " is: " << second_derivative << endl;

    return 0;
}

