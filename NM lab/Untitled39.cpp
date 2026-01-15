#include <iostream>
using namespace std;

// First delta (forward difference)
double deltaY(double y0, double y1, double h) {
    return (y1 - y0) / h;
}

// Second delta (second forward difference)
double delta2Y(double y0, double y1, double y2, double h) {
    return (y2 - 2 * y1 + y0) / (h * h);
}

int main() {
    // Given data
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {1, 8, 27, 64, 125};

    // Step size (uniform)
    double h = x[1] - x[0];

    // Using delta notation at x = 1 (index 0)
    double dy = deltaY(y[0], y[1], h);
    double d2y = delta2Y(y[0], y[1], y[2], h);

    // Output
    cout << "Using Delta Method at x = " << x[0] << ":\n";
    cout << "Δy/h (First Derivative)  = " << dy << endl;
    cout << "Δ²y/h² (Second Derivative) = " << d2y << endl;

    return 0;
}
