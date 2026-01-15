#include <iostream>
using namespace std;

double determinant(double a, double b, double c, double d) {
    return (a * d - b * c);
}

double findDet(double a1, double a2, double a3,
               double b1, double b2, double b3,
               double c1, double c2, double c3) {
    return a1 * determinant(b2, b3, c2, c3) -
           b1 * determinant(a2, a3, c2, c3) +
           c1 * determinant(a2, a3, b2, b3);
}

int main() {
    double D, Dx, Dy, Dz;
    D = findDet(27, 6, -1, 6, 15, 2, 1, 1, 54);
    Dx = findDet(85, 6, -1, 72, 15, 2, 110, 1, 54);
    Dy = findDet(27, 85, -1, 6, 72, 2, 1, 110, 54);
    Dz = findDet(27, 6, 85, 6, 15, 72, 1, 1, 110);

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        double z = Dz / D;
        cout << "Solution: x = " << x << ", y = " << y << ", z = " << z << endl;
    } else {
        cout << "The system has no unique solution." << endl;
    }

    return 0;
}

