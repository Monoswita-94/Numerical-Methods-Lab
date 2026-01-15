#include <iostream>
#include <cmath>
using namespace std;
// Function to integrate: f(x) = e^(sin(x))
double f(double x) {
    return exp(sin(x));                                       //double f(double x) { // return sqrt(1 + x * x);}

}
int main() {
    double a, b;
    int n;

    // User input for limits and number of intervals
    cout << "Enter lower limit (a): ";
    cin >> a;

    cout << "Enter upper limit (b): ";
    cin >> b;

    cout << "Enter number of subintervals (n, must be even): ";
    cin >> n;
    // Check if n is even
    if (n % 2 != 0) {
        cout << "Error: Simpson's 1/3 rule requires an even number of intervals.\n";
        return 1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    // Apply Simpson's 1/3 Rule
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x); // even index
        else
            sum += 4 * f(x); // odd index
    }
    double area = (h / 3) * sum;

    cout << "\nApproximate area under the curve " << " e^(sin x) dx = " << area << endl;

    return 0;
}
