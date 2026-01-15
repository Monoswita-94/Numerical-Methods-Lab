#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int countSignificantDigits(string num) {
    int count = 0;
    bool decimalFound = false;
    bool nonZeroFound = false;
    int trailingZeros = 0;
    size_t start = num.find_first_not_of(" ");
    if (start != string::npos)
        num = num.substr(start);

    size_t ePos = num.find_first_of("eE");
    if (ePos != string::npos) {
        num = num.substr(0, ePos);
    }

    for (size_t i = 0; i < num.length(); i++) {
        char c = num[i];
        if (c >= '1' && c <= '9') {
            count++;
            nonZeroFound = true;
            trailingZeros = 0;
        } else if (c == '0') {
            if (nonZeroFound) {
                count++;
            } else {
                trailingZeros++;
            }
        } else if (c == '.') {
            decimalFound = true;
            if (!nonZeroFound) trailingZeros = 0;
        }
    }

    return count;
}

int main() {
    string input;
    cout << "Enter a number: ";
    cin >> input;

    int sigDigits = countSignificantDigits(input);
    cout << "Number of significant digits: " << sigDigits << endl;

    return 0;
}
