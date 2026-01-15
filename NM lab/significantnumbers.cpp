#include <iostream>
#include <string>
using namespace std;

int countSignificantDigits(string num) {
    bool decimalFound = false;
    bool nonZeroSeen = false;
    int count = 0;

    // Trim leading spaces
    int start = 0;
    while (start < num.size() && num[start] == ' ') start++;

    // If decimal is present, remember its position
    size_t dotPos = num.find('.');

    for (int i = start; i < num.size(); ++i) {
        char ch = num[i];

        if (ch == '.') {
            decimalFound = true;
            continue;
        }

        if (ch >= '1' && ch <= '9') {
            nonZeroSeen = true;
            count++;
        }
        else if (ch == '0') {
            if (nonZeroSeen) {
                // Zeros after the first non-zero digit are significant
                count++;
            } else if (decimalFound) {
                // Leading zeros after decimal but before first non-zero are NOT significant
                continue;
            }
        }
    }

    // Post-processing for trailing zeros in whole numbers without decimal
    if (!decimalFound) {
        int lastNonZero = num.size() - 1;
        while (lastNonZero >= 0 && num[lastNonZero] == '0') {
            lastNonZero--;
        }

        count = 0;
        nonZeroSeen = false;

        for (int i = start; i <= lastNonZero; ++i) {
            char ch = num[i];
            if (ch >= '1' && ch <= '9') {
                nonZeroSeen = true;
                count++;
            }
            else if (ch == '0') {
                if (nonZeroSeen) count++;
            }
        }
    }

    return count;
}

int main() {
    string number;
    cout << "Enter a number: ";
    cin >> number;

    int sigDigits = countSignificantDigits(number);
    cout << "Number of significant digits: " << sigDigits << endl;

    return 0;
}



