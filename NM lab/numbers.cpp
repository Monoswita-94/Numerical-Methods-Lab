#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countSignificantDigits(string numStr) {
    if (numStr[0] == '-' || numStr[0] == '+') numStr = numStr.substr(1);
    size_t ePos = numStr.find_first_of("eE");
    if (ePos != string::npos) numStr = numStr.substr(0, ePos);
    if (numStr.find('.') == string::npos && numStr.back() == '0') return -1;
    numStr.erase(0, numStr.find_first_not_of('0'));
    if (numStr.find('.') != string::npos)
        numStr.erase(numStr.find_last_not_of('0') + 1);
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
