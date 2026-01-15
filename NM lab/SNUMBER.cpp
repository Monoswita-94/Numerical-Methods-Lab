#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int countSignificantDigits(string numStr) {
    // Remove sign if present
    if (numStr[0] == '-' || numStr[0] == '+') numStr = numStr.substr(1);

    // Check for scientific notation
    size_t ePos = numStr.find_first_of("eE");
    if (ePos != string::npos) numStr = numStr.substr(0, ePos);

    // Remove leading zeros before first non-zero digit
    size_t firstNonZero = numStr.find_first_not_of('0');
    if (firstNonZero == string::npos) {
        // If the string is all zeros, handle it separately.
        if (numStr.find('.') != string::npos) return 0; // 0.000 has zero significant digits
        else return 0; // 0 has zero significant digits.
    }
    numStr = numStr.substr(firstNonZero);

    // Remove trailing zeros if decimal exists
    size_t dotPos = numStr.find('.');
    if (dotPos != string::npos) {
        size_t lastNonZero = numStr.find_last_not_of('0');
        if (lastNonZero != string::npos && lastNonZero > dotPos) {
            numStr = numStr.substr(0, lastNonZero + 1);
        } else if (lastNonZero < dotPos || lastNonZero == string::npos){
            numStr = numStr.substr(0,dotPos+1);
        }
    }

    // If integer with trailing zeros, it's ambiguous
    if (numStr.find('.') == string::npos && numStr.find_first_of('.') == string::npos && numStr.find_last_not_of('0') != string::npos && numStr.find_last_not_of('0') < numStr.size()-1) return -1;

    // Count digits
    return count_if(numStr.begin(), numStr.end(), ::isdigit);
}

int main() {
    string numbers[] = {"3.50", "65.0", "0.230", "0.0001234", "0.001234", "0.01234", "4500", "4500.0",
                        "7.56e4", "7.560e4", "7.5600e4", "004500", "-0.00450", "000", "0.000"};

    for (const string& num : numbers) {
        int sigDigits = countSignificantDigits(num);
        if (sigDigits == -1)
            cout << num << " -> Ambiguous without scientific notation" << endl;
        else
            cout << num << " -> " << sigDigits << " significant digits" << endl;
    }
    return 0;
}
