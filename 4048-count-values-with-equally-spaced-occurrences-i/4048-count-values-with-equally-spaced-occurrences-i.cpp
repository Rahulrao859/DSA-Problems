class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Store indices of each number
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        for (auto& [x, pos] : mp) {
            // Must occur exactly 3 times
            if (pos.size() == 3) {
                if (pos[1] - pos[0] == pos[2] - pos[1]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};