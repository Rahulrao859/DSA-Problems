class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        long long ans = LLONG_MAX;

        for (int i = 0; i < nums.size(); i += 2) {
            long long merged =
                stoll(to_string(nums[i]) + to_string(nums[i + 1]));
            ans = min(ans, merged);
        }

        return ans;
    }
};