#include <iostream>
using namespace std;

int main() {
    double A[3][3], B[3], inv[3][3], result[3];
    double det;

    cout << "Enter coefficients of matrix A (3x3):\n";
    for (int i = 0; i < 3; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter constants of vector B (3 values): ";
    for (int i = 0; i < 3; i++) {
        cin >> B[i];
    }

    det = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1])
        - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0])
        + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    if (det == 0) {
        cout << "Matrix is singular. No unique solution." << endl;
        return 0;
    }

    inv[0][0] =  (A[1][1]*A[2][2] - A[2][1]*A[1][2]) / det;
    inv[0][1] = -(A[0][1]*A[2][2] - A[2][1]*A[0][2]) / det;
    inv[0][2] =  (A[0][1]*A[1][2] - A[1][1]*A[0][2]) / det;

    inv[1][0] = -(A[1][0]*A[2][2] - A[2][0]*A[1][2]) / det;
    inv[1][1] =  (A[0][0]*A[2][2] - A[2][0]*A[0][2]) / det;
    inv[1][2] = -(A[0][0]*A[1][2] - A[1][0]*A[0][2]) / det;

    inv[2][0] =  (A[1][0]*A[2][1] - A[2][0]*A[1][1]) / det;
    inv[2][1] = -(A[0][0]*A[2][1] - A[2][0]*A[0][1]) / det;
    inv[2][2] =  (A[0][0]*A[1][1] - A[1][0]*A[0][1]) / det;


    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += inv[i][j] * B[j];
        }
    }

    cout << "Solution (Matrix Inversion):" << endl;
    cout << "x = " << result[0] << endl;
    cout << "y = " << result[1] << endl;
    cout << "z = " << result[2] << endl;

    return 0;
}

