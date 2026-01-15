#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Function to count significant digits
int countSignificantDigits(string numStr) {
    // Trim leading and trailing spaces
    numStr.erase(0, numStr.find_first_not_of(" "));
    numStr.erase(numStr.find_last_not_of(" ") + 1);

    // Handle negative or positive signs
    if (numStr[0] == '-' || numStr[0] == '+') {
        numStr = numStr.substr(1);
    }

    // Check for scientific notation (e.g., 7.56e4)
    size_t ePos = numStr.find_first_of("eE");
    if (ePos != string::npos) {
        numStr = numStr.substr(0, ePos); // Remove exponent part
    }

    // If integer with trailing zeros and no decimal, it's ambiguous
    if (numStr.find('.') == string::npos && numStr.back() == '0') {
        return -1; // Ambiguous case
    }

    // Remove leading zeros
    numStr.erase(0, numStr.find_first_not_of('0'));

    // Remove trailing zeros only if there's a decimal point
    if (numStr.find('.') != string::npos) {
        numStr.erase(numStr.find_last_not_of('0') + 1);
    }

    // Count the significant digits (all non-zero digits + valid zeros)
    return count_if(numStr.begin(), numStr.end(), ::isdigit);
}

int main() {
    string num;
    cout << "Enter a number: ";
    cin >> num;

    int sigDigits = countSignificantDigits(num);
    if (sigDigits == -1)
        cout << num << " -> Ambiguous without scientific notation" << endl;
    else
        cout << num << " -> " << sigDigits << " significant digits" << endl;

    return 0;
}
