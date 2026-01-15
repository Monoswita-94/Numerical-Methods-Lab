#include <iostream>
#include <cmath>
#define EPSILON 0.001
using namespace std;
double f(double x) {
    return x*x*x - 4*x + 1;
}
void falsePosition(double x1, double x2) {
    if (f(x1) * f(x2) >= 0) {
    cout << "Invalid interval! The function must have opposite signs at x1 and x2.\n";
    return;
    }
   double x;
    int iterations = 0;
    cout << "Iteration\tX\t\tf(X)\n";
  do {
        x = x1 - f(x1)*((x2 - x1)/(f(x2) - f(x1)));
        iterations++;
        cout << iterations << "\t\t" << round(x * 1000) / 1000 << "\t\t" << round(f(x) * 1000) / 1000 << endl;
        if (fabs(f(x)) < EPSILON)
            break;
       if (f(x) * f(x1) < 0)
            x2 = x;
        else
            x1 = x;
    }
    while (true);
    cout << "\nfinalRoot: " << round(x * 1000) / 1000 << endl;
    cout << "the number of Iterations: " << iterations << endl;
}
int main() {
    double x1, x2;
    cout << "Enter the interval [x1, x2]: ";
    cin >> x1 >> x2;
    falsePosition(x1, x2);
    return 0;
}
