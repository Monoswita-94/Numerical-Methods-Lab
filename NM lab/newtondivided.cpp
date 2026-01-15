#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const int N = 5;
int main() {
    double x[N], y[N][N];
    for (int j = 1; j < N; j++)
     {
        for (int i = 0; i < N - j; i++)
            {
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j] - x[i]);
        }
    }
     cout << fixed << setprecision(4);
     cout << "\nDivided Difference Table:\n";
    double result = y[0][0];
    double term = 1;
    for (int i = 1; i < N; i++) {
        term *= (value - x[i - 1]);
        result += term * y[0][i];
    }
    double value;
    cout << "\nEnter the value x : ";
    cin >> value;
    cout << "\nThe interpolated value " << value << " is: " << result << endl;
     return 0;
}



