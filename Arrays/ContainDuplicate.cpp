#include <iostream>
#include <unordered_map>  // Required for unordered_map
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int num: nums) {
            mp[num]++;
        }

        for(auto &pair: mp) {
            if(pair.second > 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    // Test case 1: Array with duplicates
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test case 1: " << (solution.containsDuplicate(nums1) ? "True" : "False") << endl;

    // Test case 2: Array without duplicates
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test case 2: " << (solution.containsDuplicate(nums2) ? "True" : "False") << endl;

    // Test case 3: Array with all same elements
    vector<int> nums3 = {5, 5, 5, 5};
    cout << "Test case 3: " << (solution.containsDuplicate(nums3) ? "True" : "False") << endl;

    // Test case 4: Empty array
    vector<int> nums4 = {};
    cout << "Test case 4: " << (solution.containsDuplicate(nums4) ? "True" : "False") << endl;

    return 0;
}
