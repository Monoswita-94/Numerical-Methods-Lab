#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to round a number to 'n' significant figures
double roundToSignificantFigures(double num, int n) {
    if (num == 0.0) return 0.0; // If number is 0, return 0

    // Compute the scaling factor based on the number of significant figures
    double scale = pow(10, n - 1 - floor(log10(fabs(num))));
    double rounded = round(num * scale) / scale; // Scale, round, then scale back

    return rounded;
}

int main() {
    double number;
    int sigFigures;

    // User input
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the number of significant figures: ";
    cin >> sigFigures;

    // Output the rounded number
    cout << fixed << setprecision(sigFigures)
         << "Rounded number: " << roundToSignificantFigures(number, sigFigures) << endl;

    return 0;
}

