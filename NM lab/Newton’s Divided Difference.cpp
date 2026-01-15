#include <iostream>
#include <iomanip> // for formatting
using namespace std;

const int N = 5;

int main() {
    double x[N], y[N][N];

    // Take input for x values
    cout << "Enter " << " x values:\n";
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    // Take input for y = f(x) values
    cout << "Enter corresponding y = f(x) values:\n";
    for (int i = 0; i < N; i++) {
        cin >> y[i][0];
    }

    // Build divided difference table
    for (int j = 1; j < N; j++) {
        for (int i = 0; i < N - j; i++) {
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    // Display Divided Difference Table (Optional)
   // cout << fixed << setprecision(4);
   // cout << "\nDivided Difference Table:\n";
   // for (int i = 0; i < N; i++) {
   //    cout << setw(6) << x[i];
    //   for (int j = 0; j < N - i; j++) {
        //  cout << setw(12) << y[i][j];
    //    }
      // cout << endl;
   // }

    // Take input for the value of x to interpolate
    double value;
    cout << "\nEnter the value of x to interpolate: ";
    cin >> value;

    // Apply Newton's Divided Difference formula
    double result = y[0][0];
    double term = 1;

    for (int i = 1; i < N; i++) {
        term *= (value - x[i - 1]);
        result += term * y[0][i];
    }

    cout << "\nThe interpolated value at x = " << value << " is: " << result << endl;

    return 0;
}

