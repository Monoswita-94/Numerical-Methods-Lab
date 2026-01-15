#include <iostream>
using namespace std;
double f(double x, double y) {
    return x*x-y;  }
int main()
 {
    double x, y, h=0.1;
    int steps;
    cout << "Enter initial value of x (x0): ";
    cin >> x;
    cout << "Enter initial value of y (y0): ";
    cin >> y;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter number of steps: ";
    cin >> steps;

    for (int i = 0; i < steps; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
  x=x+h;
}
double y_next = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x = x + h;
        cout << "After step " << i + 1 << ": x = " << x << ", y = " << y_next << "\n";
        y = y_next;    }
    return 0;  }

