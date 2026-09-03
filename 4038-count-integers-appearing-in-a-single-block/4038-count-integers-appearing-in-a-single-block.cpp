class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> seen;
        unordered_set<int> special;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] != nums[i - 1]) {
                seen.insert(nums[i - 1]);
            }

            if (seen.count(nums[i])) {
                special.erase(nums[i]);
            } else {
                special.insert(nums[i]);
            }
        }

        return special.size();
    }
};