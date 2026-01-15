#include <iostream>
using namespace std;

void syntheticDivision(int poly[], int n, int root) {
    int quotient[n - 1];
    quotient[0] = poly[0];

    for (int i = 1; i < n - 1; i++) {
        quotient[i] = poly[i] + quotient[i - 1] * root;
    }

    cout << "Quotient Polynomial: ";
    for (int i = 0; i < n - 2; i++) {
        if (quotient[i] >= 0 && i != 0)
            cout << "+";
        cout << quotient[i] << "x^" << (n - 2 - i) << " ";
    }

    // Print the last coefficient properly
    if (quotient[n - 2] >= 0)
        cout << "+";
    cout << quotient[n - 2] << endl;
}

int main() {
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;
    n++;  // Since the number of coefficients is degree + 1

    int poly[n];
    cout << "Enter the coefficients of the polynomial: ";
    for (int i = 0; i < n; i++) {
        cin >> poly[i];
    }

    int root;
    cout << "Enter the root: ";
    cin >> root;

    syntheticDivision(poly, n, root);
    return 0;
}

