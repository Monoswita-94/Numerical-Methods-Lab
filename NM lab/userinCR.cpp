#include <iostream>
using namespace std;

int main() {
    double a1, b1, c1, d1;
    double a2, b2, c2, d2;
    double a3, b3, c3, d3;

    // Input coefficients and constants
    cout << "Enter coefficients for equation 1 (a1 b1 c1 d1): ";
    cin >> a1 >> b1 >> c1 >> d1;

    cout << "Enter coefficients for equation 2 (a2 b2 c2 d2): ";
    cin >> a2 >> b2 >> c2 >> d2;

    cout << "Enter coefficients for equation 3 (a3 b3 c3 d3): ";
    cin >> a3 >> b3 >> c3 >> d3;

    // Calculate determinants
    double D  = a1*(b2*c3 - b3*c2) - b1*(a2*c3 - a3*c2) + c1*(a2*b3 - a3*b2);
    // Determinants for Cramer's Rule
    // Dx - replace 1st column with constants
    double Dx = d1*(b2*c3 - b3*c2) - b1*(d2*c3 - d3*c2) + c1*(d2*b3 - d3*b2);
     // Dy - replace 2nd column with constants
    double Dy = a1*(d2*c3 - d3*c2) - d1*(a2*c3 - a3*c2) + c1*(a2*d3 - a3*d2);
    // Dz - replace 3rd column with constants
    double Dz = a1*(b2*d3 - b3*d2) - b1*(a2*d3 - a3*d2) + d1*(a2*b3 - a3*b2);
   // Check for unique solution
    if (D == 0) {
        cout << "No unique solution exists (D = 0)." << endl;
    } else {
        double x = Dx / D;
        double y = Dy / D;
        double z = Dz / D;

        cout << "\nSolution using Cramer's Rule:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
    }

    return 0;
}

