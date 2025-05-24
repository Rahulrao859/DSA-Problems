#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool seenB = false;
        for (char ch : s) {
            if (ch == 'b') {
                seenB = true;
            } else if (ch == 'a' && seenB) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter the string (only containing 'a' and 'b'): ";
    cin >> input;

    bool result = sol.checkString(input);

    if (result) {
        cout << "The string is valid (all 'a's appear before all 'b's)." << endl;
    } else {
        cout << "The string is invalid (an 'a' appears after a 'b')." << endl;
    } 

    return 0;
}
