#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;

        // Store the count of each character
        for (char ch : s) {
            mp[ch]++;
        }

        // Iterate over the hashmap to check the value
        if (!mp.empty()) {
            int firstValue = mp.begin()->second;
            for (auto &pair : mp) {
                if (pair.second != firstValue) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    bool result = solution.areOccurrencesEqual(s);

    if (result) {
        cout << "All characters have equal occurrences." << endl;
    } else {
        cout << "Characters do not have equal occurrences." << endl;
    }

    return 0;
}
