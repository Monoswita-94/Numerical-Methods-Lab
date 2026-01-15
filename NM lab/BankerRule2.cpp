#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double roundToSignificantFigures(double num, int n) {
    if (num == 0.0)
        return 0.0;
    double scale = pow(10, n - 1 - floor(log10(fabs(num))));
    double rounded = round(num * scale) / scale;
    return rounded;
}
int main() {
    double number;
    int sigFigures;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the number of significant figures: ";
    cin >> sigFigures;
    cout << fixed << setprecision(sigFigures)<< "Rounded number: " << roundToSignificantFigures(number, sigFigures) << endl;
    return 0;
}
