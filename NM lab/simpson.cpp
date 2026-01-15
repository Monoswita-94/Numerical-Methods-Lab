#include <iostream>
#include <cmath>
#include <graphics.h>  // For plotting the graph
using namespace std;

// Function to integrate: f(x) = e^(sin(x))
double f(double x) {
    return exp(sin(x));
}

int main() {
    double a, b;
    int n;

    // User input
    cout << "Enter lower limit (a): ";
    cin >> a;

    cout << "Enter upper limit (b): ";
    cin >> b;

    cout << "Enter number of subintervals (n, must be even): ";
    cin >> n;

    // Simpson's Rule check
    if (n % 2 != 0) {
        cout << "Error: Simpson's 1/3 rule requires an even number of intervals.\n";
        return 1;
    }

    // Step size
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    // Simpson's Rule calculation
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    double area = (h / 3) * sum;
    cout << "\nApproximate area under the curve e^(sin x) dx = " << area << endl;

    // ========================
    // Plotting the Curve
    // ========================

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw axes
    line(50, 240, 600, 240); // X-axis
    line(320, 50, 320, 430); // Y-axis

    outtextxy(600, 245, "X");
    outtextxy(325, 55, "Y");
    outtextxy(330, 245, "O");

    // Scale settings (adjust based on your graph size)
    int scale_x = 100; // pixels per x unit
    int scale_y = 80;  // pixels per y unit

    // Plotting curve for f(x)
    for (double x = a; x <= b; x += 0.001) {
        double y = f(x);
        int px = 320 + int(x * scale_x);         // x-pixel
        int py = 240 - int(y * scale_y);         // y-pixel (inverted for screen)
        putpixel(px, py, YELLOW);
    }

    outtextxy(100, 440, "Graph of y = e^(sin(x))");

    getch();
    closegraph();
    return 0;
}
