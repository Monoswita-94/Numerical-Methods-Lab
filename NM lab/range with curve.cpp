#include <iostream>
#include <graphics.h>  // For plotting the graph
using namespace std;

// Function f(x, y) = x + y
double f(double x, double y) {
    return x + y;
}

int main() {
    double x, y, h;
    int steps;

    // User input
    cout << "Enter initial value of x (x0): ";
    cin >> x;
    cout << "Enter initial value of y (y0): ";
    cin >> y;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter number of steps: ";
    cin >> steps;

    // Store initial values
    double x0 = x, y0 = y;

    // Graphics initialization
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw X and Y axes
    line(50, 240, 600, 240); // X-axis
    line(320, 50, 320, 430); // Y-axis

    outtextxy(600, 245, "X");
    outtextxy(325, 55, "Y");
    outtextxy(330, 245, "O");

    int scale_x = 100, scale_y = 80;

    // Plotting and RK4 computation
    for (int i = 0; i < steps; i++) {
        // RK4 calculation
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        double y_next = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        double x_next = x + h;

        // Print step
        cout << "After step " << i + 1 << ": x = " << x_next << ", y = " << y_next << "\n";

        // Plot point on graph
        int px = 320 + int(x * scale_x);   // X pixel
        int py = 240 - int(y * scale_y);   // Y pixel (invert for upward positive)
        putpixel(px, py, YELLOW);

        // Move to next point
        x = x_next;
        y = y_next;
    }

    outtextxy(100, 440, "RK4 Solution Curve of dy/dx = x + y");

    getch();
    closegraph();
    return 0;
}

