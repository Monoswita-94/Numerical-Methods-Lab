#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Helper function to perform Banker's rounding
double bankersRound(double number) {
    double intPart;
    double fracPart = modf(number, &intPart);

    if (fabs(fracPart - 0.5) < 1e-9) {
        // Halfway case: round to nearest even
        if (fmod(intPart, 2.0) == 0.0)
            return intPart;
        else
            return intPart + ((number > 0) ? 1.0 : -1.0);
    } else {
        // Normal rounding
        return round(number);
    }
}

// Round a number to n significant figures using Banker's rounding
double roundToSignificantFigures(double num, int n) {
    if (num == 0.0)
        return 0.0;

    // Determine the order of magnitude of the number
    double order = floor(log10(fabs(num)));
    double scale = pow(10, n - 1 - order);

    double scaledNum = num * scale;
    double rounded = bankersRound(scaledNum);

    return rounded / scale;
}

int main() {
    double num;
    int sigFigs;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter number of significant figures: ";
    cin >> sigFigs;

    double result = roundToSignificantFigures(num, sigFigs);

    cout << fixed << setprecision(sigFigs) << "Rounded result: " << result << endl;

    return 0;
}

