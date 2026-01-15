#include <iostream>
using namespace std;

int main() {
    double A[3][3] = {{1,1,1}, {1,2,3}, {1,3,4}};
    double B[3] = {1,6,6};
    double inv[3][3], det, result[3];

    det = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1])
        - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0])
        + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    if (det == 0) {
        cout << "Matrix is singular. No unique solution." << endl;
        return 0;
    }

    // Calculate inverse matrix (adjoint / determinant)
    inv[0][0] =  (A[1][1]*A[2][2] - A[2][1]*A[1][2]) / det;
    inv[0][1] = -(A[0][1]*A[2][2] - A[2][1]*A[0][2]) / det;
    inv[0][2] =  (A[0][1]*A[1][2] - A[1][1]*A[0][2]) / det;

    inv[1][0] = -(A[1][0]*A[2][2] - A[2][0]*A[1][2]) / det;
    inv[1][1] =  (A[0][0]*A[2][2] - A[2][0]*A[0][2]) / det;
    inv[1][2] = -(A[0][0]*A[1][2] - A[1][0]*A[0][2]) / det;

    inv[2][0] =  (A[1][0]*A[2][1] - A[2][0]*A[1][1]) / det;
    inv[2][1] = -(A[0][0]*A[2][1] - A[2][0]*A[0][1]) / det;
    inv[2][2] =  (A[0][0]*A[1][1] - A[1][0]*A[0][1]) / det;

    // Multiply inverse matrix by B vector
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

