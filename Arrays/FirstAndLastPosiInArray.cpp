#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FirstOcc(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;  // Move to the left part to find the first occurrence
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int LastOcc(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1;  // Move to the right part to find the last occurrence
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(FirstOcc(nums, target));
        ans.push_back(LastOcc(nums, target));
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10}; // Example input
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    // Print the result
    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}
