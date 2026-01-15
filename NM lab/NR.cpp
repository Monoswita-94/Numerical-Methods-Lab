#include <iostream>
#include <cmath>

#define EPSILON 0.001 // Accuracy up to 3 decimal places

using namespace std;

// Function f(x) = x^3 - 6x + 4
double f(double x) {
    return x*x*x - 6*x + 4;
}

// Derivative f'(x) = 3x^2 - 6
double df(double x) {
    return 3*x*x - 6;
}

// Newton-Raphson Method
void newtonRaphson(double x0) {
    double x1;
    int iterations = 0;

    cout << "Iteration\tXn\t\tf(Xn)\n";

    do {
        x1 = x0 - f(x0) / df(x0);
        iterations++;

        cout << iterations << "\t\t" << round(x1 * 1000) / 1000 << "\t\t" << round(f(x1) * 1000) / 1000 << endl;

        if (fabs(x1 - x0) < EPSILON)
            break;

        x0 = x1;
    } while (true);

    cout << "\nRoot: " << round(x1 * 1000) / 1000 << endl;
    cout << "Total Iterations: " << iterations << endl;
}

int main() {
    double initial_guess;
    cout << "Enter initial guess: ";
    cin >> initial_guess;

    newtonRaphson(initial_guess);

    return 0;
}

